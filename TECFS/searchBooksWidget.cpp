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
