#include "dialog_edit.h"
#include "ui_dialog_edit.h"

Dialog_edit::Dialog_edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_edit)
{
    ui->setupUi(this);
    pop_window_notification = std::static_pointer_cast<Notification, PopWindowNotification>(std::shared_ptr<PopWindowNotification>(new PopWindowNotification(std::shared_ptr<MainWindow>(this))));
}

Dialog_edit::~Dialog_edit()
{
    delete ui;
}

void Dialog_edit::setSpeedChangeCommand(std::shared_ptr<Command> command)
{
	ptr_speedchangeCommand = command;
}

/*void Dialog_edit::setCutConfirmCommand(std::shared_ptr<Command> ptr_cutconfirm)
{
	ptr_cutconfirmCommand = ptr_cutconfirm;
}*/

std::shared_ptr<Notification> Dialog_edit::get_pop_window_notification()
{
	return pop_window_notification;
}

void Dialog_edit::pop_window(const string &tip)
{
	QMessageBox::about(0, QObject::tr("feedback"),tip);
}

void Dialog_edit::on_pushButton_2_clicked()//cut
{

}

void Dialog_edit::on_pushButton_clicked()//change speed
{
	QString speedValue = ui->comboBox->currentText();
	double speed = speedValue.toDouble();
	ptr_speedchangeCommand->set_parameters(std::static_pointer_cast<Parameters, DoubleParameters>(std::shared_ptr<DoubleParameters>(new DoubleParameters(speed))));
	ptr_speedchangeCommand->exec();
}