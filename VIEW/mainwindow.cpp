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

void MainWindow::setAddMediaCommand(std::shared_ptr<ICommandBase> ptr_addmedia)
{
    ptr_addmediaCommand = ptr_addmedia;
}

void MainWindow::setDeletaAllCommand(std::shared_ptr<ICommandBase> ptr_deleteall)
{
    ptr_deleteallCommand = ptr_deleteall;
}

void MainWindow::setDeleteOneCommand(std::shared_ptr<ICommandBase> ptr_deleteone)
{
    ptr_deleteoneCommand = ptr_deleteone;
}

void MainWindow::setDeleteTwoCommand(std::shared_ptr<ICommandBase> ptr_deletetwo)
{
    ptr_deletetwoCommand = ptr_deletetwo;
}

void MainWindow::setDeleteThreeCommand(std::shared_ptr<ICommandBase> ptr_deletethree)
{
    ptr_deletethreeCommand = ptr_deletethree;
}
    
void MainWindow::setDeleteFourCommand(std::shared_ptr<ICommandBase> ptr_deletefour)
{
    ptr_deletefourCommand = ptr_deletefour;
}
    
void MainWindow::setDeleteFiveCommand(std::shared_ptr<ICommandBase> ptr_deletefive)
{
    ptr_deletefiveCommand = ptr_deletefive;
}
    
void MainWindow::setDeleteSixCommand(std::shared_ptr<ICommandBase> ptr_deletesix)
{
    ptr_deletesixCommand = ptr_deletesix;
}
    
void MainWindow::setEditOneCommand(std::shared_ptr<ICommandBase> ptr_editone)
{
    ptr_editoneCommand = ptr_editone;
}

void MainWindow::setEditTwoCommand(std::shared_ptr<ICommandBase> ptr_edittwo)
{
    ptr_edittwoCommand = ptr_edittwo;
}

void MainWindow::setEditThreeCommand(std::shared_ptr<ICommandBase> ptr_editthree)
{
    ptr_editthreeCommand = ptr_editthree;
}

void MainWindow::setEditFourCommand(std::shared_ptr<ICommandBase> ptr_editfour)
{
    ptr_editfourCommand = ptr_editfour;
}

void MainWindow::setEditFiveCommand(std::shared_ptr<ICommandBase> ptr_editfive)
{
    ptr_editfiveCommand = ptr_editfive;
}

void MainWindow::setEditSixCommand(std::shared_ptr<ICommandBase> ptr_editsix)
{
    ptr_editsixCommand = ptr_editsix;
}

void MainWindow::setDisplayOneCommand(std::shared_ptr<ICommandBase> ptr_displayone)
{
    ptr_displayoneCommand = ptr_displayone;
}

void MainWindow::setDisplayTwoCommand(std::shared_ptr<ICommandBase> ptr_displaytwo)
{
    ptr_displaytwoCommand = ptr_displaytwo;
}

void MainWindow::setDisplayThreeCommand(std::shared_ptr<ICommandBase> ptr_displaythree)
{
    ptr_displaythreeCommand = ptr_displaythree;
}

void MainWindow::setDisplayFourCommand(std::shared_ptr<ICommandBase> ptr_displayfour)
{
    ptr_displaytfourCommand = ptr_displayfour;
}

void MainWindow::setDisplayFiveCommand(std::shared_ptr<ICommandBase> ptr_displayfive)
{
    ptr_displayfiveCommand = ptr_displayfive;
}

void MainWindow::setDisplaySixCommand(std::shared_ptr<ICommandBase> ptr_displaysix)
{
    ptr_displaysixCommand = ptr_displaysix;
}

void MainWindow::setIntergratedCommand(std::shared_ptr<ICommandBase> ptr_intergrated)
{
    ptr_intergratedCommand = ptr_intergrated;
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
    ptr_addmediaCommand->Exec();
}

void MainWindow::on_DeleteAllMedia_clicked()
{
    /*ui->label->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_2->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_3->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_4->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_5->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    ui->label_6->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");

	if (globalplay.size == 0) QMessageBox::about(0, QObject::tr("fail"), "no video to delete");
	else {
		globalplay.PlayList.clear();
		globalplay.size = 0;
	}*/
	
	ptr_deleteallCommand->Exec();
}

void MainWindow::on_integrationDone_clicked()//the integrated video is stored in PlayList[0]
{
	/*ui->integrationDone->setEnabled(false);
	int i;
	for (i = globalplay.size - 1; i > 0; i--)
	{
		globalplay.PlayList[i - 1].link(globalplay.PlayList[i]);
	}
    integratedWindow->show();
	globalplay.PlayList[0].play();
	ui->pushButton->setEnabled(true);*/
    ptr_intergratedCommand->Exec();
}


