#ifndef MENU_MAIN_H
#define MENU_MAIN_H

#include <QDialog>

namespace Ui {
class menu_main;
}

class menu_main : public QDialog
{
    Q_OBJECT

public:
    explicit menu_main(QWidget *parent = 0);
    ~menu_main();

private slots:
    void on_diagnoseButton_clicked();
    void on_repairSystemButton_clicked();
    void on_repairInternetButton_clicked();
    void on_retrieveDataButton_clicked();
    void on_hackButton_clicked();
    void on_quitButton_clicked();
    void on_fixPrinterButton_clicked();
    void on_eraseVirusesButton_clicked();

private:
    Ui::menu_main *ui;
};

#endif
