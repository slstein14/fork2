#-------------------------------------------------
#
# Project created by QtCreator 2015-04-07T20:48:38
#
#-------------------------------------------------

QT       += core gui quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SuperCop
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controls.cpp \
    contactus.cpp \
    highscores.cpp \
    supercop_game.cpp

HEADERS  += mainwindow.h \
    controls.h \
    contactus.h \
    highscores.h \
    supercop_game.h

FORMS    += mainwindow.ui \
    controls.ui \
    contactus.ui \
    highscores.ui \
    supercop_game.ui

DISTFILES += \
    CopRollAnim.qml \
    CopRunAnim.qml
