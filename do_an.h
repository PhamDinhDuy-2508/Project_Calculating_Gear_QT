
#ifndef DO_AN_H
#define DO_AN_H

#include<utility>
#include<vector>
#include<QDebug>
#include<math.h>
#include<map>
#include<future>
using namespace  std ;
class do_an
{
private :
    double sigma_Hlim1 ;
    double sigma_Hlim2 ;
    double sigma_Flim1 ;
    double sigma_Flim2 ;
    double S_H  ;
    double S_F ;
    double HB1 ;
    double HB2 ;
    pair<double , double> HB ;
    double N1 ;
    double N2 ;
    double N3 ;
    int cond ;
    double Gioi_Han_chay_1 ;
    double Gioi_Han_chay_2 ;
    long double NHE_1 ;
    long double NHE_2 ;
    vector<double> T_i ;
    vector<double> t_i ;
    long int  time ;
    double NFE_1 ;
    double KHL_1 ;
    double KFL_1 ;
    double NFE_2 ;
    double KHL_2 ;
    double KFL_2 ;
    double sigma_H_1 ;
    double sigma_H_2 ;
    double Sigma_max_1 ;
    double Sigma_max_2 ;
    double Sigma_max_F_1 ;
    double Sigma_max_F_2 ;
    double psi_ba  ;
    double U2 ;
    double Ka ;
    double KHB ;
    double sigma_H ;
    double aw ;
    double T3 ;
    double Z1 ;
    double modul_m ;
    double Beta_angle ;
    double Z2 ;
    double x1 ;
    double x2 ;
    double Kx ;
    double Ky ;
    double delta_y ;
    double aw_3 ;
    double alpha_angle = 20 ;
    double Zh ;
    double alpha_t_w ;
    double Zm ;
    double EB ;
    double Ea ;
    double bW ;
    double Z_e ;
    double V_vong ;
    double dw1 ;
    int cap_chinh_xac ;
    double K_Ha ;
    double K_Fa ;
    double V_H ;
    double Delta_H ;
    double Delta_F ;
    double g_o ;
    double KHV ;
    double  T1 ;
    double T2 ;
    double KH ;
    int choice ;
    double Zigma_H ;
    double alpha_t ;
    double YB ;
    double YF1 ;
    double YF2 ;
    double KFV ;
    double V_F ;
    double Ye ;
    double KFB;
    double KF ;
    double Tau_F1 ;
    double Tau_F2 ;
    double aw_2 ;
    pair<double , double> YF1_YF2_choice ;
    double T ;
    double Kqt ;
    double combobox_choice ;
public:
    do_an();
    void Set_HB(double HB1 , double HB2) ;
    void Set_Cond(int Cond) ;
    vector<double> get_sigma_H_F_lim1() ;
    vector<double> get_sigma_H_F_lim2() ;
    void   Sigma_H() ;
    double Get_SigMa_H() {
        return this->sigma_H ;
    }
    void Set_Beta(double i) {
        this->Beta_angle = i ;
    }
    double Ti_Tmax(int num) ;
    void Set_N1(double N1) ;
    void Set_N2(double N2) ;
    void Set_N3( double N3) ;
    void Set_T(vector<double> T)  ;
    void Set_t(vector<double> t) ;
    void Set_time(long int time) ;
    void Set_pair(double i ,  double t){
        this->YF1_YF2_choice.first = i ;
        this->YF1_YF2_choice.second = t ;
    }
    void Set_Kqt(double i) {
        this->Kqt= i ;
    }
    double get_Kqt() {
        return this->Kqt;
    }
    pair<double,double> Get_column_choice() {
        return this->YF1_YF2_choice ;
    }
    double Get_T1()    {
        return this->T1 ;
    }
    double get_T2() {
        return this->T2 ;
    }
    double get_T3() {
        return this->T3;
    }
    void Set_T(double i) {
        this->T = i ;
    }
    double get_T() {
        return this->T ;
    }
    void Set_T1(double i){
        this->T1 =  i ;
    }
    void Set_T2(double i) {
        this->T2 = i ;
    }
    void Set_U2(double U_2) {
        this->U2 = U_2 ;
    }
    void Set_alphat_w(double i) {
           this->alpha_t_w =  i  ;
    }
    double psi_bd()  ;
    void Set_alpha_t(double i )  {
        this->alpha_t = i*3.14/180 ;
    }

