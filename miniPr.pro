#-------------------------------------------------
#
# Project created by QtCreator 2018-07-21T20:58:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = miniPr
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32{
    CONFIG(debug, debug|release):LIBS += -L$$PWD/../opencv/win32/lib/ -lopencv_world341d
    CONFIG(release, debug|release):LIBS += -L$$PWD/../opencv/win32/lib/ -lopencv_world341d
    
    INCLUDEPATH += $$PWD/../opencv/win32/include
    DEPENDPATH += $$PWD/../opencv/win32/include
}

CONFIG += c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    APP/app.cpp \
    APP/main.cpp \
    commands/addvideocommand.cpp \
    commands/playvideocommand.cpp \
    common/command.cpp \
    common/Video.cpp \
    common/windowSize.cpp \
    MODEL/prmodel.cpp \
    notification/notification.cpp \
    notification/wrongindexnotification.cpp \
    Parameters/parameters.cpp \
    VIEW/dialog_edit.cpp \
    VIEW/dialog_integratedvideo.cpp \
    VIEW/mainwindow.cpp \
    VIEWMODEL/prviewmodel.cpp

HEADERS  += mainwindow.h \
    APP/app.h \
    commands/addvideocommand.h \
    commands/playvideocommand.h \
    common/command.h \
    common/stdafx.h \
    common/Video.h \
    common/windowSize.h \
    MODEL/prmodel.h \
    notification/notification.h \
    notification/wrongindexnotification.h \
    Parameters/parameters.h \
    VIEW/dialog_edit.h \
    VIEW/dialog_integratedvideo.h \
    VIEW/mainwindow.h \
    VIEWMODEL/prviewmodel.h

FORMS    += mainwindow.ui \
    VIEW/dialog_edit.ui \
    VIEW/dialog_integratedvideo.ui \
    VIEW/mainwindow.ui
