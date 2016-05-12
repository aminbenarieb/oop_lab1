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
    model.cpp \
    handler.cpp \
    transform.cpp \
    draw.cpp \
    point.cpp \
    edge.cpp \
    stream.cpp

HEADERS  += mainwindow.h \
    file.h \
    model.h \
    handler.h \
    error.h \
    transform.h \
    point.h \
    edge.h \
    draw.h \
    stream.h

FORMS    += mainwindow.ui
