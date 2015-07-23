#ifndef MENU_DIAGNOSISREPAIRSYSTEMRETRIEVEDATA_H
#define MENU_DIAGNOSISREPAIRSYSTEMRETRIEVEDATA_H

#include <QDialog>
#include <QSize>
#include <QTimer>
#include <QStringList>
#include <QDirIterator>

namespace Ui {
    class menu_diagnosisRepairSystemRetrieveData;
}

class menu_diagnosisRepairSystemRetrieveData : public QDialog
{
    Q_OBJECT

public:
    explicit menu_diagnosisRepairSystemRetrieveData(QWidget *parent = 0);
    menu_diagnosisRepairSystemRetrieveData(int i);
    ~menu_diagnosisRepairSystemRetrieveData();

private slots:
    void on_startButton_clicked();
    void on_detailsButton_clicked();
    void on_cancelButton_clicked();

    void onCurrentTimerTick();
    void onStatusTimerTick();
    void onOverallTimerTick();

private:
    Ui::menu_diagnosisRepairSystemRetrieveData *ui;
    QSize size;
    QString repairMsg;
    QString detailedMsg;
    QTimer* currentTimer;
    QTimer* statusTimer;
    QTimer* overallTimer;
    QStringList viruses;
    QStringList drives;
    QDirIterator* iterator;
    int applicationType;
    int currentProgress;
    int overallProgress;
    int driveCounter;
    static const int currentTimerInterval = 12;
    static const int statusTimerInterval = 250;
    static const int overallTimerInterval = 60000;
    //static const int overallTimerInterval = 111;

    void fillVirusesList();
    void defineVariables(int i=0);
    void updateDiagnosisMessage();
    void updateRepairMessage();
    void updateRetrieveMessage();
    void updateEraseMessage();
    void updateDetailsMessage();
};

#endif
