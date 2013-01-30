#-------------------------------------------------
#
# Project created by QtCreator 2013-01-30T00:07:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GS2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    colorpop.cpp

HEADERS  += mainwindow.h \
    colorpop.h

FORMS    += mainwindow.ui

unix|win32: LIBS += -lMagick++
INCLUDEPATH += /usr/include/ImageMagick
QMAKE_LFLAGS += -O3

