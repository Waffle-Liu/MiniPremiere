#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBoxLayout>
#include <iostream>


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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setAddVideoCommand(std::shared_ptr<Command> command)
{
    add_video_Command = command;
}

//slot
void MainWindow::on_AddMedia_clicked()
{
    /*QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Files"));
    QString temp = fileNames.join("\\");
    String filename = temp.toStdString();


    Video tempvideo(filename);
    globalplay.PlayList.push_back(tempvideo);
    globalplay.FileList.push_back(filename);
    globalplay.size = (int)globalplay.PlayList.size();

    //设置交互图片告知是否成功导入子视频图片
    if (globalplay.size == 0){
    }
    else if(globalplay.size == 1){
        ui->label->setStyleSheet("border-image:url(:/images/images/load2.jpg)");
    }
    else if(globalplay.size == 2){
        ui->label_2->setStyleSheet("border-image:url(:/images/images/load2.jpg)");
    }
    else if(globalplay.size == 3){
        ui->label_3->setStyleSheet("border-image:url(:/images/images/load2.jpg)");
    }
    else if(globalplay.size == 4){
        ui->label_4->setStyleSheet("border-image:url(:/images/images/load2.jpg)");
    }
    else if(globalplay.size == 5){
        ui->label_5->setStyleSheet("border-image:url(:/images/images/load2.jpg)");
    }
    else if(globalplay.size == 6){
        ui->label_6->setStyleSheet("border-image:url(:/images/images/load2.jpg)");
    }
    else 
        QMessageBox::about(0, QObject::tr("fail"), "can not load video any more");

    globalplay.PlayList[globalplay.size - 1].play();//play current video*/

    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Files"));
    QString temp = fileNames.join("\\");
    std::string filename = temp.toStdString();
    add_video_Command->set_parameters(std::static_pointer_cast<Parameters, PathParameters>(std::shared_ptr<PathParameters>(new PathParameters(filename))));
    add_video_Command->exec();
}

