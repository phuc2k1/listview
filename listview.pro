#-------------------------------------------------
#
# Project created by QtCreator 2023-04-10T11:07:11
#
#-------------------------------------------------

QT       += core gui  network
LIBS += -lwiringPi
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = listview
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    debuglogger.cpp \
    classservo.cpp \
    classrobot.cpp \
    readdata.cpp \
    classfirebase.cpp \
    checkdata.cpp

HEADERS += \
        mainwindow.h \
    debuglogger.h \
    classservo.h \
    classrobot.h \
    readdata.h \
    classfirebase.h \
    checkdata.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    data.txt
