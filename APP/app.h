#pragma once


#include "../VIEW/mainwindow.h"
#include "../VIEW/dialog_edit.h"
#include "../VIEW/dialog_intergratedvideo.h"

#include "../MODEL/prmodel.h"
#include "../VIEWMODEL/prviewmodel.h"


class miniPrAPP
{
private:
    mainWindow _mainWindow;
    editWindow _editWindow;
    intergratedWindow _intergratedWindow;

    std::shared_ptr<PrModel> model;
    std::shared_ptr<PrViewModel> viewmodel;

public:
    miniPrAPP();
    ~miniPrAPP();
    void run();

    mainWindow *getMainWindow();
    editWindow *getEditWindow();
    intergratedWindow *getIntergratedWindow();
};