/*void MainWindow::on_DeleteAllMedia_clicked()
{
    ui->label->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_2->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_3->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_4->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_5->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_6->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");

    if (globalplay.size == 0) QMessageBox::about(0, QObject::tr("fail"), "no video to delete");
    else {
        globalplay.PlayList.clear();
        globalplay.size = 0;
    }
    
    
}

void MainWindow::on_integrationDone_clicked()//the integrated video is stored in PlayList[0]
{
    ui->integrationDone->setEnabled(false);
    int i;
    for (i = globalplay.size - 1; i > 0; i--)
    {
        globalplay.PlayList[i - 1].link(globalplay.PlayList[i]);
    }
    integratedWindow->show();
    globalplay.PlayList[0].play();
    ui->pushButton->setEnabled(true);
}


//mediaOne ——mediaSix : editor dialog button
//return the index to the editor
void MainWindow::on_mediaOne_clicked()
{
    globalplay.subindex = 0;
    if (globalplay.subindex + 1 <= globalplay.size)
        editWindow->show();
    else
        QMessageBox::about(0, QObject::tr("fail"), "NO VIDEO LOADED: can not edit the vedio");
}

void MainWindow::on_mediaTwo_clicked()
{
    globalplay.subindex = 1;
    if (globalplay.subindex + 1 <= globalplay.size)
        editWindow->show();
    else
        QMessageBox::about(0, QObject::tr("fail"), "NO VIDEO LOADED: can not edit the vedio");
}

void MainWindow::on_mediaThree_clicked()
{
    globalplay.subindex = 2;
    if (globalplay.subindex + 1 <= globalplay.size)
        editWindow->show();
    else
        QMessageBox::about(0, QObject::tr("fail"), "NO VIDEO LOADED: can not edit the vedio");
}

void MainWindow::on_mediaFour_clicked()
{
    globalplay.subindex = 3;
    if (globalplay.subindex + 1 <= globalplay.size)
        editWindow->show();
    else
        QMessageBox::about(0, QObject::tr("fail"), "NO VIDEO LOADED: can not edit the vedio");
}

void MainWindow::on_mediaFive_clicked()
{
    globalplay.subindex = 4;
    if (globalplay.subindex + 1 <= globalplay.size)
        editWindow->show();
    else
        QMessageBox::about(0, QObject::tr("fail"), "NO VIDEO LOADED: can not edit the vedio");
}

void MainWindow::on_mediaSix_clicked()
{
    globalplay.subindex = 5;
    if (globalplay.subindex + 1 <= globalplay.size)
        editWindow->show();
    else
        QMessageBox::about(0, QObject::tr("fail"), "NO VIDEO LOADED: can not edit the vedio");
}


//mediaOne_2 —— mediaOne_7 : display button 
void MainWindow::on_mediaOne_2_clicked()
{
    if(globalplay.size >= 1){
        globalplay.PlayList[0].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }
}

void MainWindow::on_mediaOne_3_clicked()
{
    if(globalplay.size  >= 2){
        globalplay.PlayList[1].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }
}

void MainWindow::on_mediaOne_4_clicked()
{
    if(globalplay.size >= 3){
        globalplay.PlayList[2].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }
}

void MainWindow::on_mediaOne_5_clicked()
{
    if(globalplay.size >= 4){
        globalplay.PlayList[3].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }
}

void MainWindow::on_mediaOne_6_clicked()
{
    if(globalplay.size >= 5){
        globalplay.PlayList[4].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }
}

void MainWindow::on_mediaOne_7_clicked()
{
    if(globalplay.size >= 6){
        globalplay.PlayList[5].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }
}

//pushButton —— pushButton_8 :delete button for each video
void MainWindow::on_pushButton_clicked()
{
    if(globalplay.size<1){
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
        return;
    }
    if(globalplay.size ==1){
        ui->label->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size ==2){
        ui->label_2->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size ==3){
        ui->label_3->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size ==4){
        ui->label_4->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size ==5){
        ui->label_5->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size ==6){
        ui->label_6->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }

    globalplay.PlayList.erase(globalplay.PlayList.begin());
    globalplay.size--;

}

void MainWindow::on_pushButton_4_clicked()
{
    if(globalplay.size < 2){
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
        return;
    }
    if(globalplay.size == 2){
        ui->label_2->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size == 3){
        ui->label_3->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size == 4){
        ui->label_4->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size == 5){
        ui->label_5->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size == 6){
        ui->label_6->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }

    globalplay.PlayList.erase(globalplay.PlayList.begin()+1);
    globalplay.size--;
}

void MainWindow::on_pushButton_5_clicked()
{
    if(globalplay.size<3){
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
        return;
    }
    if(globalplay.size ==3){
        ui->label_3->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size ==4){
        ui->label_4->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size ==5){
        ui->label_5->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size ==6){
        ui->label_6->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }

    globalplay.PlayList.erase(globalplay.PlayList.begin()+2);
    globalplay.size--;
}

void MainWindow::on_pushButton_6_clicked()
{
    if(globalplay.size<4){
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
        return;
    }
    if(globalplay.size ==4){
        ui->label_4->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size ==5){
        ui->label_5->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size ==6){
        ui->label_6->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }

    globalplay.PlayList.erase(globalplay.PlayList.begin()+3);
    globalplay.size--;
}

void MainWindow::on_pushButton_7_clicked()
{
    if(globalplay.size<5){
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
        return;
    }
    if(globalplay.size ==5){
        ui->label_5->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }
    if(globalplay.size ==6){
        ui->label_6->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }

    globalplay.PlayList.erase(globalplay.PlayList.begin()+4);
    globalplay.size--;
}

void MainWindow::on_pushButton_8_clicked()
{
    if(globalplay.size<6){
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
        return;
    }
    if(globalplay.size ==6){
        ui->label_6->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }

    globalplay.PlayList.erase(globalplay.PlayList.begin()+5);
    globalplay.size--;
}
*/