#include "menu_fixPrinter.h"
#include "ui_menu_fixPrinter.h"

#include "QMessageBox"

menu_fixPrinter::menu_fixPrinter(QWidget *parent) :
QDialog(parent), ui(new Ui::menu_fixPrinter){
    ui->setupUi(this);
    ui->detailsButton->hide();
    currentProgress = 0;
    overallProgress = 0;

    repairMsg = "Fixing .";
    detailedMsg = "Preparing to work...";

    size.setWidth(328);
    size.setHeight(148); 
    setMaximumHeight(148);
    setMinimumHeight(148);
    resize(size);
}

menu_fixPrinter::~menu_fixPrinter(){
    delete ui;
}

void menu_fixPrinter::on_startButton_clicked(){
    overallTimer = new QTimer(this);
    overallTimer->setInterval(overallTimerInterval);

    statusTimer = new QTimer(this);
    statusTimer->setInterval(statusTimerInterval);

    currentTimer = new QTimer(this);
    currentTimer->setInterval(currentTimerInterval);

    connect(currentTimer,SIGNAL(timeout()),this,SLOT(onCurrentTimerTick()));
    connect(statusTimer,SIGNAL(timeout()),this,SLOT(onStatusTimerTick()));
    connect(overallTimer,SIGNAL(timeout()),this,SLOT(onOverallTimerTick()));

    overallTimer->start();
    statusTimer->start();
    currentTimer->start();

    ui->statusLabel->setText(repairMsg);
    ui->startButton->hide();
    ui->detailsButton->show();
    detailedMsg += "\nGathering information about device(s)...";
    ui->detailsBrowser->setText(detailedMsg);
}

void menu_fixPrinter::on_detailsButton_clicked(){
    if(size.height() == 148){
        size.setHeight(360);
        setMaximumHeight(360);
        setMinimumHeight(360);
        resize(size);
    }else{
        size.setHeight(148);
        setMaximumHeight(148);
        setMinimumHeight(148);
        resize(size);
    }
}

void menu_fixPrinter::on_cancelButton_clicked(){
    close();
}

void menu_fixPrinter::onCurrentTimerTick(){
    if(currentProgress==99){
        currentProgress=0;
        ui->currentProgress->setValue(currentProgress);
    }else{
        currentProgress++;
        ui->currentProgress->setValue(currentProgress);
    }
}

void menu_fixPrinter::onStatusTimerTick(){
    if(repairMsg == "Fixing . . .")
        repairMsg = "Fixing";
    else
        repairMsg += " .";

    ui->statusLabel->setText(repairMsg);
}

void menu_fixPrinter::onOverallTimerTick(){
    if(overallProgress==99){
        overallTimer->stop();
        statusTimer->stop();
        currentTimer->stop();

        QString msg("An error was encountered during fixing.\n");
        msg += "Application was unable to access some of memory fragments ";
        msg += "with WMS-GEX1 G-Exes, hence it could not use device functions.\n";
        msg += "Operations shall be undo. Please try again.";
        QMessageBox::critical(this, "Fatal Error Occured", msg);
        QApplication::quit();
    }else{
        ui->overallProgress->setValue(overallProgress);
        overallProgress++;
    }

    if(overallProgress==5)
        detailedMsg += "Looking through CSV of CAT1-X1/3 Hyperion Gundam Unit 1...\n";
    else if(overallProgress==10)
        detailedMsg += "Accelerating Genoace C Nacht boost preformance...\n";
    else if(overallProgress==15)
        detailedMsg += "Testing lamp timeout with Xvm-zgc Zeydra. Looking for errors...\n";
    else if(overallProgress==20)
        detailedMsg += "Attempting to eject stucked paper from the device...\n";
    else if(overallProgress==25)
        detailedMsg += "Testing if all OneTouch properties and PaperPorts are properly configured...\n";
    else if(overallProgress==30)
        detailedMsg += "MA-05 Bigro Kai is currently occupied. Searching for another testing space...\n";
    else if(overallProgress==35)
        detailedMsg += "F90II-I Gundam F90II Intercept Type Jupiter Battle Specification iniciating...\n";
    else if(overallProgress==40)
        detailedMsg += "Installing new EMS-TC04 Desphys drivers...\n";
    else if(overallProgress==45)
        detailedMsg += "Reconfiguring users default settings...\n";
    else if(overallProgress==50)
        detailedMsg += "RGM-79GB High Boost GM engaged...\n";
    else if(overallProgress==55)
        detailedMsg += "AMX-011S Zaku III Custom settings set as default...\n";
    else if(overallProgress==60)
        detailedMsg += "Variable Vs3R_isa_F4g == true... Compiling... \n";
    else if(overallProgress==65)
        detailedMsg += "Killing ur dog...\n";
    else if(overallProgress==70)
        detailedMsg += "MS-08TX(EXAM) Efreet Custom drivers are missing... Downloading...\n";
    else if(overallProgress==75)
        detailedMsg += "Helping Pacman to avoid ghosts...\n";
    else if(overallProgress==80)
        detailedMsg += "Transparency Adapter may be jammed. Try cleaning it manually.\n";
    else if(overallProgress==85)
        detailedMsg += "WARNING! CCM-91 Chimaira is missing. Toners are likely to blow up.\n";
    else if(overallProgress==90)
        detailedMsg += "MS-06K.dll isn't up to date. Downloading...\n";
    else if(overallProgress==95)
        detailedMsg += "Computer processor must rest... Waiting for resume...\n";

    ui->detailsBrowser->setText(detailedMsg);
}
