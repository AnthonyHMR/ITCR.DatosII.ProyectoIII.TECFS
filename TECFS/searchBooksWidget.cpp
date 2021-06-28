#include "searchBooksWidget.h"
#include "ui_searchBooksWidget.h"
#include "form.h"

#include <QDebug>
#include <QJsonArray>

searchBooksWidget::searchBooksWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchBooksWidget)
{
    ui->setupUi(this);
}

searchBooksWidget::~searchBooksWidget()
{
    delete ui;
}

void searchBooksWidget::on_searchButton_clicked()
{
    ui->listWidget->clear();
    QByteArray data_json;
    QJsonDocument doc;
    QJsonObject obj;
    QJsonObject typeObj;

    obj["Type"] = ui->comboBox->currentText();
    obj["Word"] = ui->lineEdit->text();

    typeObj["Search"] = obj;

    doc.setObject(typeObj);
    data_json = doc.toJson();

    client->sendMessage(data_json);

    QJsonObject results = json->getJsonObjectFromString(client->getMessage());

    QJsonArray arrayResults = results["Results"].toArray();

    for (int i = 0; arrayResults.size() != i; i++) {
        QJsonObject res = arrayResults[i].toObject();
        ui->listWidget->addItem( QString::number(res["ID"].toInt()) + ") " + res["Author"].toString() + ": " + res["Title"].toString() + " | " + res["Date"].toString());
    }

    qDebug() << client->getMessage();
}

void searchBooksWidget::setClient(TcpClient *entry)
{
    client = entry;
}

void searchBooksWidget::on_openButton_clicked()
{
    QRegExp lines("(\\)|\\:|\\|)");

    QString currentLine = ui->listWidget->currentItem()->text();

    QStringList file = currentLine.split(lines);
    file.removeAll("");

    QByteArray data_json;
    QJsonDocument doc;
    QJsonObject obj;

    obj["File"] = file.first().toInt();

    doc.setObject(obj);
    data_json = doc.toJson();

    client->sendMessage(data_json);

    qDebug() << client->getMessage();

    Form D(this);
    D.setText(file[2], "prueba");
    if (D.exec() == QDialog::Rejected) {
        return;
    }
}
