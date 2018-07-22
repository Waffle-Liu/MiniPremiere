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
    CONFIG(release, debug|release):LIBS += -L$$PWD/../opencv/win32/lib/ -lopencv_world341

    INCLUDEPATH += $$PWD/../opencv/win32/include
    DEPENDPATH += $$PWD/../opencv/win32/include
}

CONFIG += c++14

SOURCES += \
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
    VIEWMODEL/prviewmodel.cpp \
    commands/cutvideocommand.cpp \
    commands/speedchangecommand.cpp \
    commands/removevideocommand.cpp \
    commands/selecteditvideocommand.cpp \
    commands/showeditwindowcommand.cpp \
    notification/showeditvideonotification.cpp \
    commands/integrateallvideocommand.cpp \
    commands/showintegratewindowcommand.cpp \
    common/FilterFunction.cpp \
    notification/showintegratewindownotification.cpp \
    commands/addsubtitlecommand.cpp \
    commands/addstickercommand.cpp \
    commands/mirrorcommand.cpp \
    commands/rotatecommand.cpp \
    commands/addfiltercommand.cpp \
    commands/funnycommand.cpp \
    commands/exportvideocommand.cpp \
    commands/transmodecommand.cpp

HEADERS  += \
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
    VIEWMODEL/prviewmodel.h \
    commands/cutvideocommand.h \
    commands/speedchangecommand.h \
    commands/removevideocommand.h \
    commands/selecteditvideocommand.h \
    commands/showeditwindowcommand.h \
    notification/showeditvideonotification.h \
    commands/integrateallvideocommand.h \
    commands/showintegratewindowcommand.h \
    common/FilterFunction.h \
    notification/showintegratewindownotification.h \
    commands/addsubtitlecommand.h \
    commands/addstickercommand.h \
    commands/mirrorcommand.h \
    commands/rotatecommand.h \
    commands/addfiltercommand.h \
    commands/funnycommand.h \
    commands/exportvideocommand.h \
    commands/transmodecommand.h

FORMS    += \
    VIEW/dialog_edit.ui \
    VIEW/dialog_integratedvideo.ui \
    VIEW/mainwindow.ui

RESOURCES += \
    resource.qrc
