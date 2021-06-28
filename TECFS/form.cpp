#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::setText(QString title, QString content)
{
    ui->lineEdit->setText(title);
}

void Form::on_showButton_clicked()
{

}
