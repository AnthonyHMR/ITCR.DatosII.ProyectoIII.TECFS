#ifndef STOREBOOKSWIDGET_H
#define STOREBOOKSWIDGET_H

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

private:
    Ui::storeBooksWidget *ui;
};

#endif // STOREBOOKSWIDGET_H
