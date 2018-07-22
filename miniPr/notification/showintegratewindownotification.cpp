#include "showintegratewindownotification.h"

UpdateShowIntegrateWindowNotification::UpdateShowIntegrateWindowNotification(shared_ptr<MainWindow> mw)
{
    mainwindow = mw;
}

void UpdateShowEditVideoNotification::exec()
{
    mainwindow->pop_integrate_window();
}

UpdateIntegrateCompleteNotification::UpdateIntegrateCompleteNotification(shared_ptr<PrViewModel> vm)
{
    viewmodel = vm;
}

void UpdateEditEnableNotification::exec()
{
    viewmodel->show_integrate_window_notified();
}
