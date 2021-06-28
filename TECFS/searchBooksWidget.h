#ifndef SEARCHBOOKSWIDGET_H
#define SEARCHBOOKSWIDGET_H

#include "TcpClient.h"

#include <QDialog>

namespace Ui {
class searchBooksWidget;
}

class searchBooksWidget : public QDialog
{
    Q_OBJECT

public:
    explicit searchBooksWidget(QWidget *parent = nullptr);
    ~searchBooksWidget();

private slots:
    void on_searchButton_clicked();

    void on_openButton_clicked();

public:
    void setClient(TcpClient *);

private:
    Ui::searchBooksWidget *ui;
    TcpClient *client;
};

#endif // SEARCHBOOKSWIDGET_H
