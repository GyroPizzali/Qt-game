/********************************************************************************
** Form generated from reading UI file 'bosspage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOSSPAGE_H
#define UI_BOSSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BossPage
{
public:
    QLabel *label;

    void setupUi(QWidget *BossPage)
    {
        if (BossPage->objectName().isEmpty())
            BossPage->setObjectName(QStringLiteral("BossPage"));
        BossPage->resize(1600, 900);
        BossPage->setMinimumSize(QSize(1600, 900));
        BossPage->setMaximumSize(QSize(1600, 900));
        label = new QLabel(BossPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1600, 900));
        label->setMinimumSize(QSize(1600, 900));
        label->setMaximumSize(QSize(1600, 900));

        retranslateUi(BossPage);

        QMetaObject::connectSlotsByName(BossPage);
    } // setupUi

    void retranslateUi(QWidget *BossPage)
    {
        BossPage->setWindowTitle(QApplication::translate("BossPage", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("BossPage", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BossPage: public Ui_BossPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOSSPAGE_H
