#pragma once

#include "..\common\stdafx.h"
#include "..\Parameters\parameters.h"

class Notification
{
protected:
	std::shared_ptr<Parameters> params;
public:
    Notification();
    ~Notification();
	void set_parameters(std::shared_ptr<Parameters> parameters);
    virtual void exec();
};
