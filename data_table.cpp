#include "data_table.h"
#include "ui_data_table.h"
#include <QDataWidgetMapper>
#include<future>
#include<QChar>
#include<QItemSelectionModel>
#include<table_ka_kd_zm.h>
#include<algro_process.h>
#include<add_data_material.h>
#include<edit_material.h>
#include<search_custom.h>

Data_table::Data_table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Data_table)
{
    ui->setupUi(this);
    this->setWindowTitle("Bảng Tra Vật liệu Bánh răng lớn và Nhỏ") ;
    database  = QSqlDatabase::addDatabase("QMYSQL") ;
    database.setHostName("127.0.0.1");
    database.setUserName("root") ;
    database.setPassword("") ;
    database.setDatabaseName("do_an_data_base") ;
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    Hide_all() ;  
    Constructor_Map() ;
    connect(ui->Cong_thuc_tuong_ung , SLOT(Data_Changed(QString &)) ,this , SLOT(Signal_change(QString &)));
    Processing =  new Algro_Process() ;
    Thread_load_table = async(launch::async , [=](){
       Search_HRC_HB->Set_arr_FB( Search_HRC_HB->Get_Table_From_File("E:/QT5/Project_calculating_Gear/HRC_HB.txt")) ;
    }) ;
}
void Data_table::Set_QSQLtable(QString name)
{
    if(database.open()) {
        model = new QSqlTableModel() ;
        model->setTable(name) ;
        model->select() ;
        Set_Header() ;
        ui->tableView->setModel(model);       
        //data_filter.database = database ;
        //data_filter.name_of_database = name ;
        data_filter.column_choice = 0 ;            
    }
    Title_Search tilte_search  (database , name) ;
    this->filter =  new Signal_(tilte_search,data_filter) ;
    Mapping() ;
}
void Data_table::Set_Header()
{
    model->setHeaderData(model->fieldIndex("Nhan_hieu"), Qt::Horizontal, tr("Nhãn Hiệu"));
    model->setHeaderData(model->fieldIndex("Nhiet_luyen"), Qt::Horizontal, tr("Nhiệt luyện"));
    model->setHeaderData(model->fieldIndex("Kich_thuoc_S"), Qt::Horizontal, tr("Kích Thước S"));
    model->setHeaderData(model->fieldIndex("Do_ran"), Qt::Horizontal, tr("Độ Rắn"));
    model->setHeaderData(model->fieldIndex("Gioi_han_ben"), Qt::Horizontal, tr("Giới Hạn Bền"));
    model->setHeaderData(model->fieldIndex("Gioi_han_chay"), Qt::Horizontal, tr("Giới Hạn Chảy"));
}

void Data_table::Mapping()
{   
    mapper->setModel(model) ;
    mapper->addMapping(ui->Nhan_Hieu ,  model->fieldIndex("Nhan_hieu")) ;
    mapper->addMapping(ui->Nhiet_luyen ,  model->fieldIndex("Nhiet_luyen")) ;
    mapper->addMapping(ui->Kich_Thuoc,  model->fieldIndex("Kich_thuoc_S")) ;
    mapper->addMapping(ui->Gioi_han_chay_3 ,  model->fieldIndex("Do_ran")) ;
    mapper->addMapping(ui->Do_Ran_2 ,  model->fieldIndex("Gioi_han_ben")) ;
    mapper->addMapping(ui->Gioi_han_ben_3,  model->fieldIndex("Gioi_han_chay")) ;
    mapper->addMapping(ui->Cong_thuc_tuong_ung ,  model->fieldIndex("Cong_Thuc_USTX")) ;
    connect(ui->tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            mapper, SLOT(setCurrentModelIndex(QModelIndex)));
}
void Data_table::str_specification(QString name,QString Label)
{
    Algro_Process*algro =  new  Algro_Process() ;
    algro->Set_str(name) ;
    this->map_ref[Label] = algro->check_Specification()  ;    

}
void Data_table::Hide_all()
{
    ui->kich_thuoc->hide() ;
    ui->Gioi_han_ben_2->hide() ;
    ui->Gioi_han_chay_2->hide() ;
    ui->Do_Ran->hide() ;
    ui->label_9->hide() ;
    ui->label_10->hide() ;
    ui->label_11->hide() ;
    ui->label_12->hide() ;
}
void Data_table::Constructor_Map()
{
    map_ref.insert({"S",false}) ;
    map_ref.insert({"DO_RAN",false}) ;
    map_ref.insert({"HB",false}) ;
    map_ref.insert({"HC",false}) ;
}

