#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include  "simulatedSystem.h"

class CodeList;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow* ui;

    SimulatedSystem* system;

    //Reset system values.
    int cacheSize;

    int cacheCycleCost;

    int ramCycleCost;

    int noFetchingBlocks;

    int coreAffinity;

    /**
     * @brief Returns the parsed CodeList from the given file.
     * The caller must delete this when it's not needed anymore.
     * This method handles any parsing error.
     *
     * @param fileName The dir of the file to be parsed.
     * @return
     */
    CodeList* ParseCodeList(const QString fileName);
    void LoadCode(int coreId);
    void ButtonPressed(int coreId);
public:

    explicit MainWindow(QWidget* parent = 0);

    ~MainWindow();        

    bool Cycle(int cycles, int coreIndex, bool countCycle);

    bool ShowState(int coreIndex, bool hasEnded);

    void Reset(int cacheSize, int cacheCycleCost,
               int ramCycleCost, int noFetchingBlocks, int coreAffinity, CodeList *coreZeroCode = NULL, CodeList *coreOneCode = NULL);

    void PrepareCodeList(int totalCores);

   // bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_commandLinkButton_pressed();

    void on_actionReset_triggered();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_4_clicked();

    void on_actionCore_0_triggered();

    void on_actionCore_1_triggered();
    void on_actionReset_2_triggered();
    void on_commandLinkButton_clicked();
};

#endif // MAINWINDOW_H
