#pragma once

#include <memory>
#include "../VIEWMODEL/prviewmodel.h"


class Notification
{
public:
    Notification();
    ~Notification();
    virtual void exec();
};
