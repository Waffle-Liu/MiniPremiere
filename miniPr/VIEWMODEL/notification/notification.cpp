#include "notification.h"

Notification::Notification()
{
	params = nullptr;
}

Notification::~Notification()
{
}

void Notification::set_parameters(std::shared_ptr<Parameters> parameters)
{
	params = parameters;
}

void Notification::exec()
{
}
