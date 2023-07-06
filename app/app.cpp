#include "app.h"
#include "iostream"
app::app(){}
app::~app(){}

void app::run(){


    model_ptr = std::make_shared<model>();
    viewmodel_ptr = std::make_shared<ViewModel>();
    viewmodel_ptr->SetModel(model_ptr);

    _mainwindow.SetPlayerPosX(viewmodel_ptr->GetPlayerPosX());
    _mainwindow.SetPlayerPosY(viewmodel_ptr->GetPlayerPosY());
    _mainwindow.SetPlayerScore(viewmodel_ptr->GetPlayerScore());

    //notifications
    viewmodel_ptr->AddPropertyNotification(_mainwindow.get_updateSink());

    _mainwindow.show();
}

view* app::GetMainWindow(){
    return &_mainwindow;
}

std::shared_ptr<ViewModel> app::GetViewModel(){
    return viewmodel_ptr;
}
