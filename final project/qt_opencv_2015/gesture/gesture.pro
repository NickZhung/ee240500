TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

CONFIG += no_keywords # Python redefines some qt keywords
INCLUDEPATH += /usr/include/python2.7
LIBS += -lpython2.7

QT += widgets
