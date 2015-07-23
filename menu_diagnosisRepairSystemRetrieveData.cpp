#include "menu_diagnosisRepairSystemRetrieveData.h"
#include "ui_menu_diagnosisRepairSystemRetrieveData.h"

#include <QDebug>
#include <QMessageBox>

void menu_diagnosisRepairSystemRetrieveData::fillVirusesList(){
    viruses     << "trojan.cell32"
                << "cymbalEXE"
                << "frieza.exploit32"
                << "android18.dir"
                << "veget.A"
                << "worm.saibaMan"
                << "logicBomb.Dodoria"
                << "trojanWHor(s)e.emperorPilaf"
                << "Zarbon.namekInvader"
                << "babidi.1563";
}

void menu_diagnosisRepairSystemRetrieveData::defineVariables(int i){
    QDir helper;

    currentProgress = 0;
    overallProgress = 0;
    driveCounter = 0;

    if(i<1 && i>4)
        applicationType = 1;
    else
        applicationType = i;

    detailedMsg = "Preparing to work...";

    foreach(QFileInfo drive, helper.drives()){
        drives << drive.absoluteFilePath();
    }

    size.setWidth(332);
    size.setHeight(182);
    setMaximumHeight(182);
    setMinimumHeight(182);
}

void menu_diagnosisRepairSystemRetrieveData::updateDiagnosisMessage(){
    if(overallProgress==5)
        detailedMsg += "Checking if internet speed is working at it's full potential...\n";
    else if(overallProgress==10)
        detailedMsg += "Unloading FTL for further diagnosis...\n";
    else if(overallProgress==15)
        detailedMsg += "Looking for doctor...\n";
    else if(overallProgress==20)
        detailedMsg += "Writing prescription...\n";
    else if(overallProgress==25)
        detailedMsg += "Waiting in line to computer hospital...\n";
    else if(overallProgress==30)
        detailedMsg += "All doctors are currently striking... Waiting till strike is over...\n";
    else if(overallProgress==35)
        detailedMsg += "Strikes are over... Just as working hours... I'll try again in a while...\n";
    else if(overallProgress==40)
        detailedMsg += "Using Vite Minas to ensure computers health...\n";
    else if(overallProgress==45)
        detailedMsg += "Your PC suffers from hyperviteminasation. Use some repair tool...\n";
    else if(overallProgress==50)
        detailedMsg += "There is problem in 10111010011000 memory segment...\n";
    else if(overallProgress==55)
        detailedMsg += "Casting LIBR4 to find PC weaknesses..\n";
    else if(overallProgress==60)
        detailedMsg += "Computer H!T Pnts are low. Repair must be done.\n";
    else if(overallProgress==65)
        detailedMsg += "JVR3K is stealing t3NT N4ils... Sth must be done about it.\n";
    else if(overallProgress==70)
        detailedMsg += "Computer work is slowed down by coughing. CPU FLU detected...\n";
    else if(overallProgress==75)
        detailedMsg += "Windows segment has a little space. Computer work is slowed down.\n";
    else if(overallProgress==80)
        detailedMsg += "Your mouse model is not compatible with your CPU. That can cause problems.\n";
    else if(overallProgress==85)
        detailedMsg += "Your keyboard keys are dirty. They might get stuck.\n";
    else if(overallProgress==90)
        detailedMsg += "6174!\n";
    else if(overallProgress==95)
        detailedMsg += "An massive infection found... Diagnosing...\n";
}

