#ifndef TABLE_VIEW_BANG_H
#define TABLE_VIEW_BANG_H
#include <QObject>
#include<QAbstractTableModel>
#include<QtSql>
#include<QSqlQuery>
#include<QVariant>
#include<QTableView>
class Table_view_bang :  public QAbstractTableModel
{
    Q_OBJECT
private:
    QSqlDatabase database ;
    QString name_of_table ;
    QString Title ;
    int row ;
    int column ;
public:
    explicit Table_view_bang(QObject *parent = 0);
    Table_view_bang(QObject*parent , QString name_of_database ) ;
    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override ;
    QVariant data(const QModelIndex &index , int role) const override ;
    QHash<int , QByteArray> roleNames() const override ;
    Table_view_bang(QObject*parent ,  QAbstractTableModel*abstraction) ;
    void Access_database(QString name_of_database) ;
    ~Table_view_bang() ;

};

#endif // TABLE_VIEW_BANG_H
