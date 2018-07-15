#include "dialog_edit.h"
#include "ui_dialog_edit.h"

Dialog_edit::Dialog_edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_edit)
{
    ui->setupUi(this);
}

Dialog_edit::~Dialog_edit()
{
    delete ui;
}
