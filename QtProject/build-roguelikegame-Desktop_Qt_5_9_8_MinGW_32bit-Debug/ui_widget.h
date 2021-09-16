/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *difButton;
    QPushButton *staButton;
    QPushButton *skiButton;
    QPushButton *setButton;
    QPushButton *exiButton;
    QWidget *widget_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1600, 900);
        Widget->setMinimumSize(QSize(1600, 900));
        Widget->setMaximumSize(QSize(1600, 900));
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_4 = new QWidget(Widget);
        widget_4->setObjectName(QStringLiteral("widget_4"));

        verticalLayout_2->addWidget(widget_4);

        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));

        horizontalLayout->addWidget(widget_2);

        widget1 = new QWidget(widget);
        widget1->setObjectName(QStringLiteral("widget1"));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        difButton = new QPushButton(widget1);
        difButton->setObjectName(QStringLiteral("difButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(difButton->sizePolicy().hasHeightForWidth());
        difButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(difButton);

        staButton = new QPushButton(widget1);
        staButton->setObjectName(QStringLiteral("staButton"));
        sizePolicy.setHeightForWidth(staButton->sizePolicy().hasHeightForWidth());
        staButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(staButton);

        skiButton = new QPushButton(widget1);
        skiButton->setObjectName(QStringLiteral("skiButton"));
        sizePolicy.setHeightForWidth(skiButton->sizePolicy().hasHeightForWidth());
        skiButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(skiButton);

        setButton = new QPushButton(widget1);
        setButton->setObjectName(QStringLiteral("setButton"));
        sizePolicy.setHeightForWidth(setButton->sizePolicy().hasHeightForWidth());
        setButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(setButton);

        exiButton = new QPushButton(widget1);
        exiButton->setObjectName(QStringLiteral("exiButton"));
        sizePolicy.setHeightForWidth(exiButton->sizePolicy().hasHeightForWidth());
        exiButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(exiButton);


        horizontalLayout->addWidget(widget1);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        horizontalLayout->addWidget(widget_3);


        verticalLayout_2->addWidget(widget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        difButton->setText(QApplication::translate("Widget", "Difficulty : easy", Q_NULLPTR));
        staButton->setText(QApplication::translate("Widget", "Start", Q_NULLPTR));
        skiButton->setText(QApplication::translate("Widget", "catalogue", Q_NULLPTR));
        setButton->setText(QApplication::translate("Widget", "Settings", Q_NULLPTR));
        exiButton->setText(QApplication::translate("Widget", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
