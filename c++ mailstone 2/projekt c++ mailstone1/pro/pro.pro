#-------------------------------------------------
#
# Project created by QtCreator 2016-05-30T22:28:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pro
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    health.cpp \
    score.cpp \
    enemy.cpp \
    player.cpp \
    bullet.cpp \
    button.cpp

HEADERS  += \
    game.h \
    health.h \
    score.h \
    enemy.h \
    player.h \
    bullet.h \
    button.h \
    bonus.h

FORMS    += mainwindow.ui
