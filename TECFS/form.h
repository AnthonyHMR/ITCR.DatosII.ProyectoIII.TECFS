#ifndef FORM_H
#define FORM_H

#include <QDialog>

namespace Ui {
class Form;
}

class Form : public QDialog
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void setText(QString, QString);

private slots:
    void on_showButton_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