Data_table::~Data_table()
{
    delete ui;
}
Data_table_material_Gear::Data_table_material_Gear(QWidget *parent):
    QDialog(parent)
    //ui(new Ui::Data_table)
{}
void Data_table::on_tableView_clicked(const QModelIndex &index)
{
    QVector<QString> temp ;
    int row = ui->tableView->currentIndex().row();
    for (int i = 0; i < ui->tableView->model()->columnCount(); ++i){
        QString fileName = ui->tableView->model()->data( ui->tableView->model()->index(row, i) ).toString();
        temp.push_back(fileName) ;
    }
    this-> _Cong_Thuc =  temp[6] ;
    this->Nhan_hieu =  temp[0] ;
    this->Nhiet_luyen =  temp[1];
    future<void> Thread1 = async(launch::async , [this,temp](){
        this->str_specification(temp[2],"S") ;
    }) ;
    future<void> Thread2 = async(launch::async , [this,temp](){
        this->str_specification(temp[3],"DO_RAN") ;

    }) ;
    future<void> Thread3 = async(launch::async , [this,temp](){
        this->str_specification(temp[5],"HC") ;

    }) ;
    this->str_specification(temp[4],"HB") ;
    Thread1.get() ;
    Thread2.get() ;
    Thread3.get() ;
    if(map_ref["S"]== true){
        ui->kich_thuoc->show() ;
        ui->label_9->show() ;
        ui->label_10->show() ;
        ui->label_11->show() ;
        ui->label_12->show() ;

        connect( ui->kich_thuoc , &QLineEdit::editingFinished ,[=]() {
            this->S =   ui->kich_thuoc->text() ;
         }) ;
    }
    else {
         ui->kich_thuoc->hide() ;
         ui->label_9->hide() ;
         ui->label_10->hide() ;
         ui->label_11->hide() ;
         ui->label_12->hide() ;
         S = temp[2] ;
    }
    if(map_ref["DO_RAN"]== true){       
        ui->Do_Ran->show() ;
        ui->label_16->show() ;
        ui->label_15->show() ;
        ui->label_17->show() ;
        ui->label_18->show() ;
        this->check_show_Sodi =  true ;
        connect(ui->Do_Ran , &QLineEdit::editingFinished ,[=]() {
            this->Do_ran =  ui->Do_Ran->text() ;
         }) ;
    }
    else {

        this->Do_ran = "" ;
         ui->Do_Ran->hide() ;
         this->check_show_Sodi =  false ;
         QString _str ;
         ui->label_16->hide() ;
         ui->label_15->hide() ;
         ui->label_17->hide() ;
         ui->label_18->hide() ;
         for(auto x :temp[3]) {
           if(x.isDigit()) {
               this->Do_ran+=x ;
           }
         }
    }
    if(map_ref["HB"]== true){
        ui->Gioi_han_ben_2->show() ;
        connect(ui->Gioi_han_ben_2 , &QLineEdit::editingFinished ,[=]() {
            this->HB=   ui->Gioi_han_ben_2->text() ;
         }) ;
    }
    else {
         ui->Gioi_han_ben_2->hide() ;
         this->HB = temp[4] ;
    }
    if(map_ref["HC"]== true){
        ui->Gioi_han_chay_2->show() ;
        connect(ui->Gioi_han_chay_2 , &QLineEdit::editingFinished ,[=]() {
            this->HC=   ui->Gioi_han_chay_2->text() ;
         }) ;
    }
    else {
         ui->Gioi_han_chay_2->hide() ;
           this->HC = temp[5] ;
    }
    return ;
}
void Data_table::on_pushButton_clicked()
{
    if(Sodility_Sym == "HRC"){
        Thread_load_table.get() ;
            Search_HRC_HB->Set_HBeta(ui->Do_Ran->text().toDouble()) ;
            Search_HRC_HB->Search_Table() ;
            this->Do_ran =  QString::number(Search_HRC_HB->Get_result()) ;

    }  
    accept() ;
}
void Data_table::Signal_change(QString &T)
{
    if(T == "1" ) {
         ui->Cong_thuc_tuong_ung->setText("2.8σch") ;
    }
    else {
          ui->Cong_thuc_tuong_ung->setText("40HRCm") ;
    }
}
void Data_table::on_ADD_button_clicked()
{
    ADD_data_material*Add_action =  new ADD_data_material(this) ;
    int ret =  Add_action->exec() ;
    if(ret == QDialog::Accepted) {
        QVector<QString> res  =  Add_action->Get_result() ;
        if(database.open()){
        QSqlQuery _query(database) ;
            QString name_of_Present_table = "vat_lieu_banh_rang" ;
          _query.prepare("INSERT INTO "+  name_of_Present_table+"(Nhan_hieu, Nhiet_luyen ,Kich_thuoc_S ,Do_ran,Gioi_han_ben, Gioi_han_chay,Cong_Thuc_USTX)"
                       "VALUES (?, ?, ? , ?, ?, ?, ?)");
          for(auto x : res) {
             _query.addBindValue(x) ;
          }
          _query.exec() ;
          Set_QSQLtable("vat_lieu_banh_rang") ;
      }      
    }
    if(ret == QDialog::Rejected){
        return  ;
    }
}
void Data_table::on_EDIT_Button_clicked()
{       vector<QString>data {ui->Nhan_Hieu->text(),ui->Nhiet_luyen->text(), ui->Kich_Thuoc->text() ,ui->Gioi_han_chay_3->text(),ui->Do_Ran_2->text(),ui->Gioi_han_ben_3->text(),ui->Cong_thuc_tuong_ung->text()} ;
        Edit_material*Edit =  new Edit_material(this,data) ;
        int ret = Edit->exec() ;
        if(ret == QDialog::Accepted) {
            if(database.open()){
                vector<QString>res  = Edit->Get_data() ;
                QSqlQuery query(database) ;
                query.prepare("UPDATE vat_lieu_banh_rang SET Nhan_hieu = " +res[0]+", Nhiet_luyen = " + res[1] + ", Kich_thuoc_S = " +res[2]+" , Do_ran = "+res[3] +", Gioi_han_ben = " + res[4] + ", Gioi_han_chay = " + res[5] +" , Cong_Thuc_USTX = " +res[6]
                        + " WHERE Nhan_hieu = "+"'"+ui->Nhan_Hieu->text()+"'"
                         +" AND Nhiet_luyen = " +"'"+ui->Nhiet_luyen->text()+"'"
                         +" AND Kich_thuoc_S = "+"'"+ ui->Kich_Thuoc->text()+"'"
                         +" AND Do_ran = " + "'"+ui->Gioi_han_chay_3->text()+"'"
                         +" AND Gioi_han_ben = " + "'"+ui->Do_Ran_2->text()+"'"
                         +" AND Gioi_han_chay = " +"'"+ui->Gioi_han_ben_3->text()+"'"
                         +" AND Cong_Thuc_USTX = " +"'"+ui->Cong_thuc_tuong_ung->text()+"'" );
                query.exec() ;
                Set_QSQLtable("vat_lieu_banh_rang") ;
            }
     }
}

