#include "infomation_of_engine_dialog.h"
#include "ui_infomation_of_engine_dialog.h"
#include"QCloseEvent"
#include<QDebug>
#include"QMessageBox"
#include"QPixmap"
#include<QMouseEvent>
using namespace std ;
Infomation_of_engine_Dialog::Infomation_of_engine_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Infomation_of_engine_Dialog)
{
    Set_page() ;
    QWidget::setWindowTitle("Thông tin cơ bản của hệ thống");
    ui->setupUi(this);
    this->inser_info_map() ;
}

Infomation_of_engine_Dialog::Infomation_of_engine_Dialog(QWidget *parent, map<QString,QString> temp) :
    QDialog(parent),
    map_info(temp),
    ui(new Ui::Infomation_of_engine_Dialog)

{
    ui->setupUi(this);
    QWidget::setWindowTitle("Thông tin cơ bản của hệ thống");

    Set_page() ;
    Set_line_edit() ;
   qDebug() << map_info.size() ;


}
Infomation_of_engine_Dialog::~Infomation_of_engine_Dialog()
{
    delete ui;
}

QString Infomation_of_engine_Dialog::get_Frorce()
{
    return map_info["F"] ;
}
QString Infomation_of_engine_Dialog::get_ver()
{
    return map_info["V"] ;
}
QString Infomation_of_engine_Dialog::get_zdan()
{
    return map_info["zdan"] ;
}
QString Infomation_of_engine_Dialog::get_ztai(){
    return map_info["ztai"] ;
}
QString Infomation_of_engine_Dialog::get_Time_Service() {
    return map_info["Time"] ;
}
void Infomation_of_engine_Dialog::on_pushButton_2_clicked()
{
    reject() ;
}
void Infomation_of_engine_Dialog::on_pushButton_clicked()
{
    get_data_from_line_edit() ;
    if(error_list.empty()){
        accept() ;
    }
    else {
        QString error =  error_list.front() ;
        error_list.pop();
        int ret = QMessageBox::warning(this, tr("Warning"), error,
                                         QMessageBox::Ok);
    }
    return ;
}
void Infomation_of_engine_Dialog::Set_force(QString force)
{
    this->Force = force.toLong();
    auto Find =this->map_info.find("F") ;
    if(Find != this->map_info.end()){
        Find->second = force ;
    }
    if(this->Force == 0) {
         this->error_list.push("F Error") ;
    }
    return ;
}

void Infomation_of_engine_Dialog::Set_Ver(QString V)
{
    this->ver =  V.toDouble();
    auto Find =this->map_info.find("V") ;
    if(Find != this->map_info.end()){
        Find->second = V ;
    }
    if(this->ver == 0) {
         this->error_list.push("V Error") ;
    }
    return ;
}

void Infomation_of_engine_Dialog::Set_Zdab(QString Zd)
{
        this->zdan =  Zd.toInt();
        auto Find =this->map_info.find("zdan") ;
        if(Find != this->map_info.end()){
        Find->second = Zd ;
         }
        if(this->zdan == 0) {
            this->error_list.push("Z Error") ;
         }

    return ;
}
void Infomation_of_engine_Dialog::Set_Z_tai(QString ztai)
{
    this->ztai =  ztai.toInt();
    auto Find =this->map_info.find("ztai") ;
    if(Find != this->map_info.end()){
        Find->second = ztai ;
    }
    if(this->ztai == 0) {
        this->error_list.push("Ztai Error") ;
     }

}

void Infomation_of_engine_Dialog::Set_Ser_list(QString year)
{
    this->Time_service =  year.toInt();
    auto Find =this->map_info.find("Time") ;
    if(Find != this->map_info.end()){
        Find->second = year ;
    }
    if(this->Time_service == 0) {
        this->error_list.push("Year Error") ;
     }
    return ;
}

