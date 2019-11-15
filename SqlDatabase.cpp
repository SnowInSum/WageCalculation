#include "SqlDatabase.h"
#include <QSqlQuery>

SqlDatabase::SqlDatabase()
{
    sql = QSqlDatabase::addDatabase("QSQLITE");
    sql.setDatabaseName("WageDatabase.db");
    sql.open();
    QSqlQuery query;
    query.exec("create table if not exists StaffDataTable("
               "id int primary key AUTOINCREMENT,"
               "name text not null,"
               "type int not null,"
               "year int not null,"
               "month int not null)");
    query.exec("create table if not exists PriceDataTable("
               "id int primary key AUTOINCREMENT,"
               "price text not null UNIQUE,"
               "year int not null,"
               "month int not null)");
    sql.close();
}

SqlDatabase* SqlDatabase::data = nullptr;

void SqlDatabase::createTable(const QString table)
{
    Q_UNUSED(table)
}

QStringList SqlDatabase::getTables()
{
    sql.open();

    QStringList tables = sql.tables();

    sql.close();

    return tables;
}

void SqlDatabase::outputTable(const QString table, const uint32_t year, const uint32_t month)
{
    Q_UNUSED(table)
    Q_UNUSED(year)
    Q_UNUSED(month)
}

void SqlDatabase::getTableOriginalYear(const QString table, QList<int> &year)
{
    sql.open();

    QSqlQuery query;
    query.exec(QString("select year from %1").arg(table));
    while (query.next()) {
        year << query.value(0).toInt();
    }

    sql.close();
}

void SqlDatabase::getTableOriginalMonth(const QString table, int year, QList<int> &month)
{
    sql.open();

    QSqlQuery query;
    query.exec(QString("select month from %1 where year = %2").arg(table).arg(year));
    while (query.next()) {
        month << query.value(0).toInt();
    }

    sql.close();
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
