#pragma once

#include <memory>

#include "../VIEW/mainwindow.h"
#include "../VIEW/dialog_edit.h"
#include "../VIEW/dialog_integratedvideo.h"

#include "../MODEL/prmodel.h"
#include "../VIEWMODEL/prviewmodel.h"

#include "commands/addvideocommand.h"
#include "commands/playvideocommand.h"
#include "commands/removevideocommand.h"
#include "commands/selecteditvideocommand.h"
#include "commands/showeditwindowcommand.h"
#include "commands/speedchangecommand.h"


class miniPrAPP
{
private:
    MainWindow _mainWindow;
    Dialog_edit _editWindow;
//    Dialog_IntegratedVideo _integratedWindow;

    std::shared_ptr<PrModel> model;
    std::shared_ptr<PrViewModel> viewmodel;

    std::shared_ptr<ShowEditWindowCommand> _spShowEditWindowCommand;


public:
    miniPrAPP();
    ~miniPrAPP();
    void run();

    MainWindow *getMainWindow();
    Dialog_edit *getEditWindow();
//    Dialog_IntegratedVideo *getIntegratedWindow();
};
