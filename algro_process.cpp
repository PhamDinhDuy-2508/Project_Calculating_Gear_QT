#include "algro_process.h"
#include<QDebug>
#include<sstream>
#include<fstream>
#include<iostream>
#include"QFile"
#include<do_an.h>
#include<map>
#include<thread>
using namespace std ;
 stack<QString> Algro_Process::Get_number_space()
{
     return this->stack_char ;
 }

 void Algro_Process::Pop_stack_char()
 {
     this->stack_char.pop() ;
 }

Algro_Process::Algro_Process()
{
    check_Specified .insert(pair<QString,bool>('(',true)) ;
    check_Specified .insert(pair<QString,bool>(')',true)) ;
    check_Specified .insert(pair<QString,bool>('>',true)) ;
}
Algro_Process::Algro_Process(QString name) : _str(name)
{
    return ;
}

void Algro_Process::Split_String_number()
{
    QString number = "" ;
    /*
   if(!Process.empty())   {
        while(!Process.empty()) {
           QChar _char = Process.front()[0] ;
           if(_char.isDigit()) {
               number+=Process.front() ;
           }
           if(_char ==','){
               Number.push_back(number) ;
               number = "" ;
           }
           Process.pop() ;
       }
   }
   */
    for(auto x : this->_str) {
       if(x .isDigit()) {
           number+= x ;
       }
       if(x == "," ){
           stack_char.push(number) ;
           number = "" ;
       }
       if( x == ">" || x  == "<") {
           stack_char.push(x) ;
       }
    }
    stack_char.push(number) ;
}
void Algro_Process::Set_str(QString name)
{
    this->_str =  name ;
    Number.clear() ;
    if(!Process.empty()){
       while(!Process.empty()) {
           Process.pop() ;
       }
    }
    for(auto x : _str){
        Process.push(x) ;
    }
}

void Algro_Process::_Str_material_Process()
{
    // processsing string material
}
bool Algro_Process::check_Specification()
{
    for(auto x : _str){
        if(x == "(" || x ==">"||x == "<") {
            return true ;
            break ;
        }
  }
    return false ;
}

bool Algro_Process::compair_2_limit(QString a, QString b, QString &between)
{
    return false  ;
}

vector<vector<double>>  Search_Table_KHB_KFB::Get_Table_From_File(const char* str)
{
        fstream input(str);
        string message;
        vector<vector<double>>  Read ;
        if (input.fail()) {
            return Read;
        }
        while (getline(input, message)) {
            stringstream lineStream(message);
            double value;
            vector<double> data;
            while (lineStream >> value) {
                data.push_back(value);
            }
            Read.push_back(data);
        }
        return Read;
}

double Search_Table_KHB_KFB::Get_result()
{
    return this->result ;
}

int Search_Table_KHB_KFB::Get_choice()
{
    return this->Choice ;
}

void Search_Table_KHB_KFB::Search_Table()
{

    if(HBeta == 0) {
        this->result = 0 ;
        return ;
    }
    if(array_FB.size()!= 0 ){
        if(array_FB[0].size()== 2) {
            this->Choice =  1 ;
        }
    int i =0 ;
    pair<int , int> row_column ;
    for(int i = 0; i< array_FB.size()-1 ; i++){
        if(array_FB[i][0] == HBeta) {
          result = (array_FB[i][Choice]) ;
          return ;
          break ;
         }
        if(array_FB[i][0] > HBeta){
            row_column.first =  i ;
            row_column.second = i-1 ;
            break ;
        }
    }
    if(row_column.first >= 0 && row_column.second >= 0) {
          double temp =  (HBeta - array_FB[row_column.second][0])/(array_FB[row_column.first][0]-array_FB[row_column.second][0]);
          qDebug() << temp ;
         result =  (temp*array_FB[row_column.first][Choice]+array_FB[row_column.second][Choice])/(temp+1) ;
        }
    }
    return ;
}

void Search_Table_KHB_KFB::Search_TABLE(double Value_at_row, int value_at_column)
{
     this->HBeta = Value_at_row ;
     this->Choice =  value_at_column ;
      Search_Table() ;
}

void Text_input_editor::Text_Push(QString data)
{
    if(data == "\b") {
        result.remove(data.size()-2 , 1 ) ;
    }
    else  {
        result += data ;
    }
}

Test_Gear::Test_Gear(do_an *_do_an, double mod):Do_an(_do_an) ,model(mod)
{
    this->Process =  new Search_Table_KHB_KFB() ;
    this->Process2 =  new Search_Table_KHB_KFB() ;
    Thread =  async(launch::async , [=](){
        this->Process->Set_arr_FB(this->Process->Get_Table_From_File("E:/QT5/Project_calculating_Gear/KFa.txt")); ;
    }) ;
    if(Do_an->get_Beta_angle() != 0) {
        this->Process2->Set_arr_FB(this->Process2->Get_Table_From_File("E:/QT5/Project_calculating_Gear/KHa.txt")) ;

    }
    else {
        Do_an->Set_KHa(1) ;
    }
}

