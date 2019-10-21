#-------------------------------------------------
#
# Project created by QtCreator 2019-10-14T12:02:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WaitingLine
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Model/donnee.cpp \
    Model/probleme.cpp \
    Model/solution.cpp \
    calculation.cpp

HEADERS  += mainwindow.h \
    Model/donnee.h \
    Model/probleme.h \
    Model/solution.h \
    calculation.h

FORMS    += mainwindow.ui
