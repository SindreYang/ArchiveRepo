/********************************************************************************
** Form generated from reading UI file 'setup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_H
#define UI_SETUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setui
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QWidget *Parameter_widget;
    QLabel *label_7;
    QWidget *verticalLayoutWidget_3;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_db;
    QLabel *label_6;
    QLineEdit *lineEdit_red;
    QLabel *label_8;
    QLineEdit *lineEdit_times;
    QLineEdit *lineEdit_yellow;
    QLabel *label_9;
    QLabel *label_17;
    QLineEdit *lineEdit_low_lv;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_18;
    QLabel *label_21;
    QLineEdit *lineEdit_logo;
    QPushButton *openfile;
    QWidget *Password_widget_2;
    QLabel *label_16;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QWidget *Password_widget;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_changep;
    QLineEdit *lineEdit_initp;
    QLabel *label_4;
    QLineEdit *lineEdit_confirmp;
    QWidget *page_2;
    QListWidget *listWidget_pc;
    QTableWidget *tableWidget_lr;
    QLabel *label_14;
    QLabel *label_15;
    QComboBox *comboBox_inputp;
    QComboBox *comboBox_outp;
    QListWidget *listWidget_pc_2;
    QListWidget *listWidget_now;
    QLabel *label_20;
    QLabel *label_22;
    QLabel *label_23;
    QWidget *page_3;
    QListWidget *listWidget_lc;
    QListWidget *listWidget_tl2;
    QListWidget *listWidget_tl1;
    QLabel *label_tl2;
    QLabel *label_tl1;
    QLabel *label_19;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_apply;

    void setupUi(QWidget *setui)
    {
        if (setui->objectName().isEmpty())
            setui->setObjectName(QString::fromUtf8("setui"));
        setui->resize(1320, 860);
        setui->setStyleSheet(QString::fromUtf8("\n"
"\n"
".QPushButton{\n"
" \n"
"   border-radius: 6px;\n"
"  background-color: #404040;\n"
"	border: 2px outset black;\n"
"	color:white;\n"
"}\n"
".QPushButton:checked{\n"
" \n"
"   border-radius: 6px;\n"
"  background-color: #00B0F0;\n"
"	border: 2px outset black;\n"
"	color:white;\n"
"}\n"
"#setui{\n"
"background: #404040;\n"
"}\n"
"\n"
"QLineEdit{\n"
"\n"
"border: 3px outset black;\n"
"border-radius:3px;\n"
"}"));
        stackedWidget = new QStackedWidget(setui);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(30, 60, 1261, 751));
        stackedWidget->setStyleSheet(QString::fromUtf8("\n"
"background: #404040;\n"
""));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        Parameter_widget = new QWidget(page_1);
        Parameter_widget->setObjectName(QString::fromUtf8("Parameter_widget"));
        Parameter_widget->setGeometry(QRect(240, 290, 371, 321));
        Parameter_widget->setStyleSheet(QString::fromUtf8("QWidget#Parameter_widget{\n"
" 		border: 3px outset black;\n"
"\n"
"}"));
        label_7 = new QLabel(Parameter_widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(150, 10, 67, 31));
        label_7->setStyleSheet(QString::fromUtf8("color:#B6B6B6"));
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(false);
        verticalLayoutWidget_3 = new QWidget(Parameter_widget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 40, 351, 261));
        gridLayout_2 = new QGridLayout(verticalLayoutWidget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color:white;"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        lineEdit_db = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_db->setObjectName(QString::fromUtf8("lineEdit_db"));
        lineEdit_db->setStyleSheet(QString::fromUtf8("background:white;"));
        lineEdit_db->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_db, 3, 1, 1, 1);

        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color:white;"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        lineEdit_red = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_red->setObjectName(QString::fromUtf8("lineEdit_red"));
        lineEdit_red->setStyleSheet(QString::fromUtf8("background:white;"));
        lineEdit_red->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_red, 1, 1, 1, 1);

        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("color:white;"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        lineEdit_times = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_times->setObjectName(QString::fromUtf8("lineEdit_times"));
        lineEdit_times->setStyleSheet(QString::fromUtf8("background:white;"));
        lineEdit_times->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_times, 4, 1, 1, 1);

        lineEdit_yellow = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_yellow->setObjectName(QString::fromUtf8("lineEdit_yellow"));
        lineEdit_yellow->setStyleSheet(QString::fromUtf8("background:white;"));
        lineEdit_yellow->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_yellow, 0, 1, 1, 1);

        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("color:white;"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_9, 3, 0, 1, 1);

        label_17 = new QLabel(verticalLayoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("color:#B6B6B6;"));

        gridLayout_2->addWidget(label_17, 4, 2, 1, 1);

        lineEdit_low_lv = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_low_lv->setObjectName(QString::fromUtf8("lineEdit_low_lv"));
        lineEdit_low_lv->setStyleSheet(QString::fromUtf8("background:white;"));
        lineEdit_low_lv->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lineEdit_low_lv, 2, 1, 1, 1);

        label_13 = new QLabel(verticalLayoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("color:#B6B6B6;"));

        gridLayout_2->addWidget(label_13, 3, 2, 1, 1);

        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("color:#B6B6B6;"));

        gridLayout_2->addWidget(label_12, 2, 2, 1, 1);

        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("color:#B6B6B6;"));

        gridLayout_2->addWidget(label_10, 0, 2, 1, 1);

        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("color:#B6B6B6;"));

        gridLayout_2->addWidget(label_11, 1, 2, 1, 1);

        label_18 = new QLabel(verticalLayoutWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("color:white;"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_18, 4, 0, 1, 1);

        label_21 = new QLabel(verticalLayoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("color:white;"));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_21, 5, 0, 1, 1);

        lineEdit_logo = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_logo->setObjectName(QString::fromUtf8("lineEdit_logo"));
        lineEdit_logo->setStyleSheet(QString::fromUtf8("background:white;"));
        lineEdit_logo->setDragEnabled(true);

        gridLayout_2->addWidget(lineEdit_logo, 5, 1, 1, 1);

        openfile = new QPushButton(verticalLayoutWidget_3);
        openfile->setObjectName(QString::fromUtf8("openfile"));
        openfile->setStyleSheet(QString::fromUtf8("border:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add1.png"), QSize(), QIcon::Normal, QIcon::Off);
        openfile->setIcon(icon);

        gridLayout_2->addWidget(openfile, 5, 2, 1, 1);

        Password_widget_2 = new QWidget(page_1);
        Password_widget_2->setObjectName(QString::fromUtf8("Password_widget_2"));
        Password_widget_2->setGeometry(QRect(680, 60, 351, 551));
        Password_widget_2->setStyleSheet(QString::fromUtf8("QWidget#Password_widget_2{\n"
" 		border: 3px outset black;\n"
"\n"
"}\n"
"\n"
""));
        label_16 = new QLabel(Password_widget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(120, 10, 71, 31));
        label_16->setStyleSheet(QString::fromUtf8("color:#B6B6B6"));
        label_16->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_2 = new QWidget(Password_widget_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(50, 40, 271, 491));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_1 = new QCheckBox(verticalLayoutWidget_2);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setStyleSheet(QString::fromUtf8("color:white;"));
        checkBox_1->setCheckable(true);
        checkBox_1->setChecked(false);
        checkBox_1->setAutoRepeat(false);
        checkBox_1->setAutoExclusive(false);
        checkBox_1->setTristate(false);

        verticalLayout->addWidget(checkBox_1);

        checkBox_2 = new QCheckBox(verticalLayoutWidget_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setStyleSheet(QString::fromUtf8("color:white;"));

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(verticalLayoutWidget_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setStyleSheet(QString::fromUtf8("color:white;"));

        verticalLayout->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(verticalLayoutWidget_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setStyleSheet(QString::fromUtf8("color:white;"));

        verticalLayout->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(verticalLayoutWidget_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setStyleSheet(QString::fromUtf8("color:white;"));

        verticalLayout->addWidget(checkBox_5);

        checkBox_6 = new QCheckBox(verticalLayoutWidget_2);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setStyleSheet(QString::fromUtf8("color:white;"));
        checkBox_6->setChecked(false);

        verticalLayout->addWidget(checkBox_6);

        Password_widget = new QWidget(page_1);
        Password_widget->setObjectName(QString::fromUtf8("Password_widget"));
        Password_widget->setGeometry(QRect(240, 60, 371, 211));
        Password_widget->setStyleSheet(QString::fromUtf8("QWidget#Password_widget{\n"
" 		border: 3px outset black;\n"
"\n"
"}"));
        label = new QLabel(Password_widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 6, 71, 20));
        label->setStyleSheet(QString::fromUtf8("color:#B6B6B6"));
        label->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(Password_widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 351, 171));
        gridLayout = new QGridLayout(verticalLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color:white;"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color:white;"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_changep = new QLineEdit(verticalLayoutWidget);
        lineEdit_changep->setObjectName(QString::fromUtf8("lineEdit_changep"));
        lineEdit_changep->setStyleSheet(QString::fromUtf8("background:white;"));

        gridLayout->addWidget(lineEdit_changep, 1, 1, 1, 1);

        lineEdit_initp = new QLineEdit(verticalLayoutWidget);
        lineEdit_initp->setObjectName(QString::fromUtf8("lineEdit_initp"));
        lineEdit_initp->setStyleSheet(QString::fromUtf8("background:white;"));

        gridLayout->addWidget(lineEdit_initp, 0, 1, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color:white;"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lineEdit_confirmp = new QLineEdit(verticalLayoutWidget);
        lineEdit_confirmp->setObjectName(QString::fromUtf8("lineEdit_confirmp"));
        lineEdit_confirmp->setStyleSheet(QString::fromUtf8("background:white;"));

        gridLayout->addWidget(lineEdit_confirmp, 2, 1, 1, 1);

        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        listWidget_pc = new QListWidget(page_2);
        listWidget_pc->setObjectName(QString::fromUtf8("listWidget_pc"));
        listWidget_pc->setGeometry(QRect(860, 90, 181, 491));
        listWidget_pc->setStyleSheet(QString::fromUtf8("color:white;border: 2px outset black;"));
        listWidget_pc->setDragEnabled(true);
        listWidget_pc->setDragDropMode(QAbstractItemView::NoDragDrop);
        listWidget_pc->setViewMode(QListView::ListMode);
        listWidget_pc->setSortingEnabled(false);
        tableWidget_lr = new QTableWidget(page_2);
        if (tableWidget_lr->columnCount() < 4)
            tableWidget_lr->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        tableWidget_lr->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        tableWidget_lr->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        tableWidget_lr->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QFont font;
        font.setKerning(false);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font);
        tableWidget_lr->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget_lr->rowCount() < 64)
            tableWidget_lr->setRowCount(64);
        tableWidget_lr->setObjectName(QString::fromUtf8("tableWidget_lr"));
        tableWidget_lr->setGeometry(QRect(60, 60, 781, 631));
        tableWidget_lr->setStyleSheet(QString::fromUtf8("color:white;border: 1px outset black;"));
        tableWidget_lr->setGridStyle(Qt::SolidLine);
        tableWidget_lr->setRowCount(64);
        tableWidget_lr->setColumnCount(4);
        tableWidget_lr->horizontalHeader()->setVisible(true);
        tableWidget_lr->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget_lr->horizontalHeader()->setHighlightSections(true);
        tableWidget_lr->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget_lr->horizontalHeader()->setStretchLastSection(true);
        tableWidget_lr->verticalHeader()->setVisible(false);
        tableWidget_lr->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget_lr->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_lr->verticalHeader()->setStretchLastSection(false);
        label_14 = new QLabel(page_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(860, 20, 67, 21));
        label_14->setStyleSheet(QString::fromUtf8("color:white;"));
        label_15 = new QLabel(page_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(1070, 20, 67, 21));
        label_15->setStyleSheet(QString::fromUtf8("color:white;"));
        comboBox_inputp = new QComboBox(page_2);
        comboBox_inputp->setObjectName(QString::fromUtf8("comboBox_inputp"));
        comboBox_inputp->setGeometry(QRect(930, 20, 91, 25));
        comboBox_inputp->setStyleSheet(QString::fromUtf8("background:white;"));
        comboBox_outp = new QComboBox(page_2);
        comboBox_outp->setObjectName(QString::fromUtf8("comboBox_outp"));
        comboBox_outp->setGeometry(QRect(1140, 20, 86, 25));
        comboBox_outp->setStyleSheet(QString::fromUtf8("background:white;"));
        listWidget_pc_2 = new QListWidget(page_2);
        listWidget_pc_2->setObjectName(QString::fromUtf8("listWidget_pc_2"));
        listWidget_pc_2->setGeometry(QRect(1060, 90, 181, 491));
        listWidget_pc_2->setStyleSheet(QString::fromUtf8("color:white;border: 2px outset black;"));
        listWidget_pc_2->setDragEnabled(true);
        listWidget_pc_2->setViewMode(QListView::ListMode);
        listWidget_pc_2->setSortingEnabled(false);
        listWidget_now = new QListWidget(page_2);
        listWidget_now->setObjectName(QString::fromUtf8("listWidget_now"));
        listWidget_now->setGeometry(QRect(1060, 610, 181, 81));
        listWidget_now->setStyleSheet(QString::fromUtf8("color:white;border: 2px outset black;"));
        listWidget_now->setDragEnabled(true);
        listWidget_now->setDragDropMode(QAbstractItemView::DropOnly);
        listWidget_now->setDefaultDropAction(Qt::MoveAction);
        listWidget_now->setViewMode(QListView::ListMode);
        listWidget_now->setSortingEnabled(false);
        label_20 = new QLabel(page_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(1060, 60, 181, 21));
        label_20->setStyleSheet(QString::fromUtf8("color:white;"));
        label_20->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(page_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(860, 60, 181, 21));
        label_22->setStyleSheet(QString::fromUtf8("color:white;"));
        label_22->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(page_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(880, 610, 161, 81));
        label_23->setStyleSheet(QString::fromUtf8("color:white;"));
        label_23->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        listWidget_lc = new QListWidget(page_3);
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::NoBrush);
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget_lc);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setFont(font1);
        __qlistwidgetitem->setForeground(brush);
        __qlistwidgetitem->setFlags(Qt::NoItemFlags);
        listWidget_lc->setObjectName(QString::fromUtf8("listWidget_lc"));
        listWidget_lc->setGeometry(QRect(930, 50, 201, 601));
        listWidget_lc->setStyleSheet(QString::fromUtf8("color:white;border: 2px outset black;"));
        listWidget_lc->setViewMode(QListView::ListMode);
        listWidget_lc->setSortingEnabled(false);
        listWidget_tl2 = new QListWidget(page_3);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::NoBrush);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget_tl2);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem1->setFont(font1);
        __qlistwidgetitem1->setForeground(brush1);
        __qlistwidgetitem1->setFlags(Qt::NoItemFlags);
        listWidget_tl2->setObjectName(QString::fromUtf8("listWidget_tl2"));
        listWidget_tl2->setGeometry(QRect(430, 50, 201, 611));
        listWidget_tl2->setStyleSheet(QString::fromUtf8("color:white;border: 2px outset black;"));
        listWidget_tl2->setDragEnabled(true);
        listWidget_tl2->setDefaultDropAction(Qt::MoveAction);
        listWidget_tl2->setViewMode(QListView::ListMode);
        listWidget_tl2->setSortingEnabled(false);
        listWidget_tl1 = new QListWidget(page_3);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        QBrush brush3(QColor(255, 255, 255, 255));
        brush3.setStyle(Qt::NoBrush);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget_tl1);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem2->setFont(font1);
        __qlistwidgetitem2->setBackground(brush3);
        __qlistwidgetitem2->setForeground(brush2);
        __qlistwidgetitem2->setFlags(Qt::NoItemFlags);
        listWidget_tl1->setObjectName(QString::fromUtf8("listWidget_tl1"));
        listWidget_tl1->setGeometry(QRect(120, 50, 201, 611));
        listWidget_tl1->setStyleSheet(QString::fromUtf8("color:white;border: 2px outset black;"));
        listWidget_tl1->setDragEnabled(true);
        listWidget_tl1->setDefaultDropAction(Qt::MoveAction);
        listWidget_tl1->setViewMode(QListView::ListMode);
        listWidget_tl1->setSortingEnabled(false);
        label_tl2 = new QLabel(page_3);
        label_tl2->setObjectName(QString::fromUtf8("label_tl2"));
        label_tl2->setGeometry(QRect(430, 20, 201, 20));
        label_tl2->setStyleSheet(QString::fromUtf8("color:white;"));
        label_tl2->setAlignment(Qt::AlignCenter);
        label_tl1 = new QLabel(page_3);
        label_tl1->setObjectName(QString::fromUtf8("label_tl1"));
        label_tl1->setGeometry(QRect(120, 20, 201, 20));
        label_tl1->setStyleSheet(QString::fromUtf8("color:white;"));
        label_tl1->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(page_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(930, 20, 201, 21));
        label_19->setStyleSheet(QString::fromUtf8("color:white;"));
        label_19->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_3);
        pushButton_1 = new QPushButton(setui);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(90, 20, 89, 41));
        pushButton_1->setStyleSheet(QString::fromUtf8("QForm{\n"
"backgroup:rgb(64, 64, 64)\n"
"}"));
        pushButton_1->setCheckable(true);
        pushButton_1->setChecked(true);
        pushButton_2 = new QPushButton(setui);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 20, 89, 41));
        pushButton_2->setCheckable(true);
        pushButton_3 = new QPushButton(setui);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 20, 89, 41));
        pushButton_3->setCheckable(true);
        pushButton_Cancel = new QPushButton(setui);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(860, 800, 80, 30));
        pushButton_ok = new QPushButton(setui);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(960, 800, 80, 30));
        pushButton_apply = new QPushButton(setui);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));
        pushButton_apply->setGeometry(QRect(760, 800, 80, 30));

        retranslateUi(setui);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(setui);
    } // setupUi

    void retranslateUi(QWidget *setui)
    {
        setui->setWindowTitle(QApplication::translate("setui", "set", nullptr));
        label_7->setText(QApplication::translate("setui", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_5->setText(QApplication::translate("setui", "\344\275\216\347\224\265\345\271\263\351\230\210\345\200\274:", nullptr));
        label_6->setText(QApplication::translate("setui", "\350\241\250\345\244\264\351\273\204\347\272\277\357\274\232", nullptr));
        label_8->setText(QApplication::translate("setui", "\350\241\250\345\244\264\347\272\242\347\272\277\357\274\232", nullptr));
        label_9->setText(QApplication::translate("setui", "\347\233\221\345\220\254\345\242\236\347\233\212\357\274\232", nullptr));
        label_17->setText(QApplication::translate("setui", "S", nullptr));
        label_13->setText(QApplication::translate("setui", "dB", nullptr));
        label_12->setText(QApplication::translate("setui", "dBFS", nullptr));
        label_10->setText(QApplication::translate("setui", "dBFS", nullptr));
        label_11->setText(QApplication::translate("setui", "dBFS", nullptr));
        label_18->setText(QApplication::translate("setui", "\350\275\256\345\220\254\351\227\264\351\232\224\357\274\232", nullptr));
        label_21->setText(QApplication::translate("setui", "logo\350\267\257\345\276\204\357\274\232", nullptr));
        openfile->setText(QString());
        label_16->setText(QApplication::translate("setui", "\351\224\201\345\256\232\347\256\241\347\220\206", nullptr));
        checkBox_1->setText(QApplication::translate("setui", "\351\224\201\345\256\232\351\200\232\351\201\223\350\277\236\346\216\245\350\256\276\347\275\256\346\214\211\351\222\256", nullptr));
        checkBox_2->setText(QApplication::translate("setui", "\351\224\201\345\256\232\351\237\263\351\242\221\347\233\221\345\220\254\350\275\256\345\220\254\346\214\211\351\222\256", nullptr));
        checkBox_3->setText(QApplication::translate("setui", "\351\224\201\345\256\232\351\237\263\351\242\221\346\250\241\345\235\227\350\256\276\347\275\256\346\214\211\351\222\256", nullptr));
        checkBox_4->setText(QApplication::translate("setui", "\351\224\201\345\256\232\351\237\263\351\242\221\346\250\241\345\235\227\346\212\245\350\255\246\346\214\211\351\222\256", nullptr));
        checkBox_5->setText(QApplication::translate("setui", "\351\224\201\345\256\232\351\237\263\351\242\221\346\250\241\345\235\227\351\235\231\351\237\263\346\214\211\351\222\256", nullptr));
        checkBox_6->setText(QApplication::translate("setui", "\351\224\201\345\256\232\351\237\263\351\242\221\351\237\263\351\207\217\350\260\203\350\212\202\346\214\211\351\222\256", nullptr));
        label->setText(QApplication::translate("setui", "\345\257\206\347\240\201\347\256\241\347\220\206", nullptr));
        label_3->setText(QApplication::translate("setui", "\344\277\256\346\224\271\345\257\206\347\240\201\357\274\232", nullptr));
        label_2->setText(QApplication::translate("setui", "\345\210\235\345\247\213\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QApplication::translate("setui", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_lr->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("setui", "\350\241\250\345\244\264ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_lr->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("setui", "\346\214\211\351\222\256\346\240\207\351\242\230", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_lr->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("setui", "\351\200\273\350\276\221\351\200\232\351\201\223\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_lr->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("setui", "\345\205\263\350\201\224\347\211\251\347\220\206\351\200\232\351\201\223(\345\267\246\345\217\263)", nullptr));
        label_14->setText(QApplication::translate("setui", "\350\276\223\345\205\245\350\256\276\345\244\207\357\274\232", nullptr));
        label_15->setText(QApplication::translate("setui", "\347\233\221\345\220\254\350\256\276\345\244\207\357\274\232", nullptr));
        label_20->setText(QApplication::translate("setui", "\347\233\221\345\220\254\350\256\276\345\244\207\351\200\232\351\201\223\345\210\227\350\241\250", nullptr));
        label_22->setText(QApplication::translate("setui", "\350\276\223\345\205\245\350\256\276\345\244\207\351\200\232\351\201\223\345\210\227\350\241\250", nullptr));
        label_23->setText(QApplication::translate("setui", "\345\275\223\345\211\215\347\233\221\345\220\254\351\200\232\351\201\223(\345\267\246\345\217\263)", nullptr));

        const bool __sortingEnabled = listWidget_lc->isSortingEnabled();
        listWidget_lc->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_lc->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("setui", "\351\200\273\350\276\221\351\200\232\351\201\223\345\210\227\350\241\250", nullptr));
        listWidget_lc->setSortingEnabled(__sortingEnabled);


        const bool __sortingEnabled1 = listWidget_tl2->isSortingEnabled();
        listWidget_tl2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = listWidget_tl2->item(0);
        ___qlistwidgetitem1->setText(QApplication::translate("setui", "\350\275\256\345\220\254\347\273\2042\345\210\227\350\241\250", nullptr));
        listWidget_tl2->setSortingEnabled(__sortingEnabled1);


        const bool __sortingEnabled2 = listWidget_tl1->isSortingEnabled();
        listWidget_tl1->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem2 = listWidget_tl1->item(0);
        ___qlistwidgetitem2->setText(QApplication::translate("setui", "\350\275\256\345\220\254\347\273\2041\345\210\227\350\241\250", nullptr));
        listWidget_tl1->setSortingEnabled(__sortingEnabled2);

        label_tl2->setText(QApplication::translate("setui", "\350\275\256\345\220\254\347\273\2042", nullptr));
        label_tl1->setText(QApplication::translate("setui", "\350\275\256\345\220\254\347\273\2041", nullptr));
        label_19->setText(QApplication::translate("setui", "\351\200\273\350\276\221\351\200\232\351\201\223\345\210\227\350\241\250", nullptr));
        pushButton_1->setText(QApplication::translate("setui", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        pushButton_2->setText(QApplication::translate("setui", "\351\200\232\351\201\223\347\256\241\347\220\206", nullptr));
        pushButton_3->setText(QApplication::translate("setui", "\350\275\256\345\220\254\347\256\241\347\220\206", nullptr));
        pushButton_Cancel->setText(QApplication::translate("setui", "\345\217\226\346\266\210", nullptr));
        pushButton_ok->setText(QApplication::translate("setui", "\347\241\256\350\256\244", nullptr));
        pushButton_apply->setText(QApplication::translate("setui", "\345\272\224\347\224\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setui: public Ui_setui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_H
