#include "wrongindexnotification.h"

UpdateViewNotification::UpdateViewNotification(shared_ptr<MainWindow> mw)
{
    mainwindow = mw;
}

void UpdateViewNotification::exec()
{
    mainwindow->update_load_state();
}

UpdateIndexErrorNotification::UpdateIndexErrorNotification(shared_ptr<PrViewModel> vm) : viewmodel(vm)
{
}

void UpdateIndexErrorNotification::exec()
{
	viewmodel->index_error_notified();
}