void menu_diagnosisRepairSystemRetrieveData::updateRepairMessage(){
    if(overallProgress==5)
        detailedMsg += "Tightening all the screws...\n";
    else if(overallProgress==10)
        detailedMsg += "Cleaning all devices...\n";
    else if(overallProgress==15)
        detailedMsg += "RAM shall be erased after reboot...\n";
    else if(overallProgress==20)
        detailedMsg += "Cleaning CPU memory...\n";
    else if(overallProgress==25)
        detailedMsg += "Speeding up internet...\n";
    else if(overallProgress==30)
        detailedMsg += "Downloading new drivers...\n";
    else if(overallProgress==35)
        detailedMsg += "Updating certificates...\n";
    else if(overallProgress==40)
        detailedMsg += "Testing all the devices...\n";
    else if(overallProgress==45)
        detailedMsg += "Repairing CD/DVD drive...\n";
    else if(overallProgress==50)
        detailedMsg += "Plugging all unplugged plug-ins.\n";
    else if(overallProgress==55)
        detailedMsg += "C0FF33 break...\n";
    else if(overallProgress==60)
        detailedMsg += "Installing new applications...\n";
    else if(overallProgress==65)
        detailedMsg += "Decoding coded data...\n";
    else if(overallProgress==70)
        detailedMsg += "Erasing unneeded data...\n";
    else if(overallProgress==75)
        detailedMsg += "Finding hidden objects...\n";
    else if(overallProgress==80)
        detailedMsg += "Loosing mouse scroll...\n";
    else if(overallProgress==85)
        detailedMsg += "Wiping display...\n";
    else if(overallProgress==90)
        detailedMsg += "Accelerating graphic card...\n";
    else if(overallProgress==95)
        detailedMsg += "Repairing an complex problem...\n";
}

void menu_diagnosisRepairSystemRetrieveData::updateRetrieveMessage(){
    if(overallProgress==5)
        detailedMsg += "Retreiving data deleted from Recycle Bin...\n";
    else if(overallProgress==10)
        detailedMsg += "Returning moved data to original places...\n";
    else if(overallProgress==15)
        detailedMsg += "Scanning peripherals in order to find copies of erased data...\n";
    else if(overallProgress==20)
        detailedMsg += "Gaining access to L33T.ini...\n";
    else if(overallProgress==25)
        detailedMsg += "Wow! Much data found! Such skill...\n";
    else if(overallProgress==30)
        detailedMsg += "Restoring formated data...\n";
    else if(overallProgress==35)
        detailedMsg += "Attempting to retrive 10 times deleted data...\n";
    else if(overallProgress==40)
        detailedMsg += "My power is overhelming your PC... Arise my Zombie army!\n";
    else if(overallProgress==45)
        detailedMsg += "Found old version of Windows. Restoring missing data...\n";
    else if(overallProgress==50)
        detailedMsg += "Scanning CPU and GPU memory in search for missing data...\n";
    else if(overallProgress==55)
        detailedMsg += "Opening treasure chest of data!\n";
    else if(overallProgress==60)
        detailedMsg += "Digital key to missing data is lost. Searching...\n";
    else if(overallProgress==65)
        detailedMsg += "Looking for lost data in the internet...\n";
    else if(overallProgress==70)
        detailedMsg += "Scanning lan in search for missing data...\n";
    else if(overallProgress==75)
        detailedMsg += "Gaining 4rc4n3 power...\n";
    else if(overallProgress==80)
        detailedMsg += "0SM_D3V iniciatet... Indicatin proQuo status...\n";
    else if(overallProgress==85)
        detailedMsg += "Engaging new measures...\n";
    else if(overallProgress==90)
        detailedMsg += "Program functions cannot be used any more, because of lost dlls. \n";
    else if(overallProgress==95)
        detailedMsg += "Trying to retrive lost dlls...\n";
}

