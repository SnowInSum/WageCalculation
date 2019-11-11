#include "WageCalculation.h"
#include "ui_WageCalculation.h"
#include <QIcon>
#include <QtDebug>

WageCalculation::WageCalculation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WageCalculation)
    , priceDlog(new PriceDialog())
    , staffDlog(new StaffDialog())
    , outptDlog(new OutputDataDialog())
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("./sactai_face.ico"));

    connect(priceDlog, SIGNAL(myClose()), this, SLOT(onPriceDialogClose()));
    connect(staffDlog, SIGNAL(myClose()), this, SLOT(onStaffDialogClose()));
    connect(outptDlog, SIGNAL(myClose()), this, SLOT(onOutptDialogClose()));
}

WageCalculation::~WageCalculation()
{
    delete priceDlog;
    delete staffDlog;
    delete ui;
}
void WageCalculation::onPriceDialogClose()
{
    qDebug() << __FILE__ << __FUNCTION__ << __LINE__ ;
}

void WageCalculation::onStaffDialogClose()
{
    qDebug() << __FILE__ << __FUNCTION__ << __LINE__ ;
}

void WageCalculation::onOutptDialogClose()
{
    qDebug() << __FILE__ << __FUNCTION__ << __LINE__ ;
}

void WageCalculation::on_ManagePrice_clicked()
{
    priceDlog->show();
}

void WageCalculation::on_ManageStaff_clicked()
{
    staffDlog->show();
}

void WageCalculation::on_OutputData_clicked()
{
    outptDlog->show();
}