void Data_table::on_DELETE_button_clicked()
{
    if(database.open()) {
        QSqlQuery query(database) ;
        QString S = "'" +ui->Nhan_Hieu->text()+"'" ;
        query.prepare("DELETE FROM vat_lieu_banh_rang WHERE Nhan_hieu ='"+ui->Nhan_Hieu->text()+"'"
                      +"AND Nhiet_luyen = " +"'"+ui->Nhiet_luyen->text()+"'"
                      +" AND Kich_thuoc_S = "+"'"+ ui->Kich_Thuoc->text()+"'"
                      +" AND Do_ran = " + "'"+ui->Gioi_han_chay_3->text()+"'"
                      +" AND Gioi_han_ben = " + "'"+ui->Do_Ran_2->text()+"'"
                      +" AND Gioi_han_chay = " +"'"+ui->Gioi_han_ben_3->text()+"'"
                      +" AND Gioi_han_chay = " +"'"+ui->Gioi_han_ben_3->text()+"'"
                       +" AND Cong_Thuc_USTX = " +"'"+ui->Cong_thuc_tuong_ung->text()+"'" );
       query.exec() ;
       Set_QSQLtable("vat_lieu_banh_rang") ;
    }
}

void Data_table::on_lineEdit_textChanged(const QString &arg1)
{
    if(ui->lineEdit->text() == "") {
        model = new QSqlTableModel() ;
        model->setTable("vat_lieu_banh_rang") ;
        model->select() ;
        Set_Header() ;
        ui->tableView->setModel(model);
    }
    else {
        Search_Filter(ui->lineEdit->text()) ;
    }
}
void Data_table::on_comboBox_currentIndexChanged(int index)
{
    this->present_combox_choice = index ;
    if(ui->lineEdit->text()!= "") {
        Search_Filter(ui->lineEdit->text());
    }
}
void Data_table::Search_Filter(QString text)
{
    if(present_combox_choice == 0 ) {
        Title_Search tilte_search  (database ,  "vat_lieu_banh_rang") ;
        this->filter =  new Signal_(tilte_search,data_filter) ;
    }
    else if(present_combox_choice == 1) {
        Size Size_search  (database ,  "vat_lieu_banh_rang") ;
        this->filter =  new Signal_(Size_search,data_filter) ;
    }
    else if(present_combox_choice == 2) {
        Thremal_treatment Thremal_search  (database ,  "vat_lieu_banh_rang") ;
        this->filter =  new Signal_(Thremal_search,data_filter) ;
    }
    else if(present_combox_choice == 2) {
        Size Size_search  (database ,  "vat_lieu_banh_rang") ;
        this->filter =  new Signal_(Size_search,data_filter) ;
    }
    else if(present_combox_choice == 3) {
        Solidity Solidity_search  (database ,  "vat_lieu_banh_rang") ;
        this->filter =  new Signal_(Solidity_search,data_filter) ;
    }
    else if(present_combox_choice == 4) {
        limited_durability limited_durability_search  (database ,  "vat_lieu_banh_rang") ;
        this->filter =  new Signal_(limited_durability_search,data_filter) ;
    }
    else if(present_combox_choice == 5) {
        melting_limit melting_limit_durability_search  (database ,  "vat_lieu_banh_rang") ;
        this->filter =  new Signal_(melting_limit_durability_search,data_filter) ;
    }
    model->setFilter( this->filter->filter(text)) ;
    Mapping() ;
}

