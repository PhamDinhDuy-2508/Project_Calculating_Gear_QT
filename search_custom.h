#ifndef SEARCH_CUSTOM_H
#define SEARCH_CUSTOM_H
#include<iostream>
#include<QString>
#include<QDebug>
#include<QSqlTableModel>
#include<QSqlDatabase>
#include<QtSql>
#include<QSqlRecord>
#include<QSqlQuery>
#include<map>
using namespace  std ;
enum class Choice {
    Nhan_hieu,
    Nhiet_Luyen,
    Kich_thuoc,
    Do_ran ,
    Gioi_han_ben,
    Gioi_han_cha

};
struct _choice{
    int choice ;
    QString name_of_table ;
};
class Set_Present_table{
private:
    QString name_of_tables ;
public :
    Set_Present_table() =  default  ;
    Set_Present_table(QString name) : name_of_tables(name){}
    QString get_name_of_table(){
        return this->name_of_tables ;
    }
 };

class Search_Custom
{
private :
    int index ;
    QString combo_box_choice ;
    QString search_text ;
    QSqlDatabase Database;
    QString table_name ;
public:
    Search_Custom();
    Search_Custom(QSqlDatabase database,QString Table_name):Database(database) , table_name((Table_name))  {
        this->Database =  database ;
    }
    QString get_Table_name;
};
struct Database{
//    QSqlTableModel*model ;
    int column_choice ;
    QString text ;

} ;

template <typename T> class Specification{
private :
    typedef  T* database_model ;
    QString choice ;
public :
   Specification() =  default ;
   virtual QString  Set_AND_Get_column_choice(T*item)  const = 0 ;   
  ~Specification() = default;
} ;
class Filter{
private :
    typedef Database* Model ; 
    Model model_result ;

    QString Table_present ;
public :
    Filter()  = default ;
    QString  Search_Filter(Specification<Database>  &specification ,Model model  , QString text ) {
        QString column = specification.Set_AND_Get_column_choice(model);
        QString filter = column +" LIKE '%" +text+"%'" ;

        return filter ;
    }
};
class Title_Search: public Specification<Database> {
private :
    QString text ;
    QString table_name ;
    QSqlDatabase database ;
public :
    Title_Search(QSqlDatabase Dtbase ,  QString table ):database(Dtbase) ,table_name(table){}
        QString Set_AND_Get_column_choice(Database*item) const override {
            item->column_choice =  0 ;
            return "Nhan_hieu" ;
        }              
} ;
class Thremal_treatment: public Specification<Database> {
private :
    QString text ;
    QString table_name ;
    QSqlDatabase database ;
public :
    Thremal_treatment(QSqlDatabase Dtbase ,  QString table ):database(Dtbase) ,table_name(table){}
        QString Set_AND_Get_column_choice(Database*item) const override {
            item->column_choice =  0 ;
            return "Nhiet_luyen" ;
        }
} ;
class Size: public Specification<Database> {
private :
    QString text ;
    QString table_name ;
    QSqlDatabase database ;
public :
    Size(QSqlDatabase Dtbase ,  QString table ):database(Dtbase) ,table_name(table){}
        QString Set_AND_Get_column_choice(Database*item) const override {
            item->column_choice =  0 ;
            return "Kich_thuoc_S" ;
        }
} ;
class Solidity : public Specification<Database> {
private :
    QString text ;
    QString table_name ;
    QSqlDatabase database ;
public :
    Solidity (QSqlDatabase Dtbase ,  QString table ):database(Dtbase) ,table_name(table){}
        QString Set_AND_Get_column_choice(Database*item) const override {
            item->column_choice =  0 ;
            return "Do_ran" ;
        }
} ;
class limited_durability : public Specification<Database> {
private :
    QString text ;
    QString table_name ;
    QSqlDatabase database ;
public :
    limited_durability (QSqlDatabase Dtbase ,  QString table ):database(Dtbase) ,table_name(table){}
        QString Set_AND_Get_column_choice(Database*item) const override {
            item->column_choice =  0 ;
            return "Gioi_han_ben" ;
        }
} ;
class melting_limit  : public Specification<Database> {
private :
    QString text ;
    QString table_name ;
    QSqlDatabase database ;
public :
    melting_limit (QSqlDatabase Dtbase ,  QString table ):database(Dtbase) ,table_name(table){}
        QString Set_AND_Get_column_choice(Database*item) const override {
            item->column_choice =  0 ;
            return "Gioi_han_chay" ;
        }
} ;
class gear_info  : public Specification<Database> {
private :
    QString text ;
    QString table_name ;
    int column  ;
    QSqlDatabase database ;
   map<int,QString> _Map ;
public :
    gear_info (int i,  map <int,QString> table ):column(i) ,_Map(table){}
        QString Set_AND_Get_column_choice(Database*item) const override {
            item->column_choice =  column ;
            return  "" ;
        }
        QString _get_present_choice() {
             return  _Map[column] ;
        }
} ;
class Empty: public Specification<Database> {
private :
    QString text ;
    QString table_name ;
    QSqlDatabase database ;
public :
    Empty(QSqlDatabase Dtbase ,  QString table ):database(Dtbase) ,table_name(table){}
        QString Set_AND_Get_column_choice(Database*item) const override {
            item->column_choice =  0 ;
            return "" ;
        }
} ;
class Signal_{
private:
    Specification<Database> &sfilter ;
    Database database ;
    QSqlTableModel *Mode ;
    QSqlTableModel *result ;
public:
     Signal_(Specification<Database> &filter , Database  Model ) :
         sfilter(filter),database(Model)  {}
     void Set_Filter(Specification<Database> &filter ) {
         this->sfilter =  filter ;
         qDebug() << this->sfilter.Set_AND_Get_column_choice(&database) ;
     }
     QString filter(QString text) {
         Filter filter ;

        return (filter.Search_Filter(sfilter , &database , text)) ;

     }
};
class Gear_Info   {
private :
    QString text ;
    QString table_name ;
    int column  ;
   map<int,QString> _Map ;
public :
    Gear_Info (int i,  map <int,QString> table ):column(i) ,_Map(table){}
        QString _get_present_choice() {
             return  _Map[column] ;
        }
        QString Searrch(QString text) {
            return  _Map[column]  +" LIKE '%" +text+"%'" ;
        }
} ;


#endif // SEARCH_CUSTOM_H
