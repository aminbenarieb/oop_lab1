#-------------------------------------------------
#
# Project created by QtCreator 2016-03-27T21:07:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    handler.cpp \
    qpaintwidget.cpp

HEADERS  += mainwindow.h \
    config.h \
    handler.h \
    qpaintwidget.h

FORMS += \
    mainwindow.ui
