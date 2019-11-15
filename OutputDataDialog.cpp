#include "OutputDataDialog.h"
#include "ui_OutputDataDialog.h"

#include <QDate>
#include <QDebug>

OutputDataDialog::OutputDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutputDataDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    sql = SqlDatabase::getInstance();
    QStringList tables = sql->getTables();
    ui->box_tables->addItems(tables);

    tableName = tables.at(0);
    updateTimedata();
}

OutputDataDialog::~OutputDataDialog()
{
    delete ui;
}

void OutputDataDialog::closeEvent(QCloseEvent *e)
{
    emit myClose();
    e->accept();
}

void OutputDataDialog::on_but_output_clicked()
{
    if (tableName.isEmpty()) {
        tableName = ui->box_tables->currentText();
        qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << "table name : " << tableName;
    }
    if (tableYear.isEmpty()) {
        tableYear = ui->box_year->currentText();
        tableYear.remove("年");
        qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << "table year : " << tableYear;
    }
    if (tableMonth.isEmpty()) {
        tableMonth = ui->box_month->currentText();
        tableMonth.remove("月");
        qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << "table month : " << tableMonth;
    }

    sql->outputTable(tableName, tableYear.toUInt(), tableMonth.toUInt());
    tableName.clear();
    tableYear.clear();
    tableMonth.clear();
}

void OutputDataDialog::on_but_cal_clicked()
{
    this->close();
}

void OutputDataDialog::on_box_tables_activated(const QString &arg1)
{
    tableName = arg1;
    qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << " table name : " << tableName;

    updateTimedata();
}

void OutputDataDialog::on_box_year_activated(const QString &arg1)
{
    tableYear = arg1;
    tableYear.remove("年");
    qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << " tableYear : " << tableYear;

    QDate date = QDate::currentDate();
    int currentYear = date.year();
    int currentMonth = date.month();

    QStringList strMonth;
    if (tableYear == currentYear) {
        for(int i = currentMonth - 1; i >= 1; i--) {
            strMonth << QString::number(currentMonth) + "年";
        }
    }
}

void OutputDataDialog::on_box_month_activated(const QString &arg1)
{
    tableMonth = arg1;
    tableMonth.remove("月");
    qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << " tableMonth : " << tableMonth;
}

void OutputDataDialog::updateTimedata()
{
    QList<int> originalYear, originalMonth;
    sql->getTableOriginalYear(tableName, originalYear);
    qSort(originalYear.begin(), originalYear.end());

    QDate date = QDate::currentDate();
    int currentYear = date.year();
    int currentMonth = date.month();

    QStringList strYear, strMonth;
    for(int i = currentYear; i >= originalYear; i--) {
        strYear << QString::number(currentYear) + "年";
    }
    if (originalYear == currentYear) {
        for(int i = currentMonth - 1; i >= 1; i--) {
            strMonth << QString::number(currentMonth) + "年";
        }
    } else {
        for(int i = 12; i >= 1; i--) {
            strMonth << QString::number(currentMonth) + "年";
        }
    }

    ui->box_year->clear();
    ui->box_year->addItems(strYear);
    ui->box_month->clear();
    ui->box_month->addItems(strMonth);
}
