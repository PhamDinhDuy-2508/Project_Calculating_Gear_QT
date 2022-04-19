#ifndef ALGRO_PROCESS_H
#define ALGRO_PROCESS_H
#include<QWidget>
#include<QString>
#include<map>
#include<utility>
#include<queue>
#include<stdio.h>
#include<ctype.h>
#include<QChar>
#include<QVector>
#include<QVariant>
#include<fstream>
#include<QDebug>
#include<stack>
#include<QThread>
#include<QFuture>
#include<do_an.h>
#include<QFutureWatcher>
#include <QtConcurrent>
#include<thread>
#include<QTimer>
using namespace std ;
class Algro_Process
{
private:
    QString  _str ;
    QString result ;
    bool  check ;
    queue<QString> Process ;
    stack<QString> stack_char ;
    map<QString, bool> check_Specified ;
    QString Titile ;
    QVector<QString> Number ;
    void Data_change();
    QVariant data(const QModelIndex& index, int role) const ;    
public:
    Algro_Process();
    Algro_Process(QString name) ;
    void Split_String_number() ;
    void Set_str(QString name) ;
    void _Str_material_Process() ;
    bool check_Specification() ;
    bool compair_2_limit(QString a , QString b,QString &between) ;
    QVector<pair<QString,QString>> Number_result;
    map<QString , vector<vector<double>>> Table_map ;
    stack<QString> Get_number_space() ;
    void Pop_stack_char() ;

};
class Search_Table_KHB_KFB{
private :
   double result ;
   int Choice = 0 ;
   double HBeta ;
   vector<vector<double>> array_FB ;
   vector<vector<double>> KHB_table ;
   vector<vector<double>> Kx_Ky_table ;

public :
       double check_Thread_Join =  false ;
       Search_Table_KHB_KFB() {} ;
       Search_Table_KHB_KFB(int choice , double value):Choice(choice) ,HBeta(value) {};
       vector<vector<double>> Get_Table_From_File(const char* str) ;
       void Set_arr_FB(vector<vector<double>> temp) {
          this->array_FB =  temp ;
       }
       void Set_KHB_Table( vector<vector<double>> a){
            this->KHB_table =  a ;
       }
       vector<vector<double>> Get_array_FB(){
           return this->array_FB ;
       }
       void Set_Kx_Ky_table(vector<vector<double>> temp) {
            this->Kx_Ky_table =  temp ;
       }
       double Get_HBeta(){
           return this->HBeta ;
       }
       void Set_Choice(int choice){
           this->Choice =  choice ;
       }
       void Set_HBeta(double i) {
           this->HBeta = i ;
       }
       vector<vector<double>> Get_Kx_Ky_table(){
           return this->Kx_Ky_table;
       }
       double Get_result() ;
       int Get_choice() ;
        void Search_Table() ;
        void Search_TABLE(double Value_at_row , int value_at_column) ;
};
class Text_input_editor{
private :
    QString result ;
public:
    Text_input_editor() =  default  ;
    void Refresh_Text () {
       result.clear() ;
    }
    void Text_Push(QString data);
    QString get_result() {
        return this->result ;
    }
};
class Test_Gear:QObject{
private:
    vector<double> M ;
    //double sigma_H  ;
    //double sigma_F ;
    do_an*Do_an ;
    Search_Table_KHB_KFB * Process ;
    Search_Table_KHB_KFB * Process2 ;
    shared_future<void> Thread ;
    double result ;
    bool check ;
    QFutureWatcher<void> futureWatcher ;
    double model  ;
    int combo_box_choice = 0 ;
public :
    Test_Gear()  = default ;
    Test_Gear(vector<double>T) ;
    Test_Gear(do_an*_do_an , double Model )  ;
    void Set_Combobot_choice(double i) ;
    void check_test_1()  ;
    void Get_Thread_test_1();
    bool Get_res() {
        return this->check ;
    }
};
class Flexural_strength_test{
private:
    do_an*Do_an ;
    shared_future<void> Thread ;
    double model ;
    double model2 ;
    bool check ;
    int x1_column ;
    int x2_column ;
    map<double , double> choice ;
public :
    Search_Table_KHB_KFB*Search_KFb = new Search_Table_KHB_KFB ;
    Search_Table_KHB_KFB*Search_YF1_YF2  =  new Search_Table_KHB_KFB;
    Flexural_strength_test()  ;
    Flexural_strength_test(do_an*_Do_an, double model ,double model_2, double column1 , double colum2)  ;
    void Set_x1(double x1) ;
    void Set_x2(double x2) ;
    void check_test() ;
    bool get_check() {
        return this->check ;
    }
};
class Overloading_test{
private:
    do_an*Do_an ;
   double model_H ;
    vector<double> model_F;
    map<QString , bool> result;
    double T_max ;
    double T ;
    double Kqt ;
    vector<thread> Thread ;
public :
    Overloading_test() {

    }
    Overloading_test(do_an*Do_an) ;
    void Cal_Kt() ;
    map<QString, bool> get_check() ;
};

#endif // ALGRO_PROCESS_H