    double m_F(double HB)
    {
        if (HB <= 350)
            return 6.0;
        else
            return 9.0;
    }
    void Set_psi_ba (double i){
        this->psi_ba = i ;
        return ;
    }
    void Set_aw_2(double i) {
        this->aw_2= i ;
    }
    void Set_KFb(double i) {
        this->KFB = i ;
    }
    void sigma_Hlim_Flim_1() ;
    double N_HO1() ;
    double N_FO1() ;
    double NHE1() ;
    double NFE1() ;
    double KHL1();
    double KFL1() ;
    double sigma_lim() ;
    double sigma_Hlim() ;
    void Set_Sigma_max_F_1(double i) {
        this->Sigma_max_F_1 =  i ;
    }
    double  Get_Sigma_max_F1(){
        return this->Sigma_max_F_1 ;
    }
    double  Get_Sigma_max_F2(){
        return this->Sigma_max_F_2 ;
    }

    void Set_Sigma_max_F_2(double i) {
        this->Sigma_max_F_2 =  i ;
    }
    void Set_G_H_ch_1(double i) {
        this->Gioi_Han_chay_1 =  i ;
    }
    void Set_G_H_ch_2(double i) {
        this->Gioi_Han_chay_2 =  i ;
    }
    void get_cong_thuc_sigma_max_1(int i) {
        if(i == 1)  {
            this->Sigma_max_1 =  this->Gioi_Han_chay_1*2.8 ;
        }
    }
     void get_cong_thuc_sigma_max_2(int i) {
        if(i == 1 )  {
            this->Sigma_max_2 =  this->Gioi_Han_chay_2*2.8 ;
        }
    }
     void cal_aw() ;    
     double get_aw() {         
         return aw ;
     }
    //
     void Set_Z1(double i) {
         this->Z1 = i ;
     }
     void Set_aw(double i){
         //this->aw =  aw ;
         this->aw  = i ;
     }
     void Set_M(double i){
         this->modul_m = i ;
     }
     void Set_sigma_H1(double i) ;
     void Set_sigma_H2(double i) ;
    void sigma_Hlim_Flim_2() ;
    double N_HO2() ;
    double N_FO2() ;
    double NHE2() ;
    double NFE2() ;
    double KHL2();
    double KFL2() ;
    double sigma_lim_2() ;
    double sigma_Hlim_2() ;
    void Set_ka(double i) ;
    void Set_KHB(double i) ;
    void Set_T3(double M3) ;
    double get_choice() {
        return this->choice ;
    }
    double Get_ka() {
        return this->Ka ;
    }
    double Get_KHB(){
        return this->KHB ;
    }
    double Get_psi_ba() {
        return this->psi_ba ;
    }
    double Get_sihma_1(){
        return this->sigma_H_1 ;
    }
    double Get_sigma_2() {
        return this->sigma_H_2 ;
    }
    double get_u2() {
        return this->U2 ;
    }

