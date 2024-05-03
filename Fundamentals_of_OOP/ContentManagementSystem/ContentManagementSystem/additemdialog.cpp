#include "additemdialog.h"
#include "ui_additemdialog.h"

AddItemDialog::AddItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemDialog)
{
    ui->setupUi(this);
}

AddItemDialog::~AddItemDialog()
{
    delete ui;
}

//Buttons
void AddItemDialog::on_btnDir_clicked()
{
    emit addDirClicked();
}

void AddItemDialog::on_btnFile_clicked()
{
    emit addFileClicked();
}

void AddItemDialog::on_btnTxt_clicked()
{
    emit addTxtClicked();
}

