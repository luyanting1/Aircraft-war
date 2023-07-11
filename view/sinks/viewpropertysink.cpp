#include "viewpropertysink.h"
#include "../view.h"

ViewPropertySink::ViewPropertySink(View* ctrl) throw() : ctrl(ctrl)
{
}

void ViewPropertySink::OnPropertyChanged(const std::string& str)
{

}
