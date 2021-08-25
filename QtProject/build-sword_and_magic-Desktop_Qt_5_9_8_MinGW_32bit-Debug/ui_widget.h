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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mypage.h>
#include <mypagemain.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    MyPageMain *pageMain;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *titLab;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *difBut;
    QPushButton *staBut;
    QPushButton *recBut;
    QPushButton *setBut;
    QPushButton *exiBut;
    QWidget *widget_5;
    MyPage *pageGame;
    QLabel *label;
    QWidget *page_3;
    QWidget *page_4;
    QWidget *page_5;
    QWidget *page_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1600, 900);
        Widget->setMinimumSize(QSize(1600, 900));
        Widget->setMaximumSize(QSize(1600, 900));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1600, 900));
        stackedWidget->setMinimumSize(QSize(1600, 900));
        stackedWidget->setMaximumSize(QSize(1600, 900));
        pageMain = new MyPageMain();
        pageMain->setObjectName(QStringLiteral("pageMain"));
        pageMain->setMinimumSize(QSize(1600, 900));
        pageMain->setMaximumSize(QSize(1600, 900));
        verticalLayout = new QVBoxLayout(pageMain);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(pageMain);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(642, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        titLab = new QLabel(widget);
        titLab->setObjectName(QStringLiteral("titLab"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(48);
        font.setItalic(false);
        titLab->setFont(font);

        horizontalLayout_2->addWidget(titLab);

        horizontalSpacer_2 = new QSpacerItem(642, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(pageMain);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));

        horizontalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        difBut = new QPushButton(widget_4);
        difBut->setObjectName(QStringLiteral("difBut"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(difBut->sizePolicy().hasHeightForWidth());
        difBut->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(difBut);

        staBut = new QPushButton(widget_4);
        staBut->setObjectName(QStringLiteral("staBut"));
        sizePolicy.setHeightForWidth(staBut->sizePolicy().hasHeightForWidth());
        staBut->setSizePolicy(sizePolicy);
        staBut->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(staBut);

        recBut = new QPushButton(widget_4);
        recBut->setObjectName(QStringLiteral("recBut"));
        sizePolicy.setHeightForWidth(recBut->sizePolicy().hasHeightForWidth());
        recBut->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(recBut);

        setBut = new QPushButton(widget_4);
        setBut->setObjectName(QStringLiteral("setBut"));
        sizePolicy.setHeightForWidth(setBut->sizePolicy().hasHeightForWidth());
        setBut->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(setBut);

        exiBut = new QPushButton(widget_4);
        exiBut->setObjectName(QStringLiteral("exiBut"));
        sizePolicy.setHeightForWidth(exiBut->sizePolicy().hasHeightForWidth());
        exiBut->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(exiBut);


        horizontalLayout->addWidget(widget_4);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QStringLiteral("widget_5"));

        horizontalLayout->addWidget(widget_5);


        verticalLayout->addWidget(widget_2);

        stackedWidget->addWidget(pageMain);
        pageGame = new MyPage();
        pageGame->setObjectName(QStringLiteral("pageGame"));
        label = new QLabel(pageGame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1600, 100));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(18);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        stackedWidget->addWidget(pageGame);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        stackedWidget->addWidget(page_6);

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        titLab->setText(QApplication::translate("Widget", "Sword & Magic", Q_NULLPTR));
        difBut->setText(QApplication::translate("Widget", "Difficulity : easy", Q_NULLPTR));
        staBut->setText(QApplication::translate("Widget", "Start", Q_NULLPTR));
        recBut->setText(QApplication::translate("Widget", "Record", Q_NULLPTR));
        setBut->setText(QApplication::translate("Widget", "Settings", Q_NULLPTR));
        exiBut->setText(QApplication::translate("Widget", "Exit", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "<center>press D\343\200\201A to move</center>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
