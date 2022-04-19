#ifndef ZOOM_TABLE_T_T_VIEW_H
#define ZOOM_TABLE_T_T_VIEW_H

#include <QDialog>
#include<vector>
using namespace std;
namespace Ui {
class Zoom_table_T_t_view;
}

class Zoom_table_T_t_view : public QDialog
{
    Q_OBJECT

public:
    explicit Zoom_table_T_t_view(QWidget *parent = nullptr);
    Zoom_table_T_t_view(QWidget*Parent , int number_row , QString Type,vector<double> data_in_row) ;
    ~Zoom_table_T_t_view();
    void Add_T_row() ;
    vector<double> get_result() ;
private slots:
    void on_pushButton_clicked();
private:
    Ui::Zoom_table_T_t_view *ui;
    int row ;
    vector<double> data ;
    QString Type_name ;
    vector<double>  result ;
};

#endif // ZOOM_TABLE_T_T_VIEW_H
