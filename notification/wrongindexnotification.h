#pragma once

#include "../VIEWMODEL/prviewmodel.h"

using namespace std;

class WrongIndexNotification: public Notification
{
private:
    shared_ptr<MainWindow> mainwindow;
public:
    WrongIndexNotification(shared_ptr<MainWindow> mw);
    void exec();
}
