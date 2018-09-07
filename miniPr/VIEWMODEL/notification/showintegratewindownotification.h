#pragma once

#include "../prviewmodel.h"
#include "../../VIEW/mainwindow.h"

using namespace std;

class UpdateShowIntegrateWindowNotification: public Notification
{
private:
    shared_ptr<MainWindow> mainwindow;
public:
    UpdateShowIntegrateWindowNotification(shared_ptr<MainWindow> mw);
    void exec();
};

class UpdateIntegrateCompleteNotification: public Notification
{
private:
    shared_ptr<PrViewModel> viewmodel;
public:
    UpdateIntegrateCompleteNotification(shared_ptr<PrViewModel> vm);
    void exec();
};
