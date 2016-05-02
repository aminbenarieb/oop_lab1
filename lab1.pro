#-------------------------------------------------
#
# Project created by QtCreator 2016-04-29T20:07:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    file.cpp \
    line.cpp \
    memory.cpp \
    model.cpp \
    handler.cpp \
    transform.cpp

HEADERS  += mainwindow.h \
    arguments.h \
    file.h \
    line.h \
    memory.h \
    model.h \
    handler.h \
    error.h \
    transform.h \
    point.h

FORMS    += mainwindow.ui
