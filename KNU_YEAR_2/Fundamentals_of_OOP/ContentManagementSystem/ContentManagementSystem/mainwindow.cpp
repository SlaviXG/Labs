#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //UI setup
    ui->setupUi(this);
    this->setCentralWidget(ui->verticalLayoutWidget);

    //Tree Widget setup
    ui->treeWidget->clear();
    treeRoot = new QTreeWidgetItem();
    treeRoot->setText(0, "New context");
    ui->treeWidget->addTopLevelItem(treeRoot);

    //Item Dialog setup
    this->addItemDialog = new AddItemDialog(this);
    connect(addItemDialog, &AddItemDialog::addDirClicked, this, &MainWindow::addDirItem);
    connect(addItemDialog, &AddItemDialog::addFileClicked, this, &MainWindow::addFileItem);
    connect(addItemDialog, &AddItemDialog::addTxtClicked, this, &MainWindow::addTextItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Content menubar:
void MainWindow::on_actionNew_triggered()
{
    currentTextFile.clear();
    ui->treeWidget->clear();
    ui->textEdit->setText(QString());
    setWindowTitle(QString("New context"));
    contextName = "New context";
    treeRoot = new QTreeWidgetItem();
    treeRoot->setText(0, contextName);
    ui->treeWidget->addTopLevelItem(treeRoot);
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentTextFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open the file : " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot save the file : " + file.errorString());
        return;
    }
    currentTextFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void MainWindow::on_actionExport_triggered()
{
    //TODO : Exporting file
    on_actionSave_as_triggered();
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


//Text menubar:
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

//Buttons:
void MainWindow::on_buttonAddItem_clicked()
{
    addItemDialog->show();
}


void MainWindow::on_buttonDeleteItem_clicked()
{

    QList<QTreeWidgetItem *>  items = ui->treeWidget->selectedItems();
    QTreeWidgetItem          *pp    = nullptr;

    if ( !items.isEmpty() )
    {
      foreach (QTreeWidgetItem *item, items)
      {
        if(item == ui->treeWidget->topLevelItem(0))
        {
            QMessageBox::critical(this,"Error", "Unable to delete the root item");
            break;
        }
        pp = item->parent();
        pp->removeChild(item);
        delete item;
      }
    }
}


void MainWindow::on_buttonSave_clicked()
{

}


void MainWindow::on_buttonDiscard_clicked()
{

}

//Public slots:
void MainWindow::addDirItem()
{
    addItemDialog->hide();
    QString dirName;
    dirName = QInputDialog::getText(this, "Directory name", "Enter a directory name");
    while(!isCorrectName(dirName))
    {
        QMessageBox::critical(this,"Error", "Error: directory name is incorrect. It mustn't contain either  \\ / < > : * ? \" |");
        dirName = QInputDialog::getText(this, "Directory name", "Enter a directory name");
    }

    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, dirName);
    item->setWhatsThis(0, "Dir");

    if(this->ui->treeWidget->currentItem() != nullptr)
        this->ui->treeWidget->currentItem()->addChild(item);
    else
        this->ui->treeWidget->topLevelItem(0)->addChild(item);

}

void MainWindow::addFileItem()
{
    addItemDialog->hide();

    QString fileName = QFileDialog::getOpenFileName(this, "Choose the file");
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, fileName);
    item->setWhatsThis(0, "File");
}

void MainWindow::addTextItem()
{
    addItemDialog->hide();
    QString txtName;
    txtName = QInputDialog::getText(this, "Description name", "Enter a name of the text file");
    while(!isCorrectName(txtName))
    {
        QMessageBox::critical(this,"Error", "Error: file name is incorrect. It mustn't contain either  \\ / < > : * ? \" |");
        txtName = QInputDialog::getText(this, "Description name", "Enter a name of the text file");
    }
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, txtName);
    item->setWhatsThis(0, "Txt");

    //TODO:Double left click, directory work!
}

//Additional
bool MainWindow::isCorrectName(QString name)
{
    QString prohibited = "\\/<>:*?\"|";
    for(int i = 0; i < name.size(); i++)
    {
        for(int j = 0; j < prohibited.size(); j++)
        {
            if(name[i]==prohibited[j]) return false;
        }
    }
    return true;
}
