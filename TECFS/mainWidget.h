#ifndef WIDGET_H
#define WIDGET_H

#include "TcpClient.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_storeBooks_clicked();

    void on_searchBooks_clicked();

public:
    TcpClient *client = new TcpClient();
    void sendBook(QString);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
