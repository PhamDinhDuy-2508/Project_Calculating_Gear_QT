#include "set_aw.h"
#include "ui_set_aw.h"
#include<QMessageBox>
Set_aw::Set_aw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Set_aw)
{
    ui->setupUi(this);
}

Set_aw::Set_aw(QWidget *parent, QString str):
    String_input((str)), QDialog(parent),
    ui(new Ui::Set_aw)
{
    ui->setupUi(this);
    this->setWindowTitle("Chọn lại giá trị aw") ;
    ui->label->setText(str) ;
    connect(ui->lineEdit , &QLineEdit::editingFinished ,[=](){
            if(ui->lineEdit->text().toDouble() < ui->label->text().toDouble()) {
                    ui->lineEdit->clear()     ;
                    ui->lineEdit->setText(ui->label->text()) ;
                    ui->lineEdit->setStyleSheet("border: 1px solid black") ;
            }
            if(ui->lineEdit->text().toDouble() == 0 ) {
                ui->lineEdit->setStyleSheet("border: 1px solid red") ;
            }
    }) ;
}
Set_aw::~Set_aw()
{
    delete ui;
}

double Set_aw::Get_value_aw()
{
 return this->ui->lineEdit->text().toDouble() ;
}

void Set_aw::on_pushButton_clicked()
{
    if(ui->lineEdit->text().toDouble() == 0){
        int ret = QMessageBox::warning(this, tr("Error"),
                                        tr("Giá trị Aw không phù hợp"),
                                        QMessageBox::Ok | QMessageBox::Cancel)  ;
    }
    else {
        accept() ;
    }
}

void Set_aw::on_pushButton_2_clicked()
{
    reject() ;
}
