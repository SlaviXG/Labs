#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include <QDialog>

namespace Ui {
class AddItemDialog;
}

class AddItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddItemDialog(QWidget *parent = nullptr);
    ~AddItemDialog();

private:
    Ui::AddItemDialog *ui;

signals:
    void addDirClicked();
    void addFileClicked();
    void addTxtClicked();
private slots:
    void on_btnDir_clicked();
    void on_btnFile_clicked();
    void on_btnTxt_clicked();
};

#endif // ADDITEMDIALOG_H
