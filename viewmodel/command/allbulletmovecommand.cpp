#include "allbulletmovecommand.h"
#include "viewmodel/viewmodel.h"
AllBulletMoveCommand::AllBulletMoveCommand(ViewModel* p) throw():viewmodel_ptr(p)
{}

void AllBulletMoveCommand::SetParameter(const std::any &param){
    m_param = std::any_cast<int>(param);
}

void AllBulletMoveCommand::Exec(){
    bool b;
    b = viewmodel_ptr->CallModelAllBulletMove(m_param);
}
