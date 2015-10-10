#ifndef RESETDIALOG_H
#define RESETDIALOG_H

#include <QDialog>
#include "Mainwindow.h"

namespace Ui {
class ResetDialog;
}

class ResetDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ResetDialog(int cacheSize,  int cacheCost, int memoryCost,
                         int noOfBlocks, int coreId, MainWindow *parent);

    static bool ExistsAlready();

    ~ResetDialog();
    
    virtual void closeEvent(QCloseEvent *event);

private slots:
    void on_ResetDialog_accepted();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_ResetDialog_finished(int result);

    void on_systemType_activated(int index);

private:
    MainWindow* parentWnd;

    Ui::ResetDialog *ui;

    static bool exists;
};

#endif // RESETDIALOG_H
