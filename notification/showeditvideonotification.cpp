#include "showeditvideonotification.h"

UpdateShowEditVideoNotification::UpdateShowEditVideoNotification(shared_ptr<MainWindow> mw)
{
    mainwindow = mw;
}

void UpdateShowEditVideoNotification::exec()
{
    mainwindow->pop_edit_window();
}

UpdateEditEnableNorification::UpdateEditEnableNorification(shared_ptr<PrViewModel> vm)
{
    viewmodel = vm;
}

void UpdateEditEnableNorification::exec()
{
    viewmodel->show_edit_window_notified();
}
