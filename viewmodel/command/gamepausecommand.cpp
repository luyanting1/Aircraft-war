#include "gamepausecommand.h"
#include "viewmodel/viewmodel.h"
GamePauseCommand::GamePauseCommand(ViewModel *p) throw():viewmodel_ptr(p)
{}

void GamePauseCommand::SetParameter(const std::any &param){
    m_param = std::any_cast<int>(param);
}


void GamePauseCommand::Exec(){
    bool b;
    b = viewmodel_ptr->CallModelGamePause();
}
