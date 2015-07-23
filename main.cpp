#include "menu_main.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu_main mainMenu;
    mainMenu.show();
    return a.exec();
}
