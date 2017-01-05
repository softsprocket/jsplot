#-------------------------------------------------
#
# Project created by QtCreator 2016-12-30T07:44:10
#
#-------------------------------------------------

QT       += core gui qml

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jsplot
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    graphdisplaywidget.cpp \
    debugoutputdialog.cpp \
    tabbedjseditor.cpp \
    jstextedit.cpp \
    graphdisplaydialog.cpp

HEADERS  += mainwindow.h \
    graphdisplaywidget.h \
    debugoutputdialog.h \
    tabbedjseditor.h \
    jstextedit.h \
    graphdisplaydialog.h
