#ifndef THONG_SO_DONG_CO_H
#define THONG_SO_DONG_CO_H

#include <QDialog>
#include<QListWidgetItem>
#include<QtSql>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlTableModel>
#include<QTreeWidget>
#include<QComboBox>
#include<QSqlRecord>
#include<map>
#include<search_custom.h>
using namespace  std ;
namespace Ui {
class Thong_So_Dong_co;
}
class Thong_So_Dong_co : public QDialog
{
    Q_OBJECT

public:
    explicit Thong_So_Dong_co(QWidget *parent = nullptr);
   ~Thong_So_Dong_co();
    void Set_table_of_database(QString name) ;
    void Load_combox() ;

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_comboBox_currentIndexChanged(int index);

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::Thong_So_Dong_co *ui;
    QSqlDatabase database ;
    QSqlQuery query ;
    QSqlTableModel*Model ;
    QSqlRecord record ;
    QString Present_data_table;
    map<int , QString> link_header_to_combobox ;
     Gear_Info*Gear_info ;
     Database data ;
};

#endif // THONG_SO_DONG_CO_H
