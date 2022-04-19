#ifndef SET_AW_H
#define SET_AW_H

#include <QDialog>
#include<QString>

namespace Ui {
class Set_aw;
}

class Set_aw : public QDialog
{
    Q_OBJECT

public:
    explicit Set_aw(QWidget *parent = nullptr);
    explicit Set_aw(QWidget *parent  ,  QString str) ;
    ~Set_aw();
    double Get_value_aw() ;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Set_aw *ui;
    QString String_input ;
};

#endif // SET_AW_H
