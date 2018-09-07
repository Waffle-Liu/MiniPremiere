#ifndef DIALOG_INTEGRATEDVIDEO_H
#define DIALOG_INTEGRATEDVIDEO_H

#include <QDialog>
#include <iostream>
#include "../common/Video.h"
#include <QMessageBox>
#include <vector>
#include <QString>
#include <QTableWidget>
#include <QFileDialog>
#include "../common/command.h"

namespace Ui {
class Dialog_IntegratedVideo;
}

class Dialog_IntegratedVideo : public QDialog
{

	Q_OBJECT;

public:
    explicit Dialog_IntegratedVideo(QWidget *parent = 0);
    ~Dialog_IntegratedVideo();
    void setAddSubtitleCommand(std::shared_ptr<Command>);
    void setAddStickerCommand(std::shared_ptr<Command>);
    void setMirrorCommand(std::shared_ptr<Command>);
    void setRotateCommand(std::shared_ptr<Command>);
    void setAddFilterCommand(std::shared_ptr<Command>);
    void setFunnyCommand(std::shared_ptr<Command>);
    void setPlayVideoCommand(std::shared_ptr<Command>);
    void setExportVideoCommand(std::shared_ptr<Command>);
    static string filename;
private:
    Ui::Dialog_IntegratedVideo *ui;
    std::shared_ptr<Command> ptr_addsubtitleCommand;
    std::shared_ptr<Command> ptr_addstickerCommand;
    std::shared_ptr<Command> ptr_addmirrorCommand;
    std::shared_ptr<Command> ptr_addrotateCommand;
    std::shared_ptr<Command> ptr_addfilterCommand;
    std::shared_ptr<Command> ptr_addfunnyCommand;
    std::shared_ptr<Command> ptr_playvideoCommand;
    std::shared_ptr<Command> ptr_exportvideoCommand;
private slots:

	void on_pushButton_17_clicked();
	void on_preview_clicked();
	void on_pushButton_2_clicked();
	/*void on_pushButton_clicked();*/
	void on_pushButton_4_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_5_clicked();
};


#endif // DIALOG_INTEGRATEDVIDEO_H