#-------------------------------------------------
#
# Project created by QtCreator 2022-07-16T08:13:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 01
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mypushbutton.cpp \
    choosescene.cpp \
    playscene.cpp \
    data.cpp \
    mylabel.cpp \
    towerbase.cpp \
    enemybase.cpp \
    bullet.cpp \
    defensetower1.cpp \
    defensetower2.cpp \
    enemy1.cpp \
    enemy2.cpp

HEADERS  += mainwindow.h \
    mypushbutton.h \
    choosescene.h \
    playscene.h \
    data.h \
    mylabel.h \
    towerbase.h \
    enemybase.h \
    bullet.h \
    defensetower1.h \
    defensetower2.h \
    enemy1.h \
    enemy2.h

FORMS    += mainwindow.ui
CONFIG   +=C++11

RESOURCES += \
    res.qrc
