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
** Form generated from reading UI file 'qjackctlGraphForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QJACKCTLGRAPHFORM_H
#define UI_QJACKCTLGRAPHFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qjackctlGraph.h"

QT_BEGIN_NAMESPACE

class Ui_qjackctlGraphForm
{
public:
    QAction *graphConnectAction;
    QAction *graphDisconnectAction;
    QAction *graphCloseAction;
    QAction *editSelectAllAction;
    QAction *editSelectNoneAction;
    QAction *editSelectInvertAction;
    QAction *editRenameItemAction;
    QAction *viewMenubarAction;
    QAction *viewToolbarAction;
    QAction *viewStatusbarAction;
    QAction *viewTextBesideIconsAction;
    QAction *viewCenterAction;
    QAction *viewRefreshAction;
    QAction *viewZoomInAction;
    QAction *viewZoomOutAction;
    QAction *viewZoomFitAction;
    QAction *viewZoomResetAction;
    QAction *viewZoomRangeAction;
    QAction *viewColorsJackAudioAction;
    QAction *viewColorsJackMidiAction;
    QAction *viewColorsAlsaMidiAction;
    QAction *viewColorsResetAction;
    QAction *viewSortPortNameAction;
    QAction *viewSortPortTitleAction;
    QAction *viewSortPortIndexAction;
    QAction *viewSortAscendingAction;
    QAction *viewSortDescendingAction;
    QAction *helpAboutAction;
    QAction *helpAboutQtAction;
    QWidget *MainCentralWidget;
    QVBoxLayout *vboxLayout;
    qjackctlGraphCanvas *graphCanvas;
    QStatusBar *StatusBar;
    QMenuBar *MenuBar;
    QMenu *graphMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *viewZoomMenu;
    QMenu *viewColorsMenu;
    QMenu *viewSortMenu;
    QMenu *helpMenu;
    QToolBar *ToolBar;

