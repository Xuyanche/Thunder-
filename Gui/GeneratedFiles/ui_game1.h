/********************************************************************************
** Form generated from reading UI file 'game1.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME1_H
#define UI_GAME1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game1
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QGraphicsView *view;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *game1)
    {
        if (game1->objectName().isEmpty())
            game1->setObjectName(QStringLiteral("game1"));
        game1->resize(581, 455);
        centralwidget = new QWidget(game1);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(310, 10, 261, 21));
        progressBar->setValue(24);
        view = new QGraphicsView(centralwidget);
        view->setObjectName(QStringLiteral("view"));
        view->setGeometry(QRect(10, 0, 281, 411));
        game1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(game1);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 581, 23));
        game1->setMenuBar(menubar);
        statusbar = new QStatusBar(game1);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        game1->setStatusBar(statusbar);

        retranslateUi(game1);

        QMetaObject::connectSlotsByName(game1);
    } // setupUi

    void retranslateUi(QMainWindow *game1)
    {
        game1->setWindowTitle(QApplication::translate("game1", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game1: public Ui_game1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME1_H