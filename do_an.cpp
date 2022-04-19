

#include "do_an.h"
#include<iostream>
#include<numeric>
#include<algorithm>
using namespace  std ;


do_an::do_an()
{

}

void do_an::Set_HB(double HB1, double HB2)
{
    pair<double , double> temp ;
    temp.first =  HB1;
    temp.second =  HB2 ;
    this->HB =  temp ;
}

void do_an::Set_Cond(int Cond)
{
    this->cond =  Cond ;
}

void do_an::sigma_Hlim_Flim_1()
{
   int cond1 =  this->cond ;
   HB1 =  HB.first ;

    if (cond1 == 0)
      {
          sigma_Hlim1 = 2 * HB1 + 70;
          sigma_Flim1 = 1.8 * HB1;
          S_H = 1.1;
          S_F = 1.75;
      }
      else if (cond1 == 1)
      {
          sigma_Hlim1 = 18 * HB1 + 150;
          sigma_Flim1 = 550;
          S_H = 1.1;
          S_F = 1.75;
      }
      else if (cond1 == 2)
      {
          sigma_Hlim1 = 17 * HB1 + 200;
          sigma_Flim1 = 900;
          S_H = 1.2;
          S_F = 1.75;
      }
      else if (cond1 == 3)
      {
          sigma_Hlim1 = 17 * HB1 + 200;
          sigma_Flim1 = 550;
          S_H = 1.2;
          S_F = 1.75;
      }
      else if (cond1 == 4)
      {
          sigma_Hlim1 = 1050;
          sigma_Hlim1 = 1050;
          sigma_Flim1 = 12 * HB1 + 30;
          S_H = 1.2;
          S_F = 1.75;
      }
      else if (cond1 == 5)
      {
          sigma_Hlim1 = 23 * HB1;
          sigma_Flim1 = 750;
          S_H = 1.2;
          S_F = 1.55;
      }
      else if (cond1 == 6)
      {
          sigma_Hlim1 = 23 * HB1;
          sigma_Flim1 = 1000;
          S_H = 1.2;
          S_F = 1.55;
      }
      else if (cond1 == 7)
      {
          sigma_Hlim1 = 23 * HB1;
          sigma_Flim1 = 750;
          S_H = 1.2;
          S_F = 1.55;
    }
}

void do_an::sigma_Hlim_Flim_2()
{

    int cond1 =  this->cond ;
     HB2 =  HB.second ;

     if (cond1 == 0)
       {
           sigma_Hlim2 = 2 * HB2 + 70;
           sigma_Flim2 = 1.8 * HB2;
           S_H = 1.1;
           S_F = 1.75;
       }
       else if (cond1 == 1)
       {
           sigma_Hlim2 = 18 * HB2 + 150;
           sigma_Flim2 = 550;
           S_H = 1.1;
           S_F = 1.75;
       }
       else if (cond1 == 2)
       {
           sigma_Hlim2 = 17 * HB2 + 200;
           sigma_Flim2 = 900;
           S_H = 1.2;
           S_F = 1.75;
       }
       else if (cond1 == 3)
       {
           sigma_Hlim2 = 17 * HB2 + 200;
           sigma_Flim2 = 550;
           S_H = 1.2;
           S_F = 1.75;
       }
       else if (cond1 == 4)
       {
           sigma_Hlim2 = 1050;
           sigma_Flim1 = 12 * HB2 + 30;
           S_H = 1.2;
           S_F = 1.75;
       }
       else if (cond1 == 5)
       {
           sigma_Hlim2 = 23 * HB2;
           sigma_Flim2 = 750;
           S_H = 1.2;
           S_F = 1.55;
       }
       else if (cond1 == 6)
       {
           sigma_Hlim2= 23 * HB2;
           sigma_Flim2 = 1000;
           S_H = 1.2;
           S_F = 1.55;
       }
       else if (cond1 == 7)
       {
           sigma_Hlim2 = 23 * HB2;
           sigma_Flim2 = 750;
           S_H = 1.2;
           S_F = 1.55;
     }
}
vector<double> do_an::get_sigma_H_F_lim1()
{
    vector<double> res  {this->sigma_Hlim1 , this->sigma_Flim1 ,this->N_HO1() , this->N_FO1(),this->NHE1(),
                this->NFE1() , this->KHL1() ,  this->KFL1() ,sigma_lim() ,sigma_Hlim(),Sigma_max_1,Sigma_max_F_1} ;
    return res ;
}

