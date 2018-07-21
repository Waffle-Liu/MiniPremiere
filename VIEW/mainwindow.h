#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMediaPlaylist>
#include <QMessageBox>
//#include "dialog_edit.h"
//#include "dialog_integratedvideo.h"
//#include "VideoPlay.h"
//#include "Video.h"
#include "../common/etlbase.h"

//extern VideoPlay globalplay;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT;

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
    void setAddMediaCommand(std::shared_ptr<ICommandBase> ptr_addmedia);
    void setDeletaAllCommand(std::shared_ptr<ICommandBase> ptr_deleteall);
    void setDeleteOneCommand(std::shared_ptr<ICommandBase> ptr_deleteone);
    void setDeleteTwoCommand(std::shared_ptr<ICommandBase> ptr_deletetwo);
    void setDeleteThreeCommand(std::shared_ptr<ICommandBase> ptr_deletethree);
    void setDeleteFourCommand(std::shared_ptr<ICommandBase> ptr_deletefour);
    void setDeleteFiveCommand(std::shared_ptr<ICommandBase> ptr_deletefive);
    void setDeleteSixCommand(std::shared_ptr<ICommandBase> ptr_deletesix);
    void setEditOneCommand(std::shared_ptr<ICommandBase> ptr_editone);
    void setEditTwoCommand(std::shared_ptr<ICommandBase> ptr_edittwo);
    void setEditThreeCommand(std::shared_ptr<ICommandBase> ptr_editthree);
    void setEditFourCommand(std::shared_ptr<ICommandBase> ptr_editfour);
    void setEditFiveCommand(std::shared_ptr<ICommandBase> ptr_editfive);
    void setEditSixCommand(std::shared_ptr<ICommandBase> ptr_editsix);
    void setDisplayOneCommand(std::shared_ptr<ICommandBase> ptr_displayone);
    void setDisplayTwoCommand(std::shared_ptr<ICommandBase> ptr_displaytwo);
    void setDisplayThreeCommand(std::shared_ptr<ICommandBase> ptr_displaythree);
    void setDisplayFourCommand(std::shared_ptr<ICommandBase> ptr_displayfour);
    void setDisplayFiveCommand(std::shared_ptr<ICommandBase> ptr_displayfive);
    void setDisplaySixCommand(std::shared_ptr<ICommandBase> ptr_displaysix);
    void setIntergratedCommand(std::shared_ptr<ICommandBase> ptr_intergrated);

private:
    Ui::MainWindow *ui;
    //Dialog_edit *editWindow = new Dialog_edit;
    //Dialog_IntegratedVideo *integratedWindow = new Dialog_IntegratedVideo;//two sub-windows
    std::shared_ptr<ICommandBase> ptr_addmediaCommand;
    std::shared_ptr<ICommandBase> ptr_deleteallCommand;
    std::shared_ptr<ICommandBase> ptr_deleteoneCommand;
    std::shared_ptr<ICommandBase> ptr_deletetwoCommand;
    std::shared_ptr<ICommandBase> ptr_deletethreeCommand;
    std::shared_ptr<ICommandBase> ptr_deletefourCommand;
    std::shared_ptr<ICommandBase> ptr_deletefiveCommand;
    std::shared_ptr<ICommandBase> ptr_deletesixCommand;
    std::shared_ptr<ICommandBase> ptr_editoneCommand;
    std::shared_ptr<ICommandBase> ptr_edittwoCommand;
    std::shared_ptr<ICommandBase> ptr_editthreeCommand;
    std::shared_ptr<ICommandBase> ptr_editfourCommand;
    std::shared_ptr<ICommandBase> ptr_editfiveCommmand;
    std::shared_ptr<ICommandBase> ptr_editsixCommand;
    std::shared_ptr<ICommandBase> ptr_displayoneCommand;
    std::shared_ptr<ICommandBase> ptr_displaytwoCommand;
    std::shared_ptr<ICommandBase> ptr_displaythreeCommand;
    std::shared_ptr<ICommandBase> ptr_displayfourCommand;
    std::shared_ptr<ICommandBase> ptr_displayfiveCommand;
    std::shared_ptr<ICommandBase> ptr_displaysixCommand;
    std::shared_ptr<ICommandBase> ptr_intergratedCommand;

private slots :
    void on_AddMedia_clicked();
    void on_DeleteAllMedia_clicked();
    void on_integrationDone_clicked();
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
