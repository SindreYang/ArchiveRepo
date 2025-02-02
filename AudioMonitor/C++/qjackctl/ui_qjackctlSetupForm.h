/*
JACK Audio Connection Kit - Qt GUI Interface.

   Copyright (C) 2003-2019, rncbc aka Rui Nuno Capela. All rights reserved.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  S1ee the
   GNU General Public License for more details.


   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.


*/

/********************************************************************************
** Form generated from reading UI file 'qjackctlSetupForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QJACKCTLSETUPFORM_H
#define UI_QJACKCTLSETUPFORM_H

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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qjackctlInterfaceComboBox.h"

QT_BEGIN_NAMESPACE

class Ui_qjackctlSetupForm
{
public:
    QVBoxLayout *vboxLayout;
    QTabWidget *SetupTabWidget;
    QWidget *SettingsTabPage;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout;
    QLabel *PresetTextLabel;
    QComboBox *PresetComboBox;
    QPushButton *PresetSavePushButton;
    QPushButton *PresetDeletePushButton;
    QTabWidget *SettingsTabWidget;
    QWidget *ParametersTab;
    QVBoxLayout *vboxLayout2;
    QGridLayout *gridLayout;
    QLabel *DriverTextLabel;
    QComboBox *DriverComboBox;
    QSpacerItem *spacerItem;
    QLabel *InterfaceTextLabel;
    qjackctlInterfaceComboBox *InterfaceComboBox;
    QSpacerItem *spacerItem1;
    QLabel *MidiDriverTextLabel;
    QComboBox *MidiDriverComboBox;
    QCheckBox *RealtimeCheckBox;
    QLabel *SampleRateTextLabel;
    QComboBox *SampleRateComboBox;
    QSpacerItem *spacerItem2;
    QLabel *FramesTextLabel;
    QComboBox *FramesComboBox;
    QLabel *PeriodsTextLabel;
    QSpinBox *PeriodsSpinBox;
    QSpacerItem *spacerItem3;
    QCheckBox *SyncCheckBox;
    QHBoxLayout *hboxLayout1;
    QCheckBox *VerboseCheckBox;
    QSpacerItem *spacerItem4;
    QLabel *LatencyTextLabel;
    QLabel *LatencyTextValue;
    QWidget *AdvancedTab;
    QGridLayout *gridLayout1;
    QLabel *label;
    QHBoxLayout *hboxLayout2;
    QLabel *ServerPrefixTextLabel;
    QComboBox *ServerPrefixComboBox;
    QLabel *ServerNameTextLabel;
    QComboBox *ServerNameComboBox;
    QSpacerItem *spacerItem5;
    QVBoxLayout *vboxLayout3;
    QCheckBox *NoMemLockCheckBox;
    QCheckBox *UnlockMemCheckBox;
    QCheckBox *HWMeterCheckBox;
    QCheckBox *MonitorCheckBox;
    QCheckBox *SoftModeCheckBox;
    QCheckBox *ShortsCheckBox;
    QCheckBox *IgnoreHWCheckBox;
    QSpacerItem *spacerItem6;
    QGridLayout *gridLayout2;
    QSpinBox *ChanSpinBox;
    QComboBox *WaitComboBox;
    QLabel *PriorityTextLabel;
    QComboBox *TimeoutComboBox;
    QLabel *PortMaxTextLabel;
    QLabel *ChanTextLabel;
    QComboBox *WordLengthComboBox;
    QLabel *WaitTextLabel;
    QLabel *TimeoutTextLabel;
    QComboBox *PortMaxComboBox;
    QLabel *WordLengthTextLabel;
    QSpinBox *PrioritySpinBox;
    QSpacerItem *spacerItem7;
    QGridLayout *gridLayout3;
    QLabel *AudioTextLabel;
    QComboBox *AudioComboBox;
    QLabel *DitherTextLabel;
    QComboBox *DitherComboBox;
    QLabel *OutDeviceTextLabel;
    qjackctlInterfaceComboBox *OutDeviceComboBox;
    QLabel *InDeviceTextLabel;
    qjackctlInterfaceComboBox *InDeviceComboBox;
    QLabel *InOutChannelsTextLabel;
    QSpinBox *InChannelsSpinBox;
    QSpinBox *OutChannelsSpinBox;
    QLabel *InOutLatencyTextLabel;
    QSpinBox *InLatencySpinBox;
    QSpinBox *OutLatencySpinBox;
    QSpacerItem *spacerItem8;
    QSpacerItem *spacerItem9;
    QHBoxLayout *hboxLayout3;
    QLabel *ServerSuffixTextLabel;
    QComboBox *ServerSuffixComboBox;
    QLabel *StartDelayTextLabel;
    QSpinBox *StartDelaySpinBox;
    QWidget *OptionsTabPage;
    QVBoxLayout *vboxLayout4;
    QGroupBox *ScriptingGroupBox;
    QGridLayout *gridLayout4;
    QCheckBox *StartupScriptCheckBox;
    QCheckBox *PostStartupScriptCheckBox;
    QCheckBox *ShutdownScriptCheckBox;
    QComboBox *StartupScriptShellComboBox;
    QToolButton *StartupScriptSymbolToolButton;
    QToolButton *StartupScriptBrowseToolButton;
    QComboBox *PostStartupScriptShellComboBox;
    QToolButton *PostStartupScriptSymbolToolButton;
    QToolButton *PostStartupScriptBrowseToolButton;
    QToolButton *ShutdownScriptSymbolToolButton;
    QToolButton *ShutdownScriptBrowseToolButton;
    QComboBox *ShutdownScriptShellComboBox;
    QCheckBox *PostShutdownScriptCheckBox;
    QToolButton *PostShutdownScriptSymbolToolButton;
    QToolButton *PostShutdownScriptBrowseToolButton;
    QComboBox *PostShutdownScriptShellComboBox;
    QGroupBox *StatisticsGroupBox;
    QGridLayout *gridLayout5;
    QCheckBox *StdoutCaptureCheckBox;
    QLabel *XrunRegexTextLabel;
    QComboBox *XrunRegexComboBox;
    QGroupBox *ConnectionsGroupBox;
    QGridLayout *gridLayout6;
    QCheckBox *ActivePatchbayCheckBox;
    QComboBox *ActivePatchbayPathComboBox;
    QToolButton *ActivePatchbayPathToolButton;
    QCheckBox *ActivePatchbayResetCheckBox;
    QCheckBox *QueryDisconnectCheckBox;
    QSpacerItem *spacerItem10;
    QGroupBox *LoggingGroupBox;
    QGridLayout *gridLayout7;
    QCheckBox *MessagesLogCheckBox;
    QComboBox *MessagesLogPathComboBox;
    QToolButton *MessagesLogPathToolButton;
    QWidget *DisplayTabPage;
    QVBoxLayout *vboxLayout5;
    QGroupBox *TimeDisplayGroupBox;
    QGridLayout *gridLayout8;
    QVBoxLayout *vboxLayout6;
    QRadioButton *TransportTimeRadioButton;
    QRadioButton *TransportBBTRadioButton;
    QRadioButton *ElapsedResetRadioButton;
    QRadioButton *ElapsedXrunRadioButton;
    QSpacerItem *spacerItem11;
    QGridLayout *gridLayout9;
    QLabel *DisplayFont2TextLabel;
    QLabel *DisplayFont1TextLabel;
    QLabel *DisplayFont1Label;
    QPushButton *DisplayFont2PushButton;
    QPushButton *DisplayFont1PushButton;
    QLabel *DisplayFont2Label;
    QCheckBox *DisplayBlinkCheckBox;
    QGroupBox *DisplayCustomGroupBox;
    QGridLayout *gridLayout10;
    QLabel *CustomColorThemeTextLabel;
    QComboBox *CustomColorThemeComboBox;
    QToolButton *CustomColorThemeToolButton;
    QSpacerItem *spacerItem12;
    QLabel *CustomStyleThemeTextLabel;
    QComboBox *CustomStyleThemeComboBox;
    QSpacerItem *spacerItem13;
    QGroupBox *MessagesWindowGroupBox;
    QHBoxLayout *hboxLayout4;
    QLabel *MessagesFontTextLabel;
    QPushButton *MessagesFontPushButton;
    QSpacerItem *spacerItem14;
    QCheckBox *MessagesLimitCheckBox;
    QComboBox *MessagesLimitLinesComboBox;
    QSpacerItem *spacerItem15;
    QGroupBox *ConnectionsWindowGroupBox;
    QGridLayout *gridLayout11;
    QLabel *ConnectionsFontTextLabel;
    QPushButton *ConnectionsFontPushButton;
    QSpacerItem *spacerItem16;
    QLabel *ConnectionsIconSizeTextLabel;
    QComboBox *ConnectionsIconSizeComboBox;
    QSpacerItem *spacerItem17;
    QCheckBox *AliasesEnabledCheckBox;
    QLabel *JackClientPortAliasTextLabel;
    QComboBox *JackClientPortAliasComboBox;
    QCheckBox *AliasesEditingCheckBox;
    QCheckBox *JackClientPortMetadataCheckBox;
    QWidget *MiscTabPage;
    QGridLayout *gridLayout12;
    QGroupBox *OtherGroupBox;
    QGridLayout *gridLayout13;
    QVBoxLayout *vboxLayout7;
    QCheckBox *StartJackCheckBox;
    QCheckBox *QueryCloseCheckBox;
    QCheckBox *QueryShutdownCheckBox;
    QCheckBox *KeepOnTopCheckBox;
    QCheckBox *SystemTrayCheckBox;
    QCheckBox *SystemTrayQueryCloseCheckBox;
    QCheckBox *StartMinimizedCheckBox;
    QVBoxLayout *vboxLayout8;
    QCheckBox *ServerConfigCheckBox;
    QComboBox *ServerConfigNameComboBox;
    QCheckBox *AlsaSeqEnabledCheckBox;
    QCheckBox *DBusEnabledCheckBox;
    QCheckBox *JackDBusEnabledCheckBox;
    QCheckBox *StopJackCheckBox;
    QCheckBox *SingletonCheckBox;
    QSpacerItem *spacerItem18;
    QGroupBox *ButtonsGroupBox;
    QVBoxLayout *vboxLayout9;
    QVBoxLayout *vboxLayout10;
    QCheckBox *LeftButtonsCheckBox;
    QCheckBox *RightButtonsCheckBox;
    QCheckBox *TransportButtonsCheckBox;
    QCheckBox *TextLabelsCheckBox;
    QSpacerItem *spacerItem19;
    QCheckBox *GraphButtonCheckBox;
    QGroupBox *DefaultsGroupBox;
    QGridLayout *gridLayout14;
    QSpacerItem *spacerItem20;
    QLabel *BaseFontSizeTextLabel;
    QComboBox *BaseFontSizeComboBox;
    QDialogButtonBox *DialogButtonBox;

    void setupUi(QDialog *qjackctlSetupForm)
    {
        if (qjackctlSetupForm->objectName().isEmpty())
            qjackctlSetupForm->setObjectName(QString::fromUtf8("qjackctlSetupForm"));
        qjackctlSetupForm->resize(640, 520);
        const QIcon icon = QIcon(QString::fromUtf8(":/images/setup1.png"));
        qjackctlSetupForm->setWindowIcon(icon);
        qjackctlSetupForm->setSizeGripEnabled(true);
        vboxLayout = new QVBoxLayout(qjackctlSetupForm);
        vboxLayout->setSpacing(4);
        vboxLayout->setContentsMargins(8, 8, 8, 8);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        SetupTabWidget = new QTabWidget(qjackctlSetupForm);
        SetupTabWidget->setObjectName(QString::fromUtf8("SetupTabWidget"));
        SetupTabWidget->setAcceptDrops(false);
        SettingsTabPage = new QWidget();
        SettingsTabPage->setObjectName(QString::fromUtf8("SettingsTabPage"));
        vboxLayout1 = new QVBoxLayout(SettingsTabPage);
        vboxLayout1->setSpacing(4);
        vboxLayout1->setContentsMargins(8, 8, 8, 8);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(4);
        hboxLayout->setContentsMargins(4, 4, 4, 4);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        PresetTextLabel = new QLabel(SettingsTabPage);
        PresetTextLabel->setObjectName(QString::fromUtf8("PresetTextLabel"));
        PresetTextLabel->setWordWrap(false);

        hboxLayout->addWidget(PresetTextLabel);

        PresetComboBox = new QComboBox(SettingsTabPage);
        PresetComboBox->addItem(QString());
        PresetComboBox->setObjectName(QString::fromUtf8("PresetComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PresetComboBox->sizePolicy().hasHeightForWidth());
        PresetComboBox->setSizePolicy(sizePolicy);
        PresetComboBox->setEditable(true);

        hboxLayout->addWidget(PresetComboBox);

        PresetSavePushButton = new QPushButton(SettingsTabPage);
        PresetSavePushButton->setObjectName(QString::fromUtf8("PresetSavePushButton"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/images/save1.png"));
        PresetSavePushButton->setIcon(icon1);
        PresetSavePushButton->setAutoDefault(false);

        hboxLayout->addWidget(PresetSavePushButton);

        PresetDeletePushButton = new QPushButton(SettingsTabPage);
        PresetDeletePushButton->setObjectName(QString::fromUtf8("PresetDeletePushButton"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/images/remove1.png"));
        PresetDeletePushButton->setIcon(icon2);
        PresetDeletePushButton->setAutoDefault(false);

        hboxLayout->addWidget(PresetDeletePushButton);


        vboxLayout1->addLayout(hboxLayout);

        SettingsTabWidget = new QTabWidget(SettingsTabPage);
        SettingsTabWidget->setObjectName(QString::fromUtf8("SettingsTabWidget"));
        ParametersTab = new QWidget();
        ParametersTab->setObjectName(QString::fromUtf8("ParametersTab"));
        vboxLayout2 = new QVBoxLayout(ParametersTab);
        vboxLayout2->setSpacing(4);
        vboxLayout2->setContentsMargins(8, 8, 8, 8);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(4);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        DriverTextLabel = new QLabel(ParametersTab);
        DriverTextLabel->setObjectName(QString::fromUtf8("DriverTextLabel"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        DriverTextLabel->setFont(font);
        DriverTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        DriverTextLabel->setWordWrap(false);

        gridLayout->addWidget(DriverTextLabel, 0, 0, 1, 1);

        DriverComboBox = new QComboBox(ParametersTab);
        DriverComboBox->addItem(QString());
        DriverComboBox->addItem(QString());
        DriverComboBox->addItem(QString());
        DriverComboBox->addItem(QString());
        DriverComboBox->addItem(QString());
        DriverComboBox->addItem(QString());
        DriverComboBox->addItem(QString());
        DriverComboBox->addItem(QString());
        DriverComboBox->addItem(QString());
        DriverComboBox->setObjectName(QString::fromUtf8("DriverComboBox"));
        DriverComboBox->setFont(font);
        DriverComboBox->setEditable(false);

        gridLayout->addWidget(DriverComboBox, 0, 1, 1, 1);

        spacerItem = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 0, 2, 4, 1);

        InterfaceTextLabel = new QLabel(ParametersTab);
        InterfaceTextLabel->setObjectName(QString::fromUtf8("InterfaceTextLabel"));
        InterfaceTextLabel->setFont(font);
        InterfaceTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        InterfaceTextLabel->setWordWrap(false);

        gridLayout->addWidget(InterfaceTextLabel, 0, 3, 1, 1);

        InterfaceComboBox = new qjackctlInterfaceComboBox(ParametersTab);
        InterfaceComboBox->addItem(QString());
        InterfaceComboBox->addItem(QString());
        InterfaceComboBox->addItem(QString());
        InterfaceComboBox->addItem(QString());
        InterfaceComboBox->addItem(QString());
        InterfaceComboBox->setObjectName(QString::fromUtf8("InterfaceComboBox"));
        InterfaceComboBox->setMinimumSize(QSize(140, 0));
        InterfaceComboBox->setFont(font);
        InterfaceComboBox->setEditable(true);

        gridLayout->addWidget(InterfaceComboBox, 0, 4, 1, 2);

        spacerItem1 = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem1, 0, 6, 4, 1);

        MidiDriverTextLabel = new QLabel(ParametersTab);
        MidiDriverTextLabel->setObjectName(QString::fromUtf8("MidiDriverTextLabel"));
        MidiDriverTextLabel->setFont(font);
        MidiDriverTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MidiDriverTextLabel->setWordWrap(false);

        gridLayout->addWidget(MidiDriverTextLabel, 0, 7, 1, 1);

        MidiDriverComboBox = new QComboBox(ParametersTab);
        MidiDriverComboBox->addItem(QString());
        MidiDriverComboBox->addItem(QString());
        MidiDriverComboBox->addItem(QString());
        MidiDriverComboBox->setObjectName(QString::fromUtf8("MidiDriverComboBox"));
        MidiDriverComboBox->setMinimumSize(QSize(80, 0));
        MidiDriverComboBox->setFont(font);
        MidiDriverComboBox->setEditable(false);

        gridLayout->addWidget(MidiDriverComboBox, 0, 8, 1, 1);

        RealtimeCheckBox = new QCheckBox(ParametersTab);
        RealtimeCheckBox->setObjectName(QString::fromUtf8("RealtimeCheckBox"));
        RealtimeCheckBox->setFont(font);

        gridLayout->addWidget(RealtimeCheckBox, 1, 1, 1, 1);

        SampleRateTextLabel = new QLabel(ParametersTab);
        SampleRateTextLabel->setObjectName(QString::fromUtf8("SampleRateTextLabel"));
        SampleRateTextLabel->setFont(font);
        SampleRateTextLabel->setFrameShape(QFrame::NoFrame);
        SampleRateTextLabel->setFrameShadow(QFrame::Plain);
        SampleRateTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SampleRateTextLabel->setWordWrap(false);

        gridLayout->addWidget(SampleRateTextLabel, 1, 3, 1, 1);

        SampleRateComboBox = new QComboBox(ParametersTab);
        SampleRateComboBox->addItem(QString());
        SampleRateComboBox->addItem(QString());
        SampleRateComboBox->addItem(QString());
        SampleRateComboBox->addItem(QString());
        SampleRateComboBox->addItem(QString());
        SampleRateComboBox->addItem(QString());
        SampleRateComboBox->addItem(QString());
        SampleRateComboBox->setObjectName(QString::fromUtf8("SampleRateComboBox"));
        SampleRateComboBox->setFont(font);
        SampleRateComboBox->setEditable(true);

        gridLayout->addWidget(SampleRateComboBox, 1, 4, 1, 1);

        spacerItem2 = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem2, 1, 5, 3, 1);

        FramesTextLabel = new QLabel(ParametersTab);
        FramesTextLabel->setObjectName(QString::fromUtf8("FramesTextLabel"));
        FramesTextLabel->setFont(font);
        FramesTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FramesTextLabel->setWordWrap(false);

        gridLayout->addWidget(FramesTextLabel, 2, 3, 1, 1);

        FramesComboBox = new QComboBox(ParametersTab);
        FramesComboBox->addItem(QString());
        FramesComboBox->addItem(QString());
        FramesComboBox->addItem(QString());
        FramesComboBox->addItem(QString());
        FramesComboBox->addItem(QString());
        FramesComboBox->addItem(QString());
        FramesComboBox->addItem(QString());
        FramesComboBox->addItem(QString());
        FramesComboBox->addItem(QString());
        FramesComboBox->setObjectName(QString::fromUtf8("FramesComboBox"));
        FramesComboBox->setFont(font);
        FramesComboBox->setEditable(true);

        gridLayout->addWidget(FramesComboBox, 2, 4, 1, 1);

        PeriodsTextLabel = new QLabel(ParametersTab);
        PeriodsTextLabel->setObjectName(QString::fromUtf8("PeriodsTextLabel"));
        PeriodsTextLabel->setFont(font);
        PeriodsTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        PeriodsTextLabel->setWordWrap(false);

        gridLayout->addWidget(PeriodsTextLabel, 3, 3, 1, 1);

        PeriodsSpinBox = new QSpinBox(ParametersTab);
        PeriodsSpinBox->setObjectName(QString::fromUtf8("PeriodsSpinBox"));
        PeriodsSpinBox->setFont(font);
        PeriodsSpinBox->setMinimum(2);
        PeriodsSpinBox->setMaximum(999);

        gridLayout->addWidget(PeriodsSpinBox, 3, 4, 1, 1);


        vboxLayout2->addLayout(gridLayout);

        spacerItem3 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout2->addItem(spacerItem3);

        SyncCheckBox = new QCheckBox(ParametersTab);
        SyncCheckBox->setObjectName(QString::fromUtf8("SyncCheckBox"));
        SyncCheckBox->setFont(font);

        vboxLayout2->addWidget(SyncCheckBox);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(4);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        VerboseCheckBox = new QCheckBox(ParametersTab);
        VerboseCheckBox->setObjectName(QString::fromUtf8("VerboseCheckBox"));
        VerboseCheckBox->setFont(font);

        hboxLayout1->addWidget(VerboseCheckBox);

        spacerItem4 = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem4);

        LatencyTextLabel = new QLabel(ParametersTab);
        LatencyTextLabel->setObjectName(QString::fromUtf8("LatencyTextLabel"));
        LatencyTextLabel->setFont(font);
        LatencyTextLabel->setFrameShape(QFrame::NoFrame);
        LatencyTextLabel->setFrameShadow(QFrame::Plain);
        LatencyTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LatencyTextLabel->setWordWrap(false);

        hboxLayout1->addWidget(LatencyTextLabel);

        LatencyTextValue = new QLabel(ParametersTab);
        LatencyTextValue->setObjectName(QString::fromUtf8("LatencyTextValue"));
        LatencyTextValue->setMinimumSize(QSize(72, 0));
        LatencyTextValue->setFont(font);
        LatencyTextValue->setFrameShape(QFrame::StyledPanel);
        LatencyTextValue->setFrameShadow(QFrame::Sunken);
        LatencyTextValue->setAlignment(Qt::AlignCenter);
        LatencyTextValue->setWordWrap(false);

        hboxLayout1->addWidget(LatencyTextValue);


        vboxLayout2->addLayout(hboxLayout1);

        SettingsTabWidget->addTab(ParametersTab, QString());
        AdvancedTab = new QWidget();
        AdvancedTab->setObjectName(QString::fromUtf8("AdvancedTab"));
        gridLayout1 = new QGridLayout(AdvancedTab);
        gridLayout1->setSpacing(4);
        gridLayout1->setContentsMargins(8, 8, 8, 8);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        label = new QLabel(AdvancedTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMargin(8);

        gridLayout1->addWidget(label, 0, 0, 1, 5);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(4);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        ServerPrefixTextLabel = new QLabel(AdvancedTab);
        ServerPrefixTextLabel->setObjectName(QString::fromUtf8("ServerPrefixTextLabel"));
        ServerPrefixTextLabel->setFont(font);
        ServerPrefixTextLabel->setWordWrap(false);

        hboxLayout2->addWidget(ServerPrefixTextLabel);

        ServerPrefixComboBox = new QComboBox(AdvancedTab);
        ServerPrefixComboBox->addItem(QString());
        ServerPrefixComboBox->addItem(QString());
        ServerPrefixComboBox->addItem(QString());
        ServerPrefixComboBox->setObjectName(QString::fromUtf8("ServerPrefixComboBox"));
        sizePolicy.setHeightForWidth(ServerPrefixComboBox->sizePolicy().hasHeightForWidth());
        ServerPrefixComboBox->setSizePolicy(sizePolicy);
        ServerPrefixComboBox->setFont(font);
        ServerPrefixComboBox->setEditable(true);

        hboxLayout2->addWidget(ServerPrefixComboBox);

        ServerNameTextLabel = new QLabel(AdvancedTab);
        ServerNameTextLabel->setObjectName(QString::fromUtf8("ServerNameTextLabel"));
        ServerNameTextLabel->setFont(font);
        ServerNameTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ServerNameTextLabel->setWordWrap(false);

        hboxLayout2->addWidget(ServerNameTextLabel);

        ServerNameComboBox = new QComboBox(AdvancedTab);
        ServerNameComboBox->addItem(QString());
        ServerNameComboBox->setObjectName(QString::fromUtf8("ServerNameComboBox"));
        ServerNameComboBox->setMinimumSize(QSize(120, 0));
        ServerNameComboBox->setFont(font);
        ServerNameComboBox->setEditable(true);

        hboxLayout2->addWidget(ServerNameComboBox);


        gridLayout1->addLayout(hboxLayout2, 1, 0, 1, 5);

        spacerItem5 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem5, 2, 0, 1, 5);

        vboxLayout3 = new QVBoxLayout();
        vboxLayout3->setSpacing(4);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));
        NoMemLockCheckBox = new QCheckBox(AdvancedTab);
        NoMemLockCheckBox->setObjectName(QString::fromUtf8("NoMemLockCheckBox"));
        NoMemLockCheckBox->setFont(font);

        vboxLayout3->addWidget(NoMemLockCheckBox);

        UnlockMemCheckBox = new QCheckBox(AdvancedTab);
        UnlockMemCheckBox->setObjectName(QString::fromUtf8("UnlockMemCheckBox"));
        UnlockMemCheckBox->setFont(font);

        vboxLayout3->addWidget(UnlockMemCheckBox);

        HWMeterCheckBox = new QCheckBox(AdvancedTab);
        HWMeterCheckBox->setObjectName(QString::fromUtf8("HWMeterCheckBox"));
        HWMeterCheckBox->setFont(font);

        vboxLayout3->addWidget(HWMeterCheckBox);

        MonitorCheckBox = new QCheckBox(AdvancedTab);
        MonitorCheckBox->setObjectName(QString::fromUtf8("MonitorCheckBox"));
        MonitorCheckBox->setFont(font);

        vboxLayout3->addWidget(MonitorCheckBox);

        SoftModeCheckBox = new QCheckBox(AdvancedTab);
        SoftModeCheckBox->setObjectName(QString::fromUtf8("SoftModeCheckBox"));
        SoftModeCheckBox->setFont(font);

        vboxLayout3->addWidget(SoftModeCheckBox);

        ShortsCheckBox = new QCheckBox(AdvancedTab);
        ShortsCheckBox->setObjectName(QString::fromUtf8("ShortsCheckBox"));
        ShortsCheckBox->setFont(font);

        vboxLayout3->addWidget(ShortsCheckBox);

        IgnoreHWCheckBox = new QCheckBox(AdvancedTab);
        IgnoreHWCheckBox->setObjectName(QString::fromUtf8("IgnoreHWCheckBox"));
        IgnoreHWCheckBox->setFont(font);

        vboxLayout3->addWidget(IgnoreHWCheckBox);


        gridLayout1->addLayout(vboxLayout3, 3, 0, 2, 1);

        spacerItem6 = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem6, 3, 1, 2, 1);

        gridLayout2 = new QGridLayout();
        gridLayout2->setSpacing(4);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        ChanSpinBox = new QSpinBox(AdvancedTab);
        ChanSpinBox->setObjectName(QString::fromUtf8("ChanSpinBox"));
        ChanSpinBox->setFont(font);
        ChanSpinBox->setMaximum(999);

        gridLayout2->addWidget(ChanSpinBox, 3, 1, 1, 1);

        WaitComboBox = new QComboBox(AdvancedTab);
        WaitComboBox->addItem(QString());
        WaitComboBox->setObjectName(QString::fromUtf8("WaitComboBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sans Serif"));
        font1.setBold(false);
        font1.setWeight(50);
        WaitComboBox->setFont(font1);
        WaitComboBox->setAcceptDrops(false);
        WaitComboBox->setEditable(true);

        gridLayout2->addWidget(WaitComboBox, 2, 1, 1, 1);

        PriorityTextLabel = new QLabel(AdvancedTab);
        PriorityTextLabel->setObjectName(QString::fromUtf8("PriorityTextLabel"));
        PriorityTextLabel->setFont(font);
        PriorityTextLabel->setFrameShape(QFrame::NoFrame);
        PriorityTextLabel->setFrameShadow(QFrame::Plain);
        PriorityTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        PriorityTextLabel->setWordWrap(false);

        gridLayout2->addWidget(PriorityTextLabel, 0, 0, 1, 1);

        TimeoutComboBox = new QComboBox(AdvancedTab);
        TimeoutComboBox->addItem(QString());
        TimeoutComboBox->addItem(QString());
        TimeoutComboBox->addItem(QString());
        TimeoutComboBox->addItem(QString());
        TimeoutComboBox->addItem(QString());
        TimeoutComboBox->addItem(QString());
        TimeoutComboBox->setObjectName(QString::fromUtf8("TimeoutComboBox"));
        TimeoutComboBox->setFont(font);
        TimeoutComboBox->setEditable(true);

        gridLayout2->addWidget(TimeoutComboBox, 5, 1, 1, 1);

        PortMaxTextLabel = new QLabel(AdvancedTab);
        PortMaxTextLabel->setObjectName(QString::fromUtf8("PortMaxTextLabel"));
        PortMaxTextLabel->setFont(font);
        PortMaxTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        PortMaxTextLabel->setWordWrap(false);

        gridLayout2->addWidget(PortMaxTextLabel, 4, 0, 1, 1);

        ChanTextLabel = new QLabel(AdvancedTab);
        ChanTextLabel->setObjectName(QString::fromUtf8("ChanTextLabel"));
        ChanTextLabel->setFont(font);
        ChanTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ChanTextLabel->setWordWrap(false);
        ChanTextLabel->setMargin(0);

        gridLayout2->addWidget(ChanTextLabel, 3, 0, 1, 1);

        WordLengthComboBox = new QComboBox(AdvancedTab);
        WordLengthComboBox->addItem(QString());
        WordLengthComboBox->addItem(QString());
        WordLengthComboBox->addItem(QString());
        WordLengthComboBox->setObjectName(QString::fromUtf8("WordLengthComboBox"));
        WordLengthComboBox->setFont(font);
        WordLengthComboBox->setAcceptDrops(false);
        WordLengthComboBox->setEditable(true);

        gridLayout2->addWidget(WordLengthComboBox, 1, 1, 1, 1);

        WaitTextLabel = new QLabel(AdvancedTab);
        WaitTextLabel->setObjectName(QString::fromUtf8("WaitTextLabel"));
        WaitTextLabel->setFont(font);
        WaitTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        WaitTextLabel->setWordWrap(false);

        gridLayout2->addWidget(WaitTextLabel, 2, 0, 1, 1);

        TimeoutTextLabel = new QLabel(AdvancedTab);
        TimeoutTextLabel->setObjectName(QString::fromUtf8("TimeoutTextLabel"));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        TimeoutTextLabel->setFont(font2);
        TimeoutTextLabel->setFrameShape(QFrame::NoFrame);
        TimeoutTextLabel->setFrameShadow(QFrame::Plain);
        TimeoutTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TimeoutTextLabel->setWordWrap(false);

        gridLayout2->addWidget(TimeoutTextLabel, 5, 0, 1, 1);

        PortMaxComboBox = new QComboBox(AdvancedTab);
        PortMaxComboBox->addItem(QString());
        PortMaxComboBox->addItem(QString());
        PortMaxComboBox->addItem(QString());
        PortMaxComboBox->addItem(QString());
        PortMaxComboBox->setObjectName(QString::fromUtf8("PortMaxComboBox"));
        PortMaxComboBox->setMinimumSize(QSize(60, 0));
        PortMaxComboBox->setFont(font);
        PortMaxComboBox->setEditable(true);

        gridLayout2->addWidget(PortMaxComboBox, 4, 1, 1, 1);

        WordLengthTextLabel = new QLabel(AdvancedTab);
        WordLengthTextLabel->setObjectName(QString::fromUtf8("WordLengthTextLabel"));
        WordLengthTextLabel->setFont(font);
        WordLengthTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        WordLengthTextLabel->setWordWrap(false);

        gridLayout2->addWidget(WordLengthTextLabel, 1, 0, 1, 1);

        PrioritySpinBox = new QSpinBox(AdvancedTab);
        PrioritySpinBox->setObjectName(QString::fromUtf8("PrioritySpinBox"));
        PrioritySpinBox->setFont(font);
        PrioritySpinBox->setSingleStep(1);
        PrioritySpinBox->setMinimum(5);
        PrioritySpinBox->setMaximum(99);

        gridLayout2->addWidget(PrioritySpinBox, 0, 1, 1, 1);


        gridLayout1->addLayout(gridLayout2, 3, 2, 1, 1);

        spacerItem7 = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout1->addItem(spacerItem7, 3, 3, 1, 1);

        gridLayout3 = new QGridLayout();
        gridLayout3->setSpacing(4);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        AudioTextLabel = new QLabel(AdvancedTab);
        AudioTextLabel->setObjectName(QString::fromUtf8("AudioTextLabel"));
        AudioTextLabel->setFont(font);
        AudioTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        AudioTextLabel->setWordWrap(false);

        gridLayout3->addWidget(AudioTextLabel, 0, 0, 1, 1);

        AudioComboBox = new QComboBox(AdvancedTab);
        AudioComboBox->addItem(QString());
        AudioComboBox->addItem(QString());
        AudioComboBox->addItem(QString());
        AudioComboBox->setObjectName(QString::fromUtf8("AudioComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AudioComboBox->sizePolicy().hasHeightForWidth());
        AudioComboBox->setSizePolicy(sizePolicy1);
        AudioComboBox->setFont(font);

        gridLayout3->addWidget(AudioComboBox, 0, 1, 1, 2);

        DitherTextLabel = new QLabel(AdvancedTab);
        DitherTextLabel->setObjectName(QString::fromUtf8("DitherTextLabel"));
        DitherTextLabel->setFont(font);
        DitherTextLabel->setFrameShape(QFrame::NoFrame);
        DitherTextLabel->setFrameShadow(QFrame::Plain);
        DitherTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        DitherTextLabel->setWordWrap(false);

        gridLayout3->addWidget(DitherTextLabel, 1, 0, 1, 1);

        DitherComboBox = new QComboBox(AdvancedTab);
        DitherComboBox->addItem(QString());
        DitherComboBox->addItem(QString());
        DitherComboBox->addItem(QString());
        DitherComboBox->addItem(QString());
        DitherComboBox->setObjectName(QString::fromUtf8("DitherComboBox"));
        sizePolicy1.setHeightForWidth(DitherComboBox->sizePolicy().hasHeightForWidth());
        DitherComboBox->setSizePolicy(sizePolicy1);
        DitherComboBox->setFont(font);

        gridLayout3->addWidget(DitherComboBox, 1, 1, 1, 2);

        OutDeviceTextLabel = new QLabel(AdvancedTab);
        OutDeviceTextLabel->setObjectName(QString::fromUtf8("OutDeviceTextLabel"));
        OutDeviceTextLabel->setFont(font);
        OutDeviceTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        OutDeviceTextLabel->setWordWrap(false);

        gridLayout3->addWidget(OutDeviceTextLabel, 2, 0, 1, 1);

        OutDeviceComboBox = new qjackctlInterfaceComboBox(AdvancedTab);
        OutDeviceComboBox->addItem(QString());
        OutDeviceComboBox->addItem(QString());
        OutDeviceComboBox->addItem(QString());
        OutDeviceComboBox->addItem(QString());
        OutDeviceComboBox->addItem(QString());
        OutDeviceComboBox->setObjectName(QString::fromUtf8("OutDeviceComboBox"));
        OutDeviceComboBox->setFont(font);
        OutDeviceComboBox->setEditable(true);

        gridLayout3->addWidget(OutDeviceComboBox, 2, 1, 1, 2);

        InDeviceTextLabel = new QLabel(AdvancedTab);
        InDeviceTextLabel->setObjectName(QString::fromUtf8("InDeviceTextLabel"));
        InDeviceTextLabel->setFont(font);
        InDeviceTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        InDeviceTextLabel->setWordWrap(false);

        gridLayout3->addWidget(InDeviceTextLabel, 3, 0, 1, 1);

        InDeviceComboBox = new qjackctlInterfaceComboBox(AdvancedTab);
        InDeviceComboBox->addItem(QString());
        InDeviceComboBox->addItem(QString());
        InDeviceComboBox->addItem(QString());
        InDeviceComboBox->addItem(QString());
        InDeviceComboBox->addItem(QString());
        InDeviceComboBox->setObjectName(QString::fromUtf8("InDeviceComboBox"));
        InDeviceComboBox->setFont(font);
        InDeviceComboBox->setEditable(true);

        gridLayout3->addWidget(InDeviceComboBox, 3, 1, 1, 2);

        InOutChannelsTextLabel = new QLabel(AdvancedTab);
        InOutChannelsTextLabel->setObjectName(QString::fromUtf8("InOutChannelsTextLabel"));
        InOutChannelsTextLabel->setFont(font);
        InOutChannelsTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        InOutChannelsTextLabel->setWordWrap(false);

        gridLayout3->addWidget(InOutChannelsTextLabel, 4, 0, 1, 1);

        InChannelsSpinBox = new QSpinBox(AdvancedTab);
        InChannelsSpinBox->setObjectName(QString::fromUtf8("InChannelsSpinBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(InChannelsSpinBox->sizePolicy().hasHeightForWidth());
        InChannelsSpinBox->setSizePolicy(sizePolicy2);
        InChannelsSpinBox->setMinimumSize(QSize(80, 0));
        InChannelsSpinBox->setFont(font);
        InChannelsSpinBox->setMaximum(999);

        gridLayout3->addWidget(InChannelsSpinBox, 4, 1, 1, 1);

        OutChannelsSpinBox = new QSpinBox(AdvancedTab);
        OutChannelsSpinBox->setObjectName(QString::fromUtf8("OutChannelsSpinBox"));
        sizePolicy2.setHeightForWidth(OutChannelsSpinBox->sizePolicy().hasHeightForWidth());
        OutChannelsSpinBox->setSizePolicy(sizePolicy2);
        OutChannelsSpinBox->setMinimumSize(QSize(80, 0));
        OutChannelsSpinBox->setFont(font);
        OutChannelsSpinBox->setMaximum(999);

        gridLayout3->addWidget(OutChannelsSpinBox, 4, 2, 1, 1);

        InOutLatencyTextLabel = new QLabel(AdvancedTab);
        InOutLatencyTextLabel->setObjectName(QString::fromUtf8("InOutLatencyTextLabel"));
        InOutLatencyTextLabel->setFont(font);
        InOutLatencyTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        InOutLatencyTextLabel->setWordWrap(false);

        gridLayout3->addWidget(InOutLatencyTextLabel, 5, 0, 1, 1);

        InLatencySpinBox = new QSpinBox(AdvancedTab);
        InLatencySpinBox->setObjectName(QString::fromUtf8("InLatencySpinBox"));
        sizePolicy2.setHeightForWidth(InLatencySpinBox->sizePolicy().hasHeightForWidth());
        InLatencySpinBox->setSizePolicy(sizePolicy2);
        InLatencySpinBox->setMinimumSize(QSize(80, 0));
        InLatencySpinBox->setFont(font);
        InLatencySpinBox->setMaximum(9999999);

        gridLayout3->addWidget(InLatencySpinBox, 5, 1, 1, 1);

        OutLatencySpinBox = new QSpinBox(AdvancedTab);
        OutLatencySpinBox->setObjectName(QString::fromUtf8("OutLatencySpinBox"));
        sizePolicy2.setHeightForWidth(OutLatencySpinBox->sizePolicy().hasHeightForWidth());
        OutLatencySpinBox->setSizePolicy(sizePolicy2);
        OutLatencySpinBox->setMinimumSize(QSize(80, 0));
        OutLatencySpinBox->setFont(font);
        OutLatencySpinBox->setMaximum(9999999);

        gridLayout3->addWidget(OutLatencySpinBox, 5, 2, 1, 1);


        gridLayout1->addLayout(gridLayout3, 3, 4, 1, 1);

        spacerItem8 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem8, 4, 2, 1, 3);

        spacerItem9 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem9, 5, 0, 1, 5);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(4);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        ServerSuffixTextLabel = new QLabel(AdvancedTab);
        ServerSuffixTextLabel->setObjectName(QString::fromUtf8("ServerSuffixTextLabel"));
        ServerSuffixTextLabel->setFont(font);
        ServerSuffixTextLabel->setWordWrap(false);

        hboxLayout3->addWidget(ServerSuffixTextLabel);

        ServerSuffixComboBox = new QComboBox(AdvancedTab);
        ServerSuffixComboBox->setObjectName(QString::fromUtf8("ServerSuffixComboBox"));
        sizePolicy.setHeightForWidth(ServerSuffixComboBox->sizePolicy().hasHeightForWidth());
        ServerSuffixComboBox->setSizePolicy(sizePolicy);
        ServerSuffixComboBox->setFont(font);
        ServerSuffixComboBox->setEditable(true);

        hboxLayout3->addWidget(ServerSuffixComboBox);

        StartDelayTextLabel = new QLabel(AdvancedTab);
        StartDelayTextLabel->setObjectName(QString::fromUtf8("StartDelayTextLabel"));
        StartDelayTextLabel->setFont(font);
        StartDelayTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        StartDelayTextLabel->setWordWrap(false);

        hboxLayout3->addWidget(StartDelayTextLabel);

        StartDelaySpinBox = new QSpinBox(AdvancedTab);
        StartDelaySpinBox->setObjectName(QString::fromUtf8("StartDelaySpinBox"));
        StartDelaySpinBox->setFont(font);
        StartDelaySpinBox->setMinimum(0);
        StartDelaySpinBox->setMaximum(999);

        hboxLayout3->addWidget(StartDelaySpinBox);


        gridLayout1->addLayout(hboxLayout3, 6, 0, 1, 5);

        SettingsTabWidget->addTab(AdvancedTab, QString());

        vboxLayout1->addWidget(SettingsTabWidget);

        SetupTabWidget->addTab(SettingsTabPage, QString());
        OptionsTabPage = new QWidget();
        OptionsTabPage->setObjectName(QString::fromUtf8("OptionsTabPage"));
        vboxLayout4 = new QVBoxLayout(OptionsTabPage);
        vboxLayout4->setSpacing(4);
        vboxLayout4->setContentsMargins(8, 8, 8, 8);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        ScriptingGroupBox = new QGroupBox(OptionsTabPage);
        ScriptingGroupBox->setObjectName(QString::fromUtf8("ScriptingGroupBox"));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        ScriptingGroupBox->setFont(font3);
        ScriptingGroupBox->setFlat(true);
        gridLayout4 = new QGridLayout(ScriptingGroupBox);
        gridLayout4->setSpacing(4);
        gridLayout4->setContentsMargins(8, 8, 8, 8);
        gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
        StartupScriptCheckBox = new QCheckBox(ScriptingGroupBox);
        StartupScriptCheckBox->setObjectName(QString::fromUtf8("StartupScriptCheckBox"));
        StartupScriptCheckBox->setFont(font);

        gridLayout4->addWidget(StartupScriptCheckBox, 0, 0, 1, 1);

        PostStartupScriptCheckBox = new QCheckBox(ScriptingGroupBox);
        PostStartupScriptCheckBox->setObjectName(QString::fromUtf8("PostStartupScriptCheckBox"));
        PostStartupScriptCheckBox->setFont(font);

        gridLayout4->addWidget(PostStartupScriptCheckBox, 1, 0, 1, 1);

        ShutdownScriptCheckBox = new QCheckBox(ScriptingGroupBox);
        ShutdownScriptCheckBox->setObjectName(QString::fromUtf8("ShutdownScriptCheckBox"));
        ShutdownScriptCheckBox->setFont(font);

        gridLayout4->addWidget(ShutdownScriptCheckBox, 2, 0, 1, 1);

        StartupScriptShellComboBox = new QComboBox(ScriptingGroupBox);
        StartupScriptShellComboBox->setObjectName(QString::fromUtf8("StartupScriptShellComboBox"));
        sizePolicy.setHeightForWidth(StartupScriptShellComboBox->sizePolicy().hasHeightForWidth());
        StartupScriptShellComboBox->setSizePolicy(sizePolicy);
        StartupScriptShellComboBox->setFont(font);
        StartupScriptShellComboBox->setEditable(true);

        gridLayout4->addWidget(StartupScriptShellComboBox, 0, 1, 1, 1);

        StartupScriptSymbolToolButton = new QToolButton(ScriptingGroupBox);
        StartupScriptSymbolToolButton->setObjectName(QString::fromUtf8("StartupScriptSymbolToolButton"));
        StartupScriptSymbolToolButton->setMinimumSize(QSize(22, 22));
        StartupScriptSymbolToolButton->setMaximumSize(QSize(24, 24));
        StartupScriptSymbolToolButton->setFont(font);
        StartupScriptSymbolToolButton->setFocusPolicy(Qt::TabFocus);

        gridLayout4->addWidget(StartupScriptSymbolToolButton, 0, 2, 1, 1);

        StartupScriptBrowseToolButton = new QToolButton(ScriptingGroupBox);
        StartupScriptBrowseToolButton->setObjectName(QString::fromUtf8("StartupScriptBrowseToolButton"));
        StartupScriptBrowseToolButton->setMinimumSize(QSize(22, 22));
        StartupScriptBrowseToolButton->setMaximumSize(QSize(24, 24));
        StartupScriptBrowseToolButton->setFont(font);
        StartupScriptBrowseToolButton->setFocusPolicy(Qt::TabFocus);

        gridLayout4->addWidget(StartupScriptBrowseToolButton, 0, 3, 1, 1);

        PostStartupScriptShellComboBox = new QComboBox(ScriptingGroupBox);
        PostStartupScriptShellComboBox->setObjectName(QString::fromUtf8("PostStartupScriptShellComboBox"));
        sizePolicy.setHeightForWidth(PostStartupScriptShellComboBox->sizePolicy().hasHeightForWidth());
        PostStartupScriptShellComboBox->setSizePolicy(sizePolicy);
        PostStartupScriptShellComboBox->setFont(font);
        PostStartupScriptShellComboBox->setEditable(true);

        gridLayout4->addWidget(PostStartupScriptShellComboBox, 1, 1, 1, 1);

        PostStartupScriptSymbolToolButton = new QToolButton(ScriptingGroupBox);
        PostStartupScriptSymbolToolButton->setObjectName(QString::fromUtf8("PostStartupScriptSymbolToolButton"));
        PostStartupScriptSymbolToolButton->setMinimumSize(QSize(22, 22));
        PostStartupScriptSymbolToolButton->setMaximumSize(QSize(24, 24));
        PostStartupScriptSymbolToolButton->setFont(font);
        PostStartupScriptSymbolToolButton->setFocusPolicy(Qt::TabFocus);

        gridLayout4->addWidget(PostStartupScriptSymbolToolButton, 1, 2, 1, 1);

        PostStartupScriptBrowseToolButton = new QToolButton(ScriptingGroupBox);
        PostStartupScriptBrowseToolButton->setObjectName(QString::fromUtf8("PostStartupScriptBrowseToolButton"));
        PostStartupScriptBrowseToolButton->setMinimumSize(QSize(22, 22));
        PostStartupScriptBrowseToolButton->setMaximumSize(QSize(24, 24));
        PostStartupScriptBrowseToolButton->setFont(font);
        PostStartupScriptBrowseToolButton->setFocusPolicy(Qt::TabFocus);

        gridLayout4->addWidget(PostStartupScriptBrowseToolButton, 1, 3, 1, 1);

        ShutdownScriptSymbolToolButton = new QToolButton(ScriptingGroupBox);
        ShutdownScriptSymbolToolButton->setObjectName(QString::fromUtf8("ShutdownScriptSymbolToolButton"));
        ShutdownScriptSymbolToolButton->setMinimumSize(QSize(22, 22));
        ShutdownScriptSymbolToolButton->setMaximumSize(QSize(24, 24));
        ShutdownScriptSymbolToolButton->setFont(font);
        ShutdownScriptSymbolToolButton->setFocusPolicy(Qt::TabFocus);

        gridLayout4->addWidget(ShutdownScriptSymbolToolButton, 2, 2, 1, 1);

        ShutdownScriptBrowseToolButton = new QToolButton(ScriptingGroupBox);
        ShutdownScriptBrowseToolButton->setObjectName(QString::fromUtf8("ShutdownScriptBrowseToolButton"));
        ShutdownScriptBrowseToolButton->setMinimumSize(QSize(22, 22));
        ShutdownScriptBrowseToolButton->setMaximumSize(QSize(24, 24));
        ShutdownScriptBrowseToolButton->setFont(font);
        ShutdownScriptBrowseToolButton->setFocusPolicy(Qt::TabFocus);

        gridLayout4->addWidget(ShutdownScriptBrowseToolButton, 2, 3, 1, 1);

        ShutdownScriptShellComboBox = new QComboBox(ScriptingGroupBox);
        ShutdownScriptShellComboBox->setObjectName(QString::fromUtf8("ShutdownScriptShellComboBox"));
        sizePolicy.setHeightForWidth(ShutdownScriptShellComboBox->sizePolicy().hasHeightForWidth());
        ShutdownScriptShellComboBox->setSizePolicy(sizePolicy);
        ShutdownScriptShellComboBox->setFont(font);
        ShutdownScriptShellComboBox->setEditable(true);

        gridLayout4->addWidget(ShutdownScriptShellComboBox, 2, 1, 1, 1);

        PostShutdownScriptCheckBox = new QCheckBox(ScriptingGroupBox);
        PostShutdownScriptCheckBox->setObjectName(QString::fromUtf8("PostShutdownScriptCheckBox"));
        PostShutdownScriptCheckBox->setFont(font);

        gridLayout4->addWidget(PostShutdownScriptCheckBox, 3, 0, 1, 1);

        PostShutdownScriptSymbolToolButton = new QToolButton(ScriptingGroupBox);
        PostShutdownScriptSymbolToolButton->setObjectName(QString::fromUtf8("PostShutdownScriptSymbolToolButton"));
        PostShutdownScriptSymbolToolButton->setMinimumSize(QSize(22, 22));
        PostShutdownScriptSymbolToolButton->setMaximumSize(QSize(24, 24));
        PostShutdownScriptSymbolToolButton->setFont(font);
        PostShutdownScriptSymbolToolButton->setFocusPolicy(Qt::TabFocus);

        gridLayout4->addWidget(PostShutdownScriptSymbolToolButton, 3, 2, 1, 1);

        PostShutdownScriptBrowseToolButton = new QToolButton(ScriptingGroupBox);
        PostShutdownScriptBrowseToolButton->setObjectName(QString::fromUtf8("PostShutdownScriptBrowseToolButton"));
        PostShutdownScriptBrowseToolButton->setMinimumSize(QSize(22, 22));
        PostShutdownScriptBrowseToolButton->setMaximumSize(QSize(24, 24));
        PostShutdownScriptBrowseToolButton->setFont(font);
        PostShutdownScriptBrowseToolButton->setFocusPolicy(Qt::TabFocus);

        gridLayout4->addWidget(PostShutdownScriptBrowseToolButton, 3, 3, 1, 1);

        PostShutdownScriptShellComboBox = new QComboBox(ScriptingGroupBox);
        PostShutdownScriptShellComboBox->setObjectName(QString::fromUtf8("PostShutdownScriptShellComboBox"));
        sizePolicy.setHeightForWidth(PostShutdownScriptShellComboBox->sizePolicy().hasHeightForWidth());
        PostShutdownScriptShellComboBox->setSizePolicy(sizePolicy);
        PostShutdownScriptShellComboBox->setFont(font);
        PostShutdownScriptShellComboBox->setEditable(true);

        gridLayout4->addWidget(PostShutdownScriptShellComboBox, 3, 1, 1, 1);


        vboxLayout4->addWidget(ScriptingGroupBox);

        StatisticsGroupBox = new QGroupBox(OptionsTabPage);
        StatisticsGroupBox->setObjectName(QString::fromUtf8("StatisticsGroupBox"));
        StatisticsGroupBox->setFont(font3);
        StatisticsGroupBox->setFlat(true);
        gridLayout5 = new QGridLayout(StatisticsGroupBox);
        gridLayout5->setSpacing(4);
        gridLayout5->setContentsMargins(8, 8, 8, 8);
        gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
        StdoutCaptureCheckBox = new QCheckBox(StatisticsGroupBox);
        StdoutCaptureCheckBox->setObjectName(QString::fromUtf8("StdoutCaptureCheckBox"));
        StdoutCaptureCheckBox->setFont(font);

        gridLayout5->addWidget(StdoutCaptureCheckBox, 0, 0, 1, 3);

        XrunRegexTextLabel = new QLabel(StatisticsGroupBox);
        XrunRegexTextLabel->setObjectName(QString::fromUtf8("XrunRegexTextLabel"));
        XrunRegexTextLabel->setFont(font);
        XrunRegexTextLabel->setWordWrap(false);

        gridLayout5->addWidget(XrunRegexTextLabel, 1, 1, 1, 1);

        XrunRegexComboBox = new QComboBox(StatisticsGroupBox);
        XrunRegexComboBox->addItem(QString());
        XrunRegexComboBox->setObjectName(QString::fromUtf8("XrunRegexComboBox"));
        sizePolicy.setHeightForWidth(XrunRegexComboBox->sizePolicy().hasHeightForWidth());
        XrunRegexComboBox->setSizePolicy(sizePolicy);
        XrunRegexComboBox->setFont(font);
        XrunRegexComboBox->setEditable(true);

        gridLayout5->addWidget(XrunRegexComboBox, 1, 2, 1, 1);


        vboxLayout4->addWidget(StatisticsGroupBox);

        ConnectionsGroupBox = new QGroupBox(OptionsTabPage);
        ConnectionsGroupBox->setObjectName(QString::fromUtf8("ConnectionsGroupBox"));
        ConnectionsGroupBox->setFont(font3);
        ConnectionsGroupBox->setFlat(true);
        gridLayout6 = new QGridLayout(ConnectionsGroupBox);
        gridLayout6->setSpacing(4);
        gridLayout6->setContentsMargins(8, 8, 8, 8);
        gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
        ActivePatchbayCheckBox = new QCheckBox(ConnectionsGroupBox);
        ActivePatchbayCheckBox->setObjectName(QString::fromUtf8("ActivePatchbayCheckBox"));
        ActivePatchbayCheckBox->setFont(font);

        gridLayout6->addWidget(ActivePatchbayCheckBox, 0, 0, 1, 1);

        ActivePatchbayPathComboBox = new QComboBox(ConnectionsGroupBox);
        ActivePatchbayPathComboBox->setObjectName(QString::fromUtf8("ActivePatchbayPathComboBox"));
        sizePolicy.setHeightForWidth(ActivePatchbayPathComboBox->sizePolicy().hasHeightForWidth());
        ActivePatchbayPathComboBox->setSizePolicy(sizePolicy);
        ActivePatchbayPathComboBox->setFont(font);
        ActivePatchbayPathComboBox->setEditable(true);

        gridLayout6->addWidget(ActivePatchbayPathComboBox, 0, 1, 1, 2);

        ActivePatchbayPathToolButton = new QToolButton(ConnectionsGroupBox);
        ActivePatchbayPathToolButton->setObjectName(QString::fromUtf8("ActivePatchbayPathToolButton"));
        ActivePatchbayPathToolButton->setMinimumSize(QSize(22, 22));
        ActivePatchbayPathToolButton->setMaximumSize(QSize(24, 24));
        ActivePatchbayPathToolButton->setFont(font);
        ActivePatchbayPathToolButton->setFocusPolicy(Qt::TabFocus);

        gridLayout6->addWidget(ActivePatchbayPathToolButton, 0, 3, 1, 1);

        ActivePatchbayResetCheckBox = new QCheckBox(ConnectionsGroupBox);
        ActivePatchbayResetCheckBox->setObjectName(QString::fromUtf8("ActivePatchbayResetCheckBox"));
        ActivePatchbayResetCheckBox->setFont(font);

        gridLayout6->addWidget(ActivePatchbayResetCheckBox, 1, 0, 1, 2);

        QueryDisconnectCheckBox = new QCheckBox(ConnectionsGroupBox);
        QueryDisconnectCheckBox->setObjectName(QString::fromUtf8("QueryDisconnectCheckBox"));
        QueryDisconnectCheckBox->setFont(font);

        gridLayout6->addWidget(QueryDisconnectCheckBox, 1, 2, 1, 2);


        vboxLayout4->addWidget(ConnectionsGroupBox);

        spacerItem10 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout4->addItem(spacerItem10);

        LoggingGroupBox = new QGroupBox(OptionsTabPage);
        LoggingGroupBox->setObjectName(QString::fromUtf8("LoggingGroupBox"));
        LoggingGroupBox->setFont(font3);
        LoggingGroupBox->setFlat(true);
        gridLayout7 = new QGridLayout(LoggingGroupBox);
        gridLayout7->setSpacing(4);
        gridLayout7->setContentsMargins(8, 8, 8, 8);
        gridLayout7->setObjectName(QString::fromUtf8("gridLayout7"));
        MessagesLogCheckBox = new QCheckBox(LoggingGroupBox);
        MessagesLogCheckBox->setObjectName(QString::fromUtf8("MessagesLogCheckBox"));
        MessagesLogCheckBox->setFont(font);

        gridLayout7->addWidget(MessagesLogCheckBox, 0, 0, 1, 1);

        MessagesLogPathComboBox = new QComboBox(LoggingGroupBox);
        MessagesLogPathComboBox->setObjectName(QString::fromUtf8("MessagesLogPathComboBox"));
        sizePolicy.setHeightForWidth(MessagesLogPathComboBox->sizePolicy().hasHeightForWidth());
        MessagesLogPathComboBox->setSizePolicy(sizePolicy);
        MessagesLogPathComboBox->setFont(font);
        MessagesLogPathComboBox->setEditable(true);

        gridLayout7->addWidget(MessagesLogPathComboBox, 0, 1, 1, 1);

        MessagesLogPathToolButton = new QToolButton(LoggingGroupBox);
        MessagesLogPathToolButton->setObjectName(QString::fromUtf8("MessagesLogPathToolButton"));
        MessagesLogPathToolButton->setMinimumSize(QSize(22, 22));
        MessagesLogPathToolButton->setMaximumSize(QSize(24, 24));
        MessagesLogPathToolButton->setFont(font);
        MessagesLogPathToolButton->setFocusPolicy(Qt::TabFocus);

        gridLayout7->addWidget(MessagesLogPathToolButton, 0, 2, 1, 1);


        vboxLayout4->addWidget(LoggingGroupBox);

        SetupTabWidget->addTab(OptionsTabPage, QString());
        DisplayTabPage = new QWidget();
        DisplayTabPage->setObjectName(QString::fromUtf8("DisplayTabPage"));
        vboxLayout5 = new QVBoxLayout(DisplayTabPage);
        vboxLayout5->setSpacing(4);
        vboxLayout5->setContentsMargins(8, 8, 8, 8);
        vboxLayout5->setObjectName(QString::fromUtf8("vboxLayout5"));
        TimeDisplayGroupBox = new QGroupBox(DisplayTabPage);
        TimeDisplayGroupBox->setObjectName(QString::fromUtf8("TimeDisplayGroupBox"));
        TimeDisplayGroupBox->setFont(font3);
        TimeDisplayGroupBox->setFlat(true);
        gridLayout8 = new QGridLayout(TimeDisplayGroupBox);
        gridLayout8->setSpacing(4);
        gridLayout8->setContentsMargins(8, 8, 8, 8);
        gridLayout8->setObjectName(QString::fromUtf8("gridLayout8"));
        vboxLayout6 = new QVBoxLayout();
        vboxLayout6->setSpacing(4);
        vboxLayout6->setContentsMargins(4, 4, 4, 4);
        vboxLayout6->setObjectName(QString::fromUtf8("vboxLayout6"));
        TransportTimeRadioButton = new QRadioButton(TimeDisplayGroupBox);
        TransportTimeRadioButton->setObjectName(QString::fromUtf8("TransportTimeRadioButton"));
        TransportTimeRadioButton->setFont(font);

        vboxLayout6->addWidget(TransportTimeRadioButton);

        TransportBBTRadioButton = new QRadioButton(TimeDisplayGroupBox);
        TransportBBTRadioButton->setObjectName(QString::fromUtf8("TransportBBTRadioButton"));
        TransportBBTRadioButton->setFont(font);

        vboxLayout6->addWidget(TransportBBTRadioButton);

        ElapsedResetRadioButton = new QRadioButton(TimeDisplayGroupBox);
        ElapsedResetRadioButton->setObjectName(QString::fromUtf8("ElapsedResetRadioButton"));
        ElapsedResetRadioButton->setFont(font);

        vboxLayout6->addWidget(ElapsedResetRadioButton);

        ElapsedXrunRadioButton = new QRadioButton(TimeDisplayGroupBox);
        ElapsedXrunRadioButton->setObjectName(QString::fromUtf8("ElapsedXrunRadioButton"));
        ElapsedXrunRadioButton->setFont(font);

        vboxLayout6->addWidget(ElapsedXrunRadioButton);


        gridLayout8->addLayout(vboxLayout6, 0, 0, 1, 1);

        spacerItem11 = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout8->addItem(spacerItem11, 0, 1, 2, 1);

        gridLayout9 = new QGridLayout();
        gridLayout9->setSpacing(4);
        gridLayout9->setContentsMargins(4, 4, 4, 4);
        gridLayout9->setObjectName(QString::fromUtf8("gridLayout9"));
        DisplayFont2TextLabel = new QLabel(TimeDisplayGroupBox);
        DisplayFont2TextLabel->setObjectName(QString::fromUtf8("DisplayFont2TextLabel"));
        DisplayFont2TextLabel->setMinimumSize(QSize(180, 0));
        DisplayFont2TextLabel->setMaximumSize(QSize(260, 32767));
        DisplayFont2TextLabel->setFont(font);
        DisplayFont2TextLabel->setAutoFillBackground(true);
        DisplayFont2TextLabel->setFrameShape(QFrame::StyledPanel);
        DisplayFont2TextLabel->setFrameShadow(QFrame::Sunken);
        DisplayFont2TextLabel->setAlignment(Qt::AlignCenter);
        DisplayFont2TextLabel->setWordWrap(false);

        gridLayout9->addWidget(DisplayFont2TextLabel, 3, 0, 1, 1);

        DisplayFont1TextLabel = new QLabel(TimeDisplayGroupBox);
        DisplayFont1TextLabel->setObjectName(QString::fromUtf8("DisplayFont1TextLabel"));
        DisplayFont1TextLabel->setMinimumSize(QSize(180, 0));
        DisplayFont1TextLabel->setMaximumSize(QSize(260, 32767));
        DisplayFont1TextLabel->setFont(font);
        DisplayFont1TextLabel->setAutoFillBackground(true);
        DisplayFont1TextLabel->setFrameShape(QFrame::StyledPanel);
        DisplayFont1TextLabel->setFrameShadow(QFrame::Sunken);
        DisplayFont1TextLabel->setAlignment(Qt::AlignCenter);
        DisplayFont1TextLabel->setWordWrap(false);

        gridLayout9->addWidget(DisplayFont1TextLabel, 1, 0, 1, 1);

        DisplayFont1Label = new QLabel(TimeDisplayGroupBox);
        DisplayFont1Label->setObjectName(QString::fromUtf8("DisplayFont1Label"));
        DisplayFont1Label->setFont(font);
        DisplayFont1Label->setWordWrap(false);

        gridLayout9->addWidget(DisplayFont1Label, 0, 0, 1, 2);

        DisplayFont2PushButton = new QPushButton(TimeDisplayGroupBox);
        DisplayFont2PushButton->setObjectName(QString::fromUtf8("DisplayFont2PushButton"));
        DisplayFont2PushButton->setFont(font);
        DisplayFont2PushButton->setAutoDefault(false);

        gridLayout9->addWidget(DisplayFont2PushButton, 3, 1, 1, 1);

        DisplayFont1PushButton = new QPushButton(TimeDisplayGroupBox);
        DisplayFont1PushButton->setObjectName(QString::fromUtf8("DisplayFont1PushButton"));
        DisplayFont1PushButton->setFont(font);
        DisplayFont1PushButton->setAutoDefault(false);

        gridLayout9->addWidget(DisplayFont1PushButton, 1, 1, 1, 1);

        DisplayFont2Label = new QLabel(TimeDisplayGroupBox);
        DisplayFont2Label->setObjectName(QString::fromUtf8("DisplayFont2Label"));
        DisplayFont2Label->setFont(font);
        DisplayFont2Label->setWordWrap(false);

        gridLayout9->addWidget(DisplayFont2Label, 2, 0, 1, 2);

        DisplayBlinkCheckBox = new QCheckBox(TimeDisplayGroupBox);
        DisplayBlinkCheckBox->setObjectName(QString::fromUtf8("DisplayBlinkCheckBox"));
        DisplayBlinkCheckBox->setFont(font);

        gridLayout9->addWidget(DisplayBlinkCheckBox, 4, 0, 1, 2);


        gridLayout8->addLayout(gridLayout9, 0, 2, 2, 1);


        vboxLayout5->addWidget(TimeDisplayGroupBox);

        DisplayCustomGroupBox = new QGroupBox(DisplayTabPage);
        DisplayCustomGroupBox->setObjectName(QString::fromUtf8("DisplayCustomGroupBox"));
        DisplayCustomGroupBox->setFont(font3);
        DisplayCustomGroupBox->setFlat(true);
        gridLayout10 = new QGridLayout(DisplayCustomGroupBox);
        gridLayout10->setSpacing(4);
        gridLayout10->setContentsMargins(8, 8, 8, 8);
        gridLayout10->setObjectName(QString::fromUtf8("gridLayout10"));
        CustomColorThemeTextLabel = new QLabel(DisplayCustomGroupBox);
        CustomColorThemeTextLabel->setObjectName(QString::fromUtf8("CustomColorThemeTextLabel"));
        CustomColorThemeTextLabel->setFont(font);
        CustomColorThemeTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout10->addWidget(CustomColorThemeTextLabel, 0, 0, 1, 1);

        CustomColorThemeComboBox = new QComboBox(DisplayCustomGroupBox);
        CustomColorThemeComboBox->addItem(QString());
        CustomColorThemeComboBox->addItem(QString());
        CustomColorThemeComboBox->addItem(QString());
        CustomColorThemeComboBox->setObjectName(QString::fromUtf8("CustomColorThemeComboBox"));
        CustomColorThemeComboBox->setFont(font);
        CustomColorThemeComboBox->setEditable(false);

        gridLayout10->addWidget(CustomColorThemeComboBox, 0, 1, 1, 1);

        CustomColorThemeToolButton = new QToolButton(DisplayCustomGroupBox);
        CustomColorThemeToolButton->setObjectName(QString::fromUtf8("CustomColorThemeToolButton"));
        CustomColorThemeToolButton->setMinimumSize(QSize(22, 22));
        CustomColorThemeToolButton->setMaximumSize(QSize(24, 24));
        CustomColorThemeToolButton->setFont(font);
        CustomColorThemeToolButton->setFocusPolicy(Qt::TabFocus);

        gridLayout10->addWidget(CustomColorThemeToolButton, 0, 3, 1, 1);

        spacerItem12 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout10->addItem(spacerItem12, 0, 4, 1, 1);

        CustomStyleThemeTextLabel = new QLabel(DisplayCustomGroupBox);
        CustomStyleThemeTextLabel->setObjectName(QString::fromUtf8("CustomStyleThemeTextLabel"));
        CustomStyleThemeTextLabel->setFont(font);

        gridLayout10->addWidget(CustomStyleThemeTextLabel, 0, 5, 1, 1);

        CustomStyleThemeComboBox = new QComboBox(DisplayCustomGroupBox);
        CustomStyleThemeComboBox->addItem(QString());
        CustomStyleThemeComboBox->setObjectName(QString::fromUtf8("CustomStyleThemeComboBox"));
        CustomStyleThemeComboBox->setFont(font);
        CustomStyleThemeComboBox->setEditable(false);

        gridLayout10->addWidget(CustomStyleThemeComboBox, 0, 6, 1, 1);


        vboxLayout5->addWidget(DisplayCustomGroupBox);

        spacerItem13 = new QSpacerItem(20, 4, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout5->addItem(spacerItem13);

        MessagesWindowGroupBox = new QGroupBox(DisplayTabPage);
        MessagesWindowGroupBox->setObjectName(QString::fromUtf8("MessagesWindowGroupBox"));
        MessagesWindowGroupBox->setFont(font3);
        MessagesWindowGroupBox->setFlat(true);
        hboxLayout4 = new QHBoxLayout(MessagesWindowGroupBox);
        hboxLayout4->setSpacing(4);
        hboxLayout4->setContentsMargins(8, 8, 8, 8);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        MessagesFontTextLabel = new QLabel(MessagesWindowGroupBox);
        MessagesFontTextLabel->setObjectName(QString::fromUtf8("MessagesFontTextLabel"));
        MessagesFontTextLabel->setMinimumSize(QSize(180, 0));
        MessagesFontTextLabel->setMaximumSize(QSize(260, 16777215));
        MessagesFontTextLabel->setFont(font);
        MessagesFontTextLabel->setAutoFillBackground(true);
        MessagesFontTextLabel->setFrameShape(QFrame::StyledPanel);
        MessagesFontTextLabel->setFrameShadow(QFrame::Sunken);
        MessagesFontTextLabel->setAlignment(Qt::AlignCenter);
        MessagesFontTextLabel->setWordWrap(false);

        hboxLayout4->addWidget(MessagesFontTextLabel);

        MessagesFontPushButton = new QPushButton(MessagesWindowGroupBox);
        MessagesFontPushButton->setObjectName(QString::fromUtf8("MessagesFontPushButton"));
        MessagesFontPushButton->setFont(font);
        MessagesFontPushButton->setAutoDefault(false);

        hboxLayout4->addWidget(MessagesFontPushButton);

        spacerItem14 = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem14);

        MessagesLimitCheckBox = new QCheckBox(MessagesWindowGroupBox);
        MessagesLimitCheckBox->setObjectName(QString::fromUtf8("MessagesLimitCheckBox"));
        MessagesLimitCheckBox->setFont(font);

        hboxLayout4->addWidget(MessagesLimitCheckBox);

        MessagesLimitLinesComboBox = new QComboBox(MessagesWindowGroupBox);
        MessagesLimitLinesComboBox->addItem(QString());
        MessagesLimitLinesComboBox->addItem(QString());
        MessagesLimitLinesComboBox->addItem(QString());
        MessagesLimitLinesComboBox->addItem(QString());
        MessagesLimitLinesComboBox->addItem(QString());
        MessagesLimitLinesComboBox->addItem(QString());
        MessagesLimitLinesComboBox->setObjectName(QString::fromUtf8("MessagesLimitLinesComboBox"));
        MessagesLimitLinesComboBox->setFont(font);
        MessagesLimitLinesComboBox->setEditable(true);

        hboxLayout4->addWidget(MessagesLimitLinesComboBox);


        vboxLayout5->addWidget(MessagesWindowGroupBox);

        spacerItem15 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout5->addItem(spacerItem15);

        ConnectionsWindowGroupBox = new QGroupBox(DisplayTabPage);
        ConnectionsWindowGroupBox->setObjectName(QString::fromUtf8("ConnectionsWindowGroupBox"));
        ConnectionsWindowGroupBox->setFont(font3);
        ConnectionsWindowGroupBox->setFlat(true);
        gridLayout11 = new QGridLayout(ConnectionsWindowGroupBox);
        gridLayout11->setSpacing(4);
        gridLayout11->setContentsMargins(8, 8, 8, 8);
        gridLayout11->setObjectName(QString::fromUtf8("gridLayout11"));
        ConnectionsFontTextLabel = new QLabel(ConnectionsWindowGroupBox);
        ConnectionsFontTextLabel->setObjectName(QString::fromUtf8("ConnectionsFontTextLabel"));
        ConnectionsFontTextLabel->setMinimumSize(QSize(180, 0));
        ConnectionsFontTextLabel->setMaximumSize(QSize(260, 16777215));
        ConnectionsFontTextLabel->setFont(font);
        ConnectionsFontTextLabel->setAutoFillBackground(true);
        ConnectionsFontTextLabel->setFrameShape(QFrame::StyledPanel);
        ConnectionsFontTextLabel->setFrameShadow(QFrame::Sunken);
        ConnectionsFontTextLabel->setAlignment(Qt::AlignCenter);
        ConnectionsFontTextLabel->setWordWrap(false);

        gridLayout11->addWidget(ConnectionsFontTextLabel, 0, 0, 1, 1);

        ConnectionsFontPushButton = new QPushButton(ConnectionsWindowGroupBox);
        ConnectionsFontPushButton->setObjectName(QString::fromUtf8("ConnectionsFontPushButton"));
        ConnectionsFontPushButton->setFont(font);
        ConnectionsFontPushButton->setAutoDefault(false);

        gridLayout11->addWidget(ConnectionsFontPushButton, 0, 1, 1, 1);

        spacerItem16 = new QSpacerItem(8, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout11->addItem(spacerItem16, 0, 2, 1, 2);

        ConnectionsIconSizeTextLabel = new QLabel(ConnectionsWindowGroupBox);
        ConnectionsIconSizeTextLabel->setObjectName(QString::fromUtf8("ConnectionsIconSizeTextLabel"));
        ConnectionsIconSizeTextLabel->setFont(font);
        ConnectionsIconSizeTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ConnectionsIconSizeTextLabel->setWordWrap(false);

        gridLayout11->addWidget(ConnectionsIconSizeTextLabel, 0, 4, 1, 1);

        ConnectionsIconSizeComboBox = new QComboBox(ConnectionsWindowGroupBox);
        ConnectionsIconSizeComboBox->addItem(QString());
        ConnectionsIconSizeComboBox->addItem(QString());
        ConnectionsIconSizeComboBox->addItem(QString());
        ConnectionsIconSizeComboBox->setObjectName(QString::fromUtf8("ConnectionsIconSizeComboBox"));
        ConnectionsIconSizeComboBox->setFont(font);
        ConnectionsIconSizeComboBox->setEditable(false);

        gridLayout11->addWidget(ConnectionsIconSizeComboBox, 0, 5, 1, 1);

        spacerItem17 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout11->addItem(spacerItem17, 1, 0, 1, 6);

        AliasesEnabledCheckBox = new QCheckBox(ConnectionsWindowGroupBox);
        AliasesEnabledCheckBox->setObjectName(QString::fromUtf8("AliasesEnabledCheckBox"));
        AliasesEnabledCheckBox->setFont(font);

        gridLayout11->addWidget(AliasesEnabledCheckBox, 2, 0, 1, 3);

        JackClientPortAliasTextLabel = new QLabel(ConnectionsWindowGroupBox);
        JackClientPortAliasTextLabel->setObjectName(QString::fromUtf8("JackClientPortAliasTextLabel"));
        JackClientPortAliasTextLabel->setFont(font);
        JackClientPortAliasTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        JackClientPortAliasTextLabel->setWordWrap(false);

        gridLayout11->addWidget(JackClientPortAliasTextLabel, 2, 3, 1, 2);

        JackClientPortAliasComboBox = new QComboBox(ConnectionsWindowGroupBox);
        JackClientPortAliasComboBox->addItem(QString());
        JackClientPortAliasComboBox->addItem(QString());
        JackClientPortAliasComboBox->addItem(QString());
        JackClientPortAliasComboBox->setObjectName(QString::fromUtf8("JackClientPortAliasComboBox"));
        JackClientPortAliasComboBox->setFont(font);
        JackClientPortAliasComboBox->setEditable(false);

        gridLayout11->addWidget(JackClientPortAliasComboBox, 2, 5, 1, 1);

        AliasesEditingCheckBox = new QCheckBox(ConnectionsWindowGroupBox);
        AliasesEditingCheckBox->setObjectName(QString::fromUtf8("AliasesEditingCheckBox"));
        AliasesEditingCheckBox->setFont(font);

        gridLayout11->addWidget(AliasesEditingCheckBox, 3, 0, 1, 3);

        JackClientPortMetadataCheckBox = new QCheckBox(ConnectionsWindowGroupBox);
        JackClientPortMetadataCheckBox->setObjectName(QString::fromUtf8("JackClientPortMetadataCheckBox"));
        JackClientPortMetadataCheckBox->setFont(font);

        gridLayout11->addWidget(JackClientPortMetadataCheckBox, 3, 3, 1, 3);


        vboxLayout5->addWidget(ConnectionsWindowGroupBox);

        SetupTabWidget->addTab(DisplayTabPage, QString());
        MiscTabPage = new QWidget();
        MiscTabPage->setObjectName(QString::fromUtf8("MiscTabPage"));
        gridLayout12 = new QGridLayout(MiscTabPage);
        gridLayout12->setSpacing(4);
        gridLayout12->setContentsMargins(4, 4, 4, 4);
        gridLayout12->setObjectName(QString::fromUtf8("gridLayout12"));
        OtherGroupBox = new QGroupBox(MiscTabPage);
        OtherGroupBox->setObjectName(QString::fromUtf8("OtherGroupBox"));
        OtherGroupBox->setFont(font3);
        OtherGroupBox->setFlat(true);
        gridLayout13 = new QGridLayout(OtherGroupBox);
        gridLayout13->setSpacing(4);
        gridLayout13->setContentsMargins(4, 4, 4, 4);
        gridLayout13->setObjectName(QString::fromUtf8("gridLayout13"));
        vboxLayout7 = new QVBoxLayout();
        vboxLayout7->setSpacing(4);
        vboxLayout7->setContentsMargins(0, 0, 0, 0);
        vboxLayout7->setObjectName(QString::fromUtf8("vboxLayout7"));
        StartJackCheckBox = new QCheckBox(OtherGroupBox);
        StartJackCheckBox->setObjectName(QString::fromUtf8("StartJackCheckBox"));
        StartJackCheckBox->setFont(font);

        vboxLayout7->addWidget(StartJackCheckBox);

        QueryCloseCheckBox = new QCheckBox(OtherGroupBox);
        QueryCloseCheckBox->setObjectName(QString::fromUtf8("QueryCloseCheckBox"));
        QueryCloseCheckBox->setFont(font);

        vboxLayout7->addWidget(QueryCloseCheckBox);

        QueryShutdownCheckBox = new QCheckBox(OtherGroupBox);
        QueryShutdownCheckBox->setObjectName(QString::fromUtf8("QueryShutdownCheckBox"));
        QueryShutdownCheckBox->setFont(font);

        vboxLayout7->addWidget(QueryShutdownCheckBox);

        KeepOnTopCheckBox = new QCheckBox(OtherGroupBox);
        KeepOnTopCheckBox->setObjectName(QString::fromUtf8("KeepOnTopCheckBox"));
        KeepOnTopCheckBox->setFont(font2);

        vboxLayout7->addWidget(KeepOnTopCheckBox);

        SystemTrayCheckBox = new QCheckBox(OtherGroupBox);
        SystemTrayCheckBox->setObjectName(QString::fromUtf8("SystemTrayCheckBox"));
        SystemTrayCheckBox->setFont(font);

        vboxLayout7->addWidget(SystemTrayCheckBox);

        SystemTrayQueryCloseCheckBox = new QCheckBox(OtherGroupBox);
        SystemTrayQueryCloseCheckBox->setObjectName(QString::fromUtf8("SystemTrayQueryCloseCheckBox"));
        SystemTrayQueryCloseCheckBox->setFont(font);

        vboxLayout7->addWidget(SystemTrayQueryCloseCheckBox);

        StartMinimizedCheckBox = new QCheckBox(OtherGroupBox);
        StartMinimizedCheckBox->setObjectName(QString::fromUtf8("StartMinimizedCheckBox"));
        StartMinimizedCheckBox->setFont(font);

        vboxLayout7->addWidget(StartMinimizedCheckBox);


        gridLayout13->addLayout(vboxLayout7, 0, 0, 1, 1);

        vboxLayout8 = new QVBoxLayout();
        vboxLayout8->setSpacing(4);
        vboxLayout8->setContentsMargins(0, 0, 0, 0);
        vboxLayout8->setObjectName(QString::fromUtf8("vboxLayout8"));
        ServerConfigCheckBox = new QCheckBox(OtherGroupBox);
        ServerConfigCheckBox->setObjectName(QString::fromUtf8("ServerConfigCheckBox"));
        ServerConfigCheckBox->setFont(font);

        vboxLayout8->addWidget(ServerConfigCheckBox);

        ServerConfigNameComboBox = new QComboBox(OtherGroupBox);
        ServerConfigNameComboBox->addItem(QString());
        ServerConfigNameComboBox->setObjectName(QString::fromUtf8("ServerConfigNameComboBox"));
        ServerConfigNameComboBox->setFont(font);
        ServerConfigNameComboBox->setEditable(true);

        vboxLayout8->addWidget(ServerConfigNameComboBox);

        AlsaSeqEnabledCheckBox = new QCheckBox(OtherGroupBox);
        AlsaSeqEnabledCheckBox->setObjectName(QString::fromUtf8("AlsaSeqEnabledCheckBox"));
        AlsaSeqEnabledCheckBox->setFont(font);

        vboxLayout8->addWidget(AlsaSeqEnabledCheckBox);

        DBusEnabledCheckBox = new QCheckBox(OtherGroupBox);
        DBusEnabledCheckBox->setObjectName(QString::fromUtf8("DBusEnabledCheckBox"));
        DBusEnabledCheckBox->setFont(font);

        vboxLayout8->addWidget(DBusEnabledCheckBox);

        JackDBusEnabledCheckBox = new QCheckBox(OtherGroupBox);
        JackDBusEnabledCheckBox->setObjectName(QString::fromUtf8("JackDBusEnabledCheckBox"));
        JackDBusEnabledCheckBox->setFont(font);

        vboxLayout8->addWidget(JackDBusEnabledCheckBox);

        StopJackCheckBox = new QCheckBox(OtherGroupBox);
        StopJackCheckBox->setObjectName(QString::fromUtf8("StopJackCheckBox"));
        StopJackCheckBox->setFont(font);

        vboxLayout8->addWidget(StopJackCheckBox);

        SingletonCheckBox = new QCheckBox(OtherGroupBox);
        SingletonCheckBox->setObjectName(QString::fromUtf8("SingletonCheckBox"));
        SingletonCheckBox->setFont(font);

        vboxLayout8->addWidget(SingletonCheckBox);


        gridLayout13->addLayout(vboxLayout8, 0, 1, 1, 1);

        spacerItem18 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout13->addItem(spacerItem18, 1, 0, 1, 2);


        gridLayout12->addWidget(OtherGroupBox, 0, 0, 1, 2);

        ButtonsGroupBox = new QGroupBox(MiscTabPage);
        ButtonsGroupBox->setObjectName(QString::fromUtf8("ButtonsGroupBox"));
        ButtonsGroupBox->setFont(font3);
        ButtonsGroupBox->setFlat(true);
        vboxLayout9 = new QVBoxLayout(ButtonsGroupBox);
        vboxLayout9->setSpacing(4);
        vboxLayout9->setContentsMargins(8, 8, 8, 8);
        vboxLayout9->setObjectName(QString::fromUtf8("vboxLayout9"));
        vboxLayout10 = new QVBoxLayout();
        vboxLayout10->setSpacing(4);
        vboxLayout10->setContentsMargins(0, 0, 0, 0);
        vboxLayout10->setObjectName(QString::fromUtf8("vboxLayout10"));
        LeftButtonsCheckBox = new QCheckBox(ButtonsGroupBox);
        LeftButtonsCheckBox->setObjectName(QString::fromUtf8("LeftButtonsCheckBox"));
        LeftButtonsCheckBox->setFont(font);

        vboxLayout10->addWidget(LeftButtonsCheckBox);

        RightButtonsCheckBox = new QCheckBox(ButtonsGroupBox);
        RightButtonsCheckBox->setObjectName(QString::fromUtf8("RightButtonsCheckBox"));
        RightButtonsCheckBox->setFont(font);

        vboxLayout10->addWidget(RightButtonsCheckBox);

        TransportButtonsCheckBox = new QCheckBox(ButtonsGroupBox);
        TransportButtonsCheckBox->setObjectName(QString::fromUtf8("TransportButtonsCheckBox"));
        TransportButtonsCheckBox->setFont(font);

        vboxLayout10->addWidget(TransportButtonsCheckBox);

        TextLabelsCheckBox = new QCheckBox(ButtonsGroupBox);
        TextLabelsCheckBox->setObjectName(QString::fromUtf8("TextLabelsCheckBox"));
        TextLabelsCheckBox->setFont(font);

        vboxLayout10->addWidget(TextLabelsCheckBox);

        spacerItem19 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout10->addItem(spacerItem19);

        GraphButtonCheckBox = new QCheckBox(ButtonsGroupBox);
        GraphButtonCheckBox->setObjectName(QString::fromUtf8("GraphButtonCheckBox"));
        GraphButtonCheckBox->setFont(font);

        vboxLayout10->addWidget(GraphButtonCheckBox);


        vboxLayout9->addLayout(vboxLayout10);


        gridLayout12->addWidget(ButtonsGroupBox, 1, 0, 1, 1);

        DefaultsGroupBox = new QGroupBox(MiscTabPage);
        DefaultsGroupBox->setObjectName(QString::fromUtf8("DefaultsGroupBox"));
        DefaultsGroupBox->setFont(font3);
        DefaultsGroupBox->setFlat(true);
        gridLayout14 = new QGridLayout(DefaultsGroupBox);
        gridLayout14->setSpacing(4);
        gridLayout14->setContentsMargins(4, 4, 4, 4);
        gridLayout14->setObjectName(QString::fromUtf8("gridLayout14"));
        spacerItem20 = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout14->addItem(spacerItem20, 1, 0, 1, 3);

        BaseFontSizeTextLabel = new QLabel(DefaultsGroupBox);
        BaseFontSizeTextLabel->setObjectName(QString::fromUtf8("BaseFontSizeTextLabel"));
        BaseFontSizeTextLabel->setFont(font);
        BaseFontSizeTextLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout14->addWidget(BaseFontSizeTextLabel, 0, 1, 1, 1);

        BaseFontSizeComboBox = new QComboBox(DefaultsGroupBox);
        BaseFontSizeComboBox->addItem(QString());
        BaseFontSizeComboBox->addItem(QString());
        BaseFontSizeComboBox->addItem(QString());
        BaseFontSizeComboBox->addItem(QString());
        BaseFontSizeComboBox->addItem(QString());
        BaseFontSizeComboBox->addItem(QString());
        BaseFontSizeComboBox->addItem(QString());
        BaseFontSizeComboBox->addItem(QString());
        BaseFontSizeComboBox->setObjectName(QString::fromUtf8("BaseFontSizeComboBox"));
        BaseFontSizeComboBox->setFont(font);
        BaseFontSizeComboBox->setEditable(true);

        gridLayout14->addWidget(BaseFontSizeComboBox, 0, 2, 1, 1);


        gridLayout12->addWidget(DefaultsGroupBox, 1, 1, 1, 1);

        SetupTabWidget->addTab(MiscTabPage, QString());

        vboxLayout->addWidget(SetupTabWidget);

        DialogButtonBox = new QDialogButtonBox(qjackctlSetupForm);
        DialogButtonBox->setObjectName(QString::fromUtf8("DialogButtonBox"));
        DialogButtonBox->setOrientation(Qt::Horizontal);
        DialogButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Apply|QDialogButtonBox::Ok);

        vboxLayout->addWidget(DialogButtonBox);

#ifndef QT_NO_SHORTCUT
        PresetTextLabel->setBuddy(PresetComboBox);
        DriverTextLabel->setBuddy(DriverComboBox);
        InterfaceTextLabel->setBuddy(InterfaceComboBox);
        MidiDriverTextLabel->setBuddy(MidiDriverComboBox);
        SampleRateTextLabel->setBuddy(SampleRateComboBox);
        FramesTextLabel->setBuddy(FramesComboBox);
        PeriodsTextLabel->setBuddy(PeriodsSpinBox);
        ServerPrefixTextLabel->setBuddy(ServerPrefixComboBox);
        ServerNameTextLabel->setBuddy(ServerNameComboBox);
        PriorityTextLabel->setBuddy(PrioritySpinBox);
        PortMaxTextLabel->setBuddy(PortMaxComboBox);
        ChanTextLabel->setBuddy(ChanSpinBox);
        WaitTextLabel->setBuddy(WaitComboBox);
        TimeoutTextLabel->setBuddy(TimeoutComboBox);
        WordLengthTextLabel->setBuddy(WordLengthComboBox);
        AudioTextLabel->setBuddy(AudioComboBox);
        DitherTextLabel->setBuddy(DitherComboBox);
        OutDeviceTextLabel->setBuddy(OutDeviceComboBox);
        InDeviceTextLabel->setBuddy(InDeviceComboBox);
        InOutChannelsTextLabel->setBuddy(InChannelsSpinBox);
        InOutLatencyTextLabel->setBuddy(InLatencySpinBox);
        ServerSuffixTextLabel->setBuddy(ServerSuffixComboBox);
        StartDelayTextLabel->setBuddy(StartDelaySpinBox);
        XrunRegexTextLabel->setBuddy(XrunRegexComboBox);
        CustomColorThemeTextLabel->setBuddy(CustomColorThemeComboBox);
        CustomStyleThemeTextLabel->setBuddy(CustomStyleThemeComboBox);
        ConnectionsIconSizeTextLabel->setBuddy(ConnectionsIconSizeComboBox);
        JackClientPortAliasTextLabel->setBuddy(JackClientPortAliasComboBox);
        BaseFontSizeTextLabel->setBuddy(BaseFontSizeComboBox);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(SetupTabWidget, PresetComboBox);
        QWidget::setTabOrder(PresetComboBox, PresetSavePushButton);
        QWidget::setTabOrder(PresetSavePushButton, PresetDeletePushButton);
        QWidget::setTabOrder(PresetDeletePushButton, SettingsTabWidget);
        QWidget::setTabOrder(SettingsTabWidget, DriverComboBox);
        QWidget::setTabOrder(DriverComboBox, RealtimeCheckBox);
        QWidget::setTabOrder(RealtimeCheckBox, InterfaceComboBox);
        QWidget::setTabOrder(InterfaceComboBox, SampleRateComboBox);
        QWidget::setTabOrder(SampleRateComboBox, FramesComboBox);
        QWidget::setTabOrder(FramesComboBox, PeriodsSpinBox);
        QWidget::setTabOrder(PeriodsSpinBox, MidiDriverComboBox);
        QWidget::setTabOrder(MidiDriverComboBox, SyncCheckBox);
        QWidget::setTabOrder(SyncCheckBox, VerboseCheckBox);
        QWidget::setTabOrder(VerboseCheckBox, ServerPrefixComboBox);
        QWidget::setTabOrder(ServerPrefixComboBox, ServerNameComboBox);
        QWidget::setTabOrder(ServerNameComboBox, NoMemLockCheckBox);
        QWidget::setTabOrder(NoMemLockCheckBox, UnlockMemCheckBox);
        QWidget::setTabOrder(UnlockMemCheckBox, HWMeterCheckBox);
        QWidget::setTabOrder(HWMeterCheckBox, MonitorCheckBox);
        QWidget::setTabOrder(MonitorCheckBox, SoftModeCheckBox);
        QWidget::setTabOrder(SoftModeCheckBox, ShortsCheckBox);
        QWidget::setTabOrder(ShortsCheckBox, IgnoreHWCheckBox);
        QWidget::setTabOrder(IgnoreHWCheckBox, PrioritySpinBox);
        QWidget::setTabOrder(PrioritySpinBox, WordLengthComboBox);
        QWidget::setTabOrder(WordLengthComboBox, WaitComboBox);
        QWidget::setTabOrder(WaitComboBox, ChanSpinBox);
        QWidget::setTabOrder(ChanSpinBox, PortMaxComboBox);
        QWidget::setTabOrder(PortMaxComboBox, TimeoutComboBox);
        QWidget::setTabOrder(TimeoutComboBox, AudioComboBox);
        QWidget::setTabOrder(AudioComboBox, DitherComboBox);
        QWidget::setTabOrder(DitherComboBox, OutDeviceComboBox);
        QWidget::setTabOrder(OutDeviceComboBox, InDeviceComboBox);
        QWidget::setTabOrder(InDeviceComboBox, InChannelsSpinBox);
        QWidget::setTabOrder(InChannelsSpinBox, OutChannelsSpinBox);
        QWidget::setTabOrder(OutChannelsSpinBox, InLatencySpinBox);
        QWidget::setTabOrder(InLatencySpinBox, OutLatencySpinBox);
        QWidget::setTabOrder(OutLatencySpinBox, ServerSuffixComboBox);
        QWidget::setTabOrder(ServerSuffixComboBox, StartDelaySpinBox);
        QWidget::setTabOrder(StartDelaySpinBox, StartupScriptCheckBox);
        QWidget::setTabOrder(StartupScriptCheckBox, StartupScriptShellComboBox);
        QWidget::setTabOrder(StartupScriptShellComboBox, StartupScriptSymbolToolButton);
        QWidget::setTabOrder(StartupScriptSymbolToolButton, StartupScriptBrowseToolButton);
        QWidget::setTabOrder(StartupScriptBrowseToolButton, PostStartupScriptCheckBox);
        QWidget::setTabOrder(PostStartupScriptCheckBox, PostStartupScriptShellComboBox);
        QWidget::setTabOrder(PostStartupScriptShellComboBox, PostStartupScriptSymbolToolButton);
        QWidget::setTabOrder(PostStartupScriptSymbolToolButton, PostStartupScriptBrowseToolButton);
        QWidget::setTabOrder(PostStartupScriptBrowseToolButton, ShutdownScriptCheckBox);
        QWidget::setTabOrder(ShutdownScriptCheckBox, ShutdownScriptShellComboBox);
        QWidget::setTabOrder(ShutdownScriptShellComboBox, ShutdownScriptSymbolToolButton);
        QWidget::setTabOrder(ShutdownScriptSymbolToolButton, ShutdownScriptBrowseToolButton);
        QWidget::setTabOrder(ShutdownScriptBrowseToolButton, PostShutdownScriptCheckBox);
        QWidget::setTabOrder(PostShutdownScriptCheckBox, PostShutdownScriptShellComboBox);
        QWidget::setTabOrder(PostShutdownScriptShellComboBox, PostShutdownScriptSymbolToolButton);
        QWidget::setTabOrder(PostShutdownScriptSymbolToolButton, PostShutdownScriptBrowseToolButton);
        QWidget::setTabOrder(PostShutdownScriptBrowseToolButton, StdoutCaptureCheckBox);
        QWidget::setTabOrder(StdoutCaptureCheckBox, XrunRegexComboBox);
        QWidget::setTabOrder(XrunRegexComboBox, ActivePatchbayCheckBox);
        QWidget::setTabOrder(ActivePatchbayCheckBox, ActivePatchbayPathComboBox);
        QWidget::setTabOrder(ActivePatchbayPathComboBox, ActivePatchbayPathToolButton);
        QWidget::setTabOrder(ActivePatchbayPathToolButton, ActivePatchbayResetCheckBox);
        QWidget::setTabOrder(ActivePatchbayResetCheckBox, QueryDisconnectCheckBox);
        QWidget::setTabOrder(QueryDisconnectCheckBox, MessagesLogCheckBox);
        QWidget::setTabOrder(MessagesLogCheckBox, MessagesLogPathComboBox);
        QWidget::setTabOrder(MessagesLogPathComboBox, MessagesLogPathToolButton);
        QWidget::setTabOrder(MessagesLogPathToolButton, TransportTimeRadioButton);
        QWidget::setTabOrder(TransportTimeRadioButton, TransportBBTRadioButton);
        QWidget::setTabOrder(TransportBBTRadioButton, ElapsedResetRadioButton);
        QWidget::setTabOrder(ElapsedResetRadioButton, ElapsedXrunRadioButton);
        QWidget::setTabOrder(ElapsedXrunRadioButton, DisplayFont1PushButton);
        QWidget::setTabOrder(DisplayFont1PushButton, DisplayFont2PushButton);
        QWidget::setTabOrder(DisplayFont2PushButton, DisplayBlinkCheckBox);
        QWidget::setTabOrder(DisplayBlinkCheckBox, CustomColorThemeComboBox);
        QWidget::setTabOrder(CustomColorThemeComboBox, CustomColorThemeToolButton);
        QWidget::setTabOrder(CustomColorThemeToolButton, CustomStyleThemeComboBox);
        QWidget::setTabOrder(CustomStyleThemeComboBox, MessagesFontPushButton);
        QWidget::setTabOrder(MessagesFontPushButton, MessagesLimitCheckBox);
        QWidget::setTabOrder(MessagesLimitCheckBox, MessagesLimitLinesComboBox);
        QWidget::setTabOrder(MessagesLimitLinesComboBox, ConnectionsFontPushButton);
        QWidget::setTabOrder(ConnectionsFontPushButton, ConnectionsIconSizeComboBox);
        QWidget::setTabOrder(ConnectionsIconSizeComboBox, AliasesEnabledCheckBox);
        QWidget::setTabOrder(AliasesEnabledCheckBox, AliasesEditingCheckBox);
        QWidget::setTabOrder(AliasesEditingCheckBox, JackClientPortAliasComboBox);
        QWidget::setTabOrder(JackClientPortAliasComboBox, JackClientPortMetadataCheckBox);
        QWidget::setTabOrder(JackClientPortMetadataCheckBox, StartJackCheckBox);
        QWidget::setTabOrder(StartJackCheckBox, QueryCloseCheckBox);
        QWidget::setTabOrder(QueryCloseCheckBox, QueryShutdownCheckBox);
        QWidget::setTabOrder(QueryShutdownCheckBox, KeepOnTopCheckBox);
        QWidget::setTabOrder(KeepOnTopCheckBox, SystemTrayCheckBox);
        QWidget::setTabOrder(SystemTrayCheckBox, SystemTrayQueryCloseCheckBox);
        QWidget::setTabOrder(SystemTrayQueryCloseCheckBox, StartMinimizedCheckBox);
        QWidget::setTabOrder(StartMinimizedCheckBox, ServerConfigCheckBox);
        QWidget::setTabOrder(ServerConfigCheckBox, ServerConfigNameComboBox);
        QWidget::setTabOrder(ServerConfigNameComboBox, AlsaSeqEnabledCheckBox);
        QWidget::setTabOrder(AlsaSeqEnabledCheckBox, DBusEnabledCheckBox);
        QWidget::setTabOrder(DBusEnabledCheckBox, JackDBusEnabledCheckBox);
        QWidget::setTabOrder(JackDBusEnabledCheckBox, StopJackCheckBox);
        QWidget::setTabOrder(StopJackCheckBox, SingletonCheckBox);
        QWidget::setTabOrder(SingletonCheckBox, LeftButtonsCheckBox);
        QWidget::setTabOrder(LeftButtonsCheckBox, RightButtonsCheckBox);
        QWidget::setTabOrder(RightButtonsCheckBox, TransportButtonsCheckBox);
        QWidget::setTabOrder(TransportButtonsCheckBox, TextLabelsCheckBox);
        QWidget::setTabOrder(TextLabelsCheckBox, BaseFontSizeComboBox);
        QWidget::setTabOrder(BaseFontSizeComboBox, DialogButtonBox);

        retranslateUi(qjackctlSetupForm);

        SetupTabWidget->setCurrentIndex(0);
        SettingsTabWidget->setCurrentIndex(0);
        TimeoutComboBox->setCurrentIndex(1);
        PortMaxComboBox->setCurrentIndex(1);
        MessagesLimitLinesComboBox->setCurrentIndex(3);
        ConnectionsIconSizeComboBox->setCurrentIndex(0);
        JackClientPortAliasComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(qjackctlSetupForm);
    } // setupUi

    void retranslateUi(QDialog *qjackctlSetupForm)
    {
        qjackctlSetupForm->setWindowTitle(QApplication::translate("qjackctlSetupForm", "Setup", nullptr));
        PresetTextLabel->setText(QApplication::translate("qjackctlSetupForm", "Preset &Name:", nullptr));
        PresetComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "(default)", nullptr));

#ifndef QT_NO_TOOLTIP
        PresetComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Settings preset name", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        PresetSavePushButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Save settings as current preset name", nullptr));
#endif // QT_NO_TOOLTIP
        PresetSavePushButton->setText(QApplication::translate("qjackctlSetupForm", "&Save", nullptr));
#ifndef QT_NO_TOOLTIP
        PresetDeletePushButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Delete current settings preset", nullptr));
#endif // QT_NO_TOOLTIP
        PresetDeletePushButton->setText(QApplication::translate("qjackctlSetupForm", "&Delete", nullptr));
        DriverTextLabel->setText(QApplication::translate("qjackctlSetupForm", "Driv&er:", nullptr));
        DriverComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "dummy", nullptr));
        DriverComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "sun", nullptr));
        DriverComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "oss", nullptr));
        DriverComboBox->setItemText(3, QApplication::translate("qjackctlSetupForm", "alsa", nullptr));
        DriverComboBox->setItemText(4, QApplication::translate("qjackctlSetupForm", "portaudio", nullptr));
        DriverComboBox->setItemText(5, QApplication::translate("qjackctlSetupForm", "coreaudio", nullptr));
        DriverComboBox->setItemText(6, QApplication::translate("qjackctlSetupForm", "firewire", nullptr));
        DriverComboBox->setItemText(7, QApplication::translate("qjackctlSetupForm", "net", nullptr));
        DriverComboBox->setItemText(8, QApplication::translate("qjackctlSetupForm", "netone", nullptr));

#ifndef QT_NO_TOOLTIP
        DriverComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "The audio backend driver interface to use", nullptr));
#endif // QT_NO_TOOLTIP
        InterfaceTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Interface:", nullptr));
        InterfaceComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "(default)", nullptr));
        InterfaceComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "hw:0", nullptr));
        InterfaceComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "plughw:0", nullptr));
        InterfaceComboBox->setItemText(3, QApplication::translate("qjackctlSetupForm", "/dev/audio", nullptr));
        InterfaceComboBox->setItemText(4, QApplication::translate("qjackctlSetupForm", "/dev/dsp", nullptr));

#ifndef QT_NO_TOOLTIP
        InterfaceComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "The PCM device name to use", nullptr));
#endif // QT_NO_TOOLTIP
        MidiDriverTextLabel->setText(QApplication::translate("qjackctlSetupForm", "MIDI Driv&er:", nullptr));
        MidiDriverComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "none", nullptr));
        MidiDriverComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "raw", nullptr));
        MidiDriverComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "seq", nullptr));

#ifndef QT_NO_TOOLTIP
        MidiDriverComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "The ALSA MIDI backend driver to use", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        RealtimeCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Use realtime scheduling", nullptr));
#endif // QT_NO_TOOLTIP
        RealtimeCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Realtime", nullptr));
        SampleRateTextLabel->setText(QApplication::translate("qjackctlSetupForm", "Sample &Rate:", nullptr));
        SampleRateComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "22050", nullptr));
        SampleRateComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "32000", nullptr));
        SampleRateComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "44100", nullptr));
        SampleRateComboBox->setItemText(3, QApplication::translate("qjackctlSetupForm", "48000", nullptr));
        SampleRateComboBox->setItemText(4, QApplication::translate("qjackctlSetupForm", "88200", nullptr));
        SampleRateComboBox->setItemText(5, QApplication::translate("qjackctlSetupForm", "96000", nullptr));
        SampleRateComboBox->setItemText(6, QApplication::translate("qjackctlSetupForm", "192000", nullptr));

#ifndef QT_NO_TOOLTIP
        SampleRateComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Sample rate in frames per second", nullptr));
#endif // QT_NO_TOOLTIP
        FramesTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Frames/Period:", nullptr));
        FramesComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "16", nullptr));
        FramesComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "32", nullptr));
        FramesComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "64", nullptr));
        FramesComboBox->setItemText(3, QApplication::translate("qjackctlSetupForm", "128", nullptr));
        FramesComboBox->setItemText(4, QApplication::translate("qjackctlSetupForm", "256", nullptr));
        FramesComboBox->setItemText(5, QApplication::translate("qjackctlSetupForm", "512", nullptr));
        FramesComboBox->setItemText(6, QApplication::translate("qjackctlSetupForm", "1024", nullptr));
        FramesComboBox->setItemText(7, QApplication::translate("qjackctlSetupForm", "2048", nullptr));
        FramesComboBox->setItemText(8, QApplication::translate("qjackctlSetupForm", "4096", nullptr));

#ifndef QT_NO_TOOLTIP
        FramesComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Frames per period between process() calls", nullptr));
#endif // QT_NO_TOOLTIP
        PeriodsTextLabel->setText(QApplication::translate("qjackctlSetupForm", "Periods/&Buffer:", nullptr));
#ifndef QT_NO_TOOLTIP
        PeriodsSpinBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Number of periods in the hardware buffer", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        SyncCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to use server synchronous mode", nullptr));
#endif // QT_NO_TOOLTIP
        SyncCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Use server synchronous mode", nullptr));
#ifndef QT_NO_TOOLTIP
        VerboseCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to give verbose output on messages", nullptr));
#endif // QT_NO_TOOLTIP
        VerboseCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Verbose messages", nullptr));
        LatencyTextLabel->setText(QApplication::translate("qjackctlSetupForm", "Latency:", nullptr));
#ifndef QT_NO_TOOLTIP
        LatencyTextValue->setToolTip(QApplication::translate("qjackctlSetupForm", "Output latency in milliseconds, calculated based on the period, rate and buffer settings", nullptr));
#endif // QT_NO_TOOLTIP
        LatencyTextValue->setText(QApplication::translate("qjackctlSetupForm", "0 msecs", nullptr));
        SettingsTabWidget->setTabText(SettingsTabWidget->indexOf(ParametersTab), QApplication::translate("qjackctlSetupForm", "Parameters", nullptr));
        label->setText(QApplication::translate("qjackctlSetupForm", "Please do not touch these settings unless you know what you are doing.", nullptr));
        ServerPrefixTextLabel->setText(QApplication::translate("qjackctlSetupForm", "Server &Prefix:", nullptr));
        ServerPrefixComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "jackd", nullptr));
        ServerPrefixComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "jackdmp", nullptr));
        ServerPrefixComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "jackstart", nullptr));

#ifndef QT_NO_TOOLTIP
        ServerPrefixComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Server path (command line prefix)", nullptr));
#endif // QT_NO_TOOLTIP
        ServerNameTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Name:", nullptr));
        ServerNameComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "(default)", nullptr));

#ifndef QT_NO_TOOLTIP
        ServerNameComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "The JACK Audio Connection Kit sound server name", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        NoMemLockCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Do not attempt to lock memory, even if in realtime mode", nullptr));
#endif // QT_NO_TOOLTIP
        NoMemLockCheckBox->setText(QApplication::translate("qjackctlSetupForm", "No Memory Loc&k", nullptr));
#ifndef QT_NO_TOOLTIP
        UnlockMemCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Unlock memory of common toolkit libraries (GTK+, QT, FLTK, Wine)", nullptr));
#endif // QT_NO_TOOLTIP
        UnlockMemCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Unlock Memory", nullptr));
#ifndef QT_NO_TOOLTIP
        HWMeterCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Enable hardware metering on cards that support it", nullptr));
#endif // QT_NO_TOOLTIP
        HWMeterCheckBox->setText(QApplication::translate("qjackctlSetupForm", "H/&W Meter", nullptr));
#ifndef QT_NO_TOOLTIP
        MonitorCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Provide output monitor ports", nullptr));
#endif // QT_NO_TOOLTIP
        MonitorCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Monitor", nullptr));
#ifndef QT_NO_TOOLTIP
        SoftModeCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Ignore xruns reported by the backend driver", nullptr));
#endif // QT_NO_TOOLTIP
        SoftModeCheckBox->setText(QApplication::translate("qjackctlSetupForm", "So&ft Mode", nullptr));
#ifndef QT_NO_TOOLTIP
        ShortsCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Force 16bit mode instead of failing over 32bit (default)", nullptr));
#endif // QT_NO_TOOLTIP
        ShortsCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Force &16bit", nullptr));
#ifndef QT_NO_TOOLTIP
        IgnoreHWCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Ignore hardware period/buffer size", nullptr));
#endif // QT_NO_TOOLTIP
        IgnoreHWCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Ignore H/W", nullptr));
#ifndef QT_NO_TOOLTIP
        ChanSpinBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Maximum number of audio channels to allocate", nullptr));
#endif // QT_NO_TOOLTIP
        ChanSpinBox->setSpecialValueText(QApplication::translate("qjackctlSetupForm", "(default)", nullptr));
        WaitComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "21333", nullptr));

#ifndef QT_NO_TOOLTIP
        WaitComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Number of microseconds to wait between engine processes (dummy)", nullptr));
#endif // QT_NO_TOOLTIP
        PriorityTextLabel->setText(QApplication::translate("qjackctlSetupForm", "Priorit&y:", nullptr));
        TimeoutComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "200", nullptr));
        TimeoutComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "500", nullptr));
        TimeoutComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "1000", nullptr));
        TimeoutComboBox->setItemText(3, QApplication::translate("qjackctlSetupForm", "2000", nullptr));
        TimeoutComboBox->setItemText(4, QApplication::translate("qjackctlSetupForm", "5000", nullptr));
        TimeoutComboBox->setItemText(5, QApplication::translate("qjackctlSetupForm", "10000", nullptr));

#ifndef QT_NO_TOOLTIP
        TimeoutComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Set client timeout limit in milliseconds", nullptr));
#endif // QT_NO_TOOLTIP
        PortMaxTextLabel->setText(QApplication::translate("qjackctlSetupForm", "Port Ma&ximum:", nullptr));
        ChanTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Channels:", nullptr));
        WordLengthComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "16", nullptr));
        WordLengthComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "32", nullptr));
        WordLengthComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "64", nullptr));

#ifndef QT_NO_TOOLTIP
        WordLengthComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Word length", nullptr));
#endif // QT_NO_TOOLTIP
        WaitTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Wait (usec):", nullptr));
        TimeoutTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Timeout (msec):", nullptr));
        PortMaxComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "128", nullptr));
        PortMaxComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "256", nullptr));
        PortMaxComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "512", nullptr));
        PortMaxComboBox->setItemText(3, QApplication::translate("qjackctlSetupForm", "1024", nullptr));

#ifndef QT_NO_TOOLTIP
        PortMaxComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Maximum number of ports the JACK server can manage", nullptr));
#endif // QT_NO_TOOLTIP
        WordLengthTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Word Length:", nullptr));
#ifndef QT_NO_TOOLTIP
        PrioritySpinBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Scheduler priority when running realtime", nullptr));
#endif // QT_NO_TOOLTIP
        PrioritySpinBox->setSpecialValueText(QApplication::translate("qjackctlSetupForm", "(default)", nullptr));
        AudioTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Audio:", nullptr));
        AudioComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "Duplex", nullptr));
        AudioComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "Capture Only", nullptr));
        AudioComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "Playback Only", nullptr));

#ifndef QT_NO_TOOLTIP
        AudioComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Provide either audio capture, playback or both", nullptr));
#endif // QT_NO_TOOLTIP
        DitherTextLabel->setText(QApplication::translate("qjackctlSetupForm", "Dit&her:", nullptr));
        DitherComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "None", nullptr));
        DitherComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "Rectangular", nullptr));
        DitherComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "Shaped", nullptr));
        DitherComboBox->setItemText(3, QApplication::translate("qjackctlSetupForm", "Triangular", nullptr));

#ifndef QT_NO_TOOLTIP
        DitherComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Set dither mode", nullptr));
#endif // QT_NO_TOOLTIP
        OutDeviceTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Output Device:", nullptr));
        OutDeviceComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "(default)", nullptr));
        OutDeviceComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "hw:0", nullptr));
        OutDeviceComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "plughw:0", nullptr));
        OutDeviceComboBox->setItemText(3, QApplication::translate("qjackctlSetupForm", "/dev/audio", nullptr));
        OutDeviceComboBox->setItemText(4, QApplication::translate("qjackctlSetupForm", "/dev/dsp", nullptr));

#ifndef QT_NO_TOOLTIP
        OutDeviceComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Alternate output device for playback", nullptr));
#endif // QT_NO_TOOLTIP
        InDeviceTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Input Device:", nullptr));
        InDeviceComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "(default)", nullptr));
        InDeviceComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "hw:0", nullptr));
        InDeviceComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "plughw:0", nullptr));
        InDeviceComboBox->setItemText(3, QApplication::translate("qjackctlSetupForm", "/dev/audio", nullptr));
        InDeviceComboBox->setItemText(4, QApplication::translate("qjackctlSetupForm", "/dev/dsp", nullptr));

#ifndef QT_NO_TOOLTIP
        InDeviceComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Alternate input device for capture", nullptr));
#endif // QT_NO_TOOLTIP
        InOutChannelsTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Channels I/O:", nullptr));
#ifndef QT_NO_TOOLTIP
        InChannelsSpinBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Maximum input audio hardware channels to allocate", nullptr));
#endif // QT_NO_TOOLTIP
        InChannelsSpinBox->setSpecialValueText(QApplication::translate("qjackctlSetupForm", "(default)", nullptr));
#ifndef QT_NO_TOOLTIP
        OutChannelsSpinBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Maximum output audio hardware channels to allocate", nullptr));
#endif // QT_NO_TOOLTIP
        OutChannelsSpinBox->setSpecialValueText(QApplication::translate("qjackctlSetupForm", "(default)", nullptr));
        InOutLatencyTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Latency I/O:", nullptr));
#ifndef QT_NO_TOOLTIP
        InLatencySpinBox->setToolTip(QApplication::translate("qjackctlSetupForm", "External input latency (frames)", nullptr));
#endif // QT_NO_TOOLTIP
        InLatencySpinBox->setSpecialValueText(QApplication::translate("qjackctlSetupForm", "(default)", nullptr));
#ifndef QT_NO_TOOLTIP
        OutLatencySpinBox->setToolTip(QApplication::translate("qjackctlSetupForm", "External output latency (frames)", nullptr));
#endif // QT_NO_TOOLTIP
        OutLatencySpinBox->setSpecialValueText(QApplication::translate("qjackctlSetupForm", "(default)", nullptr));
        ServerSuffixTextLabel->setText(QApplication::translate("qjackctlSetupForm", "Server Suffi&x:", nullptr));
#ifndef QT_NO_TOOLTIP
        ServerSuffixComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Extra driver options (command line suffix)", nullptr));
#endif // QT_NO_TOOLTIP
        StartDelayTextLabel->setText(QApplication::translate("qjackctlSetupForm", "Start De&lay:", nullptr));
#ifndef QT_NO_TOOLTIP
        StartDelaySpinBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Time in seconds that client is delayed after server startup", nullptr));
#endif // QT_NO_TOOLTIP
        StartDelaySpinBox->setSuffix(QApplication::translate("qjackctlSetupForm", " secs", nullptr));
        SettingsTabWidget->setTabText(SettingsTabWidget->indexOf(AdvancedTab), QApplication::translate("qjackctlSetupForm", "Advanced", nullptr));
        SetupTabWidget->setTabText(SetupTabWidget->indexOf(SettingsTabPage), QApplication::translate("qjackctlSetupForm", "Settings", nullptr));
        ScriptingGroupBox->setTitle(QApplication::translate("qjackctlSetupForm", "Scripting", nullptr));
#ifndef QT_NO_TOOLTIP
        StartupScriptCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to execute a custom shell script before starting up the JACK audio server.", nullptr));
#endif // QT_NO_TOOLTIP
        StartupScriptCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Execute script on Start&up:", nullptr));
#ifndef QT_NO_TOOLTIP
        PostStartupScriptCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to execute a custom shell script after starting up the JACK audio server.", nullptr));
#endif // QT_NO_TOOLTIP
        PostStartupScriptCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Execute script after &Startup:", nullptr));
#ifndef QT_NO_TOOLTIP
        ShutdownScriptCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to execute a custom shell script before shuting down the JACK audio server.", nullptr));
#endif // QT_NO_TOOLTIP
        ShutdownScriptCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Execute script on Shut&down:", nullptr));
#ifndef QT_NO_TOOLTIP
        StartupScriptShellComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Command line to be executed before starting up the JACK audio server", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        StartupScriptSymbolToolButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Scripting argument meta-symbols", nullptr));
#endif // QT_NO_TOOLTIP
        StartupScriptSymbolToolButton->setText(QApplication::translate("qjackctlSetupForm", ">", nullptr));
#ifndef QT_NO_TOOLTIP
        StartupScriptBrowseToolButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Browse for script to be executed before starting up the JACK audio server", nullptr));
#endif // QT_NO_TOOLTIP
        StartupScriptBrowseToolButton->setText(QApplication::translate("qjackctlSetupForm", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        PostStartupScriptShellComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Command line to be executed after starting up the JACK audio server", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        PostStartupScriptSymbolToolButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Scripting argument meta-symbols", nullptr));
#endif // QT_NO_TOOLTIP
        PostStartupScriptSymbolToolButton->setText(QApplication::translate("qjackctlSetupForm", ">", nullptr));
#ifndef QT_NO_TOOLTIP
        PostStartupScriptBrowseToolButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Browse for script to be executed after starting up the JACK audio server", nullptr));
#endif // QT_NO_TOOLTIP
        PostStartupScriptBrowseToolButton->setText(QApplication::translate("qjackctlSetupForm", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        ShutdownScriptSymbolToolButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Scripting argument meta-symbols", nullptr));
#endif // QT_NO_TOOLTIP
        ShutdownScriptSymbolToolButton->setText(QApplication::translate("qjackctlSetupForm", ">", nullptr));
#ifndef QT_NO_TOOLTIP
        ShutdownScriptBrowseToolButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Browse for script to be executed before shutting down the JACK audio server", nullptr));
#endif // QT_NO_TOOLTIP
        ShutdownScriptBrowseToolButton->setText(QApplication::translate("qjackctlSetupForm", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        ShutdownScriptShellComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Command line to be executed before shutting down the JACK audio server", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        PostShutdownScriptCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to execute a custom shell script after shuting down the JACK audio server.", nullptr));
#endif // QT_NO_TOOLTIP
        PostShutdownScriptCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Execute script after Shu&tdown:", nullptr));
#ifndef QT_NO_TOOLTIP
        PostShutdownScriptSymbolToolButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Scripting argument meta-symbols", nullptr));
#endif // QT_NO_TOOLTIP
        PostShutdownScriptSymbolToolButton->setText(QApplication::translate("qjackctlSetupForm", ">", nullptr));
#ifndef QT_NO_TOOLTIP
        PostShutdownScriptBrowseToolButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Browse for script to be executed after shutting down the JACK audio server", nullptr));
#endif // QT_NO_TOOLTIP
        PostShutdownScriptBrowseToolButton->setText(QApplication::translate("qjackctlSetupForm", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        PostShutdownScriptShellComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Command line to be executed after shutting down the JACK audio server", nullptr));
#endif // QT_NO_TOOLTIP
        StatisticsGroupBox->setTitle(QApplication::translate("qjackctlSetupForm", "Statistics", nullptr));
#ifndef QT_NO_TOOLTIP
        StdoutCaptureCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to capture standard output (stdout/stderr) into messages window", nullptr));
#endif // QT_NO_TOOLTIP
        StdoutCaptureCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Capture standard output", nullptr));
        XrunRegexTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&XRUN detection regex:", nullptr));
        XrunRegexComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "xrun of at least ([0-9|\\.]+) msecs", nullptr));

#ifndef QT_NO_TOOLTIP
        XrunRegexComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Regular expression used to detect XRUNs on server output messages", nullptr));
#endif // QT_NO_TOOLTIP
        ConnectionsGroupBox->setTitle(QApplication::translate("qjackctlSetupForm", "Connections", nullptr));
#ifndef QT_NO_TOOLTIP
        ActivePatchbayCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to activate a patchbay definition for connection persistence profile.", nullptr));
#endif // QT_NO_TOOLTIP
        ActivePatchbayCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Activate &Patchbay persistence:", nullptr));
#ifndef QT_NO_TOOLTIP
        ActivePatchbayPathComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Patchbay definition file to be activated as connection persistence profile", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ActivePatchbayPathToolButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Browse for a patchbay definition file to be activated", nullptr));
#endif // QT_NO_TOOLTIP
        ActivePatchbayPathToolButton->setText(QApplication::translate("qjackctlSetupForm", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        ActivePatchbayResetCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to reset all connections when a patchbay definition is activated.", nullptr));
#endif // QT_NO_TOOLTIP
        ActivePatchbayResetCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Reset all connections on patchbay activation", nullptr));
#ifndef QT_NO_TOOLTIP
        QueryDisconnectCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to issue a warning on active patchbay port disconnections.", nullptr));
#endif // QT_NO_TOOLTIP
        QueryDisconnectCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Warn on active patchbay disconnections", nullptr));
        LoggingGroupBox->setTitle(QApplication::translate("qjackctlSetupForm", "Logging", nullptr));
#ifndef QT_NO_TOOLTIP
        MessagesLogCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to activate a messages logging to file.", nullptr));
#endif // QT_NO_TOOLTIP
        MessagesLogCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Messages log file:", nullptr));
#ifndef QT_NO_TOOLTIP
        MessagesLogPathComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Messages log file", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        MessagesLogPathToolButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Browse for the messages log file location", nullptr));
#endif // QT_NO_TOOLTIP
        MessagesLogPathToolButton->setText(QApplication::translate("qjackctlSetupForm", "...", nullptr));
        SetupTabWidget->setTabText(SetupTabWidget->indexOf(OptionsTabPage), QApplication::translate("qjackctlSetupForm", "Options", nullptr));
        TimeDisplayGroupBox->setTitle(QApplication::translate("qjackctlSetupForm", "Time Display", nullptr));
        TransportTimeRadioButton->setText(QApplication::translate("qjackctlSetupForm", "Transport &Time Code", nullptr));
        TransportBBTRadioButton->setText(QApplication::translate("qjackctlSetupForm", "Transport &BBT (bar:beat.ticks)", nullptr));
        ElapsedResetRadioButton->setText(QApplication::translate("qjackctlSetupForm", "Elapsed time since last &Reset", nullptr));
        ElapsedXrunRadioButton->setText(QApplication::translate("qjackctlSetupForm", "Elapsed time since last &XRUN", nullptr));
#ifndef QT_NO_TOOLTIP
        DisplayFont2TextLabel->setToolTip(QApplication::translate("qjackctlSetupForm", "Sample front panel normal display font", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        DisplayFont1TextLabel->setToolTip(QApplication::translate("qjackctlSetupForm", "Sample big time display font", nullptr));
#endif // QT_NO_TOOLTIP
        DisplayFont1Label->setText(QApplication::translate("qjackctlSetupForm", "Big Time display:", nullptr));
#ifndef QT_NO_TOOLTIP
        DisplayFont2PushButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Select font for front panel normal display", nullptr));
#endif // QT_NO_TOOLTIP
        DisplayFont2PushButton->setText(QApplication::translate("qjackctlSetupForm", "&Font...", nullptr));
#ifndef QT_NO_TOOLTIP
        DisplayFont1PushButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Select font for big time display", nullptr));
#endif // QT_NO_TOOLTIP
        DisplayFont1PushButton->setText(QApplication::translate("qjackctlSetupForm", "&Font...", nullptr));
        DisplayFont2Label->setText(QApplication::translate("qjackctlSetupForm", "Normal display:", nullptr));
#ifndef QT_NO_TOOLTIP
        DisplayBlinkCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to enable blinking (flashing) of the server mode (RT) indicator", nullptr));
#endif // QT_NO_TOOLTIP
        DisplayBlinkCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Blin&k server mode indicator", nullptr));
        DisplayCustomGroupBox->setTitle(QApplication::translate("qjackctlSetupForm", "Custom", nullptr));
        CustomColorThemeTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Color palette theme:", nullptr));
        CustomColorThemeComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "(default)", nullptr));
        CustomColorThemeComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "Wonton Soup", nullptr));
        CustomColorThemeComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "KXStudio", nullptr));

#ifndef QT_NO_TOOLTIP
        CustomColorThemeComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Custom color palette theme", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        CustomColorThemeToolButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Manage custom color palette themes", nullptr));
#endif // QT_NO_TOOLTIP
        CustomColorThemeToolButton->setText(QApplication::translate("qjackctlSetupForm", "...", nullptr));
        CustomStyleThemeTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Widget style theme:", nullptr));
        CustomStyleThemeComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "(default)", nullptr));

#ifndef QT_NO_TOOLTIP
        CustomStyleThemeComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Custom widget style theme", nullptr));
#endif // QT_NO_TOOLTIP
        MessagesWindowGroupBox->setTitle(QApplication::translate("qjackctlSetupForm", "Messages Window", nullptr));
#ifndef QT_NO_TOOLTIP
        MessagesFontTextLabel->setToolTip(QApplication::translate("qjackctlSetupForm", "Sample messages text font display", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        MessagesFontPushButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Select font for the messages text display", nullptr));
#endif // QT_NO_TOOLTIP
        MessagesFontPushButton->setText(QApplication::translate("qjackctlSetupForm", "&Font...", nullptr));
#ifndef QT_NO_TOOLTIP
        MessagesLimitCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to keep a maximum number of lines in the messages window", nullptr));
#endif // QT_NO_TOOLTIP
        MessagesLimitCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Messages limit:", nullptr));
        MessagesLimitLinesComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "100", nullptr));
        MessagesLimitLinesComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "250", nullptr));
        MessagesLimitLinesComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "500", nullptr));
        MessagesLimitLinesComboBox->setItemText(3, QApplication::translate("qjackctlSetupForm", "1000", nullptr));
        MessagesLimitLinesComboBox->setItemText(4, QApplication::translate("qjackctlSetupForm", "2500", nullptr));
        MessagesLimitLinesComboBox->setItemText(5, QApplication::translate("qjackctlSetupForm", "5000", nullptr));

#ifndef QT_NO_TOOLTIP
        MessagesLimitLinesComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "The maximum number of message lines to keep in view", nullptr));
#endif // QT_NO_TOOLTIP
        ConnectionsWindowGroupBox->setTitle(QApplication::translate("qjackctlSetupForm", "Connections Window", nullptr));
#ifndef QT_NO_TOOLTIP
        ConnectionsFontTextLabel->setToolTip(QApplication::translate("qjackctlSetupForm", "Sample connections view font", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        ConnectionsFontPushButton->setToolTip(QApplication::translate("qjackctlSetupForm", "Select font for the connections view", nullptr));
#endif // QT_NO_TOOLTIP
        ConnectionsFontPushButton->setText(QApplication::translate("qjackctlSetupForm", "&Font...", nullptr));
        ConnectionsIconSizeTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Icon size:", nullptr));
        ConnectionsIconSizeComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "16 x 16", nullptr));
        ConnectionsIconSizeComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "32 x 32", nullptr));
        ConnectionsIconSizeComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "64 x 64", nullptr));

#ifndef QT_NO_TOOLTIP
        ConnectionsIconSizeComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "The icon size for each item of the connections view", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        AliasesEnabledCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to enable client/port name aliases on the connections window", nullptr));
#endif // QT_NO_TOOLTIP
        AliasesEnabledCheckBox->setText(QApplication::translate("qjackctlSetupForm", "E&nable client/port aliases", nullptr));
        JackClientPortAliasTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&JACK client/port aliases:", nullptr));
        JackClientPortAliasComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "Default", nullptr));
        JackClientPortAliasComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "First", nullptr));
        JackClientPortAliasComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "Second", nullptr));

#ifndef QT_NO_TOOLTIP
        JackClientPortAliasComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "JACK client/port aliases display mode", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        AliasesEditingCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to enable in-place client/port name editing (rename)", nullptr));
#endif // QT_NO_TOOLTIP
        AliasesEditingCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Ena&ble client/port aliases editing (rename)", nullptr));
#ifndef QT_NO_TOOLTIP
        JackClientPortMetadataCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "JACK client/port pretty-name (metadata) display mode", nullptr));
#endif // QT_NO_TOOLTIP
        JackClientPortMetadataCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Enable JA&CK client/port pretty-names (metadata)", nullptr));
        SetupTabWidget->setTabText(SetupTabWidget->indexOf(DisplayTabPage), QApplication::translate("qjackctlSetupForm", "Display", nullptr));
        OtherGroupBox->setTitle(QApplication::translate("qjackctlSetupForm", "Other", nullptr));
#ifndef QT_NO_TOOLTIP
        StartJackCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to start JACK audio server immediately on application startup", nullptr));
#endif // QT_NO_TOOLTIP
        StartJackCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Start JACK audio server on application startup", nullptr));
#ifndef QT_NO_TOOLTIP
        QueryCloseCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to ask for confirmation on application exit", nullptr));
#endif // QT_NO_TOOLTIP
        QueryCloseCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Confirm application close", nullptr));
#ifndef QT_NO_TOOLTIP
        QueryShutdownCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to ask for confirmation on JACK audio server shutdown and/or restart", nullptr));
#endif // QT_NO_TOOLTIP
        QueryShutdownCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Confirm server sh&utdown and/or restart", nullptr));
#ifndef QT_NO_TOOLTIP
        KeepOnTopCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to keep all child windows on top of the main window", nullptr));
#endif // QT_NO_TOOLTIP
        KeepOnTopCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Keep child windows always on top", nullptr));
#ifndef QT_NO_TOOLTIP
        SystemTrayCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to enable the system tray icon", nullptr));
#endif // QT_NO_TOOLTIP
        SystemTrayCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Enable system tray icon", nullptr));
#ifndef QT_NO_TOOLTIP
        SystemTrayQueryCloseCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to show system tray message on main window close", nullptr));
#endif // QT_NO_TOOLTIP
        SystemTrayQueryCloseCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Sho&w system tray message on close", nullptr));
#ifndef QT_NO_TOOLTIP
        StartMinimizedCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to start minimized to system tray", nullptr));
#endif // QT_NO_TOOLTIP
        StartMinimizedCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Start minimi&zed to system tray", nullptr));
#ifndef QT_NO_TOOLTIP
        ServerConfigCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to save the JACK server command-line configuration into a local file (auto-start)", nullptr));
#endif // QT_NO_TOOLTIP
        ServerConfigCheckBox->setText(QApplication::translate("qjackctlSetupForm", "S&ave JACK audio server configuration to:", nullptr));
        ServerConfigNameComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", ".jackdrc", nullptr));

#ifndef QT_NO_TOOLTIP
        ServerConfigNameComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "The server configuration local file name (auto-start)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        AlsaSeqEnabledCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to enable ALSA Sequencer (MIDI) support on startup", nullptr));
#endif // QT_NO_TOOLTIP
        AlsaSeqEnabledCheckBox->setText(QApplication::translate("qjackctlSetupForm", "E&nable ALSA Sequencer support", nullptr));
#ifndef QT_NO_TOOLTIP
        DBusEnabledCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to enable D-Bus interface", nullptr));
#endif // QT_NO_TOOLTIP
        DBusEnabledCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Enable D-Bus interface", nullptr));
#ifndef QT_NO_TOOLTIP
        JackDBusEnabledCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to enable JACK D-Bus interface", nullptr));
#endif // QT_NO_TOOLTIP
        JackDBusEnabledCheckBox->setText(QApplication::translate("qjackctlSetupForm", "&Enable JACK D-Bus interface", nullptr));
#ifndef QT_NO_TOOLTIP
        StopJackCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to stop JACK audio server on application exit", nullptr));
#endif // QT_NO_TOOLTIP
        StopJackCheckBox->setText(QApplication::translate("qjackctlSetupForm", "S&top JACK audio server on application exit", nullptr));
#ifndef QT_NO_TOOLTIP
        SingletonCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to restrict to one single application instance (X11)", nullptr));
#endif // QT_NO_TOOLTIP
        SingletonCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Single application &instance", nullptr));
        ButtonsGroupBox->setTitle(QApplication::translate("qjackctlSetupForm", "Buttons", nullptr));
#ifndef QT_NO_TOOLTIP
        LeftButtonsCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to hide the left button group on the main window", nullptr));
#endif // QT_NO_TOOLTIP
        LeftButtonsCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Hide main window &Left buttons", nullptr));
#ifndef QT_NO_TOOLTIP
        RightButtonsCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to hide the right button group on the main window", nullptr));
#endif // QT_NO_TOOLTIP
        RightButtonsCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Hide main window &Right buttons", nullptr));
#ifndef QT_NO_TOOLTIP
        TransportButtonsCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to hide the transport button group on the main window", nullptr));
#endif // QT_NO_TOOLTIP
        TransportButtonsCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Hide main window &Transport buttons", nullptr));
#ifndef QT_NO_TOOLTIP
        TextLabelsCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to hide the text labels on the main window buttons", nullptr));
#endif // QT_NO_TOOLTIP
        TextLabelsCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Hide main window &button text labels", nullptr));
#ifndef QT_NO_TOOLTIP
        GraphButtonCheckBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Whether to replace Connections with Graph button on the main window", nullptr));
#endif // QT_NO_TOOLTIP
        GraphButtonCheckBox->setText(QApplication::translate("qjackctlSetupForm", "Replace Connections with &Graph button", nullptr));
        DefaultsGroupBox->setTitle(QApplication::translate("qjackctlSetupForm", "Defaults", nullptr));
        BaseFontSizeTextLabel->setText(QApplication::translate("qjackctlSetupForm", "&Base font size:", nullptr));
        BaseFontSizeComboBox->setItemText(0, QApplication::translate("qjackctlSetupForm", "(default)", nullptr));
        BaseFontSizeComboBox->setItemText(1, QApplication::translate("qjackctlSetupForm", "6", nullptr));
        BaseFontSizeComboBox->setItemText(2, QApplication::translate("qjackctlSetupForm", "7", nullptr));
        BaseFontSizeComboBox->setItemText(3, QApplication::translate("qjackctlSetupForm", "8", nullptr));
        BaseFontSizeComboBox->setItemText(4, QApplication::translate("qjackctlSetupForm", "9", nullptr));
        BaseFontSizeComboBox->setItemText(5, QApplication::translate("qjackctlSetupForm", "10", nullptr));
        BaseFontSizeComboBox->setItemText(6, QApplication::translate("qjackctlSetupForm", "11", nullptr));
        BaseFontSizeComboBox->setItemText(7, QApplication::translate("qjackctlSetupForm", "12", nullptr));

#ifndef QT_NO_TOOLTIP
        BaseFontSizeComboBox->setToolTip(QApplication::translate("qjackctlSetupForm", "Base application font size (pt.)", nullptr));
#endif // QT_NO_TOOLTIP
        SetupTabWidget->setTabText(SetupTabWidget->indexOf(MiscTabPage), QApplication::translate("qjackctlSetupForm", "Misc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qjackctlSetupForm: public Ui_qjackctlSetupForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QJACKCTLSETUPFORM_H
