#include "table_ka_kd_zm.h"
#include "ui_table_ka_kd_zm.h"
#include<QDebug>
Table_Ka_kd_Zm::Table_Ka_kd_Zm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table_Ka_kd_Zm)
{  
    ui->setupUi(this);    
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectColumns);
    Ka_Kd_Zm.resize(3) ;
    this->setWindowTitle("Bảng tra Ka,Kd,Zm") ;
    database  = QSqlDatabase::addDatabase("QMYSQL") ;
    database.setHostName("127.0.0.1");
    database.setUserName("root") ;
    database.setPassword("") ;
    database.setDatabaseName("do_an_data_base") ;
    database.open() ;
    model = new QSqlTableModel() ;
    model->setTable("ka_kd_zm_thang") ;
    model->select() ;
    Set_Header() ;
    ui->tableView->setModel(model);
    ui->lineEdit->hide() ;
    ui->label_2->hide() ;
}

void Table_Ka_kd_Zm::Set_Header()
{
    model->setHeaderData(model->fieldIndex("He_so"), Qt::Horizontal, tr("Hệ Số"));
    model->setHeaderData(model->fieldIndex("Thep_Thep"), Qt::Horizontal, tr("Thép - Thép"));
    model->setHeaderData(model->fieldIndex("Thep_gang"), Qt::Horizontal, tr("Thép - Gang"));
    model->setHeaderData(model->fieldIndex("Thep_dong_thanh"), Qt::Horizontal, tr("Thép - Đồng Thanh"));
    model->setHeaderData(model->fieldIndex("gang_gang"), Qt::Horizontal, tr("Gang - Gang"));
    model->setHeaderData(model->fieldIndex("techtolit_thep"), Qt::Horizontal, tr("Techtolit - Thép"));
    model->setHeaderData(model->fieldIndex("Poliamid_thep"), Qt::Horizontal, tr("Poliamid - Thép"));
}

void Table_Ka_kd_Zm::Mapping(int i)
{
  return ;
}
Table_Ka_kd_Zm::~Table_Ka_kd_Zm()
{
    delete ui;
}

void Table_Ka_kd_Zm::on_tableView_clicked(const QModelIndex &index)
{
    if(index.column() != 0) {
        this->Ka_Kd_Zm[0] =  ui->tableView->model()->index(0,index.column()).data().toDouble();
        this->Ka_Kd_Zm[1] =  ui->tableView->model()->index(1,index.column()).data().toDouble();
        this->Ka_Kd_Zm[2] =  ui->tableView->model()->index(2,index.column()).data().toDouble();
    }
}

void Table_Ka_kd_Zm::on_pushButton_clicked()
{
    Set_Beta(ui->lineEdit->text()) ;
    Set_combobox_choice(ui->comboBox->currentIndex()) ;
    accept() ;
}

QVector<double> Table_Ka_kd_Zm::Get_Ka_Kd_Zm()
{
    return this->Ka_Kd_Zm ;
}

void Table_Ka_kd_Zm::Set_Beta(QString _Beta)
{
    this->Beta = _Beta.toDouble() ;
}

double Table_Ka_kd_Zm::Get_Beta()
{
    return (this->Beta*3.14/180) ;
}

double Table_Ka_kd_Zm::get_Cobobox_choice()
{
    return this->combobox_choice  ;
}

void Table_Ka_kd_Zm::Set_combobox_choice(int index)
{
    this->combobox_choice = double(index) ;
}

void Table_Ka_kd_Zm::on_comboBox_currentIndexChanged(int index)
{
    if(index == 2) {
        model = new QSqlTableModel() ;
        model->setTable("ka_kd_nghieng") ;
        model->select() ;
        Set_Header() ;
        ui->tableView->setModel(model);
        ui->label_2->show() ;
        ui->lineEdit->show() ;
    }
    else {
        ui->label_2->hide() ;
        ui->lineEdit->hide() ;
        model = new QSqlTableModel() ;
        model->setTable("ka_kd_zm_thang") ;
        model->select() ;
        ui->tableView->setModel(model);
        Set_Header() ;
    }
}
