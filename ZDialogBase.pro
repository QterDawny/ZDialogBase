#-------------------------------------------------
#
# Project created by QtCreator 2015-04-09T22:12:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZDialogBase
TEMPLATE = app


SOURCES += main.cpp\
        zdialogbase.cpp \
    dialogtest.cpp

HEADERS  += zdialogbase.h \
    dialogtest.h

FORMS    += zdialogbase.ui \
    dialogtest.ui

RESOURCES += \
    images.qrc
