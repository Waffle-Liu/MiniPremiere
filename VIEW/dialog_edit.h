#ifndef DIALOG_EDIT_H
#define DIALOG_EDIT_H

#include <QDialog>
#include <QMessageBox>
#include "VideoPlay.h"
#include "stdafx.h"
#include "Video.h"
using namespace cv;

extern VideoPlay globalplay;

namespace Ui {
class Dialog_edit;
}

class Dialog_edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_edit(QWidget *parent = 0);
    ~Dialog_edit();

private:
    Ui::Dialog_edit *ui;

private slots:
	void on_pushButton_2_clicked();
	void on_pushButton_clicked();
};

#endif // DIALOG_EDIT_H
