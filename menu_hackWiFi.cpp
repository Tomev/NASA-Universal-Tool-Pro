#include "menu_hackWiFi.h"
#include "ui_menu_hackWiFi.h"
#include "qglobal.h"
#include "menu_hackProgresser.h"

#include <QDebug>

menu_hackWiFi::menu_hackWiFi(QWidget *parent) :
QDialog(parent), ui(new Ui::menu_hackWiFi){
    ui->setupUi(this);

    wifiList << "SSID Number: 3964.84A2.C7F1.66F7    Signal Strength: MAX"
             << "SSID Number: 4829.48CD.EF39.1243    Signal Strength: High"
             << "SSID Number: 83CB.CC21.389C.DA7B    Signal Strength: High"
             << "SSID Number: A49D.C20E.221B.DDCD    Signal Strength: Medium"
             << "SSID Number: CCC0.3903.CD03.C3D0    Signal Strength: Medium"
             << "SSID Number: 39BA.390E.FF32.F9CE    Signal Stregnth: Low"
             << "SSID Number: HIDDEN    Signal Strength: High ";


    qsrand(qrand());
    wifiFound = qrand() % ((7) - 3) + 3;

    scanProgress = 0;
    scanTimer = new QTimer(this);
    scanTimer->setInterval(scanTimerInterval);

    connect(scanTimer,SIGNAL(timeout()),this,SLOT(onScanTimerTick()));
}

menu_hackWiFi::~menu_hackWiFi(){
    delete ui;
}

void menu_hackWiFi::on_hackNearestButton_clicked(){
    menu_hackProgresser hp(this,wifiList.at(0));
    hp.exec();
    close();
}

void menu_hackWiFi::on_scanButton_clicked(){
    scanTimer->start();
    ui->wifiList->clear();
    ui->scanButton->hide();
}

void menu_hackWiFi::on_hackButton_clicked(){
    int row = ui->wifiList->currentIndex().row();
    if(row > 6 || row < 0) //So it won't crash coz of invalid list argument.
        row = 0;
    menu_hackProgresser hp(this,wifiList.at(row));
    hp.exec();
    close();
}

void menu_hackWiFi::on_cancelButton_clicked(){
    close();
}

void menu_hackWiFi::onScanTimerTick(){
    if(scanProgress==99){
        scanProgress = 0;
        scanTimer->stop();
        ui->scanProgress->setValue(scanProgress);
        ui->scanButton->show();
    }else if(scanProgress == 2){
        ui->wifiList->addItem(wifiList.at(0));
        scanProgress++;
        ui->scanProgress->setValue(scanProgress);
     }else if(scanProgress == 10){
        ui->wifiList->addItem(wifiList.at(1));
        scanProgress++;
        ui->scanProgress->setValue(scanProgress);
     }else if(scanProgress == 16){
        ui->wifiList->addItem(wifiList.at(2));
        scanProgress++;
        ui->scanProgress->setValue(scanProgress);
     }else if(scanProgress == 33){
        if(wifiFound > 3 || ui->fullScanBox->isChecked())
            ui->wifiList->addItem(wifiList.at(3));
        scanProgress++;
        ui->scanProgress->setValue(scanProgress);
     }else if(scanProgress == 57){
        if(wifiFound > 4 || ui->fullScanBox->isChecked())
            ui->wifiList->addItem(wifiList.at(4));
        scanProgress++;
        ui->scanProgress->setValue(scanProgress);
     }else if(scanProgress == 89){
        if(wifiFound > 5 || ui->fullScanBox->isChecked())
            ui->wifiList->addItem(wifiList.at(5));
        scanProgress++;
        ui->scanProgress->setValue(scanProgress);
     }else if(ui->fullScanBox->isChecked() && scanProgress == 22){
        ui->wifiList->addItem(wifiList.at(6));
        scanProgress++;
        ui->scanProgress->setValue(scanProgress);
     }else{
        scanProgress++;
        ui->scanProgress->setValue(scanProgress);
    }
}
