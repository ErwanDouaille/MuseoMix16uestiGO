QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = uestiGO
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/../include
DEPENDPATH += $$PWD/../include

SOURCES += main.cpp \
    mainwindow.cpp \
    digitalclock.cpp

HEADERS += \
    mainwindow.h \
    digitalclock.h

win32:RC_ICONS += $$PWD/../files/ico.ico
