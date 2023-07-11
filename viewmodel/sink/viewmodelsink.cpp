#include "viewmodelsink.h"

ViewModelSink::ViewModelSink(ViewModel *vmp, View * vp) throw():viewmodel_ptr(vmp), ctrl(vp)
{
}

void ViewModelSink::OnPropertyChanged(const std::string &str){
    if (str == "myplane") {
        ctrl->SetPlayerPosX(viewmodel_ptr->GetPlayerPosX());
        ctrl->SetPlayerPosY(viewmodel_ptr->GetPlayerPosY());
        ctrl->SetPlayerScore(viewmodel_ptr->GetPlayerScore());
    }

    if (str == "allbullet" || str == "bullet") {
        ctrl->SetBulletsPosX(viewmodel_ptr->GetBulletsPosX());
        ctrl->SetBulletsPosY(viewmodel_ptr->GetBulletsPosY());
        ctrl->SetBulletsType(viewmodel_ptr->GetBulletsType());
    }
    if (str == "enemy") {
        ctrl->SetEnemiesPosX(viewmodel_ptr->GetEnemiesPosX());
        ctrl->SetEnemiesPosY(viewmodel_ptr->GetEnemiesPosY());
        ctrl->SetEnemiesType(viewmodel_ptr->GetEnemiesType());
    }
    if (str == "allbullet") {
        ctrl->SetLifeSuppliesPosX(viewmodel_ptr->GetLifeSuppliesPosX());
        ctrl->SetLifeSuppliesPosY(viewmodel_ptr->GetLifeSuppliesPosY());
        ctrl->SetPlayerLife(viewmodel_ptr->GetPlayerLife());
    }

    if (str == "skill"){
        ctrl->SetPlayerSkill(viewmodel_ptr->GetPlayerSkill());
    }
}
