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
    void setShowEditWindowCommand(std::shared_ptr<Command>);
    void setSelectEditVideoCommand(std::shared_ptr<Command>);
    void setPlayVideoCommand(std::shared_ptr<Command>);
    void setIntegrateAllVideoCommand(std::shared_ptr<Command>);
    void setShowIntegrateWindowCommand(std::shared_ptr<Command>);
    //void setIntergratedCommand(std::shared_ptr<Command> ptr_intergrated);
    std::shared_ptr<Notification> get_update_mainwindow_notification();
    std::shared_ptr<Notification> get_show_edit_notification();
    std::shared_ptr<Notification> get_show_integrate_notification();

    void update_load_state(const std::string&);
    void pop_edit_window();
    void pop_integrate_window();

private:
    Ui::MainWindow *ui;
    //Dialog_edit *editWindow = new Dialog_edit;
    //Dialog_IntegratedVideo *integratedWindow = new Dialog_IntegratedVideo;//two sub-windows
    std::shared_ptr<Command> add_video_Command;
    //std::shared_ptr<Command> ptr_deleteallCommand;
    std::shared_ptr<Command> ptr_removevideoCommand;
    std::shared_ptr<Command> ptr_showeditwindowCommand;
    srd::shared_ptr<Command> ptr_showintegratewindowCommand;
    std::shared_ptr<Command> ptr_selecteditvideoCommand;
    std::shared_ptr<Command> ptr_playvideoCommand;
    std::shared_ptr<Command> ptr_integrateallvideoCommand;
    std::shared_ptr<Notification> update_mainwindow_notification;
    std::shared_ptr<Notification> show_edit_notification;
    std::shared_ptr<Notification> show_integrate_notification;

private slots :
    void on_AddMedia_clicked();
    void on_DeleteAllMedia_clicked();
    //void on_integrationDone_clicked();
    void on_mediaOne_clicked();
    void on_mediaTwo_clicked();
    void on_mediaThree_clicked();
    void on_mediaFour_clicked();
    void on_mediaFive_clicked();
    void on_mediaSix_clicked();
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
