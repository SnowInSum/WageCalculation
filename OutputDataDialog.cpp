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
    sql->outputTable(tableName, year.toUInt(), moonth.toUInt());
    tableName.clear();
}

void OutputDataDialog::on_but_cal_clicked()
{
    this->close();
}

void OutputDataDialog::on_box_tables_activated(const QString &arg1)
{
    tableName = arg1;
    qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << " table name : " << tableName;
}

void OutputDataDialog::on_box_year_activated(const QString &arg1)
{
    year = arg1;
    if (year.contains("年")) {
        year.remove("年");
    }
    qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << " year : " << year;
}

void OutputDataDialog::on_box_moonth_activated(const QString &arg1)
{
    moonth = arg1;
    if (moonth.contains("月")) {
        moonth.remove("月");
    }
    qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << " moonth : " << moonth;
}

void OutputDataDialog::updateTimedata()
{
    uint32_t year, moonth;
    sql->getTabletime(tableName, year, moonth);

}
