#include "searchBooksWidget.h"
#include "ui_searchBooksWidget.h"

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

    ui->listWidget->addItem("prueba");
}

void searchBooksWidget::setClient(TcpClient *entry)
{
    client = entry;
}

void searchBooksWidget::on_openButton_clicked()
{
    QString test = ui->listWidget->currentItem()->text();
}
