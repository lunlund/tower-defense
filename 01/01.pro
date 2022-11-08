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
    enemy2.cpp \
    plants.cpp \
    plant1.cpp \
    plant2.cpp

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
    enemy2.h \
    plants.h \
    plant1.h \
    plant2.h

FORMS    += mainwindow.ui
CONFIG   +=C++11

RESOURCES += \
    res.qrc

OTHER_FILES += \
    ../game/SnowPea_0.png \
    ../game/SnowPea_1.png \
    ../game/SnowPea_2.png \
    ../game/SnowPea_3.png \
    ../game/SnowPea_4.png \
    ../game/SnowPea_5.png \
    ../game/SnowPea_6.png \
    ../game/SnowPea_7.png \
    ../game/SnowPea_8.png \
    ../game/SnowPea_9.png \
    ../game/SnowPea_10.png \
    ../game/SnowPea_11.png \
    ../game/SnowPea_12.png \
    ../game/SnowPea_13.png \
    ../game/SnowPea_14.png \
    ../game/PeaIce_0.png
