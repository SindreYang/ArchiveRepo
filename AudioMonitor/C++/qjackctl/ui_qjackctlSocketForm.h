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
** Form generated from reading UI file 'qjackctlSocketForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QJACKCTLSOCKETFORM_H
#define UI_QJACKCTLSOCKETFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qjackctlSocketForm
{
public:
    QVBoxLayout *vboxLayout;
    QTabWidget *SocketTabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QLabel *SocketNameTextLabel;
    QLineEdit *SocketNameLineEdit;
    QComboBox *ClientNameComboBox;
    QPushButton *PlugAddPushButton;
    QLabel *PlugNameTextLabel;
    QComboBox *PlugNameComboBox;
    QTreeWidget *PlugListView;
    QPushButton *PlugEditPushButton;
    QPushButton *PlugRemovePushButton;
    QLabel *ClientNameTextLabel;
    QPushButton *PlugDownPushButton;
    QPushButton *PlugUpPushButton;
    QSpacerItem *spacerItem;
    QCheckBox *ExclusiveCheckBox;
    QLabel *SocketForwardTextLabel;
    QComboBox *SocketForwardComboBox;
    QGroupBox *SocketTypeGroupBox;
    QHBoxLayout *hboxLayout;
    QRadioButton *AudioRadioButton;
    QRadioButton *MidiRadioButton;
    QRadioButton *AlsaRadioButton;
    QDialogButtonBox *DialogButtonBox;

    void setupUi(QDialog *qjackctlSocketForm)
    {
        if (qjackctlSocketForm->objectName().isEmpty())
            qjackctlSocketForm->setObjectName(QString::fromUtf8("qjackctlSocketForm"));
        qjackctlSocketForm->resize(400, 300);
        const QIcon icon = QIcon(QString::fromUtf8(":/images/patchbay1.png"));
        qjackctlSocketForm->setWindowIcon(icon);
        vboxLayout = new QVBoxLayout(qjackctlSocketForm);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(9, 9, 9, 9);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        SocketTabWidget = new QTabWidget(qjackctlSocketForm);
        SocketTabWidget->setObjectName(QString::fromUtf8("SocketTabWidget"));
        SocketTabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(4);
        gridLayout->setContentsMargins(8, 8, 8, 8);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        SocketNameTextLabel = new QLabel(tab);
        SocketNameTextLabel->setObjectName(QString::fromUtf8("SocketNameTextLabel"));
        SocketNameTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SocketNameTextLabel->setWordWrap(false);

        gridLayout->addWidget(SocketNameTextLabel, 0, 0, 1, 1);

        SocketNameLineEdit = new QLineEdit(tab);
        SocketNameLineEdit->setObjectName(QString::fromUtf8("SocketNameLineEdit"));

        gridLayout->addWidget(SocketNameLineEdit, 0, 1, 1, 2);

        ClientNameComboBox = new QComboBox(tab);
        ClientNameComboBox->setObjectName(QString::fromUtf8("ClientNameComboBox"));
        ClientNameComboBox->setEditable(true);

        gridLayout->addWidget(ClientNameComboBox, 2, 1, 1, 2);

        PlugAddPushButton = new QPushButton(tab);
        PlugAddPushButton->setObjectName(QString::fromUtf8("PlugAddPushButton"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/images/add1.png"));
        PlugAddPushButton->setIcon(icon1);

        gridLayout->addWidget(PlugAddPushButton, 3, 2, 1, 1);

        PlugNameTextLabel = new QLabel(tab);
        PlugNameTextLabel->setObjectName(QString::fromUtf8("PlugNameTextLabel"));
        PlugNameTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        PlugNameTextLabel->setWordWrap(false);

        gridLayout->addWidget(PlugNameTextLabel, 3, 0, 1, 1);

        PlugNameComboBox = new QComboBox(tab);
        PlugNameComboBox->setObjectName(QString::fromUtf8("PlugNameComboBox"));
        PlugNameComboBox->setEditable(true);

        gridLayout->addWidget(PlugNameComboBox, 3, 1, 1, 1);

        PlugListView = new QTreeWidget(tab);
        PlugListView->setObjectName(QString::fromUtf8("PlugListView"));
        PlugListView->setContextMenuPolicy(Qt::CustomContextMenu);
        PlugListView->setRootIsDecorated(false);
        PlugListView->setUniformRowHeights(true);
        PlugListView->setItemsExpandable(false);
        PlugListView->setAllColumnsShowFocus(true);

        gridLayout->addWidget(PlugListView, 4, 1, 5, 1);

        PlugEditPushButton = new QPushButton(tab);
        PlugEditPushButton->setObjectName(QString::fromUtf8("PlugEditPushButton"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/images/edit1.png"));
        PlugEditPushButton->setIcon(icon2);

        gridLayout->addWidget(PlugEditPushButton, 4, 2, 1, 1);

        PlugRemovePushButton = new QPushButton(tab);
        PlugRemovePushButton->setObjectName(QString::fromUtf8("PlugRemovePushButton"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/images/remove1.png"));
        PlugRemovePushButton->setIcon(icon3);

        gridLayout->addWidget(PlugRemovePushButton, 5, 2, 1, 1);

        ClientNameTextLabel = new QLabel(tab);
        ClientNameTextLabel->setObjectName(QString::fromUtf8("ClientNameTextLabel"));
        ClientNameTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ClientNameTextLabel->setWordWrap(false);

        gridLayout->addWidget(ClientNameTextLabel, 2, 0, 1, 1);

        PlugDownPushButton = new QPushButton(tab);
        PlugDownPushButton->setObjectName(QString::fromUtf8("PlugDownPushButton"));
        const QIcon icon4 = QIcon(QString::fromUtf8(":/images/down1.png"));
        PlugDownPushButton->setIcon(icon4);

        gridLayout->addWidget(PlugDownPushButton, 8, 2, 1, 1);

        PlugUpPushButton = new QPushButton(tab);
        PlugUpPushButton->setObjectName(QString::fromUtf8("PlugUpPushButton"));
        const QIcon icon5 = QIcon(QString::fromUtf8(":/images/up1.png"));
        PlugUpPushButton->setIcon(icon5);

        gridLayout->addWidget(PlugUpPushButton, 7, 2, 1, 1);

        spacerItem = new QSpacerItem(8, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 6, 2, 1, 1);

        ExclusiveCheckBox = new QCheckBox(tab);
        ExclusiveCheckBox->setObjectName(QString::fromUtf8("ExclusiveCheckBox"));

        gridLayout->addWidget(ExclusiveCheckBox, 9, 1, 1, 1);

        SocketForwardTextLabel = new QLabel(tab);
        SocketForwardTextLabel->setObjectName(QString::fromUtf8("SocketForwardTextLabel"));
        SocketForwardTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SocketForwardTextLabel->setWordWrap(false);

        gridLayout->addWidget(SocketForwardTextLabel, 10, 0, 1, 1);

        SocketForwardComboBox = new QComboBox(tab);
        SocketForwardComboBox->setObjectName(QString::fromUtf8("SocketForwardComboBox"));
        SocketForwardComboBox->setEditable(false);

        gridLayout->addWidget(SocketForwardComboBox, 10, 1, 1, 2);

        SocketTypeGroupBox = new QGroupBox(tab);
        SocketTypeGroupBox->setObjectName(QString::fromUtf8("SocketTypeGroupBox"));
        hboxLayout = new QHBoxLayout(SocketTypeGroupBox);
        hboxLayout->setSpacing(4);
        hboxLayout->setContentsMargins(8, 8, 8, 8);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        AudioRadioButton = new QRadioButton(SocketTypeGroupBox);
        AudioRadioButton->setObjectName(QString::fromUtf8("AudioRadioButton"));

        hboxLayout->addWidget(AudioRadioButton);

        MidiRadioButton = new QRadioButton(SocketTypeGroupBox);
        MidiRadioButton->setObjectName(QString::fromUtf8("MidiRadioButton"));

        hboxLayout->addWidget(MidiRadioButton);

        AlsaRadioButton = new QRadioButton(SocketTypeGroupBox);
        AlsaRadioButton->setObjectName(QString::fromUtf8("AlsaRadioButton"));

        hboxLayout->addWidget(AlsaRadioButton);


        gridLayout->addWidget(SocketTypeGroupBox, 1, 1, 1, 2);

        SocketTabWidget->addTab(tab, QString());

        vboxLayout->addWidget(SocketTabWidget);

        DialogButtonBox = new QDialogButtonBox(qjackctlSocketForm);
        DialogButtonBox->setObjectName(QString::fromUtf8("DialogButtonBox"));
        DialogButtonBox->setOrientation(Qt::Horizontal);
        DialogButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        vboxLayout->addWidget(DialogButtonBox);

#ifndef QT_NO_SHORTCUT
        SocketNameTextLabel->setBuddy(SocketNameLineEdit);
        PlugNameTextLabel->setBuddy(PlugNameComboBox);
        ClientNameTextLabel->setBuddy(ClientNameComboBox);
        SocketForwardTextLabel->setBuddy(SocketForwardComboBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(SocketTabWidget, SocketNameLineEdit);
        QWidget::setTabOrder(SocketNameLineEdit, AudioRadioButton);
        QWidget::setTabOrder(AudioRadioButton, MidiRadioButton);
        QWidget::setTabOrder(MidiRadioButton, AlsaRadioButton);
        QWidget::setTabOrder(AlsaRadioButton, ClientNameComboBox);
        QWidget::setTabOrder(ClientNameComboBox, PlugNameComboBox);
        QWidget::setTabOrder(PlugNameComboBox, PlugAddPushButton);
        QWidget::setTabOrder(PlugAddPushButton, PlugListView);
        QWidget::setTabOrder(PlugListView, PlugEditPushButton);
        QWidget::setTabOrder(PlugEditPushButton, PlugRemovePushButton);
        QWidget::setTabOrder(PlugRemovePushButton, PlugUpPushButton);
        QWidget::setTabOrder(PlugUpPushButton, PlugDownPushButton);
        QWidget::setTabOrder(PlugDownPushButton, ExclusiveCheckBox);
        QWidget::setTabOrder(ExclusiveCheckBox, SocketForwardComboBox);
        QWidget::setTabOrder(SocketForwardComboBox, DialogButtonBox);

        retranslateUi(qjackctlSocketForm);

        QMetaObject::connectSlotsByName(qjackctlSocketForm);
    } // setupUi

    void retranslateUi(QDialog *qjackctlSocketForm)
    {
        qjackctlSocketForm->setWindowTitle(QApplication::translate("qjackctlSocketForm", "Socket", nullptr));
        SocketNameTextLabel->setText(QApplication::translate("qjackctlSocketForm", "&Name (alias):", nullptr));
#ifndef QT_NO_TOOLTIP
        SocketNameLineEdit->setToolTip(QApplication::translate("qjackctlSocketForm", "Socket name (an alias for client name)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ClientNameComboBox->setToolTip(QApplication::translate("qjackctlSocketForm", "Client name (regular expression)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        PlugAddPushButton->setToolTip(QApplication::translate("qjackctlSocketForm", "Add plug to socket plug list", nullptr));
#endif // QT_NO_TOOLTIP
        PlugAddPushButton->setText(QApplication::translate("qjackctlSocketForm", "Add P&lug", nullptr));
        PlugNameTextLabel->setText(QApplication::translate("qjackctlSocketForm", "&Plug:", nullptr));
#ifndef QT_NO_TOOLTIP
        PlugNameComboBox->setToolTip(QApplication::translate("qjackctlSocketForm", "Port name (regular expression)", nullptr));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem = PlugListView->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("qjackctlSocketForm", "Socket Plugs / Ports", nullptr));
#ifndef QT_NO_TOOLTIP
        PlugListView->setToolTip(QApplication::translate("qjackctlSocketForm", "Socket plug list", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        PlugEditPushButton->setToolTip(QApplication::translate("qjackctlSocketForm", "Edit currently selected plug", nullptr));
#endif // QT_NO_TOOLTIP
        PlugEditPushButton->setText(QApplication::translate("qjackctlSocketForm", "&Edit", nullptr));
#ifndef QT_NO_TOOLTIP
        PlugRemovePushButton->setToolTip(QApplication::translate("qjackctlSocketForm", "Remove currently selected plug from socket plug list", nullptr));
#endif // QT_NO_TOOLTIP
        PlugRemovePushButton->setText(QApplication::translate("qjackctlSocketForm", "&Remove", nullptr));
        ClientNameTextLabel->setText(QApplication::translate("qjackctlSocketForm", "&Client:", nullptr));
#ifndef QT_NO_TOOLTIP
        PlugDownPushButton->setToolTip(QApplication::translate("qjackctlSocketForm", "Move down currently selected plug in socket plug list", nullptr));
#endif // QT_NO_TOOLTIP
        PlugDownPushButton->setText(QApplication::translate("qjackctlSocketForm", "&Down", nullptr));
#ifndef QT_NO_TOOLTIP
        PlugUpPushButton->setToolTip(QApplication::translate("qjackctlSocketForm", "Move up current selected plug in socket plug list", nullptr));
#endif // QT_NO_TOOLTIP
        PlugUpPushButton->setText(QApplication::translate("qjackctlSocketForm", "&Up", nullptr));
#ifndef QT_NO_TOOLTIP
        ExclusiveCheckBox->setToolTip(QApplication::translate("qjackctlSocketForm", "Enforce only one exclusive cable connection", nullptr));
#endif // QT_NO_TOOLTIP
        ExclusiveCheckBox->setText(QApplication::translate("qjackctlSocketForm", "E&xclusive", nullptr));
        SocketForwardTextLabel->setText(QApplication::translate("qjackctlSocketForm", "&Forward:", nullptr));
#ifndef QT_NO_TOOLTIP
        SocketForwardComboBox->setToolTip(QApplication::translate("qjackctlSocketForm", "Forward (clone) all connections from this socket", nullptr));
#endif // QT_NO_TOOLTIP
        SocketTypeGroupBox->setTitle(QApplication::translate("qjackctlSocketForm", "Type", nullptr));
#ifndef QT_NO_TOOLTIP
        AudioRadioButton->setToolTip(QApplication::translate("qjackctlSocketForm", "Audio socket type (JACK)", nullptr));
#endif // QT_NO_TOOLTIP
        AudioRadioButton->setText(QApplication::translate("qjackctlSocketForm", "&Audio", nullptr));
#ifndef QT_NO_TOOLTIP
        MidiRadioButton->setToolTip(QApplication::translate("qjackctlSocketForm", "MIDI socket type (JACK)", nullptr));
#endif // QT_NO_TOOLTIP
        MidiRadioButton->setText(QApplication::translate("qjackctlSocketForm", "&MIDI", nullptr));
#ifndef QT_NO_TOOLTIP
        AlsaRadioButton->setToolTip(QApplication::translate("qjackctlSocketForm", "MIDI socket type (ALSA)", nullptr));
#endif // QT_NO_TOOLTIP
        AlsaRadioButton->setText(QApplication::translate("qjackctlSocketForm", "AL&SA", nullptr));
        SocketTabWidget->setTabText(SocketTabWidget->indexOf(tab), QApplication::translate("qjackctlSocketForm", "&Socket", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qjackctlSocketForm: public Ui_qjackctlSocketForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QJACKCTLSOCKETFORM_H
