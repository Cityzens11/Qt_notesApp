/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_note;
    QAction *actionOpen_note_txt;
    QAction *actionPrint;
    QAction *actionExit;
    QAction *actionNote_color;
    QAction *actionFont_style_3;
    QAction *actionFont_color_4;
    QAction *actionSearch_note;
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QWidget *widget_2;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_6;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuFont;
    QMenu *menuSearch;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/document.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"background: rgb(33, 33, 42);\n"
"}\n"
"QWidget #menubar{\n"
"color:rgb(255, 255, 255);\n"
"background:rgb(40,35,62);\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color:rgb(43, 42, 58);\n"
"    color:rgb(211, 215, 207);\n"
"    border: 0px;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QMenu::item:selected { \n"
"    background-color: #654321;\n"
"    color:rgb(243, 243, 243);\n"
"}\n"
"QAction{\n"
"color:rgb(238, 238, 236);\n"
"}QAction:hover{\n"
"color:rgb(238, 238, 236);\n"
"}\n"
""));
        actionNew_note = new QAction(MainWindow);
        actionNew_note->setObjectName(QString::fromUtf8("actionNew_note"));
        actionOpen_note_txt = new QAction(MainWindow);
        actionOpen_note_txt->setObjectName(QString::fromUtf8("actionOpen_note_txt"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNote_color = new QAction(MainWindow);
        actionNote_color->setObjectName(QString::fromUtf8("actionNote_color"));
        actionFont_style_3 = new QAction(MainWindow);
        actionFont_style_3->setObjectName(QString::fromUtf8("actionFont_style_3"));
        actionFont_color_4 = new QAction(MainWindow);
        actionFont_color_4->setObjectName(QString::fromUtf8("actionFont_color_4"));
        actionSearch_note = new QAction(MainWindow);
        actionSearch_note->setObjectName(QString::fromUtf8("actionSearch_note"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 191, 581));
        widget->setStyleSheet(QString::fromUtf8("QWidget #widget{\n"
"background: rgb(43, 42, 58);\n"
"}\n"
"QPushButton {\n"
"background:rgb(43,42,58);\n"
"border: 0px;\n"
"color:rgb(211, 215, 207);\n"
"}\n"
"QPushButton:hover {\n"
"background:rgb(40, 35, 62);\n"
"border: 0px;\n"
"color:rgb(238, 238, 236);\n"
"}\n"
"QPushButton:hover:pressed{\n"
"background:rgb(33, 33, 42);\n"
"color:rgb(85, 87, 83);\n"
"}\n"
"QLabel{\n"
"font: 22px;\n"
"color:rgb(211, 215, 207);\n"
"background: transparent;\n"
"}"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 51, 31));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"font: 22px;\n"
"}"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 60, 191, 51));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 110, 191, 51));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 180, 191, 51));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 550, 61, 21));
        label_2->setStyleSheet(QString::fromUtf8("QLabel#label_2{\n"
"font:14px;}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(740, 520, 41, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background: rgb(43,42,58);\n"
"border: 0px;\n"
"color:rgb(211, 215, 207);\n"
"}\n"
"QPushButton:hover {\n"
"background: rgb(40, 35, 62);\n"
"border: 0px;\n"
"color:rgb(238, 238, 236);\n"
"}\n"
"QPushButton:hover:pressed{background:rgb(47, 18, 69);}"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(220, 160, 351, 201));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget #widget_2{\n"
"background:rgb(46, 52, 54);\n"
"border-radius:20px;\n"
"}\n"
"QPushButton{\n"
"background:rgb(85, 87, 83);\n"
"color:rgb(211, 215, 207);\n"
"}\n"
"QPushButton:hover{\n"
"background:rgb(46, 52, 54);\n"
"color:rgb(211, 215, 207);\n"
"}\n"
"QLineEdit{\n"
"background:rgb(211, 215, 207);\n"
"color:rgb(46, 52, 54)\n"
"}\n"
"QComboBox{\n"
"color:rgb(211, 215, 207);\n"
"selection-color: rgb(193, 125, 17);\n"
"selection-background-color: rgb(43, 42, 58);\n"
"}\n"
""));
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 50, 251, 31));
        comboBox = new QComboBox(widget_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(50, 100, 251, 31));
        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(150, 160, 89, 25));
        pushButton_6 = new QPushButton(widget_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(245, 160, 89, 25));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(190, 0, 611, 501));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea{\n"
"border: 0px;}"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 611, 501));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 591, 491));
        gridLayout_6 = new QGridLayout(gridLayoutWidget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralwidget);
        scrollArea->raise();
        widget->raise();
        pushButton_4->raise();
        widget_2->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuFont = new QMenu(menuTools);
        menuFont->setObjectName(QString::fromUtf8("menuFont"));
        menuSearch = new QMenu(menubar);
        menuSearch->setObjectName(QString::fromUtf8("menuSearch"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuSearch->menuAction());
        menuFile->addAction(actionNew_note);
        menuFile->addAction(actionOpen_note_txt);
        menuFile->addAction(actionPrint);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuTools->addAction(menuFont->menuAction());
        menuTools->addAction(actionNote_color);
        menuFont->addAction(actionFont_style_3);
        menuFont->addAction(actionFont_color_4);
        menuSearch->addAction(actionSearch_note);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_5, SIGNAL(clicked()), widget_2, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "NoteApp", nullptr));
        actionNew_note->setText(QApplication::translate("MainWindow", "New note", nullptr));
        actionOpen_note_txt->setText(QApplication::translate("MainWindow", "Open note(.txt)", nullptr));
        actionPrint->setText(QApplication::translate("MainWindow", "Print", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionNote_color->setText(QApplication::translate("MainWindow", "Window color", nullptr));
        actionFont_style_3->setText(QApplication::translate("MainWindow", "Font style", nullptr));
        actionFont_color_4->setText(QApplication::translate("MainWindow", "Font color", nullptr));
        actionSearch_note->setText(QApplication::translate("MainWindow", "Search note", nullptr));
        label->setText(QApplication::translate("MainWindow", "Note", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Home", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Search", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "@cityzen", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "+", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Enter title", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "yellow", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "purple", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "blue", nullptr));

        pushButton_5->setText(QApplication::translate("MainWindow", "cancel", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "create", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        menuFont->setTitle(QApplication::translate("MainWindow", "Font ", nullptr));
        menuSearch->setTitle(QApplication::translate("MainWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
