#-------------------------------------------------
#
# Project created by QtCreator 2019-07-18T13:12:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = beatmouce
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myscene.cpp \
    pictureitem.cpp \
    hander.cpp

HEADERS  += mainwindow.h \
    myscene.h \
    pictureitem.h \
    hander.h

FORMS    += mainwindow.ui

RESOURCES += \
    icon.qrc
