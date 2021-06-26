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
    QJsonObject typeObj;

    typeObj["Search"] = ui->lineEdit->text();

    doc.setObject(typeObj);
    data_json = doc.toJson();

    client->sendMessage(data_json);
}

void searchBooksWidget::setClient(TcpClient *entry)
{
    client = entry;
}