vector<double> do_an::get_sigma_H_F_lim2()
{
    vector<double> res  {this->sigma_Hlim2, this->sigma_Flim2 , this->N_HO2() , this->N_FO2(),this->NHE2(),
                this->NFE2() , this->KHL2() ,  this->KFL2() ,sigma_lim_2() ,sigma_Hlim_2(),Sigma_max_2 , Sigma_max_F_2} ;
    return res ;
}

double do_an::N_HO1()
{
    return (30 * pow(HB1, 2.4));
}

double do_an::N_HO2()
{
    return (30 * pow(HB1, 2.4));
}

double do_an::N_FO1()
{
    return (4* pow(10, 6));
}

double do_an::N_FO2()
{
    return (4* pow(10, 6));
}

void do_an::Set_N1(double _N1)
{
 this->N1 = _N1 ;
}
void do_an::Set_N2(double _N1)
{
    this->N2 = _N1 ;
}

void do_an::Set_N3(double _N3)
{
    this->N3 =  _N3 ;
}

void do_an::Set_T(vector<double> T)
{
    this->T_i =  T ;
}
void do_an::Set_t(vector<double> T)
{

    this->t_i =  T ;
}
void do_an::Set_time(long int Time)
{
    this ->time =  Time ;
    return ;
}

double do_an::psi_bd()
{
    return (0.53 * psi_ba * (U2+1));
}

double do_an::NHE1()
{
    double zigma = 0 ;
    long double result = 0 ;
    for(auto x : T_i) {
       zigma+=x ;
    }
    for(int i= 0 ; i < T_i.size() ; i++ ) {
       result += pow(t_i[i],3) *(T_i[i]/zigma) ;
    }
    NHE_1 =  60*result*time*N2 ;
    return  60*result*time*N2 ;
}


double do_an::KHL1()
{
    return pow((N_HO1()/NHE_1) ,1/6) ;
}

double do_an::KFL1()
{
    return pow((N_FO1()/NFE_1) ,1/6) ;
}

double do_an::sigma_lim()
{
    return (sigma_Hlim1*this->KHL1())/S_H ;
}

double do_an::sigma_Hlim()
{   this->sigma_H_1 = sigma_Flim1*0.7*KFL1()/S_H ;
    return this->sigma_H_1 ;
}

void do_an::cal_aw()
{
    Sigma_H() ;    
    this-> aw =  (this->Ka*(this->U2 +1)) * pow(((this->T3*this->KHB)/(pow(this->sigma_H,2)*U2*this->psi_ba)),(1.0/3.0)) ;
  //this->Ka*(this->U2 +1)*
    //pow
}
void do_an::Set_sigma_H1(double i)
{
    this->sigma_H_1 =  i ;
}
void do_an::Set_sigma_H2(double i)
{
    this->sigma_H_2 =  i ;
}
double do_an::NFE1()
{
    double m = m_F(this->HB1) ;
    double zigma=0 ;
    long double result = 0 ;
    for(auto x : T_i) {
       zigma+=x ;
    }
    for(int i= 0 ; i < T_i.size() ; i++ ) {
       result += pow(t_i[i],m) *(T_i[i]/zigma) ;
    }
    NFE_1 =  60*result*time*N2 ;
    return  60*result*time*N2 ;
}
double do_an::NHE2()
{
    double zigma = 0 ;
    long double result = 0 ;
    for(auto x : T_i) {
       zigma+=x ;
    }
    for(int i= 0 ; i < T_i.size() ; i++ ) {
       result += pow(t_i[i],3) *(T_i[i]/zigma) ;
    }
    NHE_2 =  60*result*time*N3 ;
    return  60*result*time*N3 ;
}


double do_an::KHL2()
{
    return pow((N_HO2()/NHE_2) ,1/6) ;
}

double do_an::KFL2()
{
    return pow((N_FO2()/NFE_2) ,1/6) ;
}

double do_an::sigma_lim_2()
{
    return (sigma_Hlim2*this->KHL2())/S_H ;
}

double do_an::sigma_Hlim_2()
{
    this->sigma_H_2 = sigma_Flim2*0.7*KFL2()/S_H  ;
    return this->sigma_H_2 ;
}

void do_an::Set_ka(double i)
{
    this->Ka =   i ;
}

void do_an::Set_KHB(double i)
{
    this->KHB = i ;
}

