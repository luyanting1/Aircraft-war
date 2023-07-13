#ifndef VIEWPROPERTYSINK_H
#define VIEWPROPERTYSINK_H
#include "../../common/etlbase.h"

class View;

class ViewPropertySink: public IPropertyNotification
{
public:
    ViewPropertySink(View* ctrl) throw();
    virtual void OnPropertyChanged(const std::string &str);
private:
    View *ctrl;
};
#endif //VIEWPROPERTYSINK_H
