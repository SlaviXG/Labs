#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QDir>
#include <QDialog>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrintDialog>
#include <QTreeWidget>
#include <QInputDialog>
#include <QDesktopServices>

#include <filesystem>
#include <cstdlib>
#include <bits/fs_path.h>

#include "additemdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //Action bar
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_as_triggered();
    void on_actionExport_triggered();
    void on_actionExit_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionCut_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();

    //Buttons
    void on_buttonAddItem_clicked();
    void on_buttonDeleteItem_clicked();
    void on_buttonSave_clicked();
    void on_buttonDiscard_clicked();

    //Tree widget
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);
    void on_treeWidget_itemChanged(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow* ui;
    QTreeWidgetItem* treeRoot;
    AddItemDialog* addItemDialog;
    QString contextName = "";
    QString currentTextFile = "";
    QString currentItemPath = "";

    QString getTreeItemPath(QTreeWidgetItem *item);
    void saveCurWidgetText();
    void setNewContextName(QString name);
    bool copyDir(QDir& source, QDir& destination);
    void loadTreeWidget(QString absFolderPath);
    void loadTreeSubdirectories(QTreeWidgetItem* root, QString path);

public slots:
    void addDirItem();
    void addFileItem();
    void addTextItem();
};
#endif // MAINWINDOW_H
