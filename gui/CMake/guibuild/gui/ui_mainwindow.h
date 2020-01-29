/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionPause;
    QAction *actionMenu;
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *durationEdit;
    QLineEdit *nameEdit;
    QLabel *warning;
    QLabel *duration;
    QComboBox *styleEdit;
    QLabel *name;
    QLabel *style;
    QPushButton *continueButton;
    QWidget *page_2;
    QProgressBar *simulationTimeBar;
    QLabel *simulationTime;
    QPushButton *Button1;
    QPushButton *Button2;
    QPushButton *Button3;
    QPushButton *Button4;
    QPushButton *Button5;
    QFrame *popup;
    QLabel *minutes;
    QLabel *downtime;
    QProgressBar *dowtimeBar;
    QLabel *bufferValue;
    QLabel *bufferSize;
    QFrame *titleFrame;
    QLabel *taskName;
    QPushButton *pushButton;
    QPushButton *Button8;
    QPushButton *Button6;
    QPushButton *Button7;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QLabel *titleLabel;
    QLabel *timeVariableLabel;
    QFrame *exitPopup;
    QLabel *label;
    QLabel *label_2;
    QPushButton *popupExitButton;
    QPushButton *popupContinueButton;
    QFrame *line_22;
    QWidget *page_3;
    QProgressBar *simulationTimeBar_2;
    QLabel *simulationTime_2;
    QPushButton *Button9;
    QPushButton *Button10;
    QPushButton *Button11;
    QPushButton *Button12;
    QPushButton *Button13;
    QPushButton *Button14;
    QPushButton *Button15;
    QPushButton *Button16;
    QPushButton *Button17;
    QPushButton *Button18;
    QPushButton *Button19;
    QFrame *line_10;
    QFrame *line_11;
    QFrame *line_12;
    QFrame *line_13;
    QFrame *line_14;
    QFrame *line_15;
    QFrame *line_16;
    QFrame *line_17;
    QFrame *line_18;
    QFrame *line_19;
    QFrame *line_20;
    QFrame *line_21;
    QLabel *titleLabel_2;
    QLabel *timeVariableLabel_2;
    QFrame *line_23;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imgs/Load.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imgs/Save.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSave->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imgs/Exit.png"), QSize(), QIcon::Normal, QIcon::On);
        actionExit->setIcon(icon2);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imgs/Start.png"), QSize(), QIcon::Normal, QIcon::On);
        actionStart->setIcon(icon3);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imgs/Stop.png"), QSize(), QIcon::Normal, QIcon::On);
        actionStop->setIcon(icon4);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imgs/Pause.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPause->setIcon(icon5);
        actionMenu = new QAction(MainWindow);
        actionMenu->setObjectName(QString::fromUtf8("actionMenu"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/imgs/Menu.png"), QSize(), QIcon::Normal, QIcon::On);
        actionMenu->setIcon(icon6);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: #f4f8ff;\n"
"}"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1281, 720));
        stackedWidget->setMinimumSize(QSize(0, 0));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        durationEdit = new QLineEdit(page);
        durationEdit->setObjectName(QString::fromUtf8("durationEdit"));
        durationEdit->setGeometry(QRect(410, 360, 511, 31));
        durationEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color: white;\n"
"border: 1px solid #333;\n"
"border-radius: 2px;\n"
"}"));
        nameEdit = new QLineEdit(page);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(410, 180, 511, 31));
        nameEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background-color: white;\n"
"border: 1px solid #333;\n"
"border-radius: 2px;\n"
"}"));
        warning = new QLabel(page);
        warning->setObjectName(QString::fromUtf8("warning"));
        warning->setGeometry(QRect(220, 40, 811, 36));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(warning->sizePolicy().hasHeightForWidth());
        warning->setSizePolicy(sizePolicy);
        warning->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size: 30px;\n"
