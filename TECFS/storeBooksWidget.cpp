#include "storeBooksWidget.h"
#include "ui_storeBooksWidget.h"

storeBooksWidget::storeBooksWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::storeBooksWidget)
{
    ui->setupUi(this);
}

storeBooksWidget::~storeBooksWidget()
{
    delete ui;
}
