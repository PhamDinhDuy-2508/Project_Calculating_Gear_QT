#ifndef TABLE_KA_KD_ZM_H
#define TABLE_KA_KD_ZM_H

#include <QDialog>
#include<QtSql>
#include<QSqlTableModel>
#include"QDataWidgetMapper"
#include<map>
#include<QVector>
using namespace std ;
namespace Ui {
class Table_Ka_kd_Zm;
}

class Table_Ka_kd_Zm : public QDialog
{
    Q_OBJECT

public:
    explicit Table_Ka_kd_Zm(QWidget *parent = nullptr);
    void Set_Header() ;
    void Mapping(int i);
    QVector<double> Get_Ka_Kd_Zm() ;
    void Set_Beta(QString Beta) ;
    double Get_Beta() ;
    double get_Cobobox_choice() ;
    void Set_combobox_choice(int index)  ;
    ~Table_Ka_kd_Zm();
private slots:
    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_clicked();
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Table_Ka_kd_Zm *ui;
    QSqlDatabase database ;
    QSqlTableModel *model ;
    QVector<double> Ka_Kd_Zm ;
    QDataWidgetMapper*mapper =  new QDataWidgetMapper(this) ;
    double Beta ;
    double combobox_choice ;

};

#endif // TABLE_KA_KD_ZM_H
