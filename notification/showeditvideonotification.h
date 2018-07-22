#pragma once

#include "../VIEWMODEL/prviewmodel.h"
#include "../VIEW/mainwindow.h"

using namespace std;

class UpdateShowEditVideoNotification: public Notification
{
private:
    shared_ptr<MainWindow> mainwindow;
public:
    UpdateShowEditVideoNotification(shared_ptr<MainWindow> mw);
    void exec();
};

class UpdateEditEnableNotification: public Notification
{
private:
    shared_ptr<PrViewModel> viewmodel;
public:
    UpdateEditEnableNorification(shared_ptr<PrViewModel> vm);
    void exec();
}
