#include "table_view_bang.h"
#include<QSqlDatabase>
#include<qqml.h>
Table_view_bang::Table_view_bang(QObject *parent):QAbstractTableModel(parent)
{
    return ;
}

Table_view_bang::Table_view_bang(QObject *parent, QString name_of_database):QAbstractTableModel(parent) , name_of_table((name_of_database))
{
   database  = QSqlDatabase::addDatabase("QMYSQL") ;
   database.setHostName("127.0.0.1");
   database.setUserName("root") ;
   database.setPassword("") ;
   return ;
}

int Table_view_bang::rowCount(const QModelIndex &) const
{
    QSqlQuery query(database) ;
    QString Prepare = "SELECT * FROM" ;
    Prepare+=name_of_table;
    query.prepare(Prepare) ;
    query.exec();
    return query.size() ;
}

int Table_view_bang::columnCount(const QModelIndex &) const
{
    QSqlQuery query(database) ;
    QString Prepare = "SELECT * FROM" ;
    Prepare+=name_of_table;
    query.prepare(Prepare) ;
    query.exec();
    return query.record().count() ;
}

QVariant Table_view_bang::data(const QModelIndex &index, int role) const
{
        return QVariant() ;
}

QHash<int, QByteArray> Table_view_bang::roleNames() const
{
    QHash<int, QByteArray> res ;
    return res;
}
Table_view_bang::Table_view_bang(QObject *parent, QAbstractTableModel*abstraction)
{
    return ;
}
void Table_view_bang::Access_database(QString name_of_database)
{
    database.setDatabaseName(name_of_database) ;
    this->name_of_table =  name_of_database ;
    return ;
}
Table_view_bang::~Table_view_bang()
{
    return ;
}
