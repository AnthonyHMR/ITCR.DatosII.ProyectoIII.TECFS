#include "storeBooksWidget.h"
#include "ui_storeBooksWidget.h"

#include "mainWidget.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QJsonObject>
#include <QDateTime>

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
    fileName = QFileDialog::getOpenFileName(
                this,
                "TextEditor - Open file",
                "/home/anthony/Documents",
                "Text Files (*.txt);;All Files (*.*)"
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
    QRegExp lines("(\\/|\\.txt)");

    QStringList titlePath = fileName.split(lines);
    titlePath.removeAll("");

    QByteArray data_json;
    QJsonDocument doc;
    QJsonObject typeObj;
    QJsonObject obj;
    QDateTime date = QDateTime::currentDateTime();
    QString format = "yyyy/MM/dd HH:mm:ss";

    obj["ID"] = count;
    obj["Title"] = titlePath.last();
    obj["Author"] = "Prueba Autor";
    obj["Date"] = date.toString(format);
    obj["Info"] = ui->plainTextEdit->toPlainText();

    typeObj["Book"] = obj;

    doc.setObject(typeObj);
    data_json = doc.toJson();

    client->sendMessage(data_json);

    count++;

    QMessageBox::information(this, tr("Information"), tr("Your book has been saved!"));
}

void storeBooksWidget::setClient(TcpClient *entry)
{
    client = entry;
}
