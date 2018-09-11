#include "wrongindexnotification.h"

UpdateViewNotification::UpdateViewNotification(shared_ptr<MainWindow> mw)
{
    mainwindow = mw;
}

void UpdateViewNotification::exec()
{
	std::string str = std::static_pointer_cast<PathParameters, Parameters>(Notification::params)->get_path();
    mainwindow->update_load_state(str);
}

UpdateInfoNotification::UpdateInfoNotification(shared_ptr<PrViewModel> vm) : viewmodel(vm)
{
}

void UpdateInfoNotification::exec()
{
	std::string str = std::static_pointer_cast<PathParameters, Parameters>(Notification::params)->get_path();
	viewmodel->update_view_notified(str);
}