"color: red;\n"
"}"));
        duration = new QLabel(page);
        duration->setObjectName(QString::fromUtf8("duration"));
        duration->setGeometry(QRect(390, 300, 291, 82));
        duration->setStyleSheet(QString::fromUtf8("QLabel{\n"
"margin: 20px;\n"
"font-size: 20px;\n"
"}"));
        styleEdit = new QComboBox(page);
        styleEdit->setObjectName(QString::fromUtf8("styleEdit"));
        styleEdit->setGeometry(QRect(410, 270, 511, 31));
        styleEdit->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"color: black;\n"
"background-color: white;\n"
"\n"
"height: 30px;\n"
"\n"
"font-size: 15px;\n"
"border: 1px solid #333;\n"
"border-radius: 2px;\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"color: black;\n"
" }\n"
"\n"
""));
        name = new QLabel(page);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(390, 120, 301, 82));
        name->setStyleSheet(QString::fromUtf8("QLabel{\n"
"margin: 20px;\n"
"font-size: 20px;\n"
"}"));
        style = new QLabel(page);
        style->setObjectName(QString::fromUtf8("style"));
        style->setGeometry(QRect(390, 210, 291, 82));
        style->setStyleSheet(QString::fromUtf8("QLabel{\n"
"margin: 20px;\n"
"font-size: 20px;\n"
"}"));
        continueButton = new QPushButton(page);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setGeometry(QRect(410, 470, 511, 38));
        continueButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"Background: #0092bd;\n"
"border: 1px solid #333;\n"
"border-radius: 2px;\n"
"color: white;\n"
"height: 30px;\n"
"font-size: 15px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"Background: #005e79;\n"
"border: 1px solid #333;\n"
"border-radius: 2px;\n"
"color: white;\n"
"height: 30px;\n"
"font-size: 15px;\n"
"}"));
        stackedWidget->addWidget(page);
        warning->raise();
        duration->raise();
        name->raise();
        style->raise();
        continueButton->raise();
        nameEdit->raise();
        styleEdit->raise();
        durationEdit->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        simulationTimeBar = new QProgressBar(page_2);
        simulationTimeBar->setObjectName(QString::fromUtf8("simulationTimeBar"));
        simulationTimeBar->setGeometry(QRect(10, 40, 251, 23));
        simulationTimeBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"background-color: #FFFFFF;\n"
"border: 1px solid #333;\n"
"border-radius: 2px;\n"
"}\n"
"\n"
"QProgressBar::chunk:horizontal{\n"
"background-color: #00FF00;\n"
"}\n"
"\n"
""));
        simulationTimeBar->setValue(24);
        simulationTimeBar->setAlignment(Qt::AlignCenter);
        simulationTime = new QLabel(page_2);
        simulationTime->setObjectName(QString::fromUtf8("simulationTime"));
        simulationTime->setGeometry(QRect(10, 10, 121, 19));
        Button1 = new QPushButton(page_2);
        Button1->setObjectName(QString::fromUtf8("Button1"));
        Button1->setGeometry(QRect(100, 170, 121, 51));
        Button2 = new QPushButton(page_2);
        Button2->setObjectName(QString::fromUtf8("Button2"));
        Button2->setGeometry(QRect(330, 170, 121, 51));
        Button3 = new QPushButton(page_2);
        Button3->setObjectName(QString::fromUtf8("Button3"));
        Button3->setGeometry(QRect(560, 170, 121, 51));
        Button4 = new QPushButton(page_2);
        Button4->setObjectName(QString::fromUtf8("Button4"));
        Button4->setGeometry(QRect(790, 170, 121, 51));
        Button5 = new QPushButton(page_2);
        Button5->setObjectName(QString::fromUtf8("Button5"));
        Button5->setGeometry(QRect(1010, 300, 121, 51));
        popup = new QFrame(page_2);
        popup->setObjectName(QString::fromUtf8("popup"));
        popup->setGeometry(QRect(1020, 470, 251, 181));
        popup->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color: 	#dfe4e9\n"
