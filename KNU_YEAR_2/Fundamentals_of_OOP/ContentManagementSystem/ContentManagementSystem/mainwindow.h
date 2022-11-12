#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QDialog>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrintDialog>
#include <QTreeWidget>
#include <QInputDialog>

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

    void on_buttonAddItem_clicked();

    void on_buttonDeleteItem_clicked();

    void on_buttonSave_clicked();

    void on_buttonDiscard_clicked();

private:
    Ui::MainWindow *ui;
    AddItemDialog *addItemDialog;
    QString contextName = "";
    QString currentTextFile = "";
    QTreeWidgetItem* treeRoot;

    bool isCorrectName(QString name);

public slots:
    void addDirItem();
    void addFileItem();
    void addTextItem();
};
#endif // MAINWINDOW_H
