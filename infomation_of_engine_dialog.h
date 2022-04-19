#ifndef INFOMATION_OF_ENGINE_DIALOG_H
#define INFOMATION_OF_ENGINE_DIALOG_H
#include <QDialog>
#include<iostream>
#include<queue>
#include<map>
using namespace std ;
namespace Ui {
class Infomation_of_engine_Dialog;
}
class Infomation_of_engine_Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Infomation_of_engine_Dialog(QWidget * parent = nullptr);
    Infomation_of_engine_Dialog(QWidget*parent  ,  map<QString,QString> temp);
    ~Infomation_of_engine_Dialog();
    QString get_Frorce() ;
    QString get_ver() ;
    QString get_zdan() ;
    QString get_ztai() ;
    QString get_Time_Service() ;   
    map<QString , QString> get_info_map() ;
   QString get_rotate() ;
   QString get_load_mode() ;
   QString  get_year_works()  ;
   QString get_sessing() ;
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void Set_force(QString force) ;
    void Set_Ver(QString V) ;
    void Set_Zdab(QString Zd) ;
    void Set_Z_tai(QString ztai) ;
    void Set_Ser_list(QString year) ;
    void Set_numer_of_rotate(QString number) ;
    void Set_year_works(QString years) ;
    void Set_load_mode(QString years) ;
   void Set_Sessiob(QString session);
    void get_data_from_line_edit() ;
    void Set_page() ;
    void inser_info_map();
    void Set_line_edit() ;
    void check_change() ;
    void Set_info_map(map<QString , QString> map_temp)  ;
private:
    Ui::Infomation_of_engine_Dialog *ui;
    long int Force ;
    double ver ;
    int zdan ;
    int ztai ;
    int Time_service;
    int number_of_rotate ;
    QString load_mode ;
    int year_work ;
    int session ;
    queue<QString> error_list ;
    map<QString , QString> map_info ;
};

#endif // INFOMATION_OF_ENGINE_DIALOG_H
