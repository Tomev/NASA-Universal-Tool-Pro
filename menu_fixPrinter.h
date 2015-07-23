#ifndef MENU_FIXPRINTER_H
#define MENU_FIXPRINTER_H

#include <QDialog>
#include <QSize>
#include <QTimer>

namespace Ui {
class menu_fixPrinter;
}

class menu_fixPrinter : public QDialog
{
    Q_OBJECT

public:
    explicit menu_fixPrinter(QWidget *parent = 0);
    ~menu_fixPrinter();

private slots:
    void on_cancelButton_clicked();
    void on_startButton_clicked();
    void on_detailsButton_clicked();

    void onCurrentTimerTick();
    void onStatusTimerTick();
    void onOverallTimerTick();

private:
    Ui::menu_fixPrinter *ui;
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

#endif // MENU_FIXPRINTER_H
