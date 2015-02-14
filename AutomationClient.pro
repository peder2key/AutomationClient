#-------------------------------------------------
#
# Project created by QtCreator 2015-02-04T22:57:07
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AutomationClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpmanger.cpp \
    setuptcpdialog.cpp

HEADERS  += mainwindow.h \
    tcpmanger.h \
    setuptcpdialog.h

FORMS    += mainwindow.ui \
    setuptcpdialog.ui
