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
** Form generated from reading UI file 'qjackctlConnectionsForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QJACKCTLCONNECTIONSFORM_H
#define UI_QJACKCTLCONNECTIONSFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "qjackctlConnect.h"

QT_BEGIN_NAMESPACE

class Ui_qjackctlConnectionsForm
{
public:
    QGridLayout *gridLayout;
    QTabWidget *ConnectionsTabWidget;
    QWidget *AudioConnectTab;
    QGridLayout *gridLayout1;
    qjackctlConnectView *AudioConnectView;
    QHBoxLayout *hboxLayout;
    QPushButton *AudioConnectPushButton;
    QPushButton *AudioDisconnectPushButton;
    QPushButton *AudioDisconnectAllPushButton;
    QSpacerItem *spacerItem;
    QPushButton *AudioExpandAllPushButton;
    QSpacerItem *spacerItem1;
    QPushButton *AudioRefreshPushButton;
    QWidget *MidiConnectTab;
    QGridLayout *gridLayout2;
    qjackctlConnectView *MidiConnectView;
    QHBoxLayout *hboxLayout1;
    QPushButton *MidiConnectPushButton;
    QPushButton *MidiDisconnectPushButton;
    QPushButton *MidiDisconnectAllPushButton;
    QSpacerItem *spacerItem2;
    QPushButton *MidiExpandAllPushButton;
    QSpacerItem *spacerItem3;
    QPushButton *MidiRefreshPushButton;
    QWidget *AlsaConnectTab;
    QGridLayout *gridLayout3;
    qjackctlConnectView *AlsaConnectView;
    QHBoxLayout *hboxLayout2;
    QPushButton *AlsaConnectPushButton;
    QPushButton *AlsaDisconnectPushButton;
    QPushButton *AlsaDisconnectAllPushButton;
    QSpacerItem *spacerItem4;
    QPushButton *AlsaExpandAllPushButton;
    QSpacerItem *spacerItem5;
    QPushButton *AlsaRefreshPushButton;

