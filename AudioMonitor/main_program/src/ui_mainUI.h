/********************************************************************************
** Form generated from reading UI file 'mainUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINUI_H
#define UI_MAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qt_h/cpumemorylabel.h"
#include "qt_h/panelitem.h"

QT_BEGIN_NAMESPACE

class Ui_mainui
{
public:
    QHBoxLayout *mainuiLayout;
    QStackedWidget *StackW;
    QWidget *Page1;
    QGridLayout *gL;
    QPushButton *pushButton_3;
    QHBoxLayout *group_1;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_1;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_8;
    QHBoxLayout *group_5;
    QPushButton *pushButton_5;
    QHBoxLayout *group_2;
    QHBoxLayout *group_3;
    QHBoxLayout *group_7;
    QHBoxLayout *group_4;
    QHBoxLayout *group_6;
    QHBoxLayout *group_8;
    QWidget *page2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_11;
    QHBoxLayout *group_9;
    QHBoxLayout *group_15;
    QHBoxLayout *group_11;
    QHBoxLayout *group_14;
    QHBoxLayout *group_16;
    QPushButton *pushButton_10;
    QHBoxLayout *group_13;
    QHBoxLayout *group_10;
    QPushButton *pushButton_12;
    QHBoxLayout *group_12;
    QPushButton *pushButton_9;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QVBoxLayout *leftLayout;
    QLabel *ACElabel;
    QHBoxLayout *changeHL;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QVBoxLayout *tab1Layout;
    CpuMemoryLabel *cpuMemorylabel;

    void setupUi(PanelItem *mainui)
    {
        if (mainui->objectName().isEmpty())
            mainui->setObjectName(QString::fromUtf8("mainui"));
        mainui->setWindowModality(Qt::NonModal);
        mainui->setEnabled(true);
        mainui->resize(1024, 768);
        mainui->setProperty("borderColor", QVariant(QColor(0, 0, 0)));
        mainui->setProperty("isAlarm", QVariant(false));
        mainui->setProperty("isEnable", QVariant(true));
        mainuiLayout = new QHBoxLayout(mainui);
        mainuiLayout->setObjectName(QString::fromUtf8("mainuiLayout"));
        mainuiLayout->setContentsMargins(-1, 35, -1, -1);
        StackW = new QStackedWidget(mainui);
        StackW->setObjectName(QString::fromUtf8("StackW"));
        StackW->setCursor(QCursor(Qt::SizeHorCursor));
        StackW->setMouseTracking(false);
        StackW->setTabletTracking(false);
        StackW->setFocusPolicy(Qt::NoFocus);
        StackW->setContextMenuPolicy(Qt::DefaultContextMenu);
        StackW->setAcceptDrops(false);
        StackW->setAutoFillBackground(false);
        StackW->setFrameShape(QFrame::NoFrame);
        StackW->setFrameShadow(QFrame::Plain);
        Page1 = new QWidget();
        Page1->setObjectName(QString::fromUtf8("Page1"));
        gL = new QGridLayout(Page1);
        gL->setObjectName(QString::fromUtf8("gL"));
        gL->setSizeConstraint(QLayout::SetDefaultConstraint);
        gL->setHorizontalSpacing(6);
        gL->setContentsMargins(9, -1, -1, -1);
        pushButton_3 = new QPushButton(Page1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gL->addWidget(pushButton_3, 1, 3, 1, 1);

        group_1 = new QHBoxLayout();
        group_1->setSpacing(0);
        group_1->setObjectName(QString::fromUtf8("group_1"));
        group_1->setSizeConstraint(QLayout::SetMaximumSize);

        gL->addLayout(group_1, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(Page1);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gL->addWidget(pushButton_7, 4, 3, 1, 1);

        pushButton_6 = new QPushButton(Page1);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gL->addWidget(pushButton_6, 4, 2, 1, 1);

        pushButton_1 = new QPushButton(Page1);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);

        gL->addWidget(pushButton_1, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(Page1);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gL->addWidget(pushButton_4, 1, 4, 1, 1);

        pushButton_2 = new QPushButton(Page1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gL->addWidget(pushButton_2, 1, 2, 1, 1);

        pushButton_8 = new QPushButton(Page1);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gL->addWidget(pushButton_8, 4, 4, 1, 1);

        group_5 = new QHBoxLayout();
        group_5->setObjectName(QString::fromUtf8("group_5"));
        group_5->setSizeConstraint(QLayout::SetMaximumSize);

        gL->addLayout(group_5, 5, 0, 1, 1);

        pushButton_5 = new QPushButton(Page1);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gL->addWidget(pushButton_5, 4, 0, 1, 1);

        group_2 = new QHBoxLayout();
        group_2->setObjectName(QString::fromUtf8("group_2"));
        group_2->setSizeConstraint(QLayout::SetMaximumSize);

        gL->addLayout(group_2, 2, 2, 1, 1);

        group_3 = new QHBoxLayout();
        group_3->setObjectName(QString::fromUtf8("group_3"));
        group_3->setSizeConstraint(QLayout::SetMaximumSize);

        gL->addLayout(group_3, 2, 3, 1, 1);

        group_7 = new QHBoxLayout();
        group_7->setObjectName(QString::fromUtf8("group_7"));
        group_7->setSizeConstraint(QLayout::SetMaximumSize);

        gL->addLayout(group_7, 5, 3, 1, 1);

        group_4 = new QHBoxLayout();
        group_4->setObjectName(QString::fromUtf8("group_4"));
        group_4->setSizeConstraint(QLayout::SetMaximumSize);

        gL->addLayout(group_4, 2, 4, 1, 1);

        group_6 = new QHBoxLayout();
        group_6->setObjectName(QString::fromUtf8("group_6"));
        group_6->setSizeConstraint(QLayout::SetMaximumSize);

        gL->addLayout(group_6, 5, 2, 1, 1);

        group_8 = new QHBoxLayout();
        group_8->setObjectName(QString::fromUtf8("group_8"));
        group_8->setSizeConstraint(QLayout::SetMaximumSize);

        gL->addLayout(group_8, 5, 4, 1, 1);

        StackW->addWidget(Page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        gridLayout = new QGridLayout(page2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_11 = new QPushButton(page2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 0, 4, 1, 1);

        group_9 = new QHBoxLayout();
        group_9->setObjectName(QString::fromUtf8("group_9"));
        group_9->setSizeConstraint(QLayout::SetMaximumSize);

        gridLayout->addLayout(group_9, 1, 2, 1, 1);

        group_15 = new QHBoxLayout();
        group_15->setObjectName(QString::fromUtf8("group_15"));
        group_15->setSizeConstraint(QLayout::SetMaximumSize);

        gridLayout->addLayout(group_15, 3, 4, 1, 1);

        group_11 = new QHBoxLayout();
        group_11->setObjectName(QString::fromUtf8("group_11"));
        group_11->setSizeConstraint(QLayout::SetMaximumSize);

        gridLayout->addLayout(group_11, 1, 4, 1, 1);

        group_14 = new QHBoxLayout();
        group_14->setObjectName(QString::fromUtf8("group_14"));
        group_14->setSizeConstraint(QLayout::SetMaximumSize);

        gridLayout->addLayout(group_14, 3, 3, 1, 1);

        group_16 = new QHBoxLayout();
        group_16->setSpacing(0);
        group_16->setObjectName(QString::fromUtf8("group_16"));
        group_16->setSizeConstraint(QLayout::SetMaximumSize);

        gridLayout->addLayout(group_16, 3, 5, 1, 1);

        pushButton_10 = new QPushButton(page2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 0, 3, 1, 1);

        group_13 = new QHBoxLayout();
        group_13->setObjectName(QString::fromUtf8("group_13"));
        group_13->setSizeConstraint(QLayout::SetMaximumSize);

        gridLayout->addLayout(group_13, 3, 2, 1, 1);

        group_10 = new QHBoxLayout();
        group_10->setObjectName(QString::fromUtf8("group_10"));
        group_10->setSizeConstraint(QLayout::SetMaximumSize);

        gridLayout->addLayout(group_10, 1, 3, 1, 1);

        pushButton_12 = new QPushButton(page2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout->addWidget(pushButton_12, 0, 5, 1, 1);

        group_12 = new QHBoxLayout();
        group_12->setObjectName(QString::fromUtf8("group_12"));
        group_12->setSizeConstraint(QLayout::SetMaximumSize);

        gridLayout->addLayout(group_12, 1, 5, 1, 1);

        pushButton_9 = new QPushButton(page2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 0, 2, 1, 1);

        pushButton_13 = new QPushButton(page2);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        gridLayout->addWidget(pushButton_13, 2, 2, 1, 1);

        pushButton_14 = new QPushButton(page2);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        gridLayout->addWidget(pushButton_14, 2, 3, 1, 1);

        pushButton_15 = new QPushButton(page2);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        gridLayout->addWidget(pushButton_15, 2, 4, 1, 1);

        pushButton_16 = new QPushButton(page2);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        sizePolicy.setHeightForWidth(pushButton_16->sizePolicy().hasHeightForWidth());
        pushButton_16->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_16, 2, 5, 1, 1);

        StackW->addWidget(page2);

        mainuiLayout->addWidget(StackW);

        leftLayout = new QVBoxLayout();
        leftLayout->setObjectName(QString::fromUtf8("leftLayout"));
        leftLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        ACElabel = new QLabel(mainui);
        ACElabel->setObjectName(QString::fromUtf8("ACElabel"));
        ACElabel->setMinimumSize(QSize(0, 90));
        ACElabel->setMaximumSize(QSize(16777215, 90));
        ACElabel->setStyleSheet(QString::fromUtf8("#ACElabel{\n"
"border:nono;\n"
"}\n"
""));
        ACElabel->setPixmap(QPixmap(QString::fromUtf8(":/rhdz")));
        ACElabel->setAlignment(Qt::AlignCenter);

        leftLayout->addWidget(ACElabel);

        changeHL = new QHBoxLayout();
        changeHL->setObjectName(QString::fromUtf8("changeHL"));
        tabWidget = new QTabWidget(mainui);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(true);
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        tab1Layout = new QVBoxLayout(tab1);
        tab1Layout->setObjectName(QString::fromUtf8("tab1Layout"));
        tabWidget->addTab(tab1, QString());

        changeHL->addWidget(tabWidget);


        leftLayout->addLayout(changeHL);

        cpuMemorylabel = new CpuMemoryLabel(mainui);
        cpuMemorylabel->setObjectName(QString::fromUtf8("cpuMemorylabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cpuMemorylabel->sizePolicy().hasHeightForWidth());
        cpuMemorylabel->setSizePolicy(sizePolicy1);
        cpuMemorylabel->setMinimumSize(QSize(0, 20));
        cpuMemorylabel->setMaximumSize(QSize(16777215, 20));
        cpuMemorylabel->setLineWidth(1);

        leftLayout->addWidget(cpuMemorylabel);


        mainuiLayout->addLayout(leftLayout);


        retranslateUi(mainui);

        StackW->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(mainui);
    } // setupUi

    void retranslateUi(PanelItem *mainui)
    {
        mainui->setWindowTitle(QApplication::translate("mainui", "Form", nullptr));
        mainui->setProperty("titleText", QVariant(QApplication::translate("mainui", "\351\237\263\351\242\221\347\233\221\346\265\213", nullptr)));
        pushButton_3->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_7->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_6->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_1->setText(QApplication::translate("mainui", "1", nullptr));
        pushButton_4->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_8->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_5->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_11->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_10->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_12->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_9->setText(QApplication::translate("mainui", "2", nullptr));
        pushButton_13->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_14->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_15->setText(QApplication::translate("mainui", "PushButton", nullptr));
        pushButton_16->setText(QApplication::translate("mainui", "PushButton", nullptr));
        ACElabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab1), QString());
    } // retranslateUi

};

namespace Ui {
    class mainui: public Ui_mainui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINUI_H
