#ifndef COMMAND_H
#define COMMAND_H
#include "../Parameters/parameters.h"
#include <string>
#include <memory>
//#include "../VIEWMODEL/prviewmodel.h"
//class ViewModel;

class Command
{
protected:
    std::shared_ptr<Parameters> params;
public:
    Command();
	virtual ~Command();
    void set_parameters(std::shared_ptr<Parameters> parameters){
        params = parameters;
    }

//    Parameters& get_params_handle();
//    void set_view_model(std::shared_ptr<ViewModel> viewmodel);
    virtual void exec();
};




#endif // COMMAND_H
