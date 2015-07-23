#ifndef MENU_HACKWIFI_H
#define MENU_HACKWIFI_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class menu_hackWiFi;
}

class menu_hackWiFi : public QDialog
{
    Q_OBJECT

public:
    explicit menu_hackWiFi(QWidget *parent = 0);
    ~menu_hackWiFi();

private slots:
    void on_hackNearestButton_clicked();
    void on_scanButton_clicked();
    void on_hackButton_clicked();
    void on_cancelButton_clicked();

    void onScanTimerTick();

private:
    Ui::menu_hackWiFi *ui;
    QString wifi1;
    QString wifi2;
    QString wifi3;
    QString wifi4;
    QString wifi5;
    QString wifi6;
    QString wifi7;
    QStringList wifiList;
    QTimer* scanTimer;
    int scanProgress;
    static const int scanTimerInterval = 50;
    int wifiFound;
};

#endif
