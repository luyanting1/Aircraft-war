#ifndef APP_H
#define APP_H
#include "../model/model.h"
#include "../viewmodel/viewmodel.h"
#include "../windows/gameview.h"
#include "view.h"
class app
{
public:
    app();
    ~app();
    std::shared_ptr<View> GetCtrl();
    std::shared_ptr<ViewModel> GetViewModel();
    void run(std::shared_ptr<QGraphicsView>);
private:
    std::shared_ptr<View> ctrl;
    std::shared_ptr<model> model_ptr;
    std::shared_ptr<ViewModel> viewmodel_ptr;
};

#endif // APP_H
