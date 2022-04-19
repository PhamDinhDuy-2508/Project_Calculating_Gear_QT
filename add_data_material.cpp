#include "add_data_material.h"
#include "ui_add_data_material.h"
#include<QDebug>
#include<QKeyEvent>
ADD_data_material::ADD_data_material(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ADD_data_material)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Tạo vật liệu") ;
    connect(ui->Do_ran , &QLineEdit::textChanged,[=](){
        Do_ran_HB = ui->comboBox->currentText() + ui->Do_ran->text() ;
        if(*Do_ran_HB.rbegin() == ",")  {
            ui->Do_ran->setText('(' + ui->Do_ran->text() +')') ;
        }
    }) ;
    this->Cong_thuc =  ui->comboBox_3->currentText() ;
    this->Nhiet_Luyen =  ui->comboBox_2->currentText() ;
}

ADD_data_material::~ADD_data_material()
{
    delete ui;
}

 QVector<QString>  ADD_data_material::Get_result()
{
     return this->res;
 }

 void ADD_data_material::Input_process(QLineEdit & line_edit, QString combo_box_text, QString ref,stack<QString> input_pro)
 {
        ref =combo_box_text+ line_edit.text() ;
        connect(&line_edit ,  &QLineEdit::textChanged , [&ref,combo_box_text ,&line_edit,&input_pro](){
            ref  = combo_box_text+ line_edit.text() ;
            if(*ref.rbegin() == ",") {
                if(input_pro.empty()) {
                   input_pro.push(",") ;
                   input_pro.push(")") ;
                }
                else {

                }
           }
        }) ;
 }

void ADD_data_material::on_comboBox_2_currentTextChanged(const QString &arg1)
{
        Nhiet_Luyen =  arg1 ;
}

void ADD_data_material::on_comboBox_currentTextChanged(const QString &arg1)
{
    Do_ran_HB = arg1 + ui->Do_ran->text() ;
    connect(ui->Do_ran , &QLineEdit::textChanged,[=](){
        Do_ran_HB = arg1 + ui->Do_ran->text() ;
        if(*Do_ran_HB.rbegin() == ",")  {
            ui->Do_ran->setText('(' + Do_ran_HB+')') ;
        }
    }) ;
}

void ADD_data_material::on_Ten_vat_lieu_textChanged(const QString &arg1)
{
    Ten_vat_Lieu = ui->Ten_vat_lieu->text() ;
}

void ADD_data_material::on_kichthuoc_textChanged(const QString &arg1)
{
    Kich_thuoc =   ui->kichthuoc->text() ;
    if(*Kich_thuoc.rbegin() == ",")  {
        ui->kichthuoc->setText('(' + Kich_thuoc+')') ;
    }
}

void ADD_data_material::on_Gioi_han_ben_u_textChanged(const QString &arg1)
{
    Gioi_han_ben_UON =   ui->Gioi_han_ben_u->text() ;
    if(*Gioi_han_ben_UON.rbegin() == ",")  {
       ui->Gioi_han_ben_u->setText('(' + Gioi_han_ben_UON+')') ;
    }
}

void ADD_data_material::on_Gioi_han_ben_chay_textChanged(const QString &arg1)
{
    Gioi_han_ben_chay =   ui->Gioi_han_ben_chay->text() ;
    if(*Gioi_han_ben_chay.rbegin() == ",")  {
       ui->Gioi_han_ben_chay->setText('(' + Gioi_han_ben_chay+')') ;
    }
}

void ADD_data_material::on_pushButton_2_clicked()
{
    res = {Ten_vat_Lieu , Nhiet_Luyen , Kich_thuoc,Do_ran_HB,Gioi_han_ben_UON,Gioi_han_ben_chay,Cong_thuc} ;
    accept() ;
}

void ADD_data_material::on_pushButton_3_clicked()
{
    reject() ;
}

void ADD_data_material::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    this->Cong_thuc = arg1 ;
}
