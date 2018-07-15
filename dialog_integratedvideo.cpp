#include "dialog_integratedvideo.h"
#include "ui_dialog_integratedvideo.h"

Dialog_IntegratedVideo::Dialog_IntegratedVideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_IntegratedVideo)
{
    ui->setupUi(this);
}

Dialog_IntegratedVideo::~Dialog_IntegratedVideo()
{
    delete ui;
}
