#include "bossgeneratecommand.h"
#include "viewmodel/viewmodel.h"
BossGenerateCommand::BossGenerateCommand(ViewModel* p) throw():viewmodel_ptr(p)
{}

void BossGenerateCommand::SetParameter(const std::any &param){
    m_param = std::any_cast<std::string>(param);
}

void BossGenerateCommand::Exec(){
    bool b;
    b = viewmodel_ptr->CallModelBossGenerate(m_param);
}