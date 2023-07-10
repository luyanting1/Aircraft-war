#include "viewmodelsink.h"
#include "../viewmodel.h"
ViewModelSink::ViewModelSink(ViewModel *p) throw():viewmodel_ptr(p)
{
}

void ViewModelSink::OnPropertyChanged(const std::string &str){
    viewmodel_ptr->Fire_OnPropertyChanged(str);
}
