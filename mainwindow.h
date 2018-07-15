#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QMediaPlaylist>
#include "dialog_edit.h"
#include "dialog_integratedvideo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addToPlaylist(const QStringList& fileNames);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QMediaPlaylist *playlist;
    QString m_fileName;
    QMediaPlayer::State m_playerState;
    Dialog_edit * editWindow = new Dialog_edit;
    Dialog_IntegratedVideo *integratedWindow = new Dialog_IntegratedVideo;//two sub-windows

private slots:
    void on_AddMedia_clicked();
    void on_DeleteMedia_clicked();
    void on_DeleteAllMedia_clicked();
    void on_integrationDone_clicked();
    void on_mediaOne_clicked();
    void on_mediaTwo_clicked();
    void on_mediaThree_clicked();
    void on_mediaFour_clicked();
    void on_mediaFive_clicked();
    void on_mediaSix_clicked();
};

#endif // MAINWINDOW_H
