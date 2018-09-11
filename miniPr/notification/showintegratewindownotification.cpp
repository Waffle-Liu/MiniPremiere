#include "showintegratewindownotification.h"

UpdateShowIntegrateWindowNotification::UpdateShowIntegrateWindowNotification(shared_ptr<MainWindow> mw)
{
    mainwindow = mw;
}

void UpdateShowIntegrateWindowNotification::exec()
{
    mainwindow->pop_integrate_window();
}

UpdateIntegrateCompleteNotification::UpdateIntegrateCompleteNotification(shared_ptr<PrViewModel> vm)
{
    viewmodel = vm;
}

void UpdateIntegrateCompleteNotification::exec()
{
    viewmodel->show_integrate_window_notified();
}