    void setupUi(QWidget *qjackctlConnectionsForm)
    {
        if (qjackctlConnectionsForm->objectName().isEmpty())
            qjackctlConnectionsForm->setObjectName(QString::fromUtf8("qjackctlConnectionsForm"));
        qjackctlConnectionsForm->resize(480, 320);
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qjackctlConnectionsForm->sizePolicy().hasHeightForWidth());
        qjackctlConnectionsForm->setSizePolicy(sizePolicy);
        QFont font;
        qjackctlConnectionsForm->setFont(font);
        const QIcon icon = QIcon(QString::fromUtf8(":/images/connections1.png"));
        qjackctlConnectionsForm->setWindowIcon(icon);
        gridLayout = new QGridLayout(qjackctlConnectionsForm);
        gridLayout->setSpacing(4);
        gridLayout->setContentsMargins(4, 4, 4, 4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        ConnectionsTabWidget = new QTabWidget(qjackctlConnectionsForm);
        ConnectionsTabWidget->setObjectName(QString::fromUtf8("ConnectionsTabWidget"));
        AudioConnectTab = new QWidget();
        AudioConnectTab->setObjectName(QString::fromUtf8("AudioConnectTab"));
        gridLayout1 = new QGridLayout(AudioConnectTab);
        gridLayout1->setSpacing(4);
        gridLayout1->setContentsMargins(4, 4, 4, 4);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        AudioConnectView = new qjackctlConnectView(AudioConnectTab);
        AudioConnectView->setObjectName(QString::fromUtf8("AudioConnectView"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AudioConnectView->sizePolicy().hasHeightForWidth());
        AudioConnectView->setSizePolicy(sizePolicy1);
        AudioConnectView->setFocusPolicy(Qt::TabFocus);

        gridLayout1->addWidget(AudioConnectView, 0, 0, 1, 1);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(4);
        hboxLayout->setContentsMargins(4, 4, 4, 4);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        AudioConnectPushButton = new QPushButton(AudioConnectTab);
        AudioConnectPushButton->setObjectName(QString::fromUtf8("AudioConnectPushButton"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/images/connect1.png"));
        AudioConnectPushButton->setIcon(icon1);

        hboxLayout->addWidget(AudioConnectPushButton);

        AudioDisconnectPushButton = new QPushButton(AudioConnectTab);
        AudioDisconnectPushButton->setObjectName(QString::fromUtf8("AudioDisconnectPushButton"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/images/disconnect1.png"));
        AudioDisconnectPushButton->setIcon(icon2);

        hboxLayout->addWidget(AudioDisconnectPushButton);

        AudioDisconnectAllPushButton = new QPushButton(AudioConnectTab);
        AudioDisconnectAllPushButton->setObjectName(QString::fromUtf8("AudioDisconnectAllPushButton"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/images/disconnectall1.png"));
        AudioDisconnectAllPushButton->setIcon(icon3);

        hboxLayout->addWidget(AudioDisconnectAllPushButton);

        spacerItem = new QSpacerItem(8, 8, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        AudioExpandAllPushButton = new QPushButton(AudioConnectTab);
        AudioExpandAllPushButton->setObjectName(QString::fromUtf8("AudioExpandAllPushButton"));
        const QIcon icon4 = QIcon(QString::fromUtf8(":/images/expandall1.png"));
        AudioExpandAllPushButton->setIcon(icon4);

        hboxLayout->addWidget(AudioExpandAllPushButton);

        spacerItem1 = new QSpacerItem(8, 8, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem1);

        AudioRefreshPushButton = new QPushButton(AudioConnectTab);
        AudioRefreshPushButton->setObjectName(QString::fromUtf8("AudioRefreshPushButton"));
        const QIcon icon5 = QIcon(QString::fromUtf8(":/images/refresh1.png"));
        AudioRefreshPushButton->setIcon(icon5);

        hboxLayout->addWidget(AudioRefreshPushButton);


        gridLayout1->addLayout(hboxLayout, 1, 0, 1, 1);

        ConnectionsTabWidget->addTab(AudioConnectTab, QString());
        MidiConnectTab = new QWidget();
        MidiConnectTab->setObjectName(QString::fromUtf8("MidiConnectTab"));
        gridLayout2 = new QGridLayout(MidiConnectTab);
        gridLayout2->setSpacing(4);
        gridLayout2->setContentsMargins(4, 4, 4, 4);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        MidiConnectView = new qjackctlConnectView(MidiConnectTab);
        MidiConnectView->setObjectName(QString::fromUtf8("MidiConnectView"));
        sizePolicy1.setHeightForWidth(MidiConnectView->sizePolicy().hasHeightForWidth());
        MidiConnectView->setSizePolicy(sizePolicy1);
        MidiConnectView->setFocusPolicy(Qt::TabFocus);

        gridLayout2->addWidget(MidiConnectView, 0, 0, 1, 1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(4);
        hboxLayout1->setContentsMargins(4, 4, 4, 4);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        MidiConnectPushButton = new QPushButton(MidiConnectTab);
        MidiConnectPushButton->setObjectName(QString::fromUtf8("MidiConnectPushButton"));
        MidiConnectPushButton->setIcon(icon1);

        hboxLayout1->addWidget(MidiConnectPushButton);

        MidiDisconnectPushButton = new QPushButton(MidiConnectTab);
        MidiDisconnectPushButton->setObjectName(QString::fromUtf8("MidiDisconnectPushButton"));
        MidiDisconnectPushButton->setIcon(icon2);

        hboxLayout1->addWidget(MidiDisconnectPushButton);

        MidiDisconnectAllPushButton = new QPushButton(MidiConnectTab);
        MidiDisconnectAllPushButton->setObjectName(QString::fromUtf8("MidiDisconnectAllPushButton"));
        MidiDisconnectAllPushButton->setIcon(icon3);

        hboxLayout1->addWidget(MidiDisconnectAllPushButton);

        spacerItem2 = new QSpacerItem(8, 8, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem2);

        MidiExpandAllPushButton = new QPushButton(MidiConnectTab);
        MidiExpandAllPushButton->setObjectName(QString::fromUtf8("MidiExpandAllPushButton"));
        MidiExpandAllPushButton->setIcon(icon4);

        hboxLayout1->addWidget(MidiExpandAllPushButton);

        spacerItem3 = new QSpacerItem(8, 8, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem3);

        MidiRefreshPushButton = new QPushButton(MidiConnectTab);
        MidiRefreshPushButton->setObjectName(QString::fromUtf8("MidiRefreshPushButton"));
        MidiRefreshPushButton->setIcon(icon5);

        hboxLayout1->addWidget(MidiRefreshPushButton);


        gridLayout2->addLayout(hboxLayout1, 1, 0, 1, 1);

        ConnectionsTabWidget->addTab(MidiConnectTab, QString());
        AlsaConnectTab = new QWidget();
        AlsaConnectTab->setObjectName(QString::fromUtf8("AlsaConnectTab"));
        gridLayout3 = new QGridLayout(AlsaConnectTab);
        gridLayout3->setSpacing(4);
        gridLayout3->setContentsMargins(4, 4, 4, 4);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        AlsaConnectView = new qjackctlConnectView(AlsaConnectTab);
        AlsaConnectView->setObjectName(QString::fromUtf8("AlsaConnectView"));
        sizePolicy1.setHeightForWidth(AlsaConnectView->sizePolicy().hasHeightForWidth());
        AlsaConnectView->setSizePolicy(sizePolicy1);
        AlsaConnectView->setFocusPolicy(Qt::TabFocus);

        gridLayout3->addWidget(AlsaConnectView, 0, 0, 1, 1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(4);
        hboxLayout2->setContentsMargins(4, 4, 4, 4);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        AlsaConnectPushButton = new QPushButton(AlsaConnectTab);
        AlsaConnectPushButton->setObjectName(QString::fromUtf8("AlsaConnectPushButton"));
        AlsaConnectPushButton->setIcon(icon1);

        hboxLayout2->addWidget(AlsaConnectPushButton);

        AlsaDisconnectPushButton = new QPushButton(AlsaConnectTab);
        AlsaDisconnectPushButton->setObjectName(QString::fromUtf8("AlsaDisconnectPushButton"));
        AlsaDisconnectPushButton->setIcon(icon2);

        hboxLayout2->addWidget(AlsaDisconnectPushButton);

        AlsaDisconnectAllPushButton = new QPushButton(AlsaConnectTab);
        AlsaDisconnectAllPushButton->setObjectName(QString::fromUtf8("AlsaDisconnectAllPushButton"));
        AlsaDisconnectAllPushButton->setIcon(icon3);

        hboxLayout2->addWidget(AlsaDisconnectAllPushButton);

        spacerItem4 = new QSpacerItem(8, 8, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem4);

        AlsaExpandAllPushButton = new QPushButton(AlsaConnectTab);
        AlsaExpandAllPushButton->setObjectName(QString::fromUtf8("AlsaExpandAllPushButton"));
        AlsaExpandAllPushButton->setIcon(icon4);

        hboxLayout2->addWidget(AlsaExpandAllPushButton);

        spacerItem5 = new QSpacerItem(8, 8, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem5);

        AlsaRefreshPushButton = new QPushButton(AlsaConnectTab);
        AlsaRefreshPushButton->setObjectName(QString::fromUtf8("AlsaRefreshPushButton"));
        AlsaRefreshPushButton->setIcon(icon5);

        hboxLayout2->addWidget(AlsaRefreshPushButton);


        gridLayout3->addLayout(hboxLayout2, 1, 0, 1, 1);

        ConnectionsTabWidget->addTab(AlsaConnectTab, QString());

        gridLayout->addWidget(ConnectionsTabWidget, 0, 0, 1, 1);

        QWidget::setTabOrder(ConnectionsTabWidget, AudioConnectView);
        QWidget::setTabOrder(AudioConnectView, AudioConnectPushButton);
        QWidget::setTabOrder(AudioConnectPushButton, AudioDisconnectPushButton);
        QWidget::setTabOrder(AudioDisconnectPushButton, AudioDisconnectAllPushButton);
        QWidget::setTabOrder(AudioDisconnectAllPushButton, AudioExpandAllPushButton);
        QWidget::setTabOrder(AudioExpandAllPushButton, AudioRefreshPushButton);
        QWidget::setTabOrder(AudioRefreshPushButton, MidiConnectView);
        QWidget::setTabOrder(MidiConnectView, MidiConnectPushButton);
        QWidget::setTabOrder(MidiConnectPushButton, MidiDisconnectPushButton);
        QWidget::setTabOrder(MidiDisconnectPushButton, MidiDisconnectAllPushButton);
        QWidget::setTabOrder(MidiDisconnectAllPushButton, MidiExpandAllPushButton);
        QWidget::setTabOrder(MidiExpandAllPushButton, MidiRefreshPushButton);
        QWidget::setTabOrder(MidiRefreshPushButton, AlsaConnectView);
        QWidget::setTabOrder(AlsaConnectView, AlsaConnectPushButton);
        QWidget::setTabOrder(AlsaConnectPushButton, AlsaDisconnectPushButton);
        QWidget::setTabOrder(AlsaDisconnectPushButton, AlsaDisconnectAllPushButton);
        QWidget::setTabOrder(AlsaDisconnectAllPushButton, AlsaExpandAllPushButton);
        QWidget::setTabOrder(AlsaExpandAllPushButton, AlsaRefreshPushButton);

        retranslateUi(qjackctlConnectionsForm);

        ConnectionsTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(qjackctlConnectionsForm);
    } // setupUi

    void retranslateUi(QWidget *qjackctlConnectionsForm)
    {
        qjackctlConnectionsForm->setWindowTitle(QApplication::translate("qjackctlConnectionsForm", "Connections", nullptr));
#ifndef QT_NO_TOOLTIP
        AudioConnectPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Connect currently selected ports", nullptr));
#endif // QT_NO_TOOLTIP
        AudioConnectPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "&Connect", nullptr));
#ifndef QT_NO_TOOLTIP
        AudioDisconnectPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Disconnect currently selected ports", nullptr));
#endif // QT_NO_TOOLTIP
        AudioDisconnectPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "&Disconnect", nullptr));
#ifndef QT_NO_TOOLTIP
        AudioDisconnectAllPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Disconnect all currently connected ports", nullptr));
#endif // QT_NO_TOOLTIP
        AudioDisconnectAllPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "Disconnect &All", nullptr));
#ifndef QT_NO_TOOLTIP
        AudioExpandAllPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Expand all client ports", nullptr));
#endif // QT_NO_TOOLTIP
        AudioExpandAllPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "E&xpand All", nullptr));
#ifndef QT_NO_TOOLTIP
        AudioRefreshPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Refresh current connections view", nullptr));
#endif // QT_NO_TOOLTIP
        AudioRefreshPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "&Refresh", nullptr));
        ConnectionsTabWidget->setTabText(ConnectionsTabWidget->indexOf(AudioConnectTab), QApplication::translate("qjackctlConnectionsForm", "Audio", nullptr));
#ifndef QT_NO_TOOLTIP
        MidiConnectPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Connect currently selected ports", nullptr));
#endif // QT_NO_TOOLTIP
        MidiConnectPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "&Connect", nullptr));
