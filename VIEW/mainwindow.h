#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include "../common/command.h"

//extern VideoPlay globalplay;

class Notification;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setAddVideoCommand(std::shared_ptr<Command>);
    //void setDeletaAllCommand(std::shared_ptr<Command> ptr_deleteall);
    void setRemoveVideoCommand(std::shared_ptr<Command>);
    /*void setDeleteTwoCommand(std::shared_ptr<Command> ptr_deletetwo);
    void setDeleteThreeCommand(std::shared_ptr<Command> ptr_deletethree);
    void setDeleteFourCommand(std::shared_ptr<Command> ptr_deletefour);
    void setDeleteFiveCommand(std::shared_ptr<Command> ptr_deletefive);
    void setDeleteSixCommand(std::shared_ptr<Command> ptr_deletesix);
    void setEditOneCommand(std::shared_ptr<Command> ptr_editone);
    void setEditTwoCommand(std::shared_ptr<Command> ptr_edittwo);
    void setEditThreeCommand(std::shared_ptr<Command> ptr_editthree);
    void setEditFourCommand(std::shared_ptr<Command> ptr_editfour);
    void setEditFiveCommand(std::shared_ptr<Command> ptr_editfive);
    void setEditSixCommand(std::shared_ptr<Command> ptr_editsix);*/
    void setPlayVideoCommand(std::shared_ptr<Command>);
    //void setIntergratedCommand(std::shared_ptr<Command> ptr_intergrated);
    std::shared_ptr<Notification> get_update_mainwindow_notification();

    void update_load_state();

private:
    Ui::MainWindow *ui;
    //Dialog_edit *editWindow = new Dialog_edit;
    //Dialog_IntegratedVideo *integratedWindow = new Dialog_IntegratedVideo;//two sub-windows
    std::shared_ptr<Command> add_video_Command;
    //std::shared_ptr<Command> ptr_deleteallCommand;
    std::shared_ptr<Command> ptr_removevideoCommand;
    /*std::shared_ptr<Command> ptr_deletetwoCommand;
    std::shared_ptr<Command> ptr_deletethreeCommand;
    std::shared_ptr<Command> ptr_deletefourCommand;
    std::shared_ptr<Command> ptr_deletefiveCommand;
    std::shared_ptr<Command> ptr_deletesixCommand;
    std::shared_ptr<Command> ptr_editoneCommand;
    std::shared_ptr<Command> ptr_edittwoCommand;
    std::shared_ptr<Command> ptr_editthreeCommand;
    std::shared_ptr<Command> ptr_editfourCommand;
    std::shared_ptr<Command> ptr_editfiveCommmand;
    std::shared_ptr<Command> ptr_editsixCommand;*/
    std::shared_ptr<Command> ptr_playvideoCommand;
    //std::shared_ptr<Command> ptr_intergratedCommand;
    std::shared_ptr<Notification> update_mainwindow_notification;

private slots :
    void on_AddMedia_clicked();
    void on_DeleteAllMedia_clicked();
    /*void on_integrationDone_clicked();
    void on_mediaOne_clicked();
    void on_mediaTwo_clicked();
    void on_mediaThree_clicked();
    void on_mediaFour_clicked();
    void on_mediaFive_clicked();
    void on_mediaSix_clicked();*/
    void on_mediaOne_2_clicked();
    void on_mediaOne_3_clicked();
    void on_mediaOne_4_clicked();
    void on_mediaOne_5_clicked();
    void on_mediaOne_6_clicked();
    void on_mediaOne_7_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
};

#endif // MAINWINDOW_H
