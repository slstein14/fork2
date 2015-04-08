#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T20:48:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SuperCop
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controls.cpp \
    contactus.cpp \
    highscores.cpp

HEADERS  += mainwindow.h \
    controls.h \
    contactus.h \
    highscores.h

FORMS    += mainwindow.ui \
    controls.ui \
    contactus.ui \
    highscores.ui
