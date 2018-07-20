#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMediaPlaylist>
#include <QMessageBox>
#include "dialog_edit.h"
#include "dialog_integratedvideo.h"
#include "VideoPlay.h"
#include "Video.h"

extern VideoPlay globalplay;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT;

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
    Ui::MainWindow *ui;
    Dialog_edit *editWindow = new Dialog_edit;
    Dialog_IntegratedVideo *integratedWindow = new Dialog_IntegratedVideo;//two sub-windows


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
