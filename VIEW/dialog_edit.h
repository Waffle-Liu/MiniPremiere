#ifndef DIALOG_EDIT_H
#define DIALOG_EDIT_H



#include <QDialog>
#include <QMessageBox>
#include "common/command.h"
//#include "VideoPlay.h"
//#include "stdafx.h"
//#include "Video.h"
//using namespace cv;

//extern VideoPlay globalplay;

namespace Ui {
class Dialog_edit;
}

class Dialog_edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_edit(QWidget *parent = 0);
    ~Dialog_edit();
    void setSpeedConfirmCommand(std::shared_ptr<Command> ptr_speedconfirm);
    void setCutConfirmCommand(std::shared_ptr<Command> ptr_cutconfirm);

private:
    Ui::Dialog_edit *ui;
    std::shared_ptr<Command> ptr_speedconfirmCommand;
    std::shared_ptr<Command> ptr_cutconfirmCommand;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // DIALOG_EDIT_H
