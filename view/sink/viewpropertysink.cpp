#include "viewpropertysink.h"
#include <exception>
#include "../view.h"

ViewPropertySink::ViewPropertySink(View* ctrl) throw() : ctrl(ctrl)
{
}

void ViewPropertySink::OnPropertyChanged(const std::string& str)
{
    try{
    ctrl->changescene();
    }catch(std::exception ex){
        qDebug() <<ex.what();
    }

}
