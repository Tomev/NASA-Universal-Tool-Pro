#include "menu_repairInternet.h"
#include "ui_menu_repairInternet.h"

#include <QMessageBox>

menu_repairInternet::menu_repairInternet(QWidget *parent) :
QDialog(parent), ui(new Ui::menu_repairInternet){
    ui->setupUi(this);
    ui->detailsButton->hide();

    currentProgress = 0;
    overallProgress = 0;
    repairMsg = "Repairing .";
    detailedMsg = "Preparing to work...";

    size.setHeight(145);
    setMaximumHeight(145);
    setMinimumHeight(145);
    resize(size);
}

menu_repairInternet::~menu_repairInternet(){
    delete ui;
}

void menu_repairInternet::on_startButton_clicked(){
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
    detailedMsg += "\nImprinring JeDI PHP signature...";
    ui->detailsBrowser->setText(detailedMsg);
}

void menu_repairInternet::on_detailsButton_clicked(){
    if(size.height()==145){
        size.setHeight(355);
        setMaximumHeight(355);
        setMinimumHeight(355);
        resize(size);
    }else{
        size.setHeight(145);
        setMaximumHeight(145);
        setMinimumHeight(145);
        resize(size);
    }
}

void menu_repairInternet::on_cancelButton_clicked(){
    close();
}

void menu_repairInternet::onOverallTimerTick(){
    if(overallProgress==99){
        overallTimer->stop();
        statusTimer->stop();
        currentTimer->stop();

        QString msg("Fatal error: c23ce3234 line:8, column:12 has occured.\n");
        msg += "The program will now shut. Operations may have to be redone.";
        QMessageBox::critical(this, "Fatal Error Occured", msg);

        QApplication::quit();
    }else{
        ui->overallProgress->setValue(overallProgress);
        overallProgress++;
    }

    if(overallProgress==5)
        detailedMsg += "\nAscending ASCII code formatting...";
    else if(overallProgress==10)
        detailedMsg += "\nFortifying ARPANet detailed info status...";
    else if(overallProgress==15)
        detailedMsg += "\nUpdating HTML Hypertext standard to Leased Line MUSE prototype...";
    else if(overallProgress==20)
        detailedMsg += "\nSearching for PSTN Protocol to find Intranet IP Number...";
    else if(overallProgress==25)
        detailedMsg += "\nListserv is currently occupied. Searching for new list using AJAX...";
    else if(overallProgress==30)
        detailedMsg += "\nNeed more Open Source Programs to find errors. \nConnecting to NASA DB to download them...";
    else if(overallProgress==35)
        detailedMsg += "\nSecurity Certificate is out of date. Installing new one...";
    else if(overallProgress==40)
        detailedMsg += "\nSEO Telnet is missing. Rewriting none of them...";
    else if(overallProgress==45)
        detailedMsg += "\nSome crazy shit is going on with Unix Tag and VPN. Resuming...";
    else if(overallProgress==50)
        detailedMsg += "\nGamma rays in graphics card influented internet card port. Fixing...";
    else if(overallProgress==55)
        detailedMsg += "\nUnable to connect WAIS. Trying to force push new JEDI...";
    else if(overallProgress==60)
        detailedMsg += "\nNERD and GEEK are broken. Need new Hashtag to continue... Downloading...";
    else if(overallProgress==65)
        detailedMsg += "\nYODA'S MIND TRICK is not working. Finding new JEDI MASTER SLAVE to proceed...";
    else if(overallProgress==70)
        detailedMsg += "\n99% of your PC data has been erased... Proceeding...";
    else if(overallProgress==75)
        detailedMsg += "\nInstalling Google Ultron and new Adobe...";
    else if(overallProgress==80)
        detailedMsg += "\nObi1 has been terminated by Virus V4D3R. Training LuKe...";
    else if(overallProgress==85)
        detailedMsg += "\nC3PO and R2D2 are currently out of date... Fixing...";
    else if(overallProgress==90)
        detailedMsg += "\nPalpatine and Vindu plug-ins are jammed. Unjamming...";
    else if(overallProgress==95)
        detailedMsg += "\nPreparing for 'Return of the Jedi'...";

    ui->detailsBrowser->setText(detailedMsg);
}

void menu_repairInternet::onStatusTimerTick(){
    if(repairMsg == "Repairing . . .")
        repairMsg = "Repairing";
    else
        repairMsg += " .";

    ui->statusLabel->setText(repairMsg);
}

void menu_repairInternet::onCurrentTimerTick(){
    if(currentProgress==99){
        currentProgress=0;
        ui->currentProgress->setValue(currentProgress);
    }else{
        currentProgress++;
        ui->currentProgress->setValue(currentProgress);
    }
}
