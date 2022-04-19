#ifndef EDIT_MATERIAL_H
#define EDIT_MATERIAL_H

#include <QDialog>
#include<vector>
#include<QComboBox>
using namespace std ;
namespace Ui {
class Edit_material;
}

class Edit_material : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_material(QWidget *parent = nullptr);
     Edit_material(QWidget*parent , vector<QString> data_choice) ;
     vector<QString> Get_data() ;
    ~Edit_material();

private slots:
     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::Edit_material *ui;
    vector<QString> data ;
    QComboBox*combobox;

};

#endif // EDIT_MATERIAL_H