void Test_Gear::Set_Combobot_choice(double i)
{
    this->combo_box_choice =  i ;
}

void Test_Gear::check_test_1()
{
    Do_an->ZH() ;
    Do_an->Cal_Ze() ;
    Do_an->Get_cap_chinh_xac() ;
    Thread.get() ;
    double v ;
//    Do_an->cal_V_vong() ;

    if(Do_an->get_V_vong() <= 2.5) {
        v =  2.5 ;
    }
    else {
        v = Do_an->get_V_vong() ;
    }
    if(Do_an->get_Beta_angle() != 0) {
        Thread =  async(launch::async, [=](){
            Process2->Set_Choice(Do_an->get_choice()) ;
            Process2->Set_HBeta(v) ;
            Process2->Search_Table() ;
            Do_an->Set_KHa(Process2->Get_result());
        }) ;
    }
    Process->Set_Choice(Do_an->get_choice()) ;
    Process->Set_HBeta(v) ;
    Process->Search_Table() ;
    Thread.get() ;
    Do_an->Gte_K_Ha_K_Hb(Do_an->Get_KHa() ,  Process->Get_result()) ;
    Do_an->Cal_V_H(combo_box_choice) ;
    Do_an->Cal_KHV() ;
    Do_an->Cal_KH() ;
    this->result =  Do_an->cal_Zigma_H() ;
    if(this->result <= model ) {
        this->check = true ;
    }
    else {
        this->check =  false ;
    }
}
void Test_Gear::Get_Thread_test_1()
{
    return;
}

Flexural_strength_test::Flexural_strength_test()
{
    choice ={{0.5,1} , {0.3,2}, {0,3} , {-0.3 , 4} , {-0.5 , 5}} ;
}

Flexural_strength_test::Flexural_strength_test(do_an *_Do_an, double model ,double model_2, double column1 , double column2)
    :Do_an(_Do_an),model(model),model2(model_2)
{
    choice ={{0.5,1} , {0.3,2}, {0,3} , {-0.3 , 4} , {-0.5 , 5}} ;
    Set_x1(column1) ;
    Set_x2(column2) ;
}
void Flexural_strength_test::Set_x1(double x1)
{
    this->x1_column = choice[x1] ;
}
void Flexural_strength_test::Set_x2(double x2)
{
    this->x2_column =  choice[x2];
}
void Flexural_strength_test::check_test()
{
   double i ;
   double j ;
   Do_an->Cal_Ye() ;
   Do_an->Cal_YB() ;
   future<void> _YF1 = async(launch::async , [&i,this](){
       Search_YF1_YF2->Search_TABLE(Do_an->get_Z1()/cos(Do_an->get_Beta_angle()) , this->x1_column);
       i = Search_YF1_YF2->Get_result()  ;
   }) ;
   Search_YF1_YF2->Search_TABLE(Do_an->get_Z2()/cos(Do_an->get_Beta_angle()) , this->x2_column);
   j = Search_YF1_YF2->Get_result()  ;
   _YF1.get() ;
   Do_an->Set_YF1_YF2(i,j) ;
   Do_an->Cal_KFV() ;
   Do_an->Cal_Tau_F1() ;
   Do_an->Cal_Tau_F2() ;

   if(Do_an->get_Tau_1() <= model && Do_an->get_Tau_2() <= model2) {
       this->check =  true ;
   }
   else {
       this->check=  false ;
   }
}

Overloading_test::Overloading_test(do_an *Do_an)
{
   map<QString , bool> temp{{"Kiểm tra quá tải F1" , true} , {"Kiểm tra quá tải F2" , true} , {"Kiểm tra quá tải H" , true}} ;
   this->result =  temp ;
    this->Kqt =  Do_an->get_Kqt() ;
}

void Overloading_test::Cal_Kt()
{
            if(this->Do_an->get_Tau_1()*sqrt(this->Kqt) <= Do_an->Get_Sigma_max_F1() ) {
                result["Kiểm tra quá tải F1"] =  true ;
            }
            else {
                result["Kiểm tra quá tải F1"] =  false ;
            }
            if(this->Do_an->get_Tau_2()*sqrt(this->Kqt) <= Do_an->Get_Sigma_max_F2() ) {
                result["Kiểm tra quá tải F2"] =  true ;
            }
            else {
                result["Kiểm tra quá tải F2"] =  false ;
            }
}
map<QString, bool> Overloading_test::get_check(){
    for(auto x : result) {
        qDebug() << x.first << x.second ;
    }
    return this->result ;
}