void menu_diagnosisRepairSystemRetrieveData::updateEraseMessage(){
    if(overallProgress==5){
        qsrand(qrand());
        int virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";

        virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";

        virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";
    }
    else if(overallProgress==10)
        detailedMsg += "N4m3k driver is highly probable to get inffected. Sending G0q...\n";
    else if(overallProgress==15){
        qsrand(qrand());
        int virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";

        virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";
    }
    else if(overallProgress==20)
        detailedMsg += "Forming special Z Team for better Virus erasing...\n";
    else if(overallProgress==25)
        detailedMsg += "Training application at R0M-o-SprtTm to speed up the processes...\n";
    else if(overallProgress==30){
        qsrand(qrand());
        int virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";

        virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";

        virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";

        virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";
    }
    else if(overallProgress==35)
        detailedMsg += "PC is highly infected. This may slow down application executing time...\n";
    else if(overallProgress==40)
        detailedMsg += "Sending V3G3T4 to delay inffection spread.\n";
    else if(overallProgress==45)
        detailedMsg += "V3G3T4 ceased to work.\n";
    else if(overallProgress==50){
        qsrand(qrand());
        int virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";

        virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";

        virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";
    }
    else if(overallProgress==55)
        detailedMsg += "Krillan.exe was terminated.\n";
    else if(overallProgress==60)
        detailedMsg += "Engaging SSJ mode for more efficient viruses erasing...\n";
    else if(overallProgress==65)
        detailedMsg += "H3LL gates has been opened. Trying to \n";
    else if(overallProgress==70)
        detailedMsg += "SSJ2 mode iniciated. Virus eradiction is nearing...\n";
    else if(overallProgress==75){
        qsrand(qrand());
        int virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";

        virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";

        virusNumber = qrand() % 10;
        detailedMsg += QString("Found a virus: %1 at %2! Attempting to cure...\n")
                       .arg(viruses.at(virusNumber))
                       .arg(iterator->path());
        detailedMsg += "Virus cured!\n";
    }
    else if(overallProgress==80)
        detailedMsg += "Erasing all other viruses...\n";
    else if(overallProgress==85)
        detailedMsg += "Gathering power from all PC components...\n";
    else if(overallProgress==90)
        detailedMsg += "Using G3NKI D4M4 algorithms to enpower application work.\n";
    else if(overallProgress==95)
        detailedMsg += "An inffection is trying to take over program... Engaging counter means...\n";
}

void menu_diagnosisRepairSystemRetrieveData::updateDetailsMessage(){
    if(applicationType == 1)
        updateDiagnosisMessage();
    else if(applicationType == 2)
        updateRepairMessage();
    else if(applicationType == 3)
        updateRetrieveMessage();
    else if(applicationType == 4)
        updateEraseMessage();
    else{
        QString msg("An unacceptable error has occured. The program will now shut.");
        QMessageBox::critical(this, "Fatal Error Occured", msg);
        QApplication::quit();
    }
}

menu_diagnosisRepairSystemRetrieveData::menu_diagnosisRepairSystemRetrieveData(QWidget *parent) :
QDialog(parent), ui(new Ui::menu_diagnosisRepairSystemRetrieveData){
    ui->setupUi(this);
    ui->detailsButton->hide();

    QString title;
    QString msg;

    title = "NASA PC Synergist Ultra v. 3.00";
    msg = "Would you like to start diagnosing your PC?";
    repairMsg = "Diagnosing .";

    defineVariables();
    fillVirusesList();

    setWindowTitle(title);
    ui->statusDirLabel->setText(msg);
    this->resize(size);
}

menu_diagnosisRepairSystemRetrieveData::menu_diagnosisRepairSystemRetrieveData(int i) :
ui(new Ui::menu_diagnosisRepairSystemRetrieveData){
    ui->setupUi(this);
    ui->detailsButton->hide();
    ui->statusDirLabel->setWordWrap(true);

    QString title;
    QString msg;

    defineVariables(i);

    if(applicationType == 1){
        title = "NASA PC Synergist Ultra v. 3.00";
        msg = "Would you like to start diagnosing your PC?";
        repairMsg = "Diagnosing .";
        fillVirusesList();
    }else if(applicationType == 2){
        title = "NASA Hyper Disk Medic Gamma";
        msg = "Would you like to start repairing your PC?";
        repairMsg = "Repairing .";
    }else if(applicationType == 3){
        title = "NASA Ultimate Data Ravager Pro v. 5.67";
        msg = "Would you like to start retrieving lost data?";
        repairMsg = "Retrieving .";
    }else if(applicationType == 4){
        title = "NASA Saiyan Power PC Commando";
        msg = "Would you like to start erasing viruses from your PC?";
        repairMsg = "Erasing .";
        fillVirusesList();
    }

    setWindowTitle(title);
    ui->statusDirLabel->setText(msg);
    this->resize(size);
}

