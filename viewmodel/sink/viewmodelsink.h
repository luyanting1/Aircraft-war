#ifndef VIEWMODELSINK_H
#define VIEWMODELSINK_H
#include "../../common/etlbase.h"
#include "../viewmodel.h"
#include "../../view/view.h"

class ViewModelSink:public IPropertyNotification
{
public:
    ViewModelSink(ViewModel *vmp, View * vp) throw();
    virtual void OnPropertyChanged(const std::string& str);
private:
    ViewModel* viewmodel_ptr;
    View* ctrl;
};

#endif // VIEWMODELSINK_H
