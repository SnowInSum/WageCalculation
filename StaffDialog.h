#ifndef STAFFDIALOG_H
#define STAFFDIALOG_H

#include <QDialog>
#include <QShowEvent>
#include <QCloseEvent>
#include "SqlDatabase.h"

namespace Ui {
class StaffDialog;
}

class StaffDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StaffDialog(QWidget *parent = nullptr);
    ~StaffDialog() override;

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
    Ui::StaffDialog *ui;
    SqlDatabase *sql;

};

#endif // STAFFDIALOG_H