#ifndef QT_NO_TOOLTIP
        MidiDisconnectPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Disconnect currently selected ports", nullptr));
#endif // QT_NO_TOOLTIP
        MidiDisconnectPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "&Disconnect", nullptr));
#ifndef QT_NO_TOOLTIP
        MidiDisconnectAllPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Disconnect all currently connected ports", nullptr));
#endif // QT_NO_TOOLTIP
        MidiDisconnectAllPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "Disconnect &All", nullptr));
#ifndef QT_NO_TOOLTIP
        MidiExpandAllPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Expand all client ports", nullptr));
#endif // QT_NO_TOOLTIP
        MidiExpandAllPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "E&xpand All", nullptr));
#ifndef QT_NO_TOOLTIP
        MidiRefreshPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Refresh current connections view", nullptr));
#endif // QT_NO_TOOLTIP
        MidiRefreshPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "&Refresh", nullptr));
        ConnectionsTabWidget->setTabText(ConnectionsTabWidget->indexOf(MidiConnectTab), QApplication::translate("qjackctlConnectionsForm", "MIDI", nullptr));
#ifndef QT_NO_TOOLTIP
        AlsaConnectPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Connect currently selected ports", nullptr));
#endif // QT_NO_TOOLTIP
        AlsaConnectPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "&Connect", nullptr));
