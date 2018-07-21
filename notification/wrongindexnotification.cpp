#include "wrongindexnotification.h"

WrongIndexNotification::WrongIndexNotification(shared_ptr<MainWindow> mw)
{
    mainwindow = mw;
}

void WrongIndexNotification::exec()
{
    mainwindow->update_load_state();
}