"}"));
        popup->setFrameShape(QFrame::StyledPanel);
        popup->setFrameShadow(QFrame::Raised);
        minutes = new QLabel(popup);
        minutes->setObjectName(QString::fromUtf8("minutes"));
        minutes->setGeometry(QRect(100, 93, 67, 19));
        QFont font;
        font.setPointSize(9);
        minutes->setFont(font);
        downtime = new QLabel(popup);
        downtime->setObjectName(QString::fromUtf8("downtime"));
        downtime->setGeometry(QRect(10, 93, 81, 19));
        dowtimeBar = new QProgressBar(popup);
        dowtimeBar->setObjectName(QString::fromUtf8("dowtimeBar"));
        dowtimeBar->setGeometry(QRect(10, 120, 231, 20));
        dowtimeBar->setLayoutDirection(Qt::LeftToRight);
        dowtimeBar->setAutoFillBackground(false);
        dowtimeBar->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"background-color: #FFFFFF;\n"
"border: 1px solid #333;\n"
"border-radius: 2px;\n"
"}\n"
"\n"
"QProgressBar::chunk:horizontal{\n"
"background-color: #FF0000;\n"
"}\n"
"\n"
""));
        dowtimeBar->setMaximum(100);
        dowtimeBar->setValue(24);
        dowtimeBar->setAlignment(Qt::AlignCenter);
        dowtimeBar->setOrientation(Qt::Horizontal);
        dowtimeBar->setTextDirection(QProgressBar::BottomToTop);
        bufferValue = new QLabel(popup);
        bufferValue->setObjectName(QString::fromUtf8("bufferValue"));
        bufferValue->setGeometry(QRect(100, 60, 67, 19));
        bufferValue->setFont(font);
        bufferSize = new QLabel(popup);
        bufferSize->setObjectName(QString::fromUtf8("bufferSize"));
        bufferSize->setGeometry(QRect(10, 60, 81, 19));
        titleFrame = new QFrame(popup);
        titleFrame->setObjectName(QString::fromUtf8("titleFrame"));
        titleFrame->setGeometry(QRect(0, 0, 251, 41));
        titleFrame->setFrameShape(QFrame::StyledPanel);
        titleFrame->setFrameShadow(QFrame::Raised);
        taskName = new QLabel(titleFrame);
        taskName->setObjectName(QString::fromUtf8("taskName"));
        taskName->setGeometry(QRect(20, 10, 211, 21));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        taskName->setFont(font1);
        taskName->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(titleFrame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 10, 20, 20));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: red;\n"
