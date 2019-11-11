#include "PriceDialog.h"
#include "ui_PriceDialog.h"

PriceDialog::PriceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PriceDialog)
{
    ui->setupUi(this);
    this->setFixedSize(460, 135);

    sql = SqlDatabase::getInstance();
}

PriceDialog::~PriceDialog()
{
    delete ui;
}

void PriceDialog::showEvent(QShowEvent *e)
{
    ui->edit_type->clear();
    ui->edit_work->clear();
    ui->edit_price->clear();
    ui->edit_width->clear();
    ui->edit_height->clear();
    e->accept();
}

void PriceDialog::closeEvent(QCloseEvent *e)
{
    emit myClose();
    e->accept();
}

void PriceDialog::on_but_del_clicked()
{
    Price_t price;
    sql->deletePrice(price);
}

void PriceDialog::on_but_add_clicked()
{
    Price_t price;
    sql->addPrice(price);
}

void PriceDialog::on_but_cal_clicked()
{
    this->close();
}
