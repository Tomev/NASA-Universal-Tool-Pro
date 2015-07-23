#include "menu_hackProgresser.h"
#include "ui_menu_hackProgresser.h"

#include <QMessageBox>

menu_hackProgresser::menu_hackProgresser(QWidget *parent) :
QDialog(parent), ui(new Ui::menu_hackProgresser){
    ui->setupUi(this);

    setMaximumHeight(158);
    setMinimumHeight(158);
    size.setHeight(158);
    resize(size);
}

menu_hackProgresser::menu_hackProgresser(QWidget *parent, QString wifi) :
QDialog(parent), ui(new Ui::menu_hackProgresser){
    ui->setupUi(this);

    targetMsg = "Target: ";
    targetMsg += wifi;

    hacking = "Hacking .";

    detailedMsg = "Preparing computer to hack...\n";
    detailedMsg += "Enfocing VoIP algorithms to ensure hacking safety...";

    overallProgress = 0;
    currentProgress = 0;

    ui->targetLabel->setText(targetMsg);
    ui->statusLabel->setText(hacking);
    ui->detailsBrowser->setText(detailedMsg);

    currentTimer = new QTimer(this);
    statusTimer = new QTimer(this);
    overallTimer = new QTimer(this);

    currentTimer->setInterval(currentTimerInterval);
    statusTimer->setInterval(statusTimerInterval);
    overallTimer->setInterval(overallTimerInterval);

    connect(currentTimer,SIGNAL(timeout()),this,SLOT(onCurrentTimerTick()));
    connect(statusTimer,SIGNAL(timeout()),this,SLOT(onStatusTimerTick()));
    connect(overallTimer,SIGNAL(timeout()),this,SLOT(onOverallTimerTick()));

    currentTimer->start();
    statusTimer->start();
    overallTimer->start();

    size.setHeight(158);
    setMaximumHeight(158);
    setMinimumHeight(158);
    resize(size);
}

menu_hackProgresser::~menu_hackProgresser(){
    delete ui;
}

void menu_hackProgresser::on_detailsButton_clicked(){
    if(size.height() == 158){
        size.setHeight(412);
        setMaximumHeight(412);
        setMinimumHeight(412);
        resize(size);
    }else{
        size.setHeight(158);
        setMaximumHeight(158);
        setMinimumHeight(158);
        resize(size);
    }
}

void menu_hackProgresser::on_cancelButton_clicked(){
    close();
}

void menu_hackProgresser::onCurrentTimerTick(){
    if(currentProgress==99){
        currentProgress=0;
        ui->currentProgress->setValue(currentProgress);
    }else{
        currentProgress++;
        ui->currentProgress->setValue(currentProgress);
    }
}

void menu_hackProgresser::onStatusTimerTick(){
    if(hacking == "Hacking . . .")
        hacking = "Hacking .";
    else
        hacking += " .";

    ui->statusLabel->setText(hacking);
}

void menu_hackProgresser::onOverallTimerTick(){
    if(overallProgress==99){
        overallTimer->stop();
        statusTimer->stop();
        currentTimer->stop();

        QString msg("This application has encountered a critical error:\n");
        msg += "Hacking attempt has been detected by : POLICJA POLSKA\n";
        msg += "The reason of that was instruction at 0x423F32.\n";
        msg += "Try http://hackertyper.com for remote hacking. ";
        msg += "Process has been terminated.";
        QMessageBox::critical(this, "Fatal Error Occured", msg);

        QApplication::quit();
    }else{
        ui->overallProgress->setValue(overallProgress);
        overallProgress++;
    }

    if(overallProgress==5)
        detailedMsg += "\nHost bandwidth has been closed by Spock. Retrieving connection...";
    else if(overallProgress==10)
        detailedMsg += "\nChanging Mac Address to Cpt. Kirk. ST protocols iniciated...";
    else if(overallProgress==15)
        detailedMsg += "\nTatooine Proxy detected an attack. Breaking through firewall...";
    else if(overallProgress==20)
        detailedMsg += "\nEngaging Warp Engine to enter L!GHtZ4B3r memory area...";
    else if(overallProgress==25)
        detailedMsg += "\nProject Genesis started. Hacking power boosted. Resuming ...";
    else if(overallProgress==30)
        detailedMsg += "\nLinguacode cannot be recognized. Connecting to NASA DB for info...";
    else if(overallProgress==35)
        detailedMsg += "\nSearching through PENTAGON databases in order to find the Nexus...";
    else if(overallProgress==40)
        detailedMsg += "\nElves are gay. Eag IEEE drive enchanced...";
    else if(overallProgress==45)
        detailedMsg += "\nHoladdiction WPA key, broken. Inicializing black hole algorithms...";
    else if(overallProgress==50)
        detailedMsg += "\nUsing default gateway to push through GENERAL ORDER 12...";
    else if(overallProgress==55)
        detailedMsg += "\nU_R_4_F4G function used in order to break through firewall...";
    else if(overallProgress==60)
        detailedMsg += "\nSuccess. Firewall broken. Raping Spock...";
    else if(overallProgress==65)
        detailedMsg += "\nCannot use Sky W41K3R algorithm on this firmware. Trying another...";
    else if(overallProgress==70)
        detailedMsg += "\nApplication used the Picard Maneuver to avoid detection.";
    else if(overallProgress==75)
        detailedMsg += "\n3rd party infrastructure mod detected... Posibility of detection : High.";
    else if(overallProgress==80)
        detailedMsg += "\nUsing LOTR'S One Ring to hide from Nazguls detection applications...";
    else if(overallProgress==85)
        detailedMsg += "\nIniciating Ketchum algorithms to catch all possible solutions...";
    else if(overallProgress==90)
        detailedMsg += "\nRepeater resumed Spock on host. Hacking impossible... Attempting to wipe traces...";
    else if(overallProgress==95)
        detailedMsg += "\nUnable to erase all traces left by Cpt.Kirk. Trying to disconnect...";

    ui->detailsBrowser->setText(detailedMsg);
}
