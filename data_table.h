#ifndef DATA_TABLE_H
#define DATA_TABLE_H
#include <QDialog>
#include<QtSql>
#include<QSqlTableModel>
#include<QMap>
#include"algro_process.h"
#include"QDataWidgetMapper"
#include<utility>
#include<map>
#include <vector>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<algro_process.h>
#include<search_custom.h>
#include<map>
#include<algro_process.h>
#include<QLabel>
using namespace std ;
namespace Ui {
class Data_table;
}

class Data_table : public QDialog
{
    Q_OBJECT

public:    
    explicit Data_table(QWidget *parent = nullptr);
    void Set_QSQLtable(QString name);
    void Set_Header() ;
    void Mapping()  ;
    void str_specification(QString name,QString Label);
    Ui::Data_table *ui;
    void Hide_all() ;
    void Constructor_Map() ;
    QString Get_S()  {
        return this->S ;
    }
    QString Get_Do_ran() {
        return this->Do_ran ;
    }
    QString Get_HB() {
        return this->HB ;
    }
    QString Get_Hc() {
        return this->HC ;
    }
    QString Get_Nhan_hieu() {
        return this->Nhan_hieu ;
    }
    QString Get_Nhiet_luyen(){
        return this->Nhiet_luyen ;
    }
    int  Get_Cong_Thuc (){
        if(this->_Cong_Thuc[0] == '2' ) {
            return 1 ;
        }
        else {
            return 2 ;
        }
    }
    void Search_Filter(QString text) ;
    void  check_data_is_valid(QLineEdit* arg1  , QLabel*left , QLabel*right) ;

    ~Data_table();
signals:
    void Data_Changed(QString &) ;
private slots:
    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_clicked();
    void Signal_change(QString &) ;
    //them 1 ham xet gia tri trong khoang//
    void on_ADD_button_clicked();

    void on_EDIT_Button_clicked();

    void on_DELETE_button_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_Gioi_han_chay_3_textChanged(const QString &arg1);

    void on_Kich_Thuoc_textChanged(const QString &arg1);

    void on_Do_Ran_2_textChanged(const QString &arg1);

    void on_Gioi_han_ben_3_textChanged(const QString &arg1);

    void on_kich_thuoc_textChanged(const QString &arg1);

    void on_Do_Ran_textChanged(const QString &arg1);

    void on_Gioi_han_ben_2_textChanged(const QString &arg1);

    void on_Gioi_han_chay_2_textChanged(const QString &arg1);

private:
    int name_of_data_base ;
    QSqlTableModel*model ;
    QSqlDatabase database ;
    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    map<QString , bool> map_ref ;
    QVariant data(const QModelIndex &index, int role) const;
    vector<vector<QString>> check_Spcification;
    QString S ;
    QString Do_ran ;
    QString HB ;
    QString HC ;
    QString Nhan_hieu ;
    QString Nhiet_luyen ;
    QString _Cong_Thuc ;
    Algro_Process*Processing ;
    QSqlQuery query(QSqlDatabase) ;
    Database data_filter ;
    Signal_ *filter ;
    int  present_combox_choice = 0 ;
    map<int ,Signal_*> specification ;
    Search_Table_KHB_KFB*Search_HRC_HB  = new Search_Table_KHB_KFB();
    shared_future<void> Thread_load_table ;
    QString Sodility_Sym ;
    bool check_show_Sodi  = false ;
    QTimer*mtime =  new QTimer() ;
};
class Data_table_material_Gear:public Data_table,public QDialog{
    Q_OBJECT
private :
   QString name_data_base ;
   QSqlDatabase database ;
   QSqlTableModel*model ;
public:
    Data_table_material_Gear(QWidget *parent = nullptr) ;
};

#endif // DATA_TABLE_H