void do_an::Set_T3(double M3)
{
    this->T3 = M3 ;
}

void do_an::cal_Kx()
{
    double z = (this->Z1+this->Z2) ;
    double x =  (this->x1+this->x2) ;
    this->Kx = 1000*x/z ;
    qDebug() << "KX"<< Kx ;
}

double do_an::Cal_Z1(double angle)
{
    double res = 0  ;
    this->Beta_angle =  angle ;
    if(angle == 0) {
       res=  2*this->aw_2/(modul_m*(U2+1)) ;
    }
    else {
        return res;
   }
    return res;
}


double do_an::Cal_Z2()
{
    this->Z2 = this->U2*this->Z1 ;
    return  Z2 ;
}

void do_an::Coefficient_correction_x1__x2()
{
   if(this->Z1 >= 21) {
       this->x1 =  0 ;
       this->x2 = 0 ;
   }
   else if((Z1 <= 20 && Z1 >= 14) && this->U2 >= 3.5)  {
       this->x1 = 0.3 ;
       this->x2 = -0.3 ;
   }
   if((Z1 <= 30 && Z1 >=14) &&( abs(this->HB1 - this->HB2) <= 70 && this->HB1 <= 320)){
       this->x1 = 0.5 ;
       this->x2 =  0.5 ;
   }
   return  ;
}

void do_an::Cal_Ky()
{
    double y = (this->aw/this->modul_m)-0.5*(this->Z1+this->Z2);
    this->Ky = 10000*y/(this->Z1+this->Z2) ;
}

void do_an::Cal_aw_3()
{
    double zt = this->Z1+this->Z2;
    qDebug() <<this->Z1+this->Z2 << modul_m;
    double result = (0.5*(zt)/cos(this->Beta_angle)) +(x1+x2) - delta_y;
    this->aw_3 =  result*modul_m ;
}
double do_an::NFE2()
{
    double m = m_F(this->HB2) ;
    double zigma=0 ;
    long double result = 0 ;
    for(auto x : T_i) {
       zigma+=x ;
    }
    for(int i= 0 ; i < T_i.size() ; i++ ) {
       result += pow(t_i[i],m) *(T_i[i]/zigma) ;
    }
    NFE_1 =  60*result*time*N3 ;
    return  60*result*time*N3 ;
}
void do_an::Sigma_H()
{
    this->sigma_H =  (this->sigma_H_1+this->sigma_H_2)/2.0 ;
}

double do_an::d1()
{
    return modul_m * Z1/ cos(Beta_angle);
}
double do_an::d2()
{
    return modul_m * Z2 / cos(Beta_angle);
}
double do_an::d_w1()
{
    this->dw1 = 2 * aw_3 / (U2 + 1);
    return 2 * aw_3 / (U2 + 1);
}

double do_an::d_w2()
{
    return d_w1() * U2;
}

double do_an::d_a1()
{
    return d1() + 2 * modul_m * (1 + x1 - delta_y);
}
double do_an::d_a2()
{
    return d2() + 2 * modul_m * (1 + x2 - delta_y);
}
double do_an::d_f1()
{
    return d1() - (2.5 - 2 * x1) *modul_m;
}
double do_an::d_f2()
{
    return d2() - (2.5 - 2 * x2) * modul_m;
}
double do_an::d_b1()
{
    return d1() * cos(20*3.14/180);
}
double do_an::d_b2()
{
    return d2() * cos(20*3.14/180);
}
double do_an::alpha_t_angle()
{
    return atan(tan(20*3.14/180) / cos(Beta_angle))*180/3.14;
}

double do_an::alpha_tw_angle()
{
    return (acos(a()*cos(alpha_t_angle()) / a_w_new3()))*180/3.14;
}

vector<double> do_an::Table_Gear_1()
{
    vector<double> res = {a(), a_w_new3(), d1() , d_w1(),d_a1() ,  d_f1(),d_b1(),this->alpha_angle,alpha_t_angle(),alpha_tw_angle()} ;
    return res ;
}
vector<double> do_an::Table_Gear_2()
{
    vector<double> res = {a(), a_w_new3(), d2() , d_w2(),d_a2() ,  d_f2(),d_b2(),alpha_angle ,  alpha_t_angle(),alpha_tw_angle()} ;
    return res ;
}

void do_an::testing_gear_load(vector<double> T, double sigma_H, double sigma_L)
{
    double T_max = *max_element(T.begin() , T.end())   ;
    bool check =  true ;
}

