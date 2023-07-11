#ifndef VIEWPROPERTYSINK_H
#define VIEWPROPERTYSINK_H
#include "../../common/etlbase.h"

class view;

class ViewPropertySink: public IPropertyNotification
{
public:
    ViewPropertySink(view* ctrl);
    virtual void OnPropertyChanged(const std::string &str);
private:
    view *ctrl;
};
#endif //VIEWPROPERTYSINK_H
