#include "mainWidget.h"
#include "ui_mainWidget.h"
#include "storeBooksWidget.h"
#include "searchBooksWidget.h"
#include "TcpClient.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    TcpClient *client = new TcpClient();
    client->Connect();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_storeBooks_clicked()
{
    storeBooksWidget D(this);
    if (D.exec() == QDialog::Rejected) {
        return;
    }
}

void Widget::on_searchBooks_clicked()
{
    searchBooksWidget D(this);
    if (D.exec() == QDialog::Rejected) {
        return;
    }
}
