#-------------------------------------------------
#
# Project created by QtCreator 2016-06-19T11:32:51
#
#-------------------------------------------------

QT     += gui KRunner KCoreAddons KConfigCore KService

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = MyTestRunner
TEMPLATE = lib

DEFINES += MYTESTRUNNER_LIBRARY

SOURCES += mytestrunner.cpp

HEADERS += mytestrunner.h\
        mytestrunner_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += /usr/include/KF5

DISTFILES += \
    plasma-runner-mytestrunner.desktop
