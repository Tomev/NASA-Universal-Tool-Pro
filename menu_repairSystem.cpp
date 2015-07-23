#include "menu_repairSystem.h"
#include "ui_menu_repairSystem.h"

menu_repairSystem::menu_repairSystem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_repairSystem)
{
    ui->setupUi(this);
}

menu_repairSystem::~menu_repairSystem()
{
    delete ui;
}
