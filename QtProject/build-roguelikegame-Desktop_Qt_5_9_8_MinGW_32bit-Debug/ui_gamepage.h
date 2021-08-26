/********************************************************************************
** Form generated from reading UI file 'gamepage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPAGE_H
#define UI_GAMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePage
{
public:

    void setupUi(QWidget *GamePage)
    {
        if (GamePage->objectName().isEmpty())
            GamePage->setObjectName(QStringLiteral("GamePage"));
        GamePage->resize(1600, 900);
        GamePage->setMinimumSize(QSize(1600, 900));
        GamePage->setMaximumSize(QSize(1600, 900));

        retranslateUi(GamePage);

        QMetaObject::connectSlotsByName(GamePage);
    } // setupUi

    void retranslateUi(QWidget *GamePage)
    {
        GamePage->setWindowTitle(QApplication::translate("GamePage", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GamePage: public Ui_GamePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
