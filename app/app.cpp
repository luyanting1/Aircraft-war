#include "app.h"
#include "iostream"
app::app(){}
app::~app(){}

void app::run(QGraphicsView* game_interface){//std::shared_ptr<QGraphicsView> game_interface){

    //std::shared_ptr<View>ctrl = make_shared<View>();
    View *ctrl = new View();
    //std::shared_ptr<QGraphicsScene> game_ctrl = static_pointer_cast<QGraphicsScene>(ctrl);
    game_interface->setScene(ctrl);//game_ctrl.get());
    game_interface->setBackgroundBrush(QBrush(QPixmap("://images/background1.png")));
    game_interface->show();

    model_ptr = std::make_shared<model>();
    viewmodel_ptr = std::make_shared<ViewModel>();
    viewmodel_ptr->SetModel(model_ptr);

    ctrl->SetPlayerPosX(viewmodel_ptr->GetPlayerPosX());
    ctrl->SetPlayerPosY(viewmodel_ptr->GetPlayerPosY());
    ctrl->SetPlayerScore(viewmodel_ptr->GetPlayerScore());
    ctrl->SetBulletsPosX(viewmodel_ptr->GetBulletsPosX());
    ctrl->SetBulletsPosY(viewmodel_ptr->GetBulletsPosY());
    ctrl->SetBulletsType(viewmodel_ptr->GetBulletsType());
    ctrl->SetEnemiesPosX(viewmodel_ptr->GetEmemiesPosX());
    ctrl->SetEnemiesPosY(viewmodel_ptr->GetEmemiesPosY());
    ctrl->SetEnemiesType(viewmodel_ptr->GetEmemiesType());
    ctrl->SetLifeSuppliesPosX(viewmodel_ptr->GetLifeSuppliesPosX());
    ctrl->SetLifeSuppliesPosY(viewmodel_ptr->GetLifeSuppliesPosY());
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
    model_ptr->AddPropertyNotification(ctrl->GetPropertySink());
    viewmodel_ptr->AddPropertyNotification(ctrl->GetPropertySink());

}

std::shared_ptr<View> app::GetCtrl(){
    return ctrl;
}

std::shared_ptr<ViewModel> app::GetViewModel(){
    return viewmodel_ptr;
}
