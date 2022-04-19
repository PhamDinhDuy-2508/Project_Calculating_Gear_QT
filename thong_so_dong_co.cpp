#include "thong_so_dong_co.h"
#include "ui_thong_so_dong_co.h"
#include<QDebug>
Thong_So_Dong_co::Thong_So_Dong_co(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Thong_So_Dong_co)
{
    ui->setupUi(this);
    this->setWindowTitle("Bảng tra thông số động cơ") ;
    database  = QSqlDatabase::addDatabase("QMYSQL") ;
    database.setHostName("127.0.0.1");
    database.setUserName("root") ;
    database.setPassword("") ;
    database.setDatabaseName("gear_info") ;
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    data.text=" " ;
    data.column_choice = 0 ;

}
Thong_So_Dong_co::~Thong_So_Dong_co()
{
    delete ui;
}

void Thong_So_Dong_co::Set_table_of_database(QString name)
{
    if(database.open()) {
        Model =  new QSqlTableModel() ;
        Model->setTable(name) ;
        Model->select() ;
        ui->tableView->setModel(Model) ;     
    }
    else {
        return ;
    }
}

void Thong_So_Dong_co::Load_combox()
{
    for(int i = 0; i < Model->columnCount();i++){
        link_header_to_combobox.insert({i+1 ,  ui->tableView->model()->headerData(i,Qt::Horizontal).toString()}) ;
        ui->comboBox->addItem(ui->tableView->model()->headerData(i,Qt::Horizontal).toString() ) ;
    }
    return ;

}
void Thong_So_Dong_co::on_listWidget_itemClicked(QListWidgetItem *item)
{
    return  ;
}

void Thong_So_Dong_co::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->comboBox->clear() ;
    ui->comboBox->addItem("</all> ") ;
    link_header_to_combobox.clear() ;
    Set_table_of_database(item->text(0)) ;
    Load_combox() ;
    ui->label_3->hide() ;
    this->Present_data_table =  item->text(0) ;
}

void Thong_So_Dong_co::on_comboBox_currentIndexChanged(int index)
{
    if(index != 0 && index != -1){
        Gear_info  = new Gear_Info(index , link_header_to_combobox) ;
    }
}

void Thong_So_Dong_co::on_lineEdit_2_textChanged(const QString &arg1)
{
    if(ui->comboBox->currentIndex() != 0 ) {
        qDebug() << Gear_info->Searrch(arg1) ;
        Model->setFilter( Gear_info->Searrch(arg1)) ;
    }
    if(ui->lineEdit_2->text() == "") {
        Model =  new QSqlTableModel() ;
        Model->setTable(this->Present_data_table) ;
        Model->select() ;
        ui->tableView->setModel(Model) ;

    }
}
