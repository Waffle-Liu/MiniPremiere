#ifndef DIALOG_EDIT_H
#define DIALOG_EDIT_H



#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <string>
#include "../common/command.h"
#include "../notification/notification.h"
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
    void setSpeedChangeCommand(std::shared_ptr<Command>);
    void setCutVideoCommand(std::shared_ptr<Command>);
    void setTransModeCommand(std::shared_ptr<Command>);
    std::shared_ptr<Notification> get_pop_window_notification();
    //void pop_window(const std::string &tip);

private:
    Ui::Dialog_edit *ui;
    std::shared_ptr<Command> ptr_speedchangeCommand;
    std::shared_ptr<Command> ptr_cutvideoCommand;
    std::shared_ptr<Command> ptr_transmodeCommand;
    std::shared_ptr<Notification> pop_window_notification;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
};

#endif // DIALOG_EDIT_H
