#include "playerbulletshootcommand.h"
#include "viewmodel/viewmodel.h"
PlayerBulletShootCommand::PlayerBulletShootCommand(ViewModel* p) throw():viewmodel_ptr(p)
{}

void PlayerBulletShootCommand::SetParameter(const std::any &param){
    m_param = std::any_cast<int>(param);
}

void PlayerBulletShootCommand::Exec(){
    bool b;
    b = viewmodel_ptr->CallModelPlayerBulletShoot(m_param);
}
