#ifndef PROCESSING_STRING_H
#define PROCESSING_STRING_H
#include<iostream>
#include"QString"
#include"QStack"
#include"QThread"
#include<future>
#include<vector>
using namespace  std ;
class Processing_String
{
private:
    QString operate ;
    QString load_mode ;
public:
    Processing_String();
    Processing_String(QString) ;
    void Operate() ;
    void Load_mode() ;
    ~Processing_String() = default ;
};


#endif // PROCESSING_STRING_H