"}"));
        titleFrame->raise();
        minutes->raise();
        downtime->raise();
        dowtimeBar->raise();
        bufferValue->raise();
        bufferSize->raise();
        Button8 = new QPushButton(page_2);
        Button8->setObjectName(QString::fromUtf8("Button8"));
        Button8->setGeometry(QRect(560, 430, 121, 51));
        Button6 = new QPushButton(page_2);
        Button6->setObjectName(QString::fromUtf8("Button6"));
        Button6->setGeometry(QRect(100, 430, 121, 51));
        Button7 = new QPushButton(page_2);
        Button7->setObjectName(QString::fromUtf8("Button7"));
        Button7->setGeometry(QRect(330, 430, 121, 51));
        line = new QFrame(page_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(230, 190, 91, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(page_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(460, 190, 91, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(page_2);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(690, 190, 91, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(page_2);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(230, 450, 91, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(page_2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(460, 450, 91, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(page_2);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(690, 450, 341, 16));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(page_2);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(920, 190, 111, 16));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(page_2);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(1020, 360, 16, 81));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(page_2);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(1020, 210, 16, 81));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);
        titleLabel = new QLabel(page_2);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(290, 20, 701, 51));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        titleLabel->setFont(font2);
        titleLabel->setAlignment(Qt::AlignCenter);
        timeVariableLabel = new QLabel(page_2);
        timeVariableLabel->setObjectName(QString::fromUtf8("timeVariableLabel"));
        timeVariableLabel->setGeometry(QRect(130, 10, 151, 19));
        exitPopup = new QFrame(page_2);
        exitPopup->setObjectName(QString::fromUtf8("exitPopup"));
        exitPopup->setGeometry(QRect(380, 190, 521, 251));
        exitPopup->setFrameShape(QFrame::StyledPanel);
        exitPopup->setFrameShadow(QFrame::Raised);
        label = new QLabel(exitPopup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 391, 51));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(exitPopup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 50, 301, 31));
        label_2->setFont(font3);
        popupExitButton = new QPushButton(exitPopup);
        popupExitButton->setObjectName(QString::fromUtf8("popupExitButton"));
        popupExitButton->setGeometry(QRect(97, 150, 101, 41));
        popupContinueButton = new QPushButton(exitPopup);
        popupContinueButton->setObjectName(QString::fromUtf8("popupContinueButton"));
        popupContinueButton->setGeometry(QRect(317, 150, 101, 41));
        line_22 = new QFrame(page_2);
        line_22->setObjectName(QString::fromUtf8("line_22"));
        line_22->setGeometry(QRect(-3, 70, 1281, 20));
        line_22->setFrameShape(QFrame::HLine);
        line_22->setFrameShadow(QFrame::Sunken);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        simulationTimeBar_2 = new QProgressBar(page_3);
        simulationTimeBar_2->setObjectName(QString::fromUtf8("simulationTimeBar_2"));
        simulationTimeBar_2->setGeometry(QRect(10, 40, 251, 23));
        simulationTimeBar_2->setStyleSheet(QString::fromUtf8("QProgressBar{\n"
"background-color: #FFFFFF;\n"
"border: 1px solid #333;\n"
"border-radius: 2px;\n"
"}\n"
"\n"
"QProgressBar::chunk:horizontal{\n"
"background-color: #00FF00;\n"
"}"));
        simulationTimeBar_2->setValue(24);
        simulationTimeBar_2->setAlignment(Qt::AlignCenter);
        simulationTime_2 = new QLabel(page_3);
        simulationTime_2->setObjectName(QString::fromUtf8("simulationTime_2"));
        simulationTime_2->setGeometry(QRect(10, 10, 121, 19));
        Button9 = new QPushButton(page_3);
        Button9->setObjectName(QString::fromUtf8("Button9"));
        Button9->setGeometry(QRect(60, 170, 121, 51));
        Button10 = new QPushButton(page_3);
        Button10->setObjectName(QString::fromUtf8("Button10"));
        Button10->setGeometry(QRect(230, 170, 121, 51));
        Button11 = new QPushButton(page_3);
        Button11->setObjectName(QString::fromUtf8("Button11"));
        Button11->setGeometry(QRect(400, 170, 121, 51));
        Button12 = new QPushButton(page_3);
        Button12->setObjectName(QString::fromUtf8("Button12"));
        Button12->setGeometry(QRect(570, 170, 121, 51));
        Button13 = new QPushButton(page_3);
        Button13->setObjectName(QString::fromUtf8("Button13"));
        Button13->setGeometry(QRect(740, 170, 121, 51));
        Button14 = new QPushButton(page_3);
        Button14->setObjectName(QString::fromUtf8("Button14"));
        Button14->setGeometry(QRect(910, 170, 121, 51));
        Button15 = new QPushButton(page_3);
        Button15->setObjectName(QString::fromUtf8("Button15"));
        Button15->setGeometry(QRect(60, 430, 121, 51));
        Button16 = new QPushButton(page_3);
        Button16->setObjectName(QString::fromUtf8("Button16"));
        Button16->setGeometry(QRect(230, 430, 121, 51));
        Button17 = new QPushButton(page_3);
        Button17->setObjectName(QString::fromUtf8("Button17"));
        Button17->setGeometry(QRect(400, 430, 121, 51));
        Button18 = new QPushButton(page_3);
        Button18->setObjectName(QString::fromUtf8("Button18"));
        Button18->setGeometry(QRect(570, 430, 121, 51));
        Button19 = new QPushButton(page_3);
        Button19->setObjectName(QString::fromUtf8("Button19"));
        Button19->setGeometry(QRect(1100, 300, 121, 51));
        line_10 = new QFrame(page_3);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(190, 190, 31, 16));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        line_11 = new QFrame(page_3);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(360, 190, 31, 16));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);
        line_12 = new QFrame(page_3);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(530, 190, 31, 16));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);
        line_13 = new QFrame(page_3);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setGeometry(QRect(700, 190, 31, 16));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);
        line_14 = new QFrame(page_3);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setGeometry(QRect(870, 190, 31, 16));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);
        line_15 = new QFrame(page_3);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setGeometry(QRect(190, 450, 31, 16));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);
        line_16 = new QFrame(page_3);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setGeometry(QRect(360, 450, 31, 16));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);
        line_17 = new QFrame(page_3);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setGeometry(QRect(530, 450, 31, 16));
        line_17->setFrameShape(QFrame::HLine);
        line_17->setFrameShadow(QFrame::Sunken);
        line_18 = new QFrame(page_3);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setGeometry(QRect(700, 450, 421, 16));
        line_18->setFrameShape(QFrame::HLine);
        line_18->setFrameShadow(QFrame::Sunken);
        line_19 = new QFrame(page_3);
        line_19->setObjectName(QString::fromUtf8("line_19"));
        line_19->setGeometry(QRect(1040, 190, 81, 16));
        line_19->setFrameShape(QFrame::HLine);
        line_19->setFrameShadow(QFrame::Sunken);
        line_20 = new QFrame(page_3);
        line_20->setObjectName(QString::fromUtf8("line_20"));
        line_20->setGeometry(QRect(1110, 360, 20, 81));
        line_20->setFrameShape(QFrame::VLine);
        line_20->setFrameShadow(QFrame::Sunken);
        line_21 = new QFrame(page_3);
        line_21->setObjectName(QString::fromUtf8("line_21"));
        line_21->setGeometry(QRect(1110, 210, 20, 81));
        line_21->setFrameShape(QFrame::VLine);
        line_21->setFrameShadow(QFrame::Sunken);
        titleLabel_2 = new QLabel(page_3);
        titleLabel_2->setObjectName(QString::fromUtf8("titleLabel_2"));
        titleLabel_2->setGeometry(QRect(290, 20, 701, 51));
        titleLabel_2->setFont(font2);
        titleLabel_2->setAlignment(Qt::AlignCenter);
        timeVariableLabel_2 = new QLabel(page_3);
        timeVariableLabel_2->setObjectName(QString::fromUtf8("timeVariableLabel_2"));
        timeVariableLabel_2->setGeometry(QRect(140, 10, 141, 19));
        line_23 = new QFrame(page_3);
        line_23->setObjectName(QString::fromUtf8("line_23"));
        line_23->setGeometry(QRect(0, 70, 1281, 20));
        line_23->setFrameShape(QFrame::HLine);
        line_23->setFrameShadow(QFrame::Sunken);
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 24));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionMenu);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionStart);
        menuEdit->addAction(actionStop);
        menuEdit->addAction(actionPause);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simulation Program", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionStart->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        actionMenu->setText(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
        nameEdit->setText(QString());
        warning->setText(QString());
        duration->setText(QApplication::translate("MainWindow", "Duration:", 0, QApplication::UnicodeUTF8));
        styleEdit->clear();
        styleEdit->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Basic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Luxe", 0, QApplication::UnicodeUTF8)
        );
        name->setText(QApplication::translate("MainWindow", "Name:", 0, QApplication::UnicodeUTF8));
        style->setText(QApplication::translate("MainWindow", "Style:", 0, QApplication::UnicodeUTF8));
        continueButton->setText(QApplication::translate("MainWindow", "Continue", 0, QApplication::UnicodeUTF8));
        simulationTime->setText(QApplication::translate("MainWindow", "Simulation time:", 0, QApplication::UnicodeUTF8));
        Button1->setText(QApplication::translate("MainWindow", "Planken zagen", 0, QApplication::UnicodeUTF8));
        Button2->setText(QApplication::translate("MainWindow", "Voorboren", 0, QApplication::UnicodeUTF8));
        Button3->setText(QApplication::translate("MainWindow", "Schuren", 0, QApplication::UnicodeUTF8));
        Button4->setText(QApplication::translate("MainWindow", "Spuiten", 0, QApplication::UnicodeUTF8));
        Button5->setText(QApplication::translate("MainWindow", "Inpakken", 0, QApplication::UnicodeUTF8));
        minutes->setText(QApplication::translate("MainWindow", "20 min", 0, QApplication::UnicodeUTF8));
        downtime->setText(QApplication::translate("MainWindow", "Downtime:", 0, QApplication::UnicodeUTF8));
        bufferValue->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        bufferSize->setText(QApplication::translate("MainWindow", "Buffer size:", 0, QApplication::UnicodeUTF8));
        taskName->setText(QApplication::translate("MainWindow", "Zagen platen", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        Button8->setText(QApplication::translate("MainWindow", "Poeder coaten", 0, QApplication::UnicodeUTF8));
        Button6->setText(QApplication::translate("MainWindow", "Pijpen zagen", 0, QApplication::UnicodeUTF8));
        Button7->setText(QApplication::translate("MainWindow", "Lassen", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("MainWindow", "Title not found", 0, QApplication::UnicodeUTF8));
        timeVariableLabel->setText(QApplication::translate("MainWindow", "Time", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Return to main menu?", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Simulation will be stopped", 0, QApplication::UnicodeUTF8));
        popupExitButton->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        popupContinueButton->setText(QApplication::translate("MainWindow", "Continue", 0, QApplication::UnicodeUTF8));
        simulationTime_2->setText(QApplication::translate("MainWindow", "Simulation time:", 0, QApplication::UnicodeUTF8));
        Button9->setText(QApplication::translate("MainWindow", "Zagen", 0, QApplication::UnicodeUTF8));
        Button10->setText(QApplication::translate("MainWindow", "Lijmen", 0, QApplication::UnicodeUTF8));
        Button11->setText(QApplication::translate("MainWindow", "Frezen", 0, QApplication::UnicodeUTF8));
        Button12->setText(QApplication::translate("MainWindow", "Voorboren", 0, QApplication::UnicodeUTF8));
        Button13->setText(QApplication::translate("MainWindow", "Schuren", 0, QApplication::UnicodeUTF8));
        Button14->setText(QApplication::translate("MainWindow", "Spuiten", 0, QApplication::UnicodeUTF8));
        Button15->setText(QApplication::translate("MainWindow", "Zagen", 0, QApplication::UnicodeUTF8));
        Button16->setText(QApplication::translate("MainWindow", "Buigen", 0, QApplication::UnicodeUTF8));
        Button17->setText(QApplication::translate("MainWindow", "Lassen", 0, QApplication::UnicodeUTF8));
        Button18->setText(QApplication::translate("MainWindow", "Polijsten", 0, QApplication::UnicodeUTF8));
        Button19->setText(QApplication::translate("MainWindow", "Inpakken", 0, QApplication::UnicodeUTF8));
        titleLabel_2->setText(QApplication::translate("MainWindow", "Title not found", 0, QApplication::UnicodeUTF8));
        timeVariableLabel_2->setText(QApplication::translate("MainWindow", "Time", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
