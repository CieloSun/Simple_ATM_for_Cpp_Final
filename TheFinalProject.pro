#-------------------------------------------------
#
# Project created by QtCreator 2015-06-04T19:53:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TheFinalProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Account.cpp \
    DeadAccount.cpp \
    Manage.cpp \
    SavingAccount.cpp \
    foradministor.cpp \
    accountdialog.cpp \
    adminenterdialog.cpp \
    adminmanagedialog.cpp \
    interestsetting.cpp

HEADERS  += mainwindow.h \
    Account.h \
    Manage.h \
    SavingAccount.h \
    DeadAccount.h \
    accountdialog.h \
    adminenterdialog.h \
    toolneed.h \
    adminmanagedialog.h \
    interestsetting.h

FORMS    += mainwindow.ui \
    adminenterdialog.ui \
    accountdialog.ui \
    adminmanagedialog.ui \
    interestsetting.ui
CONFIG   += c++11

RESOURCES += \
    res.qrc