#ifndef QT_NO_TOOLTIP
        AlsaDisconnectPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Disconnect currently selected ports", nullptr));
#endif // QT_NO_TOOLTIP
        AlsaDisconnectPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "&Disconnect", nullptr));
#ifndef QT_NO_TOOLTIP
        AlsaDisconnectAllPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Disconnect all currently connected ports", nullptr));
#endif // QT_NO_TOOLTIP
        AlsaDisconnectAllPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "Disconnect &All", nullptr));
#ifndef QT_NO_TOOLTIP
        AlsaExpandAllPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Expand all client ports", nullptr));
#endif // QT_NO_TOOLTIP
        AlsaExpandAllPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "E&xpand All", nullptr));
#ifndef QT_NO_TOOLTIP
        AlsaRefreshPushButton->setToolTip(QApplication::translate("qjackctlConnectionsForm", "Refresh current connections view", nullptr));
#endif // QT_NO_TOOLTIP
        AlsaRefreshPushButton->setText(QApplication::translate("qjackctlConnectionsForm", "&Refresh", nullptr));
        ConnectionsTabWidget->setTabText(ConnectionsTabWidget->indexOf(AlsaConnectTab), QApplication::translate("qjackctlConnectionsForm", "ALSA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qjackctlConnectionsForm: public Ui_qjackctlConnectionsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QJACKCTLCONNECTIONSFORM_H
