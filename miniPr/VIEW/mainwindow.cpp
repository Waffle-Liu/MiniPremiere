#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBoxLayout>
#include <iostream>
#include "../notification/notification.h"
#include "../notification/wrongindexnotification.h"
#include "../notification/showeditvideonotification.h"
#include "../notification/showintegratewindownotification.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*ui->label->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_2->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_3->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_4->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_5->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_6->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");*/
    update_mainwindow_notification = std::static_pointer_cast<Notification, UpdateViewNotification>(std::shared_ptr<UpdateViewNotification>(new UpdateViewNotification(std::shared_ptr<MainWindow>(this))));
    show_edit_notification = std::static_pointer_cast<Notification, UpdateShowEditVideoNotification>(std::shared_ptr<UpdateShowEditVideoNotification>(new UpdateShowEditVideoNotification(std::shared_ptr<MainWindow>(this))));
    show_integrate_notification=std::static_pointer_cast<Notification, UpdateShowIntegrateWindowNotification>(std::shared_ptr<UpdateShowIntegrateWindowNotification>(new UpdateShowIntegrateWindowNotification(std::shared_ptr<MainWindow>(this))));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setAddVideoCommand(std::shared_ptr<Command> command)
{
    add_video_Command = command;
}

void MainWindow::setPlayVideoCommand(std::shared_ptr<Command> command)
{
    ptr_playvideoCommand = command;
}


void MainWindow::setRemoveVideoCommand(std::shared_ptr<Command> command)
{
    ptr_removevideoCommand = command;
}

void MainWindow::setShowEditWindowCommand(std::shared_ptr<Command> command)
{
    ptr_showeditwindowCommand = command;
}

void MainWindow::setSelectEditVideoCommand(std::shared_ptr<Command> command)
{
    ptr_selecteditvideoCommand = command;
}

void MainWindow::setIntegrateAllVideoCommand(std::shared_ptr<Command> command)
{
    ptr_integrateallvideoCommand = command;
}

void MainWindow::setShowIntegrateWindowCommand(std::shared_ptr<Command> command)
{
    ptr_showintegratewindowCommand = command;
}

std::shared_ptr<Notification> MainWindow::get_update_mainwindow_notification()
{
    return update_mainwindow_notification;
}

std::shared_ptr<Notification> MainWindow::get_show_edit_notification()
{
    return show_edit_notification;
}

std::shared_ptr<Notification> MainWindow::get_show_integrate_notification()
{
    return show_integrate_notification;
}

void MainWindow::update_load_state(const string &s)
{
    QString temp = QString::fromStdString(s);
    QMessageBox::about(0, QObject::tr("feedback"),temp);
}

void MainWindow::pop_edit_window()
{
    ptr_showeditwindowCommand->exec();
}

void MainWindow::pop_integrate_window()
{
    ptr_showintegratewindowCommand->exec();
}

//slot
void MainWindow::on_AddMedia_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Files"));
    QString temp = fileNames.join("\\");
    std::string filename = temp.toStdString();
    add_video_Command->set_parameters(std::static_pointer_cast<Parameters, PathParameters>(std::shared_ptr<PathParameters>(new PathParameters(filename))));
    add_video_Command->exec();
}

void MainWindow::on_DeleteAllMedia_clicked()
{
    ptr_removevideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(6))));
    ptr_removevideoCommand->exec();
}

//the integrated video is stored in PlayList[0]
void MainWindow::on_integrationDone_clicked()
{
    ptr_integrateallvideoCommand->exec();
}

//mediaOne ——mediaSix : editor dialog button
//return the index to the editor
void MainWindow::on_mediaOne_clicked()
{
    ptr_selecteditvideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(0))));
    ptr_selecteditvideoCommand->exec();
}

void MainWindow::on_mediaTwo_clicked()
{
    ptr_selecteditvideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(1))));
    ptr_selecteditvideoCommand->exec();
}

void MainWindow::on_mediaThree_clicked()
{
    ptr_selecteditvideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(2))));
    ptr_selecteditvideoCommand->exec();
}

void MainWindow::on_mediaFour_clicked()
{
    ptr_selecteditvideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(3))));
    ptr_selecteditvideoCommand->exec();
}

void MainWindow::on_mediaFive_clicked()
{
    ptr_selecteditvideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(4))));
    ptr_selecteditvideoCommand->exec();
}

void MainWindow::on_mediaSix_clicked()
{
    ptr_selecteditvideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(5))));
    ptr_selecteditvideoCommand->exec();
}


//mediaOne_2 —— mediaOne_7 : display button 
void MainWindow::on_mediaOne_2_clicked()
{
    ptr_playvideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(0))));
    ptr_playvideoCommand->exec();
}

void MainWindow::on_mediaOne_3_clicked()
{
    ptr_playvideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(1))));
    ptr_playvideoCommand->exec();
}

void MainWindow::on_mediaOne_4_clicked()
{
    ptr_playvideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(2))));
    ptr_playvideoCommand->exec();
}

void MainWindow::on_mediaOne_5_clicked()
{
    ptr_playvideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(3))));
    ptr_playvideoCommand->exec();
}

void MainWindow::on_mediaOne_6_clicked()
{
    ptr_playvideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(4))));
    ptr_playvideoCommand->exec();
}

void MainWindow::on_mediaOne_7_clicked()
{
    /*if(globalplay.size >= 6){
        globalplay.PlayList[5].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }*/
    ptr_playvideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(5))));
    ptr_playvideoCommand->exec();
}

//pushButton —— pushButton_8 :delete button for each video
void MainWindow::on_pushButton_clicked()
{
    ptr_removevideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(0))));
    ptr_removevideoCommand->exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    ptr_removevideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(1))));
    ptr_removevideoCommand->exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    ptr_removevideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(2))));
    ptr_removevideoCommand->exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    ptr_removevideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(3))));
    ptr_removevideoCommand->exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    ptr_removevideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(4))));
    ptr_removevideoCommand->exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    ptr_removevideoCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(5))));
    ptr_removevideoCommand->exec();
}
