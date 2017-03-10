QT += core
QT -= gui

CONFIG += c++14

TARGET = Observer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    event.cpp \
    event_manager.cpp

HEADERS += \
    event.h \
    event_manager.h \
    event_listener.h
