#include "StaffDialog.h"
#include "ui_StaffDialog.h"

StaffDialog::StaffDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    sql = SqlDatabase::getInstance();
}

StaffDialog::~StaffDialog()
{
    delete ui;
}

void StaffDialog::showEvent(QShowEvent *e)
{
    ui->edit_name->clear();
    e->accept();
}

void StaffDialog::closeEvent(QCloseEvent *e)
{
    emit myClose();
    e->accept();
}

void StaffDialog::on_but_del_clicked()
{
    Staff_t staff;
    sql->deleteStaff(staff);
}

void StaffDialog::on_but_add_clicked()
{
    Staff_t staff;
    sql->addStaff(staff);
}

void StaffDialog::on_but_cal_clicked()
{
    this->close();
}

void StaffDialog::on_box_unit_activated(int index)
{
    Q_UNUSED(index)
}
