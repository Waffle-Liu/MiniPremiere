#include "showeditvideonotification.h"

UpdateShowEditVideoNotification::UpdateShowEditVideoNotification(shared_ptr<MainWindow> mw)
{
    mainwindow = mw;
}

void UpdateShowEditVideoNotification::exec()
{
    mainwindow->pop_edit_window();
}

UpdateEditEnableNotification::UpdateEditEnableNotification(shared_ptr<PrViewModel> vm)
{
    viewmodel = vm;
}

void UpdateEditEnableNotification::exec()
{
    viewmodel->show_edit_window_notified();
}
