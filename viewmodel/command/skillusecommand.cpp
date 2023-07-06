#include "skillusecommand.h"
#include "viewmodel/viewmodel.h"

SkillUseCommand::SkillUseCommand(ViewModel* p) throw():viewmodel_ptr(p)
{}

void SkillUseCommand::SetParameter(const std::any &param){
    m_param = std::any_cast<int>(param);
}


void SkillUseCommand::Exec(){
    bool b;
    b = viewmodel_ptr->CallModelSkillUse(m_param);
}
