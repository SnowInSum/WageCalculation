#ifndef WAGECALCULATION_H
#define WAGECALCULATION_H

#include <QWidget>
#include "PriceDialog.h"
#include "StaffDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WageCalculation; }
QT_END_NAMESPACE

class WageCalculation : public QWidget
{
    Q_OBJECT

public:
    WageCalculation(QWidget *parent = nullptr);
    ~WageCalculation();

private slots:
    void on_AddPrice_clicked();
    void on_DeletePrice_clicked();
    void on_AddStaff_clicked();
    void on_DeleteStaff_clicked();
    void on_OutputData_clicked();

    void onPriceDialogClose();
    void onStaffDialogClose();

private:
    Ui::WageCalculation *ui;
    PriceDialog *priceDlog;
    StaffDialog *staffDlog;

    uint32_t staffCount;
    uint32_t priceCount;

};
#endif // WAGECALCULATION_H
