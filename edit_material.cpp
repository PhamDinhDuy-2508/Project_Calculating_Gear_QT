#include "edit_material.h"
#include "ui_edit_material.h"
#include<QTableWidgetItem>
#include<iostream>
#include<QDebug>
using namespace  std ;
Edit_material::Edit_material(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_material)
{
    ui->setupUi(this);
}

Edit_material::Edit_material(QWidget *parent, vector<QString> data_choice) :
    QDialog(parent),ui(new Ui::Edit_material),data(data_choice)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Chỉnh sửa vật liệu") ;
    for(int i = 0; i < data.size()-1 ; i++) {
        if(i == 1) {
            continue ;
        }
        QTableWidgetItem*name = new QTableWidgetItem ;
        name->setText(data[i]) ;
        ui->tableWidget->setItem(0,i,name) ;
    }
    ui->comboBox_2->setCurrentText(data[1]) ;
    if(data[data.size()-1][0] == '2') {
        ui->comboBox->setCurrentIndex(0) ;
    }
    else {
        ui->comboBox->setCurrentIndex(1) ;
    }
}

Edit_material::~Edit_material()
{
    delete ui;
}

void Edit_material::on_pushButton_2_clicked()
{
    for(int i = 0; i < data.size()-1;i++){
        if(i ==1) {
            this->data[i] = "'" + ui->comboBox_2->currentText() +"'";
            continue ;
          }
         this->data[i] = "'" + ui->tableWidget->model()->index(0,i).data().toString()+"'" ;
    }
    this->data[data.size()-1] = "'"+ui->comboBox->currentText()+"'" ;
    accept() ;
}
vector<QString> Edit_material::Get_data(){
    return this->data ;
}

void Edit_material::on_pushButton_3_clicked()
{
    reject() ;
}
void Edit_material::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    data[1] =  arg1 ;
}
