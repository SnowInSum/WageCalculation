#include "SqlDatabase.h"
#include <QSqlQuery>

SqlDatabase::SqlDatabase()
{
    sql = QSqlDatabase::addDatabase("QSQLITE");
    sql.setDatabaseName("faceDatabase.db");
    sql.open();
    QSqlQuery query;
    query.exec("create table if not exists StaffDataTable("
               "id int primary key AUTOINCREMENT,"
               "name text not null,"
               "type int not null)");
    query.exec("create table if not exists PriceDataTable("
               "id int primary key AUTOINCREMENT,"
               "price text not null UNIQUE)");
    sql.close();
}

SqlDatabase* SqlDatabase::data = nullptr;

void SqlDatabase::createTable(const QString table)
{
    Q_UNUSED(table)
}

void SqlDatabase::outputTable(const QString table)
{
    Q_UNUSED(table)
}

void SqlDatabase::addPrice(const Price_t price)
{
    Q_UNUSED(price)
}

void SqlDatabase::addStaff(const Staff_t staff)
{
    Q_UNUSED(staff)
}

void SqlDatabase::deletePrice(const Price_t price)
{
    Q_UNUSED(price)
}

void SqlDatabase::deleteStaff(const Staff_t staff)
{
    Q_UNUSED(staff)
}
