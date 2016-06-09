/********************************************************************************
** Form generated from reading UI file 'subwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBWINDOW_H
#define UI_SUBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubWindow
{
public:
    QLabel *displayLabel;

    void setupUi(QWidget *SubWindow)
    {
        if (SubWindow->objectName().isEmpty())
            SubWindow->setObjectName(QStringLiteral("SubWindow"));
        SubWindow->resize(640, 480);
        displayLabel = new QLabel(SubWindow);
        displayLabel->setObjectName(QStringLiteral("displayLabel"));
        displayLabel->setGeometry(QRect(0, 0, 640, 480));

        retranslateUi(SubWindow);

        QMetaObject::connectSlotsByName(SubWindow);
    } // setupUi

    void retranslateUi(QWidget *SubWindow)
    {
        SubWindow->setWindowTitle(QApplication::translate("SubWindow", "SubWidget", 0));
        displayLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SubWindow: public Ui_SubWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBWINDOW_H
