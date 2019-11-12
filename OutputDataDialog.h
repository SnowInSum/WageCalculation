#ifndef OUTPUTDATADIALOG_H
#define OUTPUTDATADIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include "SqlDatabase.h"

namespace Ui {
class OutputDataDialog;
}

class OutputDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OutputDataDialog(QWidget *parent = nullptr);
    ~OutputDataDialog() override;

protected:
    void closeEvent(QCloseEvent *e) override;

    void updateTimedata();

signals:
    void myClose();

private slots:
    void on_but_output_clicked();
    void on_but_cal_clicked();
    void on_box_tables_activated(const QString &arg1);
    void on_box_year_activated(const QString &arg1);
    void on_box_moonth_activated(const QString &arg1);

private:
    Ui::OutputDataDialog *ui;
    SqlDatabase *sql;

    QString tableName;
    QString year;
    QString moonth;

};

#endif // OUTPUTDATADIALOG_H
