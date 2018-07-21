#pragma once

#include <memory>

#include "../VIEW/mainwindow.h"
#include "../VIEW/dialog_edit.h"
#include "../VIEW/dialog_intergratedvideo.h"

#include "../MODEL/prmodel.h"
#include "../VIEWMODEL/prviewmodel.h"

#include "commands/addmediacommand.h"


class miniPrAPP
{
private:
    MainWindow _mainWindow;
    Dialog_edit _editWindow;
    Dialog_IntergratedVideo _intergratedWindow;

    std::shared_ptr<PrModel> model;
    std::shared_ptr<PrViewModel> viewmodel;
    
    std::shared_ptr<AddMediaCommand> _spAddMediaCommand;

public:
    miniPrAPP();
    ~miniPrAPP();
    void run();

    MainWindow *getMainWindow();
    Dialog_edit *getEditWindow();
    Dialog_IntergratedVideo *getIntergratedWindow();
};
