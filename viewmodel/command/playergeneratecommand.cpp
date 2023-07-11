#include "playergeneratecommand.h"
#include "viewmodel/viewmodel.h"
PlayerGenerateCommand::PlayerGenerateCommand(ViewModel* p) throw():viewmodel_ptr(p)
{}

void PlayerGenerateCommand::SetParameter(const std::any &param){
    m_param = std::any_cast<int>(param);
}

void PlayerGenerateCommand::Exec(){
    bool b;
    b = viewmodel_ptr->CallModelPlayerGenerate();
}
