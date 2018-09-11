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
    VIEWMODEL/commands/addvideocommand.cpp \
    VIEWMODEL/commands/playvideocommand.cpp \
    common/command.cpp \
    common/Video.cpp \
    common/windowSize.cpp \
    MODEL/prmodel.cpp \
    VIEWMODEL/notification/notification.cpp \
    VIEWMODEL/notification/wrongindexnotification.cpp \
    Parameters/parameters.cpp \
    VIEW/dialog_edit.cpp \
    VIEW/dialog_integratedvideo.cpp \
    VIEW/mainwindow.cpp \
    VIEWMODEL/prviewmodel.cpp \
    VIEWMODEL/commands/cutvideocommand.cpp \
    VIEWMODEL/commands/speedchangecommand.cpp \
    VIEWMODEL/commands/removevideocommand.cpp \
    VIEWMODEL/commands/selecteditvideocommand.cpp \
    VIEWMODEL/commands/showeditwindowcommand.cpp \
    VIEWMODEL/notification/showeditvideonotification.cpp \
    VIEWMODEL/commands/integrateallvideocommand.cpp \
    VIEWMODEL/commands/showintegratewindowcommand.cpp \
    common/FilterFunction.cpp \
    VIEWMODEL/notification/showintegratewindownotification.cpp \
    VIEWMODEL/commands/addsubtitlecommand.cpp \
    VIEWMODEL/commands/addstickercommand.cpp \
    VIEWMODEL/commands/mirrorcommand.cpp \
    VIEWMODEL/commands/rotatecommand.cpp \
    VIEWMODEL/commands/addfiltercommand.cpp \
    VIEWMODEL/commands/funnycommand.cpp \
    VIEWMODEL/commands/exportvideocommand.cpp \
    VIEWMODEL/commands/transmodecommand.cpp

HEADERS  += \
    APP/app.h \
    VIEWMODEL/commands/addvideocommand.h \
    VIEWMODEL/commands/playvideocommand.h \
    common/command.h \
    common/stdafx.h \
    common/Video.h \
    common/windowSize.h \
    MODEL/prmodel.h \
    VIEWMODEL/notification/notification.h \
    VIEWMODEL/notification/wrongindexnotification.h \
    Parameters/parameters.h \
    VIEW/dialog_edit.h \
    VIEW/dialog_integratedvideo.h \
    VIEW/mainwindow.h \
    VIEWMODEL/prviewmodel.h \
    VIEWMODEL/commands/cutvideocommand.h \
    VIEWMODEL/commands/speedchangecommand.h \
    VIEWMODEL/commands/removevideocommand.h \
    VIEWMODEL/commands/selecteditvideocommand.h \
    VIEWMODEL/commands/showeditwindowcommand.h \
    VIEWMODEL/notification/showeditvideonotification.h \
    VIEWMODEL/commands/integrateallvideocommand.h \
    VIEWMODEL/commands/showintegratewindowcommand.h \
    common/FilterFunction.h \
    VIEWMODEL/notification/showintegratewindownotification.h \
    VIEWMODEL/commands/addsubtitlecommand.h \
    VIEWMODEL/commands/addstickercommand.h \
    VIEWMODEL/commands/mirrorcommand.h \
    VIEWMODEL/commands/rotatecommand.h \
    VIEWMODEL/commands/addfiltercommand.h \
    VIEWMODEL/commands/funnycommand.h \
    VIEWMODEL/commands/exportvideocommand.h \
    VIEWMODEL/commands/transmodecommand.h

FORMS    += \
    VIEW/dialog_edit.ui \
    VIEW/dialog_integratedvideo.ui \
    VIEW/mainwindow.ui

RESOURCES += \
    resource.qrc
