#ifndef ADD_DATA_MATERIAL_H
#define ADD_DATA_MATERIAL_H
#include <QDialog>
#include <stack>
#include<QLineEdit>
using namespace std ;
namespace Ui {
class ADD_data_material;
}

class ADD_data_material : public QDialog
{
    Q_OBJECT

public:
    explicit ADD_data_material(QWidget *parent = nullptr);
    ~ADD_data_material();
     QVector<QString>  Get_result() ;
     void Input_process(QLineEdit & , QString combo_box_text , QString ref,stack<QString> input_pro) ;
private slots:
    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_Ten_vat_lieu_textChanged(const QString &arg1);

    void on_kichthuoc_textChanged(const QString &arg1);

    void on_Gioi_han_ben_u_textChanged(const QString &arg1);

    void on_Gioi_han_ben_chay_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_3_currentTextChanged(const QString &arg1);

private:
    Ui::ADD_data_material *ui;
    QString Do_ran_HB ;
    QString Ten_vat_Lieu ;
    QString Kich_thuoc ;
    QString Gioi_han_ben_chay ;
    QString Gioi_han_ben_UON ;
    QString Cong_thuc ;
    QString Nhiet_Luyen ;
    QVector<QString> res ;
    stack<QString> stack_input ;


};

#endif // ADD_DATA_MATERIAL_H
