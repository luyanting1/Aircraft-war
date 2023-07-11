#ifndef APP_H
#define APP_H
#include "../model/model.h"
#include "../viewmodel/viewmodel.h"
#include "../view/view.h"

class app
{
public:
    app();
    ~app();
    std::shared_ptr<View> GetCtrl();
    std::shared_ptr<ViewModel> GetViewModel();
    void run(QGraphicsView* game_interface);
private:
    std::shared_ptr<View> ctrl;
    std::shared_ptr<model> model_ptr;
    std::shared_ptr<ViewModel> viewmodel_ptr;
};

#endif // APP_H
