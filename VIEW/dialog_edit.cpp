#include "dialog_edit.h"
#include "ui_dialog_edit.h"

Dialog_edit::Dialog_edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_edit)
{
    ui->setupUi(this);
}

Dialog_edit::~Dialog_edit()
{
    delete ui;
}

void Dialog_edit::setSpeedConfirmCommand(std::shared_ptr<Command> ptr_speedconfirm)
{
	ptr_speedconfirmCommand = ptr_speedconfirm;
}

void Dialog_edit::setCutConfirmCommand(std::shared_ptr<Command> ptr_cutconfirm)
{
	ptr_cutconfirmCommand = ptr_cutconfirm;
}

void Dialog_edit::on_pushButton_2_clicked()//cut
{
	/*ui->pushButton->setEnabled(false);//set the button can be pressed only once
	QString startstring = ui->lineEdit->text();
	QString endstring = ui->lineEdit_2->text();
	int start = startstring.toInt();
	int end = endstring.toInt();
	
	int index = globalplay.subindex;
	globalplay.PlayList[index].cut(start, end);
	QMessageBox::about(0, QObject::tr("success"), "Edit sucessfully!");
	ui->pushButton->setEnabled(true);*/
	QString startstring = ui->lineEdit->text();
	QString endstring = ui->lineEdit_2->text();
	int start = startstring.toInt();
	int end = endstring.toInt();/*
	ptr_cutconfirmCommand->SetParameter(_new_any_space_::any_cast<double>(start));
	ptr_cutconfirmCommand->SetParameter(_new_any_space_::any_cast<double>(end));*/
	//ptr_cutconfirmCommand->Exec();
}

void Dialog_edit::on_pushButton_clicked()//change speed
{
	/*ui->pushButton->setEnabled(false);
	QString speedValue = ui->comboBox->currentText();
	double speed = speedValue.toDouble();

	globalplay.PlayList[globalplay.subindex].changeSpeed(speed);
	QMessageBox::about(0, QObject::tr("success"), "Edit sucessfully!");
	ui->pushButton->setEnabled(true);*/
	//QString speedValue = ui->comboBox->currentText();
	//double speed = speedValue.toDouble();
	//ptr_speedconfirmCommand->SetParameter(_new_any_space_::any_cast<double>(speed));
	//ptr_speedconfirmCommand->Exec();
}