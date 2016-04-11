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
    qpaintwidget.cpp \
    steamhandler.cpp \
    errorinfo.cpp \
    scenehandler.cpp \
    modelhandler.cpp \
    canvashandler.cpp \
    filehandler.cpp \
    fileloader.cpp \
    datahandler.cpp

HEADERS  += mainwindow.h \
    config.h \
    handler.h \
    qpaintwidget.h \
    steamhandler.h \
    errorinfo.h \
    scenehandler.h \
    modelhandler.h \
    canvashandler.h \
    filehandler.h \
    fileloader.h \
    modeldata.h \
    datahandler.h

FORMS += \
    mainwindow.ui