void Infomation_of_engine_Dialog::Set_numer_of_rotate(QString number)
{
    this->number_of_rotate =  number.toInt();
    auto Find =this->map_info.find("Rotate") ;
    if(Find != this->map_info.end()){
        Find->second = number ;
    }
    if(this->number_of_rotate == 0) {
        this->error_list.push("Rotate Error") ;
     }
    return ;
}
void Infomation_of_engine_Dialog::Set_year_works(QString days)
{
    this->year_work =  days.toInt();
    auto Find =this->map_info.find("year") ;
    if(Find != this->map_info.end()){
        Find->second = days ;
    }
    if(this->year_work == 0) {
        this->error_list.push("year Error") ;
     }
    return ;
}

void Infomation_of_engine_Dialog::Set_load_mode(QString load)
{
    this->year_work =  load.toInt();
    auto Find =this->map_info.find("load") ;
    if(Find != this->map_info.end()){
        Find->second = load ;
    }
}

void Infomation_of_engine_Dialog::Set_Sessiob(QString session)
{
    this->year_work =  session.toInt();
    auto Find =this->map_info.find("Session") ;
    if(Find != this->map_info.end()){
        Find->second = session ;
    }
}
void Infomation_of_engine_Dialog::get_data_from_line_edit()
{
    this->Set_force(ui->Force->text()) ;
    this->Set_Ver(ui->ver->text()) ;
    this->Set_Zdab(ui->zdan->text()) ;
    this->Set_Z_tai(ui->ztai->text()) ;
    this->Set_Ser_list(ui->time_service->text()) ;
    this->Set_numer_of_rotate(ui->number__rotate->text()) ;
    this->Set_load_mode(ui->comboBox_impact->currentText());
    this->Set_Sessiob(ui->comboBox_day_work->currentText())  ;
    this->Set_year_works(ui->year_works->text()) ;
    return ;
}

void Infomation_of_engine_Dialog::Set_page()
{
    QPixmap background("E:/dowload/color-background.png") ;
    background.scaled(this->size() ,Qt::IgnoreAspectRatio) ;
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
}

void Infomation_of_engine_Dialog::inser_info_map()
{
    this->map_info.insert({"F",""})  ;
    this->map_info.insert({"V" ,""}) ;
    this->map_info.insert({"zdan",""});
    this->map_info.insert({"ztai",""}) ;
    this->map_info.insert({"Time" , ""}) ;
    this->map_info.insert({"Rotate" , ""}) ;
    this->map_info.insert({"load" , ""}) ;
    this->map_info.insert({"year" , ""}) ;
    this->map_info.insert({"Session",""}) ;
    return ;
}

void Infomation_of_engine_Dialog::Set_line_edit()
{
    ui->Force->setText(this->map_info["F"]) ;
    ui->ver->setText(this->map_info["V"]) ;
    ui->zdan->setText(this->map_info["zdan"]) ;
    ui->ztai->setText(this->map_info["ztai"]) ;
    ui->time_service->setText(this->map_info["Time"]) ;
    ui->number__rotate->setText(this->map_info["Rotate"]) ;
    ui->comboBox_impact->setCurrentText(this->map_info["load"]) ;
    ui->year_works->setText(this->map_info["year"]) ;
    ui->comboBox_day_work->setCurrentText(this->map_info["Session"]) ;
    return ;
}

void Infomation_of_engine_Dialog::check_change()
{
}

map<QString, QString> Infomation_of_engine_Dialog::get_info_map()
{
    return this->map_info ;
}

QString Infomation_of_engine_Dialog::get_rotate()
{
    return this->map_info["Rotate"] ;
}

QString Infomation_of_engine_Dialog::get_load_mode()
{
    return this->map_info["load"] ;
}

QString Infomation_of_engine_Dialog::get_year_works()
{
    return this->map_info["year"] ;
}

QString Infomation_of_engine_Dialog::get_sessing()
{
   return this->map_info["Session"] ;
}

void Infomation_of_engine_Dialog::Set_info_map(map<QString, QString> map_temp)
{
    this->map_info =  map_temp ;
}
