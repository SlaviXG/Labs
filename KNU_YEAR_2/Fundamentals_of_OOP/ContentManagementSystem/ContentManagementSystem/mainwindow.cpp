#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "auxiliary.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //UI setup
    ui->setupUi(this);
    this->setCentralWidget(ui->verticalLayoutWidget);

    //Context name setup
    this->contextName = "New context";

    //Tree Widget setup
    ui->treeWidget->clear();
    treeRoot = new QTreeWidgetItem();
    treeRoot->setText(0, contextName);
    treeRoot->setWhatsThis(0, "Dir");
    ui->treeWidget->addTopLevelItem(treeRoot);

    //Setting a new directory
    QString path = "contexts/" + contextName;
    QDir dir;
    dir.mkpath(path);

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
    //clearing the name of current text file
    currentTextFile.clear();

    //clearing tree widget
    ui->treeWidget->clear();

    //clearing text edit wodget
    ui->textEdit->setText(QString());

    //Changing context name holder
    contextName = "New context";

    //Changing mainwindow title
    setWindowTitle(contextName);

    //Setting-up a new tree root with context name
    treeRoot = new QTreeWidgetItem();
    treeRoot->setText(0, contextName);
    ui->treeWidget->addTopLevelItem(treeRoot);

    //Setting the real directory
    QString path = "contexts/" + contextName;
    QDir dir;
    dir.mkpath(path);
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentTextFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open the file: " + file.errorString());
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
        QMessageBox::warning(this, "Warning", "Cannot save the file: " + file.errorString());
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
    QTreeWidgetItem *curTreeItem = this->ui->treeWidget->currentItem();
    if(curTreeItem == nullptr)
        addItemDialog->show();
    else if(curTreeItem->whatsThis(0) == "Dir")
        addItemDialog->show();
    else
        QMessageBox::warning(this, "Error", "Error: you can add subitem only to the directory");
}


void MainWindow::on_buttonDeleteItem_clicked()
{

    QList<QTreeWidgetItem *>  items = ui->treeWidget->selectedItems();
    QTreeWidgetItem          *pp    = nullptr;
    QString path;

    if (!items.isEmpty())
    {
      foreach (QTreeWidgetItem *item, items)
      {
        if(item == ui->treeWidget->topLevelItem(0))
        {
            QMessageBox::critical(this,"Error", "Unable to delete the root item");
            break;
        }
        pp = item->parent();

        //Removing from real directory
        path = "contexts" + getTreeItemPath(item);
        QMessageBox::information(this, "DEBUG", path);
        if(item->whatsThis(0) != "Dir")
        {
            bool deleted = QFile::remove(path);
            if(!deleted) QMessageBox::critical(this, "Error", "Error, unable to delete the file.");
        }
        else
        {
            QDir dir(path);
            if(dir.exists())
            {
                bool deleted = dir.removeRecursively();
                if(!deleted) QMessageBox::critical(this, "Error", "Error, unable to delete the directory.");
            }
            else
            {
                QMessageBox::critical(this, "Error", "Error, unable to delete the directory. It doesn't exist.");
            }
        }

        //Removing from tree widget
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
    //Hiding the dialog wondow
    addItemDialog->hide();

    //Entering item name
    QString dirName;
    bool okClicked = false;
    dirName = QInputDialog::getText(this, "Directory name", "Enter a directory name", QLineEdit::Normal, QDir::home().dirName(), &okClicked);
    trimStr(dirName);
    //Returning if not clicked ok
    if(!okClicked) return;

    //Re-entering input if incorrect
    while(!isCorrectName(dirName))
    {
        QMessageBox::warning(this,"Error", "Error: directory name is incorrect. It mustn't contain either  \\ / < > : * ? \" | "
                                           "\n or be empty.");
        dirName = QInputDialog::getText(this, "Directory name", "Enter a directory name", QLineEdit::Normal, QDir::home().dirName(), &okClicked);
        trimStr(dirName);
        //Returning if not clicked ok
        if(!okClicked) return;
    }

    //Setting-up an item
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, dirName);
    item->setWhatsThis(0, "Dir");

    //Adding this item to the treeWidget
    if(this->ui->treeWidget->currentItem() != nullptr)
        this->ui->treeWidget->currentItem()->addChild(item);
    else
        this->ui->treeWidget->topLevelItem(0)->addChild(item);

    //Setting the real directory
    QString path = "contexts/" + getTreeItemPath(item);
    QDir dir;
    dir.mkpath(path);
}

void MainWindow::addFileItem()
{
    //Hiding the dialog wondow
    addItemDialog->hide();

    //Choosing a file
    QString filePath = QFileDialog::getOpenFileName(this, "Choose the file");

    //Returning if not ok
    if(filePath == "") return;

    QString fileName = getFileNameFromPath(filePath);
    QString fileExtension = getFileExtension(fileName);

    //Setting-up an item
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, fileName);
    item->setWhatsThis(0, ((fileExtension == "txt") ? "Txt" : "File"));

    //Adding this item to the treeWidget
    if(this->ui->treeWidget->currentItem() != nullptr)
        this->ui->treeWidget->currentItem()->addChild(item);
    else
        this->ui->treeWidget->topLevelItem(0)->addChild(item);

    //Setting the real file
    QString path = "contexts" + getTreeItemPath(item);
    bool coppied = QFile::copy(filePath, path);
    if(!coppied)
    {
        QMessageBox::warning(this, "Warning", "Error. Cannot copy the file.");
        this->ui->treeWidget->removeItemWidget(item, 0);
        return;
    }
}

void MainWindow::addTextItem()
{
    //Hiding the dialog wondow
    addItemDialog->hide();

    //Entering item name
    QString txtName;
    bool okClicked = false;
    txtName = QInputDialog::getText(this, "Description name", "Enter a name of the text file", QLineEdit::Normal, QDir::home().dirName(), &okClicked);
    trimStr(txtName);
    //Returning if not clicked ok
    if(!okClicked) return;

    //Re-entering input if incorrect
    while(!isCorrectName(txtName))
    {
        QMessageBox::warning(this,"Error", "Error: item name is incorrect. It mustn't contain either  \\ / < > : * ? \" | "
                                           "\n or be empty.");
        txtName = QInputDialog::getText(this, "Description name", "Enter a name of the text file", QLineEdit::Normal, QDir::home().dirName(), &okClicked);
        trimStr(txtName);
        //Returning if not clicked ok
        if(!okClicked) return;
    }

    //Setting-up an item
    QTreeWidgetItem *item = new QTreeWidgetItem();
    item->setText(0, txtName + ".txt");
    item->setWhatsThis(0, "Txt");

    //Adding this item to the treeWidget
    if(this->ui->treeWidget->currentItem() != nullptr)
        this->ui->treeWidget->currentItem()->addChild(item);
    else
        this->ui->treeWidget->topLevelItem(0)->addChild(item);

    //Setting the real file
    QString path = "contexts" + getTreeItemPath(item);
    QFile txtFile(path);

    if(!txtFile.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot create the file: " + txtFile.errorString());
        return;
    }
    QTextStream out(&txtFile);
    out << "";
    txtFile.close();
}


//Additional
QString MainWindow::getTreeItemPath(QTreeWidgetItem *item)
{
    QString path = "";

    while(item != nullptr)
    {
        path = '/' + item->text(0) + path;
        item = item->parent();
    }

    return path;
}
