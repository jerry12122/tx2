/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCheckBox *LED1;
    QCheckBox *LED2;
    QCheckBox *LED3;
    QCheckBox *LED4;
    QLabel *Times;
    QPushButton *LED_Shining;
    QLineEdit *times;
    QLabel *label;
    QLabel *label_2;
    QLabel *counter;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(496, 450);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LED1 = new QCheckBox(centralWidget);
        LED1->setObjectName(QStringLiteral("LED1"));
        LED1->setGeometry(QRect(50, 80, 92, 23));
        LED2 = new QCheckBox(centralWidget);
        LED2->setObjectName(QStringLiteral("LED2"));
        LED2->setGeometry(QRect(50, 110, 92, 23));
        LED3 = new QCheckBox(centralWidget);
        LED3->setObjectName(QStringLiteral("LED3"));
        LED3->setGeometry(QRect(50, 140, 92, 23));
        LED4 = new QCheckBox(centralWidget);
        LED4->setObjectName(QStringLiteral("LED4"));
        LED4->setGeometry(QRect(50, 170, 92, 23));
        Times = new QLabel(centralWidget);
        Times->setObjectName(QStringLiteral("Times"));
        Times->setGeometry(QRect(30, 220, 67, 17));
        LED_Shining = new QPushButton(centralWidget);
        LED_Shining->setObjectName(QStringLiteral("LED_Shining"));
        LED_Shining->setGeometry(QRect(40, 280, 89, 25));
        times = new QLineEdit(centralWidget);
        times->setObjectName(QStringLiteral("times"));
        times->setGeometry(QRect(90, 220, 113, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 91, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 40, 141, 16));
        counter = new QLabel(centralWidget);
        counter->setObjectName(QStringLiteral("counter"));
        counter->setGeometry(QRect(260, 120, 67, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 496, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        LED1->setText(QApplication::translate("MainWindow", "LED1", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        LED1->setShortcut(QApplication::translate("MainWindow", "1", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        LED2->setText(QApplication::translate("MainWindow", "LED2", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        LED2->setShortcut(QApplication::translate("MainWindow", "2", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        LED3->setText(QApplication::translate("MainWindow", "LED3", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        LED3->setShortcut(QApplication::translate("MainWindow", "3", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        LED4->setText(QApplication::translate("MainWindow", "LED4", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        LED4->setShortcut(QApplication::translate("MainWindow", "4", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        Times->setText(QApplication::translate("MainWindow", "Count:", Q_NULLPTR));
        LED_Shining->setText(QApplication::translate("MainWindow", "Semaphore", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        LED_Shining->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        label->setText(QApplication::translate("MainWindow", "LED Status", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Process Time", Q_NULLPTR));
        counter->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
