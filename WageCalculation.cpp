#include "WageCalculation.h"
#include "ui_WageCalculation.h"
#include <QIcon>
#include <QtDebug>

WageCalculation::WageCalculation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WageCalculation)
    , priceDlog(new PriceDialog())
    , staffDlog(new StaffDialog())
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("./sactai_face.ico"));

    connect(priceDlog, SIGNAL(myClose()), this, SLOT(onPriceDialogClose()));
    connect(staffDlog, SIGNAL(myClose()), this, SLOT(onStaffDialogClose()));
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

void WageCalculation::on_AddPrice_clicked()
{
    priceDlog->show();
}

void WageCalculation::on_DeletePrice_clicked()
{
    priceDlog->show();
}

void WageCalculation::on_AddStaff_clicked()
{
    staffDlog->show();
}

void WageCalculation::on_DeleteStaff_clicked()
{
    staffDlog->show();
}

void WageCalculation::on_OutputData_clicked()
{

}