    void Set_z1(double i) {
        this->Z1 =  i ;
    }
    double get_Z1() {
        return this->Z1 ;
    }
    double get_Z2() {
        return this->Z2 ;
    }
    void Set_z2(double i) {
        this->Z2 = i ;
    }
    void cal_Kx();
    double Cal_Z1(double angle) ;
    double Cal_Z2() ;
    void Coefficient_correction_x1__x2() ;
    double get_x1(){
        return this->x1 ;
    }
    double get_x2() {
        return this->x2 ;
    }
    double Get_HB1(){
        return this->HB1 ;
    }
    double Get_HB2() {
        return this->HB2 ;
    }
    void Set_HB1(double HB){
        this->HB1 = HB ;
    }
    void Set_HB2(double HB){
        this->HB1 = HB ;
    }
    void Cal_Ky() ;
    double Get_Ky() {
        return this->Ky ;
    }
    void Set_ky(double K_y){
        this->Ky = K_y ;
    }
    void Set_Kx(double kx){
        this->Kx =  kx ;
    }
    double Get_kx() {
        return this->Kx ;
    }
    void Set_x1(double x){
        this->x1 =  x ;
    }
    void Set_x2 (double x) {
        this->x2 = x ;
    }
    double get_delta_y(){
        return this->delta_y;
    }
    void Cal_delta_y(){
        this->delta_y =  this->Ky *(this->Z1+this->Z2)/1000 ;
    }
    double Get_aw_3(){
        return this->aw_3;
    }
    double Get_ZM(){
        return this->Zm ;
    }
    double get_Tau_1() {
        return this->Tau_F1 ;
    }
    double get_Tau_2() {
        return this->Tau_F2 ;
    }
    void Cal_aw_3();
        double a();// tuong tu a_w
        double a_w_new3();// tuong tu a_w_new2
        double d1();
        double d2();
        double d_w1();
        double d_w2();
        double d_a1();
        double d_a2();
        double d_f1();
        double d_f2();
        double d_b1();
        double d_b2();
        double alpha_t_angle();//rad
        double alpha_tw_angle();//rad OK
        vector<double> Table_Gear_1()  ;
        vector<double> Table_Gear_2() ;
        void testing_gear_load(vector<double> T , double sigma_H,  double sigma_L ) ;
        void testting_gear_1() ;
        double get_Beta_angle() {
            return this->Beta_angle ;
        }
        double ZH() ;
        double get_V_vong() {
            return this->V_vong ;
        }
    /* Kiem nghiem 1*/
    void Cal_V_H(double i)  ;
    void Gte_K_Ha_K_Hb(double i , double j) {
        if(this->Beta_angle == 0 ) {
            K_Ha =  1 ;
            K_Fa =  j ;
        }
        else {
            K_Ha = i ;
            K_Fa =  j ;
        }
//        qDebug() <<"KHA:" <<  i << "KFa:" << j  ;
    }    // search table
    void Set_KHa(double i){
        this->K_Ha =  i ;
    }
    double Get_KHa() {
        return this-> K_Ha ;
    }
    void Cal_KHV() ;
    void Cal_KH() {
        this->KH = this->KHB*this->K_Ha*this->KHV ;
//        qDebug() << "KH" << this->KH ;
    }
    void Get_cap_chinh_xac() ;
    void cal_V_vong(){
       this->V_vong =  this->dw1*3.14*this->N2/6000 ; // set N1
    }
    double cal_Zigma_H() {


       this->Zigma_H = (this->Zm * this->Zh * this->Z_e / this->dw1) * sqrt(2 *this->KH *T2  * (U2 + 1) / (this->bW * U2)) ;
       //qDebug() << "ZIGma_H" << this->Zigma_H ;
        return this->Zigma_H;
    }
    double Get_ZIGMA_H() {
        return this->Zigma_H ;
    }
    void Cal_Ze(){
       Cal_EB() ;
       Cal_Ea() ;
       if(EB ==0 ) {
           this->Z_e = sqrt((4 - Ea) / 3);
       }
       else if(EB > 0 & EB < 1) {
           this->Z_e =  sqrt((4 - Ea) * (1 - EB) / 3);
       }
       else {
          this->Z_e = sqrt(1 / Ea) ;
       }
//        qDebug() <<"Ze:"<<this->Z_e ;
        return ;
    }
    void Set_ZM(double i) {
        this->Zm =  i  ;
    }
    void Cal_Ea() {
          this->Ea =  (1.88 - 3.2 * ((1 / this->Z1) + (1 / this->Z2))) * cos(this->Beta_angle*3.14/180);
    }
    void Cal_Bw(){
        this->bW =  this->psi_ba * this->aw_3 ;
//        qDebug() << "BW :"<<this->bW ;
    }
    void Cal_EB(){
     Cal_Bw()  ;
     this->EB = this->bW*sin(this->Beta_angle*3.14/180)/(this->modul_m*3.14) ;
//     qDebug() << "EB :"<<this->EB ;
    }
    /* Kiem nghiem 1*/
    /* kiem nghiem 2 */
    void Cal_YB(){
       this->YB = 1- this->Beta_angle/140;
    }
    void Cal_Ye() {
        this->Ye =  1/this->Ea ;
    }
    void Set_YF1_YF2(double yf1 , double yf2)  {
        this->YF1 =  yf1  ;
        this->YF2=  yf2 ;
    }

    void Cal_VF() {
        this->V_F = this->Delta_F*this->g_o*sqrt(this->aw/this->U2);
    }
    void Cal_KFV()  {
        Cal_VF() ;
//       qDebug() << "VF" << this->V_F ;


        this->KFV = 1 + ((this->V_F*this->bW*this->dw1)/(2*T2*this->KFB*this->K_Fa))  ;
        this->KF=  this->KFB*this->K_Fa*this->KFV ;
    }
    void Cal_Tau_F1() {
//        qDebug() <<"KF" <<this->KF ;        
     /*  qDebug() <<"Ye" <<this->Ye ;
       qDebug() <<"YB" <<this->YB ;
       qDebug() <<"YF1" <<this->YF1 ;
       qDebug() << "Bw"  << this->bW ;
       qDebug() << "KF" << this->KF;
       */
        this->Tau_F1 = (2*this->T2*this->KF*this->Ye*this->YB*this->YF1)/(this->bW * this->dw1*this->modul_m) ;
    }
    void Cal_Tau_F2() {
        this->Tau_F2 = this->Tau_F1*this->YF2/this->YF1 ;

    }
   double get_tau_f1() {
       return this->Tau_F1 ;
   }
   double get_tau_f2() {
       return this->Tau_F2 ;
   }
    /* kiem nghiem ve uon
     * Ye //
     * YB //
     * YF1..
     * YF2..
     * KF->(KFB,KFa,KFV) //
     * KFV //
     * Vf//
    khiem nghiem ve uon */

};

#endif // DO_AN_H
