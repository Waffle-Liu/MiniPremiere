/********************************************************************************
** Form generated from reading UI file 'dialog_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_EDIT_H
#define UI_DIALOG_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_edit
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *widget;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *Intercept;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *tab_3;

    void setupUi(QDialog *Dialog_edit)
    {
        if (Dialog_edit->objectName().isEmpty())
            Dialog_edit->setObjectName(QStringLiteral("Dialog_edit"));
        Dialog_edit->resize(400, 329);
        verticalLayout = new QVBoxLayout(Dialog_edit);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(Dialog_edit);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 120, 91, 16));
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 120, 241, 22));
        comboBox->setEditable(false);
        comboBox->setMaxVisibleItems(5);
        comboBox->setMaxCount(5);
        tabWidget->addTab(widget, QString());
        Intercept = new QWidget();
        Intercept->setObjectName(QStringLiteral("Intercept"));
        label_2 = new QLabel(Intercept);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 101, 16));
        lineEdit = new QLineEdit(Intercept);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 100, 161, 20));
        label_3 = new QLabel(Intercept);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 100, 54, 12));
        label_4 = new QLabel(Intercept);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 180, 101, 16));
        lineEdit_2 = new QLineEdit(Intercept);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 180, 161, 20));
        label_5 = new QLabel(Intercept);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(280, 180, 81, 20));
        label_6 = new QLabel(Intercept);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 20, 101, 16));
        tabWidget->addTab(Intercept, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(Dialog_edit);

        tabWidget->setCurrentIndex(0);
        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Dialog_edit);
    } // setupUi

    void retranslateUi(QDialog *Dialog_edit)
    {
        Dialog_edit->setWindowTitle(QApplication::translate("Dialog_edit", "VideoEdit", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        widget->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        label->setText(QApplication::translate("Dialog_edit", "\350\260\203\346\225\264\346\222\255\346\224\276\351\200\237\345\272\246\357\274\232", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Dialog_edit", "0.5", Q_NULLPTR)
         << QApplication::translate("Dialog_edit", "1.0", Q_NULLPTR)
         << QApplication::translate("Dialog_edit", "1.5", Q_NULLPTR)
         << QApplication::translate("Dialog_edit", "2.0", Q_NULLPTR)
         << QApplication::translate("Dialog_edit", "3.0", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(widget), QApplication::translate("Dialog_edit", "\350\247\206\351\242\221\345\217\230\351\200\237", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog_edit", "\346\210\252\345\217\226\347\232\204\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog_edit", "> 0 ", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog_edit", "\346\210\252\345\217\226\347\232\204\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog_edit", "< 6363125000", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog_edit", "\345\215\225\344\275\215\357\274\232 \345\276\256\347\247\222", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Intercept), QApplication::translate("Dialog_edit", "\350\247\206\351\242\221\346\210\252\345\217\226", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Dialog_edit", "\347\274\226\350\276\221\357\274\210\346\227\213\350\275\254 \347\277\273\350\275\254 \350\243\201\345\211\252\357\274\211", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_edit: public Ui_Dialog_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EDIT_H
