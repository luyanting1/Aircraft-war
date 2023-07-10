#include "enemybulletshootcommand.h"
#include "viewmodel/viewmodel.h"
EnemyBulletShootCommand::EnemyBulletShootCommand(ViewModel* p) throw():viewmodel_ptr(p)
{}

void EnemyBulletShootCommand::SetParameter(const std::any &param){
    m_param = std::any_cast<int>(param);
}

void EnemyBulletShootCommand::Exec(){
    bool b;
    b = viewmodel_ptr->CallModelEnemyBulletShoot();
}