menu_diagnosisRepairSystemRetrieveData::~menu_diagnosisRepairSystemRetrieveData(){
    delete ui;
}

void menu_diagnosisRepairSystemRetrieveData::on_startButton_clicked(){
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

    ui->statusDirLabel->setText(repairMsg);
    ui->startButton->hide();
    ui->detailsButton->show();
    detailedMsg += "\n";
    ui->detailsBrowser->setText(detailedMsg);

    QString parentFolder(drives.at(driveCounter++));
    iterator = new QDirIterator(parentFolder, QDir::Files | QDir::Dirs
                               | QDir::NoSymLinks | QDir::NoDotAndDotDot,
                               QDirIterator::Subdirectories);
}

void menu_diagnosisRepairSystemRetrieveData::on_detailsButton_clicked(){
    if(size.height() == 182){
        size.setHeight(400);
        setMaximumHeight(400);
        setMinimumHeight(400);
        resize(size);
    }else{
        size.setHeight(182);
        setMaximumHeight(182);
        setMinimumHeight(182);
        resize(size);
    }
}

void menu_diagnosisRepairSystemRetrieveData::on_cancelButton_clicked(){
    close();
}

void menu_diagnosisRepairSystemRetrieveData::onCurrentTimerTick(){
    if(currentProgress==99){
        currentProgress=0;
        ui->currentProgress->setValue(currentProgress);
    }else{
        currentProgress++;
        ui->currentProgress->setValue(currentProgress);
    }

    if(iterator->hasNext()){
        iterator->next();
        ui->statusDirLabel->setText(iterator->filePath());
    }else{
        if(driveCounter > drives.size()){
            driveCounter = 0;
        }
        QString parentFolder(drives.at(driveCounter++));
        iterator = new QDirIterator(parentFolder, QDir::Files | QDir::Dirs
                                   | QDir::NoSymLinks | QDir::NoDotAndDotDot,
                                   QDirIterator::Subdirectories);
    }
}

void menu_diagnosisRepairSystemRetrieveData::onStatusTimerTick(){
    if(applicationType == 1){
        if(repairMsg == "Diagnosing . . .")
            repairMsg = "Diagnosing";
        else
            repairMsg += " .";
    }else if(applicationType == 2){
        if(repairMsg == "Repairing . . .")
            repairMsg = "Repairing";
        else
            repairMsg += " .";
    }else if(applicationType == 3){
        if(repairMsg == "Retrieving . . .")
            repairMsg = "Retrieving";
        else
            repairMsg += " .";
    }else if(applicationType == 4){
        if(repairMsg == "Erasing . . .")
            repairMsg = "Erasing";
        else
            repairMsg += " .";
    }
    ui->statusLabel->setText(repairMsg);
}

void menu_diagnosisRepairSystemRetrieveData::onOverallTimerTick(){
    if(overallProgress==99){
        QString msg("");
        overallTimer->stop();
        statusTimer->stop();
        currentTimer->stop();

        if(applicationType == 1){
            msg += "Infection proved to be extremely complicated. Computer may need to be formated.";
            msg += "\nDiagnosis could not be finished.";
        }else if(applicationType == 2){
            msg += "Problem proved to be extremely complicated. Sending problem data to NASA in order";
            msg += " to find the solution. Try again after upgrading program.";
            msg += "\nRepairing could not be finished.";
        }else if(applicationType == 3){
            msg += "Due to lack of uRStpd.dll and turboF4G.dll retreiving could not be finished.\n";
            msg += "Changes will be reversed and application will now shut.";
        }else if(applicationType == 4){
            msg += "Virus has taken over the application! Unable to continue...\n";
            msg += "Computer should be reboot as fast as possible to avoid further damage.\n";
            msg += "Application will now be terminated...";
        }

        QMessageBox::critical(this, "Fatal Error Occured", msg);
        QApplication::quit();
    }else{
        ui->overallProgress->setValue(overallProgress);
        overallProgress++;
    }


    updateDetailsMessage();

    ui->detailsBrowser->setText(detailedMsg);
}
