#ifndef SEARCHBOOKSWIDGET_H
#define SEARCHBOOKSWIDGET_H

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

private:
    Ui::searchBooksWidget *ui;
};

#endif // SEARCHBOOKSWIDGET_H
