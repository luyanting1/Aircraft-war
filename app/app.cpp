﻿#include "app.h"
#include "iostream"
app::app(){}
app::~app(){}

void app::run(QGraphicsView* game_interface){//std::shared_ptr<QGraphicsView> game_interface){

    //std::shared_ptr<View>ctrl = make_shared<View>();
    ctrl = new View();
    //std::shared_ptr<QGraphicsScene> game_ctrl = static_pointer_cast<QGraphicsScene>(ctrl);
    game_interface->setScene(ctrl);//game_ctrl.get());
    game_interface->setBackgroundBrush(QBrush(QPixmap("://images/background1.png")));
    game_interface->show();

    model_ptr = std::make_shared<model>();
    viewmodel_ptr = std::make_shared<ViewModel>();
    viewmodel_ptr->SetModel(model_ptr);

    ctrl->SetMyPlane(viewmodel_ptr->GetMyPlane());
    ctrl->SetEnemiesPlane(viewmodel_ptr->GetEnemiesPlane());
    ctrl->SetBullets(viewmodel_ptr->GetBullets());
    ctrl->SetLifeSupplies(viewmodel_ptr->GetLifeSupplies());
    ctrl->SetPlayerScore(viewmodel_ptr->GetPlayerScore());
    ctrl->SetPlayerLife(viewmodel_ptr->GetPlayerLife());
    ctrl->SetPlayerSkill(viewmodel_ptr->GetPlayerSkill());

    //commands
    ctrl->SetAllBulletMoveCommand(viewmodel_ptr->GetAllBulletMove());
    ctrl->SetBossGenerateCommand(viewmodel_ptr->GetBossGenerate());
    ctrl->SetEnemyBulletShootCommand(viewmodel_ptr->GetEnemyBulletShoot());
    ctrl->SetEnemyGenerateCommand(viewmodel_ptr->GetEnemyGenerate());
    ctrl->SetEnemyMoveCommand(viewmodel_ptr->GetEnemyMove());
    ctrl->SetGamePauseCommand(viewmodel_ptr->GetGamePause());
    ctrl->SetGameResetCommand(viewmodel_ptr->GetGameReset());
    ctrl->SetPlayerGenerateCommand(viewmodel_ptr->GetPlayerGenerate());
    ctrl->SetPlayerBulletShootCommand(viewmodel_ptr->GetPlayerBulletShoot());
    ctrl->SetPlayerMoveCommand(viewmodel_ptr->GetPlayerMove());
    ctrl->SetSkillUseCommand(viewmodel_ptr->GetSkillUse());

    //notifications
    viewmodel_ptr->AddPropertyNotification(ctrl->GetPropertySink());

}

View* app::GetCtrl(){
    return ctrl;
}

std::shared_ptr<ViewModel> app::GetViewModel(){
    return viewmodel_ptr;
}

std::shared_ptr<model> app::GetModel(){
    return model_ptr;
}
