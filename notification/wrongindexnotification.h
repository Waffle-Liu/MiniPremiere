#pragma once

#include "../VIEWMODEL/prviewmodel.h"
#include "../VIEW/mainwindow.h"

using namespace std;

class UpdateViewNotification: public Notification
{
private:
    shared_ptr<MainWindow> mainwindow;
public:
    UpdateViewNotification(shared_ptr<MainWindow> mw);
    void exec();
};


class UpdateIndexErrorNotification : public Notification
{
private:
	shared_ptr<PrViewModel> viewmodel;
public:
	UpdateIndexErrorNotification(shared_ptr<PrViewModel> vm);
	void exec();
};