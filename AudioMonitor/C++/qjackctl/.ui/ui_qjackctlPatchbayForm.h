/*
JACK Audio Connection Kit - Qt GUI Interface.

   Copyright (C) 2003-2019, rncbc aka Rui Nuno Capela. All rights reserved.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

 
*/

/********************************************************************************
** Form generated from reading UI file 'qjackctlPatchbayForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QJACKCTLPATCHBAYFORM_H
#define UI_QJACKCTLPATCHBAYFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "qjackctlPatchbay.h"

QT_BEGIN_NAMESPACE

class Ui_qjackctlPatchbayForm
{
public:
    QGridLayout *gridLayout;
    QFrame *line;
    QSpacerItem *spacerItem;
    QGridLayout *gridLayout1;
    qjackctlPatchbayView *PatchbayView;
    QPushButton *ISocketMoveDownPushButton;
    QPushButton *OSocketAddPushButton;
    QSpacerItem *spacerItem1;
    QPushButton *ISocketEditPushButton;
    QSpacerItem *spacerItem2;
    QPushButton *ISocketMoveUpPushButton;
    QPushButton *OSocketRemovePushButton;
    QPushButton *OSocketCopyPushButton;
    QPushButton *OSocketMoveDownPushButton;
    QPushButton *ISocketRemovePushButton;
    QPushButton *ISocketCopyPushButton;
    QPushButton *ISocketAddPushButton;
    QPushButton *OSocketEditPushButton;
    QPushButton *OSocketMoveUpPushButton;
    QSpacerItem *spacerItem3;
    QHBoxLayout *hboxLayout;
    QPushButton *ConnectPushButton;
    QPushButton *DisconnectPushButton;
    QPushButton *DisconnectAllPushButton;
    QSpacerItem *spacerItem4;
    QPushButton *ExpandAllPushButton;
    QSpacerItem *spacerItem5;
    QPushButton *RefreshPushButton;
    QHBoxLayout *hboxLayout1;
    QPushButton *NewPatchbayPushButton;
    QPushButton *LoadPatchbayPushButton;
    QPushButton *SavePatchbayPushButton;
    QComboBox *PatchbayComboBox;
    QPushButton *ActivatePatchbayPushButton;

    void setupUi(QWidget *qjackctlPatchbayForm)
    {
        if (qjackctlPatchbayForm->objectName().isEmpty())
            qjackctlPatchbayForm->setObjectName(QString::fromUtf8("qjackctlPatchbayForm"));
        qjackctlPatchbayForm->resize(520, 320);
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qjackctlPatchbayForm->sizePolicy().hasHeightForWidth());
        qjackctlPatchbayForm->setSizePolicy(sizePolicy);
        QFont font;
        qjackctlPatchbayForm->setFont(font);
        const QIcon icon = QIcon(QString::fromUtf8(":/images/patchbay1.png"));
        qjackctlPatchbayForm->setWindowIcon(icon);
        gridLayout = new QGridLayout(qjackctlPatchbayForm);
        gridLayout->setSpacing(4);
        gridLayout->setContentsMargins(4, 4, 4, 4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line = new QFrame(qjackctlPatchbayForm);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 3);

        spacerItem = new QSpacerItem(80, 8, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 3, 2, 1, 1);

        gridLayout1 = new QGridLayout();
        gridLayout1->setSpacing(4);
        gridLayout1->setContentsMargins(4, 4, 4, 4);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        PatchbayView = new qjackctlPatchbayView(qjackctlPatchbayForm);
        PatchbayView->setObjectName(QString::fromUtf8("PatchbayView"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PatchbayView->sizePolicy().hasHeightForWidth());
        PatchbayView->setSizePolicy(sizePolicy1);
        PatchbayView->setFocusPolicy(Qt::TabFocus);

        gridLayout1->addWidget(PatchbayView, 0, 1, 7, 1);

        ISocketMoveDownPushButton = new QPushButton(qjackctlPatchbayForm);
        ISocketMoveDownPushButton->setObjectName(QString::fromUtf8("ISocketMoveDownPushButton"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/images/down1.png"));
        ISocketMoveDownPushButton->setIcon(icon1);

        gridLayout1->addWidget(ISocketMoveDownPushButton, 6, 2, 1, 1);

        OSocketAddPushButton = new QPushButton(qjackctlPatchbayForm);
        OSocketAddPushButton->setObjectName(QString::fromUtf8("OSocketAddPushButton"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/images/add1.png"));
        OSocketAddPushButton->setIcon(icon2);

        gridLayout1->addWidget(OSocketAddPushButton, 0, 0, 1, 1);

        spacerItem1 = new QSpacerItem(8, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem1, 4, 2, 1, 1);

        ISocketEditPushButton = new QPushButton(qjackctlPatchbayForm);
        ISocketEditPushButton->setObjectName(QString::fromUtf8("ISocketEditPushButton"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/images/edit1.png"));
        ISocketEditPushButton->setIcon(icon3);

        gridLayout1->addWidget(ISocketEditPushButton, 1, 2, 1, 1);

        spacerItem2 = new QSpacerItem(8, 42, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem2, 4, 0, 1, 1);

        ISocketMoveUpPushButton = new QPushButton(qjackctlPatchbayForm);
        ISocketMoveUpPushButton->setObjectName(QString::fromUtf8("ISocketMoveUpPushButton"));
        const QIcon icon4 = QIcon(QString::fromUtf8(":/images/up1.png"));
        ISocketMoveUpPushButton->setIcon(icon4);

        gridLayout1->addWidget(ISocketMoveUpPushButton, 5, 2, 1, 1);

        OSocketRemovePushButton = new QPushButton(qjackctlPatchbayForm);
        OSocketRemovePushButton->setObjectName(QString::fromUtf8("OSocketRemovePushButton"));
        const QIcon icon5 = QIcon(QString::fromUtf8(":/images/remove1.png"));
        OSocketRemovePushButton->setIcon(icon5);

        gridLayout1->addWidget(OSocketRemovePushButton, 3, 0, 1, 1);

        OSocketCopyPushButton = new QPushButton(qjackctlPatchbayForm);
        OSocketCopyPushButton->setObjectName(QString::fromUtf8("OSocketCopyPushButton"));
        const QIcon icon6 = QIcon(QString::fromUtf8(":/images/copy1.png"));
        OSocketCopyPushButton->setIcon(icon6);

        gridLayout1->addWidget(OSocketCopyPushButton, 2, 0, 1, 1);

        OSocketMoveDownPushButton = new QPushButton(qjackctlPatchbayForm);
        OSocketMoveDownPushButton->setObjectName(QString::fromUtf8("OSocketMoveDownPushButton"));
        OSocketMoveDownPushButton->setIcon(icon1);

        gridLayout1->addWidget(OSocketMoveDownPushButton, 6, 0, 1, 1);

        ISocketRemovePushButton = new QPushButton(qjackctlPatchbayForm);
        ISocketRemovePushButton->setObjectName(QString::fromUtf8("ISocketRemovePushButton"));
        ISocketRemovePushButton->setIcon(icon5);

        gridLayout1->addWidget(ISocketRemovePushButton, 3, 2, 1, 1);

        ISocketCopyPushButton = new QPushButton(qjackctlPatchbayForm);
        ISocketCopyPushButton->setObjectName(QString::fromUtf8("ISocketCopyPushButton"));
        ISocketCopyPushButton->setIcon(icon6);

        gridLayout1->addWidget(ISocketCopyPushButton, 2, 2, 1, 1);

        ISocketAddPushButton = new QPushButton(qjackctlPatchbayForm);
        ISocketAddPushButton->setObjectName(QString::fromUtf8("ISocketAddPushButton"));
        ISocketAddPushButton->setIcon(icon2);

        gridLayout1->addWidget(ISocketAddPushButton, 0, 2, 1, 1);

        OSocketEditPushButton = new QPushButton(qjackctlPatchbayForm);
        OSocketEditPushButton->setObjectName(QString::fromUtf8("OSocketEditPushButton"));
        OSocketEditPushButton->setIcon(icon3);

        gridLayout1->addWidget(OSocketEditPushButton, 1, 0, 1, 1);

        OSocketMoveUpPushButton = new QPushButton(qjackctlPatchbayForm);
        OSocketMoveUpPushButton->setObjectName(QString::fromUtf8("OSocketMoveUpPushButton"));
        OSocketMoveUpPushButton->setIcon(icon4);

        gridLayout1->addWidget(OSocketMoveUpPushButton, 5, 0, 1, 1);


        gridLayout->addLayout(gridLayout1, 2, 0, 1, 3);

        spacerItem3 = new QSpacerItem(80, 8, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem3, 3, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(4);
        hboxLayout->setContentsMargins(4, 4, 4, 4);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        ConnectPushButton = new QPushButton(qjackctlPatchbayForm);
        ConnectPushButton->setObjectName(QString::fromUtf8("ConnectPushButton"));
        const QIcon icon7 = QIcon(QString::fromUtf8(":/images/connect1.png"));
        ConnectPushButton->setIcon(icon7);

        hboxLayout->addWidget(ConnectPushButton);

        DisconnectPushButton = new QPushButton(qjackctlPatchbayForm);
        DisconnectPushButton->setObjectName(QString::fromUtf8("DisconnectPushButton"));
        const QIcon icon8 = QIcon(QString::fromUtf8(":/images/disconnect1.png"));
        DisconnectPushButton->setIcon(icon8);

        hboxLayout->addWidget(DisconnectPushButton);

        DisconnectAllPushButton = new QPushButton(qjackctlPatchbayForm);
        DisconnectAllPushButton->setObjectName(QString::fromUtf8("DisconnectAllPushButton"));
        DisconnectAllPushButton->setIcon(icon8);

        hboxLayout->addWidget(DisconnectAllPushButton);

        spacerItem4 = new QSpacerItem(8, 8, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem4);

        ExpandAllPushButton = new QPushButton(qjackctlPatchbayForm);
        ExpandAllPushButton->setObjectName(QString::fromUtf8("ExpandAllPushButton"));
        const QIcon icon9 = QIcon(QString::fromUtf8(":/images/expandall1.png"));
        ExpandAllPushButton->setIcon(icon9);

        hboxLayout->addWidget(ExpandAllPushButton);

        spacerItem5 = new QSpacerItem(8, 8, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem5);

        RefreshPushButton = new QPushButton(qjackctlPatchbayForm);
        RefreshPushButton->setObjectName(QString::fromUtf8("RefreshPushButton"));
        const QIcon icon10 = QIcon(QString::fromUtf8(":/images/refresh1.png"));
        RefreshPushButton->setIcon(icon10);

        hboxLayout->addWidget(RefreshPushButton);


        gridLayout->addLayout(hboxLayout, 3, 1, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(4);
        hboxLayout1->setContentsMargins(4, 4, 4, 4);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        NewPatchbayPushButton = new QPushButton(qjackctlPatchbayForm);
        NewPatchbayPushButton->setObjectName(QString::fromUtf8("NewPatchbayPushButton"));
        const QIcon icon11 = QIcon(QString::fromUtf8(":/images/new1.png"));
        NewPatchbayPushButton->setIcon(icon11);
        NewPatchbayPushButton->setAutoDefault(false);

        hboxLayout1->addWidget(NewPatchbayPushButton);

        LoadPatchbayPushButton = new QPushButton(qjackctlPatchbayForm);
        LoadPatchbayPushButton->setObjectName(QString::fromUtf8("LoadPatchbayPushButton"));
        const QIcon icon12 = QIcon(QString::fromUtf8(":/images/open1.png"));
        LoadPatchbayPushButton->setIcon(icon12);
        LoadPatchbayPushButton->setAutoDefault(false);

        hboxLayout1->addWidget(LoadPatchbayPushButton);

        SavePatchbayPushButton = new QPushButton(qjackctlPatchbayForm);
        SavePatchbayPushButton->setObjectName(QString::fromUtf8("SavePatchbayPushButton"));
        const QIcon icon13 = QIcon(QString::fromUtf8(":/images/save1.png"));
        SavePatchbayPushButton->setIcon(icon13);
        SavePatchbayPushButton->setAutoDefault(false);

        hboxLayout1->addWidget(SavePatchbayPushButton);

        PatchbayComboBox = new QComboBox(qjackctlPatchbayForm);
        PatchbayComboBox->setObjectName(QString::fromUtf8("PatchbayComboBox"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(5));
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PatchbayComboBox->sizePolicy().hasHeightForWidth());
        PatchbayComboBox->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        PatchbayComboBox->setFont(font1);

        hboxLayout1->addWidget(PatchbayComboBox);

        ActivatePatchbayPushButton = new QPushButton(qjackctlPatchbayForm);
        ActivatePatchbayPushButton->setObjectName(QString::fromUtf8("ActivatePatchbayPushButton"));
        const QIcon icon14 = QIcon(QString::fromUtf8(":/images/apply1.png"));
        ActivatePatchbayPushButton->setIcon(icon14);
        ActivatePatchbayPushButton->setCheckable(true);
        ActivatePatchbayPushButton->setAutoDefault(false);

        hboxLayout1->addWidget(ActivatePatchbayPushButton);


        gridLayout->addLayout(hboxLayout1, 0, 0, 1, 3);

        QWidget::setTabOrder(NewPatchbayPushButton, LoadPatchbayPushButton);
        QWidget::setTabOrder(LoadPatchbayPushButton, SavePatchbayPushButton);
        QWidget::setTabOrder(SavePatchbayPushButton, PatchbayComboBox);
        QWidget::setTabOrder(PatchbayComboBox, ActivatePatchbayPushButton);
        QWidget::setTabOrder(ActivatePatchbayPushButton, OSocketAddPushButton);
        QWidget::setTabOrder(OSocketAddPushButton, OSocketEditPushButton);
        QWidget::setTabOrder(OSocketEditPushButton, OSocketCopyPushButton);
        QWidget::setTabOrder(OSocketCopyPushButton, OSocketRemovePushButton);
        QWidget::setTabOrder(OSocketRemovePushButton, OSocketMoveUpPushButton);
        QWidget::setTabOrder(OSocketMoveUpPushButton, OSocketMoveDownPushButton);
        QWidget::setTabOrder(OSocketMoveDownPushButton, PatchbayView);
        QWidget::setTabOrder(PatchbayView, ISocketAddPushButton);
        QWidget::setTabOrder(ISocketAddPushButton, ISocketEditPushButton);
        QWidget::setTabOrder(ISocketEditPushButton, ISocketCopyPushButton);
        QWidget::setTabOrder(ISocketCopyPushButton, ISocketRemovePushButton);
        QWidget::setTabOrder(ISocketRemovePushButton, ISocketMoveUpPushButton);
        QWidget::setTabOrder(ISocketMoveUpPushButton, ISocketMoveDownPushButton);
        QWidget::setTabOrder(ISocketMoveDownPushButton, ConnectPushButton);
        QWidget::setTabOrder(ConnectPushButton, DisconnectPushButton);
        QWidget::setTabOrder(DisconnectPushButton, DisconnectAllPushButton);
        QWidget::setTabOrder(DisconnectAllPushButton, ExpandAllPushButton);
        QWidget::setTabOrder(ExpandAllPushButton, RefreshPushButton);

        retranslateUi(qjackctlPatchbayForm);

        RefreshPushButton->setDefault(true);


        QMetaObject::connectSlotsByName(qjackctlPatchbayForm);
    } // setupUi

    void retranslateUi(QWidget *qjackctlPatchbayForm)
    {
        qjackctlPatchbayForm->setWindowTitle(QApplication::translate("qjackctlPatchbayForm", "Patchbay", nullptr));
#ifndef QT_NO_TOOLTIP
        ISocketMoveDownPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Move currently selected output socket down one position", nullptr));
#endif // QT_NO_TOOLTIP
        ISocketMoveDownPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Down", nullptr));
#ifndef QT_NO_TOOLTIP
        OSocketAddPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Create a new output socket", nullptr));
#endif // QT_NO_TOOLTIP
        OSocketAddPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Add...", nullptr));
#ifndef QT_NO_TOOLTIP
        ISocketEditPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Edit currently selected input socket properties", nullptr));
#endif // QT_NO_TOOLTIP
        ISocketEditPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Edit...", nullptr));
#ifndef QT_NO_TOOLTIP
        ISocketMoveUpPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Move currently selected output socket up one position", nullptr));
#endif // QT_NO_TOOLTIP
        ISocketMoveUpPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Up", nullptr));
#ifndef QT_NO_TOOLTIP
        OSocketRemovePushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Remove currently selected output socket", nullptr));
#endif // QT_NO_TOOLTIP
        OSocketRemovePushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Remove", nullptr));
#ifndef QT_NO_TOOLTIP
        OSocketCopyPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Duplicate (copy) currently selected output socket", nullptr));
#endif // QT_NO_TOOLTIP
        OSocketCopyPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Copy...", nullptr));
#ifndef QT_NO_TOOLTIP
        OSocketMoveDownPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Move currently selected output socket down one position", nullptr));
#endif // QT_NO_TOOLTIP
        OSocketMoveDownPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Down", nullptr));
#ifndef QT_NO_TOOLTIP
        ISocketRemovePushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Remove currently selected input socket", nullptr));
#endif // QT_NO_TOOLTIP
        ISocketRemovePushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Remove", nullptr));
#ifndef QT_NO_TOOLTIP
        ISocketCopyPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Duplicate (copy) currently selected input socket", nullptr));
#endif // QT_NO_TOOLTIP
        ISocketCopyPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Copy...", nullptr));
#ifndef QT_NO_TOOLTIP
        ISocketAddPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Create a new input socket", nullptr));
#endif // QT_NO_TOOLTIP
        ISocketAddPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Add...", nullptr));
#ifndef QT_NO_TOOLTIP
        OSocketEditPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Edit currently selected output socket properties", nullptr));
#endif // QT_NO_TOOLTIP
        OSocketEditPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Edit...", nullptr));
#ifndef QT_NO_TOOLTIP
        OSocketMoveUpPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Move currently selected output socket up one position", nullptr));
#endif // QT_NO_TOOLTIP
        OSocketMoveUpPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Up", nullptr));
#ifndef QT_NO_TOOLTIP
        ConnectPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Connect currently selected sockets", nullptr));
#endif // QT_NO_TOOLTIP
        ConnectPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "&Connect", nullptr));
#ifndef QT_NO_TOOLTIP
        DisconnectPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Disconnect currently selected sockets", nullptr));
#endif // QT_NO_TOOLTIP
        DisconnectPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "&Disconnect", nullptr));
#ifndef QT_NO_TOOLTIP
        DisconnectAllPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Disconnect all currently connected sockets", nullptr));
#endif // QT_NO_TOOLTIP
        DisconnectAllPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Disconnect &All", nullptr));
#ifndef QT_NO_TOOLTIP
        ExpandAllPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Expand all items", nullptr));
#endif // QT_NO_TOOLTIP
        ExpandAllPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "E&xpand All", nullptr));
#ifndef QT_NO_TOOLTIP
        RefreshPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Refresh current patchbay view", nullptr));
#endif // QT_NO_TOOLTIP
        RefreshPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "&Refresh", nullptr));
#ifndef QT_NO_TOOLTIP
        NewPatchbayPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Create a new patchbay profile", nullptr));
#endif // QT_NO_TOOLTIP
        NewPatchbayPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "&New", nullptr));
#ifndef QT_NO_TOOLTIP
        LoadPatchbayPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Load patchbay profile", nullptr));
#endif // QT_NO_TOOLTIP
        LoadPatchbayPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "&Load...", nullptr));
#ifndef QT_NO_TOOLTIP
        SavePatchbayPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Save current patchbay profile", nullptr));
#endif // QT_NO_TOOLTIP
        SavePatchbayPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "&Save...", nullptr));
#ifndef QT_NO_TOOLTIP
        PatchbayComboBox->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Current (recent) patchbay profile(s)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ActivatePatchbayPushButton->setToolTip(QApplication::translate("qjackctlPatchbayForm", "Toggle activation of current patchbay profile", nullptr));
#endif // QT_NO_TOOLTIP
        ActivatePatchbayPushButton->setText(QApplication::translate("qjackctlPatchbayForm", "Acti&vate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qjackctlPatchbayForm: public Ui_qjackctlPatchbayForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QJACKCTLPATCHBAYFORM_H
