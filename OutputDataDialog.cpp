#include "OutputDataDialog.h"
#include "ui_OutputDataDialog.h"

OutputDataDialog::OutputDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutputDataDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
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

}

void OutputDataDialog::on_but_cal_clicked()
{
    this->close();
}

void OutputDataDialog::on_comboBox_activated(const QString &arg1)
{
    Q_UNUSED(arg1)
}
