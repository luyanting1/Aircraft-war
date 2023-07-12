#include "viewmodelsink.h"

ViewModelSink::ViewModelSink(ViewModel *vmp) throw():viewmodel_ptr(vmp)
{
}

void ViewModelSink::OnPropertyChanged(const std::string &str){
    viewmodel_ptr->Fire_OnPropertyChanged("str");
}
