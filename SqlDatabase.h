#ifndef SQLDATABASE_H
#define SQLDATABASE_H

#include <QList>
#include <QSqlDatabase>

enum class LengthUnit {
    Meter   = 0,    // 公尺
    Foot            // 英尺
};

enum class StaffType {
    Packing   = 0,    // 包装
    Sewing            // 缝纫
};

struct Price_t {
    QString     type;
    uint32_t    width;
    uint32_t    height;
    LengthUnit  unit;
    float       price;

    Price_t() { }
    Price_t(QString t, uint32_t w, uint32_t h, LengthUnit u, float p)
        :   type(t)
        ,   width(w)
        ,   height(h)
        ,   unit(u)
        ,   price(p)
    { }
};

struct Staff_t {
    uint32_t    id;
    QString     name;
    StaffType   type;

    Staff_t() { }
    Staff_t(uint32_t i, QString n, StaffType s)
        :   id(i)
        ,   name(n)
        ,   type(s)
    { }
};

class SqlDatabase
{
public:
    static SqlDatabase* getInstance() {
        if (nullptr == data) {
            data = new SqlDatabase();
        }
        return data;
    }

    void createTable(const QString table);
    void outputTable(const QString table);
    void addPrice(const Price_t price);
    void addStaff(const Staff_t staff);
    void deletePrice(const Price_t price);
    void deleteStaff(const Staff_t staff);

private:
    SqlDatabase();
    SqlDatabase(SqlDatabase&)=delete;
    SqlDatabase& operator=(const SqlDatabase&)=delete;

    static SqlDatabase *data;
    QSqlDatabase sql;

};

#endif // SQLDATABASE_H
