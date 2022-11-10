/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *actionExport;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionUndo;
    QAction *actionRedo;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonSave;
    QPushButton *buttonDiscard;
    QLineEdit *searchLine;
    QPushButton *buttonAddFile;
    QPushButton *buttonDeleteFile;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_4;
    QTreeWidget *treeWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 450);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ics/ics/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ics/ics/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName("actionSave_as");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ics/ics/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon2);
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName("actionExport");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ics/ics/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport->setIcon(icon3);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/ics/ics/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/ics/ics/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon5);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/ics/ics/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon6);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/ics/ics/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon7);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/ics/ics/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon8);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/ics/ics/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon9);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(9, 9, 781, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        buttonSave = new QPushButton(verticalLayoutWidget);
        buttonSave->setObjectName("buttonSave");
        buttonSave->setEnabled(true);

        horizontalLayout->addWidget(buttonSave);

        buttonDiscard = new QPushButton(verticalLayoutWidget);
        buttonDiscard->setObjectName("buttonDiscard");

        horizontalLayout->addWidget(buttonDiscard);

        searchLine = new QLineEdit(verticalLayoutWidget);
        searchLine->setObjectName("searchLine");
        searchLine->setAutoFillBackground(false);

        horizontalLayout->addWidget(searchLine);

        buttonAddFile = new QPushButton(verticalLayoutWidget);
        buttonAddFile->setObjectName("buttonAddFile");

        horizontalLayout->addWidget(buttonAddFile);

        buttonDeleteFile = new QPushButton(verticalLayoutWidget);
        buttonDeleteFile->setObjectName("buttonDeleteFile");

        horizontalLayout->addWidget(buttonDeleteFile);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName("textEdit");

        verticalLayout_2->addWidget(textEdit);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        treeWidget = new QTreeWidget(verticalLayoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");

        verticalLayout_4->addWidget(treeWidget);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionExport);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ContentManagementSystem", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
        actionExport->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        actionCut->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        buttonSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        buttonDiscard->setText(QCoreApplication::translate("MainWindow", "Discard", nullptr));
        searchLine->setText(QString());
        searchLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        buttonAddFile->setText(QCoreApplication::translate("MainWindow", "Add File", nullptr));
        buttonDeleteFile->setText(QCoreApplication::translate("MainWindow", "Delete File", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Content", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