void  Data_table::check_data_is_valid(QLineEdit*arg1, QLabel *left, QLabel *right)
{
    if(left->text().toDouble()!= 0  ) {
       if(arg1->text().toDouble() < left->text().toDouble()) {
           arg1->setText(left->text()) ;
       }
       if(arg1->text().toDouble() > right->text().toDouble())  {
            arg1->setText(right->text()) ;
        }
    }
    else {
        if(left->text() == "<")   {
            if(arg1->text().toDouble()  > right->text().toDouble()) {
                arg1->setText(right->text()) ;
            }
        }
        else  {
            if(arg1->text().toDouble() < right->text().toDouble()) {
                arg1->setText(right->text()) ;
            }
        }
    }
}

void Data_table::on_Gioi_han_chay_3_textChanged(const QString &arg1)
{
    if(arg1[2] == "C" ) {
        this->Sodility_Sym = "HRC" ;
    }
    else {
        this->Sodility_Sym = "HB"  ;
    }
    Processing =  new Algro_Process(arg1) ;
    Processing->Split_String_number() ;
    if(Processing->Get_number_space().size() >= 2) {
        QString First ;
        QString Second  ;
        stack<QString> k  =  Processing->Get_number_space() ;
        First=  k.top() ;
        k.pop() ;
        Second =  k.top() ;
        if(First.toDouble() != 0  && Second.toDouble() != 0  ) {
                ui->label_16->setText("≤") ;
                ui->label_17->setText("≤") ;
                ui->label_15->setText(Second) ;
                ui->label_18->setText(First) ;
                ui->Do_Ran->show() ;
        }
        else if(First.toDouble() && (Second == ">" || Second == "<")) {
            ui->label_17->setText(Second) ;
            ui->label_18->setText(First) ;
            ui->label_16->setText("") ;
            ui->label_15->setText("")  ;
        }
    }
    return ;
}

void Data_table::on_Kich_Thuoc_textChanged(const QString &arg1)
{
    Processing =  new Algro_Process(arg1) ;
    Processing->Split_String_number() ;
    if(Processing->Get_number_space().size() >= 2) {
        ui->label_11->setText(Processing->Get_number_space().top()) ;
        Processing->Pop_stack_char() ;
        ui->label_9->setText(Processing->Get_number_space().top());
    }
}
void Data_table::on_Do_Ran_2_textChanged(const QString &arg1)
{
    Processing =  new Algro_Process(arg1) ;
    Processing->Split_String_number() ;
    if(Processing->Get_number_space().size() >= 2) {
        QString First ;
        QString Second  ;
        stack<QString> k  =  Processing->Get_number_space() ;
        First=  k.top() ;
        k.pop() ;
        Second =  k.top() ;
        if(First.toDouble() != 0  && Second.toDouble() != 0  ) {
                ui->label_20->setText("≤") ;
                ui->label_21->setText("≤") ;
                ui->label_19->setText(Second) ;
                ui->label_22->setText(First) ;
        }
        else if(First.toDouble() && (Second == ">" || Second == "<")) {
            ui->label_19->setText(Second) ;
            ui->label_22->setText(First) ;
            ui->label_20->setText("") ;
            ui->label_21->setText("")  ;
        }
    }
}

void Data_table::on_Gioi_han_ben_3_textChanged(const QString &arg1)
{
    Processing =  new Algro_Process(arg1) ;
    Processing->Split_String_number() ;
    if(Processing->Get_number_space().size() >= 2) {
        QString First ;
        QString Second  ;
        stack<QString> k  =  Processing->Get_number_space() ;
        First=  k.top() ;
        k.pop() ;
        Second =  k.top() ;
        if(First.toDouble() != 0  && Second.toDouble() != 0  ) {
                ui->label_24->setText("≤") ;
                ui->label_25->setText("≤") ;
                ui->label_23->setText(Second) ;
                ui->label_26->setText(First) ;
        }
        else if(First.toDouble() && (Second == ">" || Second == "<")) {
            ui->label_23->setText(Second) ;
            ui->label_26->setText(First) ;
            ui->label_24->setText("") ;
            ui->label_25->setText("")  ;
        }
    }
}

void Data_table::on_kich_thuoc_textChanged(const QString &arg1)
{
    if(ui->label_10->text() == "≤") {
        this->mtime->setSingleShot(true) ;
        this->mtime->start(1000);
        if(arg1 != "") {
            connect(mtime , &QTimer::timeout , [=](){
                check_data_is_valid(ui->kich_thuoc , ui->label_9 , ui->label_11 ) ;
            }) ;
        }
    }
}

void Data_table::on_Do_Ran_textChanged(const QString &arg1)
{
    if(ui->label_17->text() == "≤") {
        this->mtime->setSingleShot(true) ;
        this->mtime->start(1000);
        if(arg1 != "") {
            connect(mtime , &QTimer::timeout , [=](){
                check_data_is_valid(ui->Do_Ran , ui->label_15 , ui->label_18 ) ;
            }) ;
        }
    }
    else {
        this->mtime->setSingleShot(true) ;
        this->mtime->start(1000);
        if(arg1 != "") {
            connect(mtime , &QTimer::timeout , [=](){
                check_data_is_valid(ui->Do_Ran , ui->label_17 , ui->label_18 ) ;
            }) ;
        }
    }
}
void Data_table::on_Gioi_han_ben_2_textChanged(const QString &arg1)
{
    if(ui->label_21->text() == "≤") {
        this->mtime->setSingleShot(true) ;
        this->mtime->start(1000);
        if(arg1 != "") {
            connect(mtime , &QTimer::timeout , [=](){
                check_data_is_valid(ui->Gioi_han_ben_2 , ui->label_19 , ui->label_22 ) ;
            }) ;
        }
    }
    else {
        this->mtime->setSingleShot(true) ;
        this->mtime->start(1000);
        if(arg1 != "") {
            connect(mtime , &QTimer::timeout , [=](){
                check_data_is_valid(ui->Gioi_han_ben_2 , ui->label_20 , ui->label_22) ;
            }) ;
        }
    }
}
void Data_table::on_Gioi_han_chay_2_textChanged(const QString &arg1)
{
    if(ui->label_25->text() == "≤") {
        this->mtime->setSingleShot(true) ;
        this->mtime->start(1000);
        if(arg1 != "") {
            connect(mtime , &QTimer::timeout , [=](){
                check_data_is_valid(ui->Gioi_han_chay_2 , ui->label_23 , ui->label_26 ) ;
            }) ;
        }
    }
    else {
        this->mtime->setSingleShot(true) ;
        this->mtime->start(1000);
        if(arg1 != "") {
            connect(mtime , &QTimer::timeout , [=](){
                check_data_is_valid(ui->Gioi_han_chay_2 , ui->label_24 , ui->label_26) ;
            }) ;
        }
    }
}