void do_an::testting_gear_1()
{

}

double do_an::ZH() // Bb = atan(cos(at)*tan(beta))
{
    double B =  this->Beta_angle*3.14/180 ;
    double a =20*3.14/180 ;
    double BetaB = atan(cos(alpha_t)*tan(B)) ;
    this->Zh= sqrt(2 * cos((BetaB) / sin(2 * (atan(tan(a)/cos(B))))));
//    qDebug() << "Zh :" <<  Zh ;

    return Zh ;
}
double do_an::a()
{   double zt = this->Z1 + this->Z2 ;
    return 0.5*(zt)*modul_m/cos(Beta_angle) ;
}
void do_an::Get_cap_chinh_xac(){
    this->cal_V_vong() ;
//    qDebug() << "V_VONG: "<<this->V_vong ;
    if(Beta_angle == 0 ) {
        if(this->V_vong<= 2){
            this->cap_chinh_xac =  9 ;
            this->choice =  4 ;
        }
        else if (this->V_vong > 2 &&this->V_vong<= 6 ) {
             this->cap_chinh_xac =  8 ;
            this->choice =  3 ;

        }
        else if (this->V_vong > 6 &&this->V_vong<= 10 ) {
             this->cap_chinh_xac =  7 ;
            this->choice =  2 ;

        }
        else if (this->V_vong > 10 &&this->V_vong<= 15 ) {
             this->cap_chinh_xac =  6 ;
            this->choice =  1 ;

        }
    }
    else {
        if(this->V_vong<= 4){
            this->cap_chinh_xac =  9 ;
            this->choice =  4;

        }
        else if (this->V_vong > 4 &&this->V_vong<= 10 ) {
             this->cap_chinh_xac =  8 ;
            this->choice =  3;

        }
        else if (this->V_vong > 10 &&this->V_vong<= 15 ) {
             this->cap_chinh_xac =  7 ;
            this->choice =  2;

        }
        else if (this->V_vong > 15 &&this->V_vong<= 25 ) {
             this->cap_chinh_xac =  6 ;
            this->choice =  1;

        }
    }
//    qDebug() <<" cap chinh xac : "<<this->cap_chinh_xac ;
}
double do_an::a_w_new3()
{
    return a() + (x2 + x1 - delta_y) * modul_m;
}
void do_an::Cal_V_H(double i) /* i la thu tu trong combo box*/ {
    if(this->HB1 <= 350) {
        if(i == 0 ){
           Delta_H = 0.006 ;
           Delta_F =  0.016 ;
        }
        else if(i == 1) {
            Delta_H = 0.004 ;
            Delta_F =  0.011 ;
        }
        else if(i == 2) {
            Delta_H = 0.002 ;
            Delta_F =  0.006 ;
        }
    }

    else if(this->HB1 > 350 && this->HB2 > 350) {
        if(i == 0 ){
           Delta_H = 0.014 ;
           Delta_F =  0.016 ;
        }
        else if(i == 1) {            
            Delta_H = 0.010 ;
            Delta_F =  0.011 ;
        }
        else if(i == 2) {
            Delta_H = 0.004 ;
            Delta_F =  0.006 ;
        }
    }
    if(this->modul_m <= 3.55) {
        map<int , int> search ={{6, 38}  ,{7,47} , {8,56}, {9,73}} ;
        this->g_o =  search[this->cap_chinh_xac] ;
    }
   else if(this->modul_m > 3.55 && this->modul_m <= 10) {
        map<int , int> search ={{6, 42}  ,{7,53} , {8,61}, {9,82}} ;
        this->g_o =  search[this->cap_chinh_xac] ;
    }
    else if(this->modul_m > 10) {
        map<int , int> search ={{6, 48}  ,{7,64} , {8,73}, {9,100}} ;
        this->g_o =  search[this->cap_chinh_xac] ;
    }
    else {
        this->V_H = Delta_H * g_o * V_vong * sqrt(this->aw_3 / U2);

    }
//    qDebug() << Delta_H<< g_o << aw_3  <<V_vong  ;
    this->V_H = Delta_H * g_o * V_vong * sqrt(this->aw_3 / U2);   
}
void do_an::Cal_KHV() {


 this->KHV = 1+((this->V_H*this->bW*this->dw1)/(2*this->T2*this->KHB*this->K_Ha)) ;
// qDebug() << "KHV = " << this->KHV  ;
}
