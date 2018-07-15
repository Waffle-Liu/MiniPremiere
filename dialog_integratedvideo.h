#ifndef DIALOG_INTEGRATEDVIDEO_H
#define DIALOG_INTEGRATEDVIDEO_H

#include <QDialog>

namespace Ui {
class Dialog_IntegratedVideo;
}

class Dialog_IntegratedVideo : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_IntegratedVideo(QWidget *parent = 0);
    ~Dialog_IntegratedVideo();

private:
    Ui::Dialog_IntegratedVideo *ui;
};

#endif // DIALOG_INTEGRATEDVIDEO_H
