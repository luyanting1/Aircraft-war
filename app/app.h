﻿#ifndef APP_H
#define APP_H
#include "../model/model.h"
#include "../viewmodel/viewmodel.h"
#include "../view/view.h"

class app
{
public:
    app();
    ~app();
    View* GetCtrl();
    std::shared_ptr<ViewModel> GetViewModel();
    std::shared_ptr<model> GetModel();
    void run(QGraphicsView* game_interface);
private:
    View * ctrl;
    std::shared_ptr<model> model_ptr;
    std::shared_ptr<ViewModel> viewmodel_ptr;
};

#endif // APP_H
