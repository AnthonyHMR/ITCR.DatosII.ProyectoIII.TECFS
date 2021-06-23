#ifndef STOREBOOKSWIDGET_H
#define STOREBOOKSWIDGET_H

#include "TcpClient.h"

#include <QDialog>

namespace Ui {
class storeBooksWidget;
}

class storeBooksWidget : public QDialog
{
    Q_OBJECT

public:
    explicit storeBooksWidget(QWidget *parent = nullptr);
    ~storeBooksWidget();

private slots:
    void on_openFile_clicked();

    void on_saveFile_clicked();

public:
    void setClient(TcpClient *);

private:
    Ui::storeBooksWidget *ui;
    TcpClient *client;
};

#endif // STOREBOOKSWIDGET_H
