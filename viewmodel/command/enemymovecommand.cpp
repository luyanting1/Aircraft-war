#include "enemymovecommand.h"
#include "viewmodel/viewmodel.h"
EnemyMoveCommand::EnemyMoveCommand(ViewModel* p) throw():viewmodel_ptr(p)
{}

void EnemyMoveCommand::SetParameter(const std::any &param){
    m_param = std::any_cast<int>(param);
}

void EnemyMoveCommand::Exec(){
    bool b;
    b = viewmodel_ptr->CallModelEnemyMove();
}
