#pragma once

#include "../prviewmodel.h"
#include "../../VIEW/mainwindow.h"

using namespace std;

class UpdateViewNotification: public Notification
{
private:
    shared_ptr<MainWindow> mainwindow;
public:
    UpdateViewNotification(shared_ptr<MainWindow> mw);
    void exec();
};


class UpdateInfoNotification : public Notification
{
private:
	shared_ptr<PrViewModel> viewmodel;
public:
	UpdateInfoNotification(shared_ptr<PrViewModel> vm);
	void exec();
};