#-------------------------------------------------
#
# Project created by QtCreator 2018-04-27T15:55:23
#
#-------------------------------------------------

QT       += core gui qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Puissance4QT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    jeu.cpp \
    joueur.cpp \
    partie.cpp \
    humain.cpp \
    ordi.cpp

CONFIG += debug_and_release c++11 c++14

HEADERS += \
        mainwindow.h \
    jeu.h \
    joueur.h \
    partie.h \
    humain.h \
    ordi.h \
    couleur.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    images.qrc

DISTFILES +=
