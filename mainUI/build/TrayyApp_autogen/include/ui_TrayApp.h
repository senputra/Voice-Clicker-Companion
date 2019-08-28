/********************************************************************************
** Form generated from reading UI file 'TrayApp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAYAPP_H
#define UI_TRAYAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_TrayAppClass
{
public:

    void setupUi(QDialog *TrayAppClass)
    {
        if (TrayAppClass->objectName().isEmpty())
            TrayAppClass->setObjectName(QStringLiteral("TrayAppClass"));
        TrayAppClass->resize(600, 400);

        retranslateUi(TrayAppClass);

        QMetaObject::connectSlotsByName(TrayAppClass);
    } // setupUi

    void retranslateUi(QDialog *TrayAppClass)
    {
        TrayAppClass->setWindowTitle(QApplication::translate("TrayAppClass", "TrayApp", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TrayAppClass: public Ui_TrayAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAYAPP_H
