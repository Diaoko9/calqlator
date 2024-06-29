/********************************************************************************
** Form generated from reading UI file 'calqlator.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALQLATOR_H
#define UI_CALQLATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calqlator
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Calqlator)
    {
        if (Calqlator->objectName().isEmpty())
            Calqlator->setObjectName(QString::fromUtf8("Calqlator"));
        Calqlator->resize(800, 600);
        centralwidget = new QWidget(Calqlator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Calqlator->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Calqlator);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Calqlator->setMenuBar(menubar);
        statusbar = new QStatusBar(Calqlator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Calqlator->setStatusBar(statusbar);

        retranslateUi(Calqlator);

        QMetaObject::connectSlotsByName(Calqlator);
    } // setupUi

    void retranslateUi(QMainWindow *Calqlator)
    {
        Calqlator->setWindowTitle(QCoreApplication::translate("Calqlator", "Calqlator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calqlator: public Ui_Calqlator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALQLATOR_H
