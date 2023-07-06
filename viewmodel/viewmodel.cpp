#include "viewmodel.h"

ViewModel::ViewModel():
    m_cmdFrameRun(std::make_shared<FrameRunCommand>(this)),
    m_cmdPlayerMove(std::make_shared<PlayerMoveCommand>(this)),
    m_cmdGameReset(std::make_shared<GameResetCommand>(this)),
    m_cmdBuyItems(std::make_shared<BuyItemsCommand>(this)),
    m_cmdSkillUse(std::make_shared<SkillUseCommand>(this)),
    m_sink(std::make_shared<ViewModelSink>(this))
{}

void ViewModel::SetModel(const std::shared_ptr<model> &model_){
    m_model = model_;
    m_model->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(m_sink));
//    todo : notification
}

bool ViewModel::CallModelFrameRun(){
    return m_model->framerun();
}

bool ViewModel::CallModelPlayerMove(std::string direction){
    return m_model->playermove(direction);
}

bool ViewModel::CallModelGameReset(){
    return m_model->gamereset();
}

bool ViewModel::CallModelGamePause(){
    return m_model->gamepause();
}

bool ViewModel::CallModelGameQuit(){
    return m_model->gamequit();
}

bool ViewModel::CallModelSkillUse(int skill_index){
    return m_model->skilluse(skill_index);
}

std::shared_ptr<ICommandBase> ViewModel::GetFrameRun(){
    return std::static_pointer_cast<ICommandBase>(m_cmdFrameRun);
}

std::shared_ptr<ICommandBase> ViewModel::GetPlayerMove(){
    return std::static_pointer_cast<ICommandBase>(m_cmdPlayerMove);
}

std::shared_ptr<ICommandBase> ViewModel::GetGameReset(){
    return std::static_pointer_cast<ICommandBase>(m_cmdGameReset);
}

std::shared_ptr<ICommandBase> ViewModel::GetGamePause(){
    return std::static_pointer_cast<ICommandBase>(m_cmdGamePause);
}

std::shared_ptr<ICommandBase> ViewModel::GetSkillUse(){
    return std::static_pointer_cast<ICommandBase>(m_cmdSkillUse);
}

std::shared_ptr<POS> ViewModel::GetPlayerPosX(){
    return m_model->GetPlayerPosx();
}

std::shared_ptr<POS> ViewModel::GetPlayerPosY(){
    return m_model->GetPlayerPosy();
}

std::shared_ptr<SCORE> ViewModel::GetPlayerScore(){
    return m_model->GetPlayerScore();
}

std::shared_ptr<POS> ViewModel::GetBulletsPosX(){
    return m_model->GetBulletPosx();
}

std::shared_ptr<POS> ViewModel::GetBulletsPosY(){
    return m_model->GetBulletPosy();
}

std::shared_ptr<POS> ViewModel::GetEmemiesPosX(){
    return m_model->GetEnemyPosx();
}

std::shared_ptr<POS> ViewModel::GetEmemiesPosY(){
    return m_model->GetEnemyPosy();
}

std::shared_ptr<POS> ViewModel::GetEmemiesType(){
    return m_model->GetEnemyType();
}

std::shared_ptr<TYPES> ViewModel::GetBulletsType(){
    return m_model->GetBulletType();
}

std::shared_ptr<int>  ViewModel::GetPlayerLife(){
    return m_model->GetPlayerLife();
}

std::shared_ptr<int>  ViewModel::GetPlayerSkill(){
    return m_model->GetPlayerSkill();
}