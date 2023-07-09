#include "playermovecommand.h"
#include "viewmodel/viewmodel.h"
PlayerMoveCommand::PlayerMoveCommand(ViewModel* p) throw():viewmodel_ptr(p)
{}

void PlayerMoveCommand::SetParameter(const std::any &param){
    m_param = std::any_cast<char>(param);
}

void PlayerMoveCommand::Exec(){
    bool b;
    b = viewmodel_ptr->CallModelPlayerMove(m_param);
}
