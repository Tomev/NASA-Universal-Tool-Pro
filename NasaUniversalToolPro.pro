#-------------------------------------------------
#
# Project created by QtCreator 2014-07-19T16:51:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NasaUniversalToolPro
TEMPLATE = app


SOURCES += main.cpp\
    menu_main.cpp \
    menu_repairInternet.cpp \
    menu_hackWiFi.cpp \
    menu_diagnosisRepairSystemRetrieveData.cpp \
    menu_hackProgresser.cpp \
    menu_fixPrinter.cpp

HEADERS  += \
    menu_main.h \
    menu_repairInternet.h \
    menu_hackWiFi.h \
    menu_diagnosisRepairSystemRetrieveData.h \
    menu_hackProgresser.h \
    menu_fixPrinter.h

FORMS    += \
    menu_main.ui \
    menu_repairInternet.ui \
    menu_hackWiFi.ui \
    menu_diagnosisRepairSystemRetrieveData.ui \
    menu_hackProgresser.ui \
    menu_fixPrinter.ui

CONFIG += static
