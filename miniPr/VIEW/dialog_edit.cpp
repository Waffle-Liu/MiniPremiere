#include "dialog_edit.h"
#include "ui_dialog_edit.h"
#include "..\notification\showeditvideonotification.h"

Dialog_edit::Dialog_edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_edit)
{
    ui->setupUi(this);
    //pop_window_notification = std::static_pointer_cast<Notification, UpdateView>(std::shared_ptr<UpdateShowEditVideoNotification>(new UpdateShowEditVideoNotification(std::shared_ptr<MainWindow>(this))));
}

Dialog_edit::~Dialog_edit()
{
    delete ui;
}

void Dialog_edit::setSpeedChangeCommand(std::shared_ptr<Command> command)
{
	ptr_speedchangeCommand = command;
}

void Dialog_edit::setCutVideoCommand(std::shared_ptr<Command> command)
{
	ptr_cutvideoCommand = command;
}

void Dialog_edit::setTransModeCommand(std::shared_ptr<Command> command)
{
	ptr_transmodeCommand = command;
}

std::shared_ptr<Notification> Dialog_edit::get_pop_window_notification()
{
	return pop_window_notification;
}

/*void Dialog_edit::pop_window(const std::string &tip)
{
	QMessageBox::about(0, QObject::tr("feedback"),tip);
}*/

void Dialog_edit::on_pushButton_2_clicked()//cut
{
	QString startstring = ui->lineEdit->text();
	QString endstring = ui->lineEdit_2->text();
	int start = startstring.toInt();
	int end = endstring.toInt();
	ptr_cutvideoCommand->set_parameters(std::static_pointer_cast<Parameters, Int2Parameters>(std::shared_ptr<Int2Parameters>(new Int2Parameters(start, end))));
	ptr_cutvideoCommand->exec();
}

void Dialog_edit::on_pushButton_clicked()//change speed
{
	QString speedValue = ui->comboBox->currentText();
	double speed = speedValue.toDouble();
	ptr_speedchangeCommand->set_parameters(std::static_pointer_cast<Parameters, DoubleParameters>(std::shared_ptr<DoubleParameters>(new DoubleParameters(speed))));
	ptr_speedchangeCommand->exec();
}

void Dialog_edit::on_pushButton_3_clicked()//trans mode
{
	if(ui->checkBox->isChecked())
	{
		ptr_transmodeCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(2))));
		ptr_transmodeCommand->exec();
	}

	else if(ui->checkBox_5->isChecked())
	{
		ptr_transmodeCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(11))));
		ptr_transmodeCommand->exec();
	}

	else if(ui->checkBox_2->isChecked())
	{
		ptr_transmodeCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(8))));
		ptr_transmodeCommand->exec();
	}

	else if(ui->checkBox_3->isChecked())
	{
		ptr_transmodeCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(9))));
		ptr_transmodeCommand->exec();
	}

	else if(ui->checkBox_4->isChecked())
	{
		ptr_transmodeCommand->set_parameters(std::static_pointer_cast<Parameters, IntParameters>(std::shared_ptr<IntParameters>(new IntParameters(10))));
		ptr_transmodeCommand->exec();
	}
}