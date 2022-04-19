#ifndef TABLE_BD_BD_MAX_H
#define TABLE_BD_BD_MAX_H

#include <QDialog>

namespace Ui {
class table_bd_bd_max;
}

class table_bd_bd_max : public QDialog
{
    Q_OBJECT

public:
    explicit table_bd_bd_max(QWidget *parent = nullptr);
    ~table_bd_bd_max();

private:
    Ui::table_bd_bd_max *ui;
};

#endif // TABLE_BD_BD_MAX_H
