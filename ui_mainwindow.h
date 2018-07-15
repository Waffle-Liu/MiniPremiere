/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *AddMedia;
    QPushButton *DeleteMedia;
    QPushButton *DeleteAllMedia;
    QGraphicsView *graphicsView;
    QFrame *line;
    QFrame *line_2;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView_3;
    QGraphicsView *graphicsView_4;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QGraphicsView *graphicsView_5;
    QGraphicsView *graphicsView_6;
    QGraphicsView *graphicsView_7;
    QLabel *label_7;
    QPushButton *integrationDone;
    QPushButton *mediaOne;
    QPushButton *mediaThree;
    QPushButton *mediaTwo;
    QPushButton *mediaFour;
    QPushButton *mediaFive;
    QPushButton *mediaSix;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(742, 490);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AddMedia = new QPushButton(centralWidget);
        AddMedia->setObjectName(QStringLiteral("AddMedia"));
        AddMedia->setGeometry(QRect(10, 50, 75, 23));
        AddMedia->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/button1.png);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        DeleteMedia = new QPushButton(centralWidget);
        DeleteMedia->setObjectName(QStringLiteral("DeleteMedia"));
        DeleteMedia->setGeometry(QRect(140, 50, 75, 23));
        DeleteMedia->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/button1.png);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        DeleteAllMedia = new QPushButton(centralWidget);
        DeleteAllMedia->setObjectName(QStringLiteral("DeleteAllMedia"));
        DeleteAllMedia->setGeometry(QRect(270, 50, 101, 23));
        DeleteAllMedia->setStyleSheet(QString::fromUtf8("border-image: url(:/images/images/button1.png);\n"
"font: 10pt \"\351\273\221\344\275\223\";"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 110, 371, 271));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(510, 130, 3, 61));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(620, 130, 3, 61));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(410, 120, 91, 81));
        graphicsView_3 = new QGraphicsView(centralWidget);
        graphicsView_3->setObjectName(QStringLiteral("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(520, 120, 91, 81));
        graphicsView_4 = new QGraphicsView(centralWidget);
        graphicsView_4->setObjectName(QStringLiteral("graphicsView_4"));
        graphicsView_4->setGeometry(QRect(630, 120, 91, 81));
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(410, 230, 311, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(510, 280, 3, 61));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(620, 280, 3, 61));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        graphicsView_5 = new QGraphicsView(centralWidget);
        graphicsView_5->setObjectName(QStringLiteral("graphicsView_5"));
        graphicsView_5->setGeometry(QRect(410, 270, 91, 81));
        graphicsView_6 = new QGraphicsView(centralWidget);
        graphicsView_6->setObjectName(QStringLiteral("graphicsView_6"));
        graphicsView_6->setGeometry(QRect(520, 270, 91, 81));
        graphicsView_7 = new QGraphicsView(centralWidget);
        graphicsView_7->setObjectName(QStringLiteral("graphicsView_7"));
        graphicsView_7->setGeometry(QRect(630, 270, 91, 81));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(400, 80, 331, 20));
        label_7->setStyleSheet(QString::fromUtf8("font: 10pt \"\346\226\271\346\255\243\345\260\217\346\240\207\345\256\213\347\256\200\344\275\223\";"));
        integrationDone = new QPushButton(centralWidget);
        integrationDone->setObjectName(QStringLiteral("integrationDone"));
        integrationDone->setGeometry(QRect(350, 410, 75, 23));
        integrationDone->setStyleSheet(QStringLiteral("border-image: url(:/images/images/button1.png);"));
        mediaOne = new QPushButton(centralWidget);
        mediaOne->setObjectName(QStringLiteral("mediaOne"));
        mediaOne->setGeometry(QRect(420, 210, 75, 23));
        mediaThree = new QPushButton(centralWidget);
        mediaThree->setObjectName(QStringLiteral("mediaThree"));
        mediaThree->setGeometry(QRect(640, 210, 75, 23));
        mediaTwo = new QPushButton(centralWidget);
        mediaTwo->setObjectName(QStringLiteral("mediaTwo"));
        mediaTwo->setGeometry(QRect(530, 210, 75, 23));
        mediaFour = new QPushButton(centralWidget);
        mediaFour->setObjectName(QStringLiteral("mediaFour"));
        mediaFour->setGeometry(QRect(420, 360, 75, 23));
        mediaFive = new QPushButton(centralWidget);
        mediaFive->setObjectName(QStringLiteral("mediaFive"));
        mediaFive->setGeometry(QRect(530, 360, 75, 23));
        mediaSix = new QPushButton(centralWidget);
        mediaSix->setObjectName(QStringLiteral("mediaSix"));
        mediaSix->setGeometry(QRect(640, 360, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 742, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setStyleSheet(QStringLiteral("background-image: url(:/images/images/frame1.jpeg);"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MiniVideoEditor", Q_NULLPTR));
        AddMedia->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\345\252\222\344\275\223", Q_NULLPTR));
        DeleteMedia->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\252\222\344\275\223", Q_NULLPTR));
        DeleteAllMedia->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\205\250\351\203\250\345\252\222\344\275\223", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "PS\357\274\232\347\202\271\345\207\273\345\255\220\350\247\206\351\242\221\346\214\211\351\222\256\345\217\257\344\273\245\345\257\271\345\205\266\350\277\233\350\241\214\350\243\201\345\211\252\343\200\201\345\217\230\351\200\237\347\255\211\347\274\226\350\276\221", Q_NULLPTR));
        integrationDone->setText(QApplication::translate("MainWindow", "\346\225\264\345\220\210\345\256\214\346\257\225", Q_NULLPTR));
        mediaOne->setText(QApplication::translate("MainWindow", "Media 1", Q_NULLPTR));
        mediaThree->setText(QApplication::translate("MainWindow", "Media 3", Q_NULLPTR));
        mediaTwo->setText(QApplication::translate("MainWindow", "Media 2", Q_NULLPTR));
        mediaFour->setText(QApplication::translate("MainWindow", "Media 4", Q_NULLPTR));
        mediaFive->setText(QApplication::translate("MainWindow", "Media 5", Q_NULLPTR));
        mediaSix->setText(QApplication::translate("MainWindow", "Media 6", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
