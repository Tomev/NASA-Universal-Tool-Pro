#ifndef MENU_REPAIRINTERNET_H
#define MENU_REPAIRINTERNET_H

#include <QDialog>
#include <QSize>
#include <QTimer>

namespace Ui {
class menu_repairInternet;
}

class menu_repairInternet : public QDialog
{
    Q_OBJECT

public:
    explicit menu_repairInternet(QWidget *parent = 0);
    ~menu_repairInternet();

private slots:
    void on_startButton_clicked();
    void on_detailsButton_clicked();
    void on_cancelButton_clicked();
    void onCurrentTimerTick();
    void onStatusTimerTick();
    void onOverallTimerTick();

private:
    Ui::menu_repairInternet *ui;
    QSize size;
    QString repairMsg;
    QString detailedMsg;
    QTimer* currentTimer;
    QTimer* statusTimer;
    QTimer* overallTimer;
    int currentProgress;
    int overallProgress;
    static const int currentTimerInterval = 12;
    static const int statusTimerInterval = 250;
    static const int overallTimerInterval = 60000;
};

#endif
