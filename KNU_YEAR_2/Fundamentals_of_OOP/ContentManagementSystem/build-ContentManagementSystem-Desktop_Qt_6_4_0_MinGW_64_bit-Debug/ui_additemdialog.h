/********************************************************************************
** Form generated from reading UI file 'additemdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEMDIALOG_H
#define UI_ADDITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddItemDialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnDir;
    QPushButton *btnFile;
    QPushButton *btnTxt;

    void setupUi(QDialog *AddItemDialog)
    {
        if (AddItemDialog->objectName().isEmpty())
            AddItemDialog->setObjectName("AddItemDialog");
        AddItemDialog->resize(410, 59);
        horizontalLayoutWidget = new QWidget(AddItemDialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 391, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnDir = new QPushButton(horizontalLayoutWidget);
        btnDir->setObjectName("btnDir");

        horizontalLayout->addWidget(btnDir);

        btnFile = new QPushButton(horizontalLayoutWidget);
        btnFile->setObjectName("btnFile");

        horizontalLayout->addWidget(btnFile);

        btnTxt = new QPushButton(horizontalLayoutWidget);
        btnTxt->setObjectName("btnTxt");

        horizontalLayout->addWidget(btnTxt);


        retranslateUi(AddItemDialog);

        QMetaObject::connectSlotsByName(AddItemDialog);
    } // setupUi

    void retranslateUi(QDialog *AddItemDialog)
    {
        AddItemDialog->setWindowTitle(QCoreApplication::translate("AddItemDialog", "Item Type", nullptr));
        btnDir->setText(QCoreApplication::translate("AddItemDialog", "Directory", nullptr));
        btnFile->setText(QCoreApplication::translate("AddItemDialog", "File", nullptr));
        btnTxt->setText(QCoreApplication::translate("AddItemDialog", "Text description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddItemDialog: public Ui_AddItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMDIALOG_H
