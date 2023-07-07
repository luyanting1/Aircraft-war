#include "enemygeneratecommand.h"
#include "viewmodel/viewmodel.h"
EnemyGenerateCommand::EnemyGenerateCommand(ViewModel* p) throw():viewmodel_ptr(p)
{}

void EnemyGenerateCommand::SetParameter(const std::any &param){
    m_param = std::any_cast<std::string>(param);
}

void EnemyGenerateCommand::Exec(){
    bool b;
    b = viewmodel_ptr->CallModelEnemyGenerate(m_param);
}