#include "menu_main.h"
#include "ui_menu_main.h"

#include "menu_diagnosisRepairSystemRetrieveData.h"
#include "menu_repairInternet.h"
#include "menu_hackWiFi.h"
#include "menu_fixPrinter.h"

menu_main::menu_main(QWidget *parent) :
QDialog(parent), ui(new Ui::menu_main){
    ui->setupUi(this);
}

menu_main::~menu_main(){
    delete ui;
}

void menu_main::on_diagnoseButton_clicked(){
    menu_diagnosisRepairSystemRetrieveData diagnosis(1);
    diagnosis.exec();
}

void menu_main::on_eraseVirusesButton_clicked(){
    menu_diagnosisRepairSystemRetrieveData eraser(4);
    eraser.exec();
}

void menu_main::on_repairSystemButton_clicked(){
    menu_diagnosisRepairSystemRetrieveData repairSystem(2);
    repairSystem.exec();
}

void menu_main::on_repairInternetButton_clicked(){
    menu_repairInternet repairInternet;
    repairInternet.exec();
}

void menu_main::on_retrieveDataButton_clicked(){
    menu_diagnosisRepairSystemRetrieveData retrieveData(3);
    retrieveData.exec();
}

void menu_main::on_hackButton_clicked(){
    menu_hackWiFi hackWiFi;
    hackWiFi.exec();
}

void menu_main::on_fixPrinterButton_clicked(){
    menu_fixPrinter fixer;
    fixer.exec();
}

void menu_main::on_quitButton_clicked(){
    QApplication::quit();
}
