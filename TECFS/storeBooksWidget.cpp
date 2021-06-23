#include "storeBooksWidget.h"
#include "ui_storeBooksWidget.h"

#include "mainWidget.h"

#include <QFileDialog>
#include <QMessageBox>

extern Widget *widget;

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

void storeBooksWidget::on_openFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                "TextEditor - Open file",
                "/home/anthony/Documents",
                "Text Files (*.pdf);;All Files (*.*)"
                );
    if(!fileName.isEmpty()){
        QFile file(fileName);
        if(file.open(QFile::ReadOnly)){
            ui->plainTextEdit->setPlainText(file.readAll());
        }else{
            QMessageBox::warning(
                        this,
                        "TextEditor",
                        tr("Cannot read file %1.\nError: %2")
                        .arg(fileName)
                        .arg(file.errorString()));
        }
    }
}

void storeBooksWidget::on_saveFile_clicked()
{
    client->sendMessage(ui->plainTextEdit->toPlainText());
}

void storeBooksWidget::setClient(TcpClient *entry)
{
    client = entry;
}