    void setupUi(QMainWindow *qjackctlGraphForm)
    {
        if (qjackctlGraphForm->objectName().isEmpty())
            qjackctlGraphForm->setObjectName(QString::fromUtf8("qjackctlGraphForm"));
        qjackctlGraphForm->resize(800, 600);
        const QIcon icon = QIcon(QString::fromUtf8(":/images/graph1.png"));
        qjackctlGraphForm->setWindowIcon(icon);
        graphConnectAction = new QAction(qjackctlGraphForm);
        graphConnectAction->setObjectName(QString::fromUtf8("graphConnectAction"));
        const QIcon icon1 = QIcon(QString::fromUtf8(":/images/graphConnect.png"));
        graphConnectAction->setIcon(icon1);
        graphDisconnectAction = new QAction(qjackctlGraphForm);
        graphDisconnectAction->setObjectName(QString::fromUtf8("graphDisconnectAction"));
        const QIcon icon2 = QIcon(QString::fromUtf8(":/images/graphDisconnect.png"));
        graphDisconnectAction->setIcon(icon2);
        graphCloseAction = new QAction(qjackctlGraphForm);
        graphCloseAction->setObjectName(QString::fromUtf8("graphCloseAction"));
        editSelectAllAction = new QAction(qjackctlGraphForm);
        editSelectAllAction->setObjectName(QString::fromUtf8("editSelectAllAction"));
        editSelectNoneAction = new QAction(qjackctlGraphForm);
        editSelectNoneAction->setObjectName(QString::fromUtf8("editSelectNoneAction"));
        editSelectInvertAction = new QAction(qjackctlGraphForm);
        editSelectInvertAction->setObjectName(QString::fromUtf8("editSelectInvertAction"));
        editRenameItemAction = new QAction(qjackctlGraphForm);
        editRenameItemAction->setObjectName(QString::fromUtf8("editRenameItemAction"));
        const QIcon icon3 = QIcon(QString::fromUtf8(":/images/graphRename.png"));
        editRenameItemAction->setIcon(icon3);
        viewMenubarAction = new QAction(qjackctlGraphForm);
        viewMenubarAction->setObjectName(QString::fromUtf8("viewMenubarAction"));
        viewMenubarAction->setCheckable(true);
        viewToolbarAction = new QAction(qjackctlGraphForm);
        viewToolbarAction->setObjectName(QString::fromUtf8("viewToolbarAction"));
        viewToolbarAction->setCheckable(true);
        viewStatusbarAction = new QAction(qjackctlGraphForm);
        viewStatusbarAction->setObjectName(QString::fromUtf8("viewStatusbarAction"));
        viewStatusbarAction->setCheckable(true);
        viewTextBesideIconsAction = new QAction(qjackctlGraphForm);
        viewTextBesideIconsAction->setObjectName(QString::fromUtf8("viewTextBesideIconsAction"));
        viewTextBesideIconsAction->setCheckable(true);
        viewCenterAction = new QAction(qjackctlGraphForm);
        viewCenterAction->setObjectName(QString::fromUtf8("viewCenterAction"));
        const QIcon icon4 = QIcon(QString::fromUtf8(":/images/graphCenter.png"));
        viewCenterAction->setIcon(icon4);
        viewRefreshAction = new QAction(qjackctlGraphForm);
        viewRefreshAction->setObjectName(QString::fromUtf8("viewRefreshAction"));
        viewZoomInAction = new QAction(qjackctlGraphForm);
        viewZoomInAction->setObjectName(QString::fromUtf8("viewZoomInAction"));
        const QIcon icon5 = QIcon(QString::fromUtf8(":/images/graphZoomIn.png"));
        viewZoomInAction->setIcon(icon5);
        viewZoomOutAction = new QAction(qjackctlGraphForm);
        viewZoomOutAction->setObjectName(QString::fromUtf8("viewZoomOutAction"));
        const QIcon icon6 = QIcon(QString::fromUtf8(":/images/graphZoomOut.png"));
        viewZoomOutAction->setIcon(icon6);
        viewZoomFitAction = new QAction(qjackctlGraphForm);
        viewZoomFitAction->setObjectName(QString::fromUtf8("viewZoomFitAction"));
        const QIcon icon7 = QIcon(QString::fromUtf8(":/images/graphZoomFit.png"));
        viewZoomFitAction->setIcon(icon7);
        viewZoomResetAction = new QAction(qjackctlGraphForm);
        viewZoomResetAction->setObjectName(QString::fromUtf8("viewZoomResetAction"));
        const QIcon icon8 = QIcon(QString::fromUtf8(":/images/graphZoomReset.png"));
        viewZoomResetAction->setIcon(icon8);
        viewZoomRangeAction = new QAction(qjackctlGraphForm);
        viewZoomRangeAction->setObjectName(QString::fromUtf8("viewZoomRangeAction"));
        viewZoomRangeAction->setCheckable(true);
        const QIcon icon9 = QIcon(QString::fromUtf8(":/images/graphZoomRange.png"));
        viewZoomRangeAction->setIcon(icon9);
        viewColorsJackAudioAction = new QAction(qjackctlGraphForm);
        viewColorsJackAudioAction->setObjectName(QString::fromUtf8("viewColorsJackAudioAction"));
        viewColorsJackMidiAction = new QAction(qjackctlGraphForm);
        viewColorsJackMidiAction->setObjectName(QString::fromUtf8("viewColorsJackMidiAction"));
        viewColorsAlsaMidiAction = new QAction(qjackctlGraphForm);
        viewColorsAlsaMidiAction->setObjectName(QString::fromUtf8("viewColorsAlsaMidiAction"));
        viewColorsResetAction = new QAction(qjackctlGraphForm);
        viewColorsResetAction->setObjectName(QString::fromUtf8("viewColorsResetAction"));
        viewSortPortNameAction = new QAction(qjackctlGraphForm);
        viewSortPortNameAction->setObjectName(QString::fromUtf8("viewSortPortNameAction"));
        viewSortPortNameAction->setCheckable(true);
        viewSortPortTitleAction = new QAction(qjackctlGraphForm);
        viewSortPortTitleAction->setObjectName(QString::fromUtf8("viewSortPortTitleAction"));
        viewSortPortTitleAction->setCheckable(true);
        viewSortPortIndexAction = new QAction(qjackctlGraphForm);
        viewSortPortIndexAction->setObjectName(QString::fromUtf8("viewSortPortIndexAction"));
        viewSortPortIndexAction->setCheckable(true);
        viewSortAscendingAction = new QAction(qjackctlGraphForm);
        viewSortAscendingAction->setObjectName(QString::fromUtf8("viewSortAscendingAction"));
        viewSortAscendingAction->setCheckable(true);
        viewSortDescendingAction = new QAction(qjackctlGraphForm);
        viewSortDescendingAction->setObjectName(QString::fromUtf8("viewSortDescendingAction"));
        viewSortDescendingAction->setCheckable(true);
        helpAboutAction = new QAction(qjackctlGraphForm);
        helpAboutAction->setObjectName(QString::fromUtf8("helpAboutAction"));
        helpAboutQtAction = new QAction(qjackctlGraphForm);
        helpAboutQtAction->setObjectName(QString::fromUtf8("helpAboutQtAction"));
        MainCentralWidget = new QWidget(qjackctlGraphForm);
        MainCentralWidget->setObjectName(QString::fromUtf8("MainCentralWidget"));
        vboxLayout = new QVBoxLayout(MainCentralWidget);
        vboxLayout->setSpacing(0);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        graphCanvas = new qjackctlGraphCanvas(MainCentralWidget);
        graphCanvas->setObjectName(QString::fromUtf8("graphCanvas"));

        vboxLayout->addWidget(graphCanvas);

        qjackctlGraphForm->setCentralWidget(MainCentralWidget);
        StatusBar = new QStatusBar(qjackctlGraphForm);
        StatusBar->setObjectName(QString::fromUtf8("StatusBar"));
        qjackctlGraphForm->setStatusBar(StatusBar);
        MenuBar = new QMenuBar(qjackctlGraphForm);
        MenuBar->setObjectName(QString::fromUtf8("MenuBar"));
        MenuBar->setGeometry(QRect(0, 0, 800, 20));
        graphMenu = new QMenu(MenuBar);
        graphMenu->setObjectName(QString::fromUtf8("graphMenu"));
        editMenu = new QMenu(MenuBar);
        editMenu->setObjectName(QString::fromUtf8("editMenu"));
        viewMenu = new QMenu(MenuBar);
        viewMenu->setObjectName(QString::fromUtf8("viewMenu"));
        viewZoomMenu = new QMenu(viewMenu);
        viewZoomMenu->setObjectName(QString::fromUtf8("viewZoomMenu"));
        const QIcon icon10 = QIcon(QString::fromUtf8(":/images/graphZoomTool.png"));
        viewZoomMenu->setIcon(icon10);
        viewColorsMenu = new QMenu(viewMenu);
        viewColorsMenu->setObjectName(QString::fromUtf8("viewColorsMenu"));
        const QIcon icon11 = QIcon(QString::fromUtf8(":/images/graphColors.png"));
        viewColorsMenu->setIcon(icon11);
        viewSortMenu = new QMenu(viewMenu);
        viewSortMenu->setObjectName(QString::fromUtf8("viewSortMenu"));
        helpMenu = new QMenu(MenuBar);
        helpMenu->setObjectName(QString::fromUtf8("helpMenu"));
        qjackctlGraphForm->setMenuBar(MenuBar);
        ToolBar = new QToolBar(qjackctlGraphForm);
        ToolBar->setObjectName(QString::fromUtf8("ToolBar"));
        ToolBar->setAllowedAreas(Qt::AllToolBarAreas);
        ToolBar->setOrientation(Qt::Horizontal);
        ToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ToolBar->setFloatable(true);
        qjackctlGraphForm->addToolBar(Qt::TopToolBarArea, ToolBar);

        MenuBar->addAction(graphMenu->menuAction());
        MenuBar->addAction(editMenu->menuAction());
        MenuBar->addAction(viewMenu->menuAction());
        MenuBar->addSeparator();
        MenuBar->addAction(helpMenu->menuAction());
        graphMenu->addAction(graphConnectAction);
        graphMenu->addAction(graphDisconnectAction);
        graphMenu->addSeparator();
        graphMenu->addAction(graphCloseAction);
        editMenu->addAction(editSelectAllAction);
        editMenu->addAction(editSelectNoneAction);
        editMenu->addAction(editSelectInvertAction);
        editMenu->addSeparator();
        editMenu->addAction(editRenameItemAction);
        viewMenu->addAction(viewMenubarAction);
        viewMenu->addAction(viewStatusbarAction);
        viewMenu->addAction(viewToolbarAction);
        viewMenu->addSeparator();
        viewMenu->addAction(viewTextBesideIconsAction);
        viewMenu->addAction(viewColorsMenu->menuAction());
        viewMenu->addAction(viewSortMenu->menuAction());
        viewMenu->addSeparator();
        viewMenu->addAction(viewCenterAction);
        viewMenu->addAction(viewZoomMenu->menuAction());
        viewMenu->addAction(viewZoomRangeAction);
        viewMenu->addSeparator();
        viewMenu->addAction(viewRefreshAction);
        viewZoomMenu->addAction(viewZoomInAction);
        viewZoomMenu->addAction(viewZoomOutAction);
        viewZoomMenu->addSeparator();
        viewZoomMenu->addAction(viewZoomFitAction);
        viewZoomMenu->addAction(viewZoomResetAction);
        viewColorsMenu->addAction(viewColorsJackAudioAction);
        viewColorsMenu->addAction(viewColorsJackMidiAction);
        viewColorsMenu->addAction(viewColorsAlsaMidiAction);
        viewColorsMenu->addSeparator();
        viewColorsMenu->addAction(viewColorsResetAction);
        viewSortMenu->addAction(viewSortPortNameAction);
        viewSortMenu->addAction(viewSortPortTitleAction);
        viewSortMenu->addAction(viewSortPortIndexAction);
        viewSortMenu->addSeparator();
        viewSortMenu->addAction(viewSortAscendingAction);
        viewSortMenu->addAction(viewSortDescendingAction);
        helpMenu->addAction(helpAboutAction);
        helpMenu->addAction(helpAboutQtAction);
        ToolBar->addAction(graphConnectAction);
        ToolBar->addAction(graphDisconnectAction);
        ToolBar->addSeparator();
        ToolBar->addAction(viewCenterAction);
        ToolBar->addSeparator();
        ToolBar->addAction(viewZoomInAction);
        ToolBar->addAction(viewZoomOutAction);
        ToolBar->addSeparator();
        ToolBar->addAction(viewZoomFitAction);
        ToolBar->addAction(viewZoomResetAction);
        ToolBar->addSeparator();
        ToolBar->addAction(viewZoomRangeAction);

        retranslateUi(qjackctlGraphForm);

        QMetaObject::connectSlotsByName(qjackctlGraphForm);
    } // setupUi

