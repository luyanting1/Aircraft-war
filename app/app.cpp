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
    _mainwindow.SetBulletsPosX(viewmodel_ptr->GetBulletsPosX());
    _mainwindow.SetBulletsPosY(viewmodel_ptr->GetBulletsPosY());
    _mainwindow.SetBulletsType(viewmodel_ptr->GetBulletsType());
    _mainwindow.SetEnemiesPosX(viewmodel_ptr->GetEmemiesPosX());
    _mainwindow.SetEnemiesPosY(viewmodel_ptr->GetEmemiesPosY());
    _mainwindow.SetEnemiesType(viewmodel_ptr->GetEmemiesType());
    _mainwindow.SetPlayerLife(viewmodel_ptr->GetPlayerLife());
    _mainwindow.SetPlayerSkill(viewmodel_ptr->GetPlayerSkill());

    //commands
    _mainwindow.SetAllBulletMoveCommand(viewmodel_ptr->GetAllBulletMove());
    _mainwindow.SetBossGenerateCommand(viewmodel_ptr->GetBossGenerate());
    _mainwindow.SetEnemyBulletShootCommand(viewmodel_ptr->GetEnemyBulletShoot());
    _mainwindow.SetEnemyGenerateCommand(viewmodel_ptr->GetEnemyGenerate());
    _mainwindow.SetEnemyMoveCommand(viewmodel_ptr->GetEnemyMove());
    _mainwindow.SetGamePauseCommand(viewmodel_ptr->GetGamePause());
    _mainwindow.SetGameResetCommand(viewmodel_ptr->GetGameReset());
    _mainwindow.SetPlayerBulletShootCommand(viewmodel_ptr->GetPlayerBulletShoot());
    _mainwindow.SetPlayerMoveCommand(viewmodel_ptr->GetPlayerMove());
    _mainwindow.SetSkillUseCommand(viewmodel_ptr->GetSkillUse());

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
