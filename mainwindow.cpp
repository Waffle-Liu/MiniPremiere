#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_playerState(QMediaPlayer::StoppedState)
{
    ui->setupUi(this);

    //QWidget *widget=new QWidget;//set a QWidget for displaying video

    player = new QMediaPlayer;//create a player object
    playlist = new QMediaPlaylist;//create a play list
    player->setPlaylist(playlist);//realize the binding between player and playlist
    videoWidget = new QVideoWidget;

    //black background for VideoWidget
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,Qt::black);
    videoWidget->setPalette(*palette);
    videoWidget->setAutoFillBackground(true);
    delete palette;

    player->setVideoOutput(videoWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//slot
void MainWindow::on_AddMedia_clicked()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Files"));
    addToPlaylist(fileNames);
    playlist->setCurrentIndex(0);
    m_playerState = QMediaPlayer::PlayingState;
    videoWidget->show();
    player->play();
}

void MainWindow::on_DeleteMedia_clicked()
{

}

void MainWindow::on_DeleteAllMedia_clicked()
{

}

void MainWindow::on_integrationDone_clicked()
{
    integratedWindow->show();
}


void MainWindow::on_mediaOne_clicked()
{
    editWindow->show();
}

void MainWindow::on_mediaTwo_clicked()
{
    editWindow->show();
}

void MainWindow::on_mediaThree_clicked()
{
    editWindow->show();
}

void MainWindow::on_mediaFour_clicked()
{
    editWindow->show();
}

void MainWindow::on_mediaFive_clicked()
{
    editWindow->show();
}

void MainWindow::on_mediaSix_clicked()
{
    editWindow->show();
}

void MainWindow::addToPlaylist(const QStringList& fileNames)
{
    foreach(QString const &argument, fileNames){
        QFileInfo fileInfo(argument);
        if(fileInfo.exists()){
            QUrl url = QUrl::fromLocalFile(fileInfo.absoluteFilePath());
            if(fileInfo.suffix().toLower() == QLatin1String("m3u")){
                playlist->load(url);
            }
            else{
                playlist->addMedia(url);
            }
        }
        else{
            QUrl url(argument);
            if(url.isValid()){
                playlist->addMedia(url);
            }
        }
    }
}