//mediaOne ——mediaSix : editor dialog button
//return the index to the editor
void MainWindow::on_mediaOne_clicked()
{
	/*globalplay.subindex = 0;
	if (globalplay.subindex + 1 <= globalplay.size)
		editWindow->show();
	else
		QMessageBox::about(0, QObject::tr("fail"), "NO VIDEO LOADED: can not edit the vedio");*/
    ptr_editoneCommand->Exec();
}

void MainWindow::on_mediaTwo_clicked()
{
	/*globalplay.subindex = 1;
	if (globalplay.subindex + 1 <= globalplay.size)
		editWindow->show();
	else
		QMessageBox::about(0, QObject::tr("fail"), "NO VIDEO LOADED: can not edit the vedio");*/
    ptr_edittwoCommand->Exec();
}

void MainWindow::on_mediaThree_clicked()
{
	/*globalplay.subindex = 2;
	if (globalplay.subindex + 1 <= globalplay.size)
		editWindow->show();
	else
		QMessageBox::about(0, QObject::tr("fail"), "NO VIDEO LOADED: can not edit the vedio");*/
    ptr_editthreeCommand->Exec();
}

void MainWindow::on_mediaFour_clicked()
{
	/*globalplay.subindex = 3;
	if (globalplay.subindex + 1 <= globalplay.size)
		editWindow->show();
	else
		QMessageBox::about(0, QObject::tr("fail"), "NO VIDEO LOADED: can not edit the vedio");*/
    ptr_editfourCommand->Exec();
}

void MainWindow::on_mediaFive_clicked()
{
	/*globalplay.subindex = 4;
	if (globalplay.subindex + 1 <= globalplay.size)
		editWindow->show();
	else
		QMessageBox::about(0, QObject::tr("fail"), "NO VIDEO LOADED: can not edit the vedio");*/
    ptr_editfiveCommand->Exec();
}

void MainWindow::on_mediaSix_clicked()
{
	/*globalplay.subindex = 5;
	if (globalplay.subindex + 1 <= globalplay.size)
		editWindow->show();
	else
		QMessageBox::about(0, QObject::tr("fail"), "NO VIDEO LOADED: can not edit the vedio");*/
    ptr_editsixCommand->Exec();
}


//mediaOne_2 —— mediaOne_7 : display button 
void MainWindow::on_mediaOne_2_clicked()
{
    /*if(globalplay.size >= 1){
		globalplay.PlayList[0].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }*/
    ptr_displayoneCommand->Exec();
}

void MainWindow::on_mediaOne_3_clicked()
{
    /*if(globalplay.size  >= 2){
		globalplay.PlayList[1].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }*/
    ptr_displaytwoCommand->Exec();
}

void MainWindow::on_mediaOne_4_clicked()
{
    /*if(globalplay.size >= 3){
		globalplay.PlayList[2].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }*/
    ptr_displaythreeCommand->Exec();
}

void MainWindow::on_mediaOne_5_clicked()
{
    /*if(globalplay.size >= 4){
		globalplay.PlayList[3].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }*/
    ptr_displaytfourCommand->Exec();
}

void MainWindow::on_mediaOne_6_clicked()
{
    /*if(globalplay.size >= 5){
		globalplay.PlayList[4].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }*/
    ptr_displayfiveCommand->Exec();
}

void MainWindow::on_mediaOne_7_clicked()
{
    /*if(globalplay.size >= 6){
		globalplay.PlayList[5].play();
    }
    else{
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
    }*/
    ptr_displaysixCommand->Exec();
}

//pushButton —— pushButton_8 :delete button for each video
void MainWindow::on_pushButton_clicked()
{
    /*if(globalplay.size<1){
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
	globalplay.size--;*/
    ptr_deleteoneCommand->Exec();

}

void MainWindow::on_pushButton_4_clicked()
{
    /*if(globalplay.size < 2){
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
	globalplay.size--;*/
    ptr_deletetwoCommand->Exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    /*if(globalplay.size<3){
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
	globalplay.size--;*/
    ptr_deletethreeCommand->Exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    /*if(globalplay.size<4){
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
	globalplay.size--;*/
    ptr_deletefourCommand->Exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    /*if(globalplay.size<5){
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
	globalplay.size--;*/
    ptr_deletefiveCommand->Exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    /*if(globalplay.size<6){
        QMessageBox::about(0,QObject::tr("fail"),"此处子视频未导入");
        return;
    }
    if(globalplay.size ==6){
        ui->label_6->setStyleSheet("border-image:url(:/images/images/nothing.jpg)");
    }

	globalplay.PlayList.erase(globalplay.PlayList.begin()+5);
	globalplay.size--;*/
    ptr_deletesixCommand->Exec();
}




