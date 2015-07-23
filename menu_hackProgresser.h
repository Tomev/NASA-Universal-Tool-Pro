#ifndef MENU_HACKPROGRESSER_H
#define MENU_HACKPROGRESSER_H

#include <QDialog>
#include <QSize>
#include <QTimer>

namespace Ui {
class menu_hackProgresser;
}

class menu_hackProgresser : public QDialog
{
    Q_OBJECT

public:
    explicit menu_hackProgresser(QWidget *parent = 0);
    menu_hackProgresser(QWidget *parent = 0, QString wifi = "HIDDEN");
    ~menu_hackProgresser();

private slots:
    void on_detailsButton_clicked();
    void on_cancelButton_clicked();

    void onCurrentTimerTick();
    void onStatusTimerTick();
    void onOverallTimerTick();

private:
    Ui::menu_hackProgresser *ui;
    QSize size;
    QString targetMsg;
    QString hacking;
    QString detailedMsg;
    QTimer* currentTimer;
    QTimer* overallTimer;
    QTimer* statusTimer;
    static const int currentTimerInterval = 12;
    static const int statusTimerInterval = 250;
    static const int overallTimerInterval = 60000;
    int currentProgress;
    int overallProgress;
};

#endif
