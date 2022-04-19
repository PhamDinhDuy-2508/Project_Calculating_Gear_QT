#include "zoom_table_t_t_view.h"
#include "ui_zoom_table_t_t_view.h"
#include<future>
#include<QDebug>
Zoom_table_T_t_view::Zoom_table_T_t_view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Zoom_table_T_t_view)
{
    ui->setupUi(this);
}

Zoom_table_T_t_view::Zoom_table_T_t_view(QWidget *Parent, int number_row, QString Type, vector<double> data_in_row):
    QDialog(Parent),
    ui(new Ui::Zoom_table_T_t_view) , row(number_row) , Type_name(Type) , data(data_in_row)
{
    ui->setupUi(this);
    QWidget::setWindowTitle(Type) ;
    Add_T_row() ;
}

Zoom_table_T_t_view::~Zoom_table_T_t_view()
{
    delete ui;
}

void Zoom_table_T_t_view::Add_T_row()
{
    if(ui->tableWidget->rowCount() != 0 ) {
        ui->tableWidget->setRowCount(0) ;
    }
    for(int i = 0 ; i < row ; i++) {
        ui->tableWidget->insertRow(0) ;
    }
    future<void> Thread1  = async(launch::async , [=](){
        for(int i = 0; i < row ; i++){
            QTableWidgetItem*name1 = new QTableWidgetItem ;
            name1->setText(QString::number(data[i]));
            ui->tableWidget->setItem(i,1,name1) ;
        }
    }) ;
    if(Type_name == "T") {
        for(int i = 0; i < row ; i++){
            QTableWidgetItem*name1 = new QTableWidgetItem ;
            name1->setText("T" + QString::number(i+1)+"=");
            ui->tableWidget->setItem(i,0,name1) ;
            ui->tableWidget->item(i,0)->setFlags(ui->tableWidget->item(i,0)->flags() &  ~Qt::ItemIsEditable);
       }
    }
    else if(Type_name == "t") {
        for(int i = 0; i < row ; i++){
            QTableWidgetItem*name1 = new QTableWidgetItem ;
            name1->setText("t" + QString::number(i+1)+"=");
            ui->tableWidget->setItem(i,0,name1) ;
            ui->tableWidget->item(i,0)->setFlags(ui->tableWidget->item(i,0)->flags() &  ~Qt::ItemIsEditable);
       }
    }
    Thread1.get()  ;
}

vector<double> Zoom_table_T_t_view::get_result()
{
    return this->result ;
}
void Zoom_table_T_t_view::on_pushButton_clicked()
{
    for(int i = 0; i < row ; i++){
        result.push_back(ui->tableWidget->model()->index(i , 1).data().toDouble()) ;
    }
    accept() ;
}
