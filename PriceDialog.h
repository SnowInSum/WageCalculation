#ifndef PRICEDIALOG_H
#define PRICEDIALOG_H

#include <QDialog>
#include <QShowEvent>
#include <QCloseEvent>
#include "SqlDatabase.h"

namespace Ui {
class PriceDialog;
}

class PriceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PriceDialog(QWidget *parent = nullptr);
    ~PriceDialog() override;

protected:
    void showEvent(QShowEvent *e) override;
    void closeEvent(QCloseEvent *e) override;

signals:
    void myClose();

private slots:
    void on_but_del_clicked();
    void on_but_add_clicked();
    void on_but_cal_clicked();
    void on_box_unit_activated(int index);

private:
    Ui::PriceDialog *ui;
    SqlDatabase *sql;

};

#endif // PRICEDIALOG_H