    void retranslateUi(QMainWindow *qjackctlGraphForm)
    {
        qjackctlGraphForm->setWindowTitle(QApplication::translate("qjackctlGraphForm", "Graph", nullptr));
        graphConnectAction->setText(QApplication::translate("qjackctlGraphForm", "&Connect", nullptr));
        graphConnectAction->setIconText(QApplication::translate("qjackctlGraphForm", "Connect", nullptr));
#ifndef QT_NO_TOOLTIP
        graphConnectAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Connect", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        graphConnectAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Connect selected ports", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        graphConnectAction->setShortcut(QApplication::translate("qjackctlGraphForm", "Ins", nullptr));
#endif // QT_NO_SHORTCUT
        graphDisconnectAction->setText(QApplication::translate("qjackctlGraphForm", "&Disconnect", nullptr));
        graphDisconnectAction->setIconText(QApplication::translate("qjackctlGraphForm", "Disconnect", nullptr));
#ifndef QT_NO_TOOLTIP
        graphDisconnectAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Disconnect", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        graphDisconnectAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Disconnect selected ports", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        graphDisconnectAction->setShortcut(QApplication::translate("qjackctlGraphForm", "Del", nullptr));
#endif // QT_NO_SHORTCUT
        graphCloseAction->setText(QApplication::translate("qjackctlGraphForm", "Cl&ose", nullptr));
        graphCloseAction->setIconText(QApplication::translate("qjackctlGraphForm", "Close", nullptr));
#ifndef QT_NO_TOOLTIP
        graphCloseAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Close", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        graphCloseAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Close this application window", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        graphCloseAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        editSelectAllAction->setText(QApplication::translate("qjackctlGraphForm", "Select &All", nullptr));
        editSelectAllAction->setIconText(QApplication::translate("qjackctlGraphForm", "Select All", nullptr));
#ifndef QT_NO_TOOLTIP
        editSelectAllAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Select All", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        editSelectAllAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Select All", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        editSelectAllAction->setShortcut(QApplication::translate("qjackctlGraphForm", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        editSelectNoneAction->setText(QApplication::translate("qjackctlGraphForm", "Select &None", nullptr));
        editSelectNoneAction->setIconText(QApplication::translate("qjackctlGraphForm", "Select None", nullptr));
#ifndef QT_NO_TOOLTIP
        editSelectNoneAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Select None", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        editSelectNoneAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Select None", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        editSelectNoneAction->setShortcut(QApplication::translate("qjackctlGraphForm", "Ctrl+Shift+A", nullptr));
#endif // QT_NO_SHORTCUT
        editSelectInvertAction->setText(QApplication::translate("qjackctlGraphForm", "Select &Invert", nullptr));
        editSelectInvertAction->setIconText(QApplication::translate("qjackctlGraphForm", "Select Invert", nullptr));
#ifndef QT_NO_TOOLTIP
        editSelectInvertAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Select Invert", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        editSelectInvertAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Select Invert", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        editSelectInvertAction->setShortcut(QApplication::translate("qjackctlGraphForm", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        editRenameItemAction->setText(QApplication::translate("qjackctlGraphForm", "&Rename...", nullptr));
        editRenameItemAction->setIconText(QApplication::translate("qjackctlGraphForm", "Rename item", nullptr));
#ifndef QT_NO_TOOLTIP
        editRenameItemAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Rename Item", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        editRenameItemAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Rename Item", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        editRenameItemAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        viewMenubarAction->setText(QApplication::translate("qjackctlGraphForm", "&Menubar", nullptr));
        viewMenubarAction->setIconText(QApplication::translate("qjackctlGraphForm", "Menubar", nullptr));
#ifndef QT_NO_TOOLTIP
        viewMenubarAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Menubar", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewMenubarAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Show/hide the main program window menubar", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewMenubarAction->setShortcut(QApplication::translate("qjackctlGraphForm", "Ctrl+M", nullptr));
#endif // QT_NO_SHORTCUT
        viewToolbarAction->setText(QApplication::translate("qjackctlGraphForm", "&Toolbar", nullptr));
        viewToolbarAction->setIconText(QApplication::translate("qjackctlGraphForm", "Toolbar", nullptr));
#ifndef QT_NO_TOOLTIP
        viewToolbarAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Toolbar", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewToolbarAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Show/hide main program window file toolbar", nullptr));
#endif // QT_NO_STATUSTIP
        viewStatusbarAction->setText(QApplication::translate("qjackctlGraphForm", "&Statusbar", nullptr));
        viewStatusbarAction->setIconText(QApplication::translate("qjackctlGraphForm", "Statusbar", nullptr));
#ifndef QT_NO_TOOLTIP
        viewStatusbarAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Statusbar", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewStatusbarAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Show/hide the main program window statusbar", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewStatusbarAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        viewTextBesideIconsAction->setText(QApplication::translate("qjackctlGraphForm", "Text Beside &Icons", nullptr));
        viewTextBesideIconsAction->setIconText(QApplication::translate("qjackctlGraphForm", "Text beside icons", nullptr));
#ifndef QT_NO_TOOLTIP
        viewTextBesideIconsAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Text beside icons", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewTextBesideIconsAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Show/hide text beside icons", nullptr));
#endif // QT_NO_STATUSTIP
        viewCenterAction->setText(QApplication::translate("qjackctlGraphForm", "&Center", nullptr));
        viewCenterAction->setIconText(QApplication::translate("qjackctlGraphForm", "Center", nullptr));
#ifndef QT_NO_TOOLTIP
        viewCenterAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Center", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewCenterAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Center view", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewCenterAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        viewRefreshAction->setText(QApplication::translate("qjackctlGraphForm", "&Refresh", nullptr));
        viewRefreshAction->setIconText(QApplication::translate("qjackctlGraphForm", "Refresh", nullptr));
#ifndef QT_NO_TOOLTIP
        viewRefreshAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Refresh", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewRefreshAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Refresh view", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewRefreshAction->setShortcut(QApplication::translate("qjackctlGraphForm", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        viewZoomInAction->setText(QApplication::translate("qjackctlGraphForm", "Zoom &In", nullptr));
        viewZoomInAction->setIconText(QApplication::translate("qjackctlGraphForm", "Zoom In", nullptr));
#ifndef QT_NO_TOOLTIP
        viewZoomInAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Zoom In", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewZoomInAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Zoom In", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewZoomInAction->setShortcut(QApplication::translate("qjackctlGraphForm", "Ctrl++", nullptr));
#endif // QT_NO_SHORTCUT
        viewZoomOutAction->setText(QApplication::translate("qjackctlGraphForm", "Zoom &Out", nullptr));
        viewZoomOutAction->setIconText(QApplication::translate("qjackctlGraphForm", "Zoom Out", nullptr));
#ifndef QT_NO_TOOLTIP
        viewZoomOutAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Zoom Out", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewZoomOutAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Zoom Out", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewZoomOutAction->setShortcut(QApplication::translate("qjackctlGraphForm", "Ctrl+-", nullptr));
#endif // QT_NO_SHORTCUT
        viewZoomFitAction->setText(QApplication::translate("qjackctlGraphForm", "Zoom &Fit", nullptr));
        viewZoomFitAction->setIconText(QApplication::translate("qjackctlGraphForm", "Zoom Fit", nullptr));
#ifndef QT_NO_TOOLTIP
        viewZoomFitAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Zoom Fit", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewZoomFitAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Zoom Fit", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewZoomFitAction->setShortcut(QApplication::translate("qjackctlGraphForm", "Ctrl+0", nullptr));
#endif // QT_NO_SHORTCUT
        viewZoomResetAction->setText(QApplication::translate("qjackctlGraphForm", "Zoom &Reset", nullptr));
        viewZoomResetAction->setIconText(QApplication::translate("qjackctlGraphForm", "Zoom Reset", nullptr));
#ifndef QT_NO_TOOLTIP
        viewZoomResetAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Zoom Reset", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewZoomResetAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Zoom Reset", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewZoomResetAction->setShortcut(QApplication::translate("qjackctlGraphForm", "Ctrl+1", nullptr));
#endif // QT_NO_SHORTCUT
        viewZoomRangeAction->setText(QApplication::translate("qjackctlGraphForm", "&Zoom Range", nullptr));
        viewZoomRangeAction->setIconText(QApplication::translate("qjackctlGraphForm", "Zoom Range", nullptr));
#ifndef QT_NO_TOOLTIP
        viewZoomRangeAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Zoom Range", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewZoomRangeAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Zoom Range", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewZoomRangeAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        viewColorsJackAudioAction->setText(QApplication::translate("qjackctlGraphForm", "JACK &Audio...", nullptr));
        viewColorsJackAudioAction->setIconText(QApplication::translate("qjackctlGraphForm", "JACK Audio color", nullptr));
#ifndef QT_NO_TOOLTIP
        viewColorsJackAudioAction->setToolTip(QApplication::translate("qjackctlGraphForm", "JACK Audio color", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewColorsJackAudioAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "JACK Audio color", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewColorsJackAudioAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        viewColorsJackMidiAction->setText(QApplication::translate("qjackctlGraphForm", "JACK &MIDI...", nullptr));
        viewColorsJackMidiAction->setIconText(QApplication::translate("qjackctlGraphForm", "JACK MIDI", nullptr));
#ifndef QT_NO_TOOLTIP
        viewColorsJackMidiAction->setToolTip(QApplication::translate("qjackctlGraphForm", "JACK MIDI color", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewColorsJackMidiAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "JACK MIDI color", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewColorsJackMidiAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        viewColorsAlsaMidiAction->setText(QApplication::translate("qjackctlGraphForm", "&ALSA MIDI...", nullptr));
        viewColorsAlsaMidiAction->setIconText(QApplication::translate("qjackctlGraphForm", "ALSA MIDI", nullptr));
#ifndef QT_NO_TOOLTIP
        viewColorsAlsaMidiAction->setToolTip(QApplication::translate("qjackctlGraphForm", "ALSA MIDI color", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewColorsAlsaMidiAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "ALSA MIDI color", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewColorsAlsaMidiAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        viewColorsResetAction->setText(QApplication::translate("qjackctlGraphForm", "&Reset", nullptr));
        viewColorsResetAction->setIconText(QApplication::translate("qjackctlGraphForm", "Reset colors", nullptr));
#ifndef QT_NO_TOOLTIP
        viewColorsResetAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Reset colors", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewColorsResetAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Reset colors", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewColorsResetAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        viewSortPortNameAction->setText(QApplication::translate("qjackctlGraphForm", "Port &Name", nullptr));
#ifndef QT_NO_TOOLTIP
        viewSortPortNameAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Port name", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewSortPortNameAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Sort by port name", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewSortPortNameAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        viewSortPortTitleAction->setText(QApplication::translate("qjackctlGraphForm", "Port &Title", nullptr));
#ifndef QT_NO_TOOLTIP
        viewSortPortTitleAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Port title", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewSortPortTitleAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Sort by port title", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewSortPortTitleAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        viewSortPortIndexAction->setText(QApplication::translate("qjackctlGraphForm", "Port &Index", nullptr));
#ifndef QT_NO_TOOLTIP
        viewSortPortIndexAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Port index", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewSortPortIndexAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Sort by port index", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewSortPortIndexAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        viewSortAscendingAction->setText(QApplication::translate("qjackctlGraphForm", "&Ascending", nullptr));
#ifndef QT_NO_TOOLTIP
        viewSortAscendingAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Ascending", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewSortAscendingAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Ascending sort order", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewSortAscendingAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        viewSortDescendingAction->setText(QApplication::translate("qjackctlGraphForm", "&Descending", nullptr));
#ifndef QT_NO_TOOLTIP
        viewSortDescendingAction->setToolTip(QApplication::translate("qjackctlGraphForm", "Descending", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        viewSortDescendingAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Descending sort order", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        viewSortDescendingAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        helpAboutAction->setText(QApplication::translate("qjackctlGraphForm", "&About...", nullptr));
        helpAboutAction->setIconText(QApplication::translate("qjackctlGraphForm", "About...", nullptr));
#ifndef QT_NO_TOOLTIP
        helpAboutAction->setToolTip(QApplication::translate("qjackctlGraphForm", "About", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        helpAboutAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Show information about this application program", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        helpAboutAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        helpAboutQtAction->setText(QApplication::translate("qjackctlGraphForm", "About &Qt...", nullptr));
        helpAboutQtAction->setIconText(QApplication::translate("qjackctlGraphForm", "About Qt...", nullptr));
#ifndef QT_NO_TOOLTIP
        helpAboutQtAction->setToolTip(QApplication::translate("qjackctlGraphForm", "About Qt", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        helpAboutQtAction->setStatusTip(QApplication::translate("qjackctlGraphForm", "Show information about the Qt toolkit", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        helpAboutQtAction->setShortcut(QString());
#endif // QT_NO_SHORTCUT
        graphMenu->setTitle(QApplication::translate("qjackctlGraphForm", "&Graph", nullptr));
        editMenu->setTitle(QApplication::translate("qjackctlGraphForm", "&Edit", nullptr));
        viewMenu->setTitle(QApplication::translate("qjackctlGraphForm", "&View", nullptr));
        viewZoomMenu->setTitle(QApplication::translate("qjackctlGraphForm", "&Zoom", nullptr));
        viewColorsMenu->setTitle(QApplication::translate("qjackctlGraphForm", "Co&lors", nullptr));
        viewSortMenu->setTitle(QApplication::translate("qjackctlGraphForm", "S&ort", nullptr));
        helpMenu->setTitle(QApplication::translate("qjackctlGraphForm", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qjackctlGraphForm: public Ui_qjackctlGraphForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QJACKCTLGRAPHFORM_H
