#include "viewmodel.h"

ViewModel::ViewModel():
    m_cmdAllBulletMove(std::make_shared<AllBulletMoveCommand>(this)),
    m_cmdBossGenerate(std::make_shared<BossGenerateCommand>(this)),
    m_cmdEnemyBulletShoot(std::make_shared<EnemyBulletShootCommand>(this)),
    m_cmdEnemyGenerate(std::make_shared<EnemyGenerateCommand>(this)),
    m_cmdEnemyMove(std::make_shared<EnemyMoveCommand>(this)),
    m_cmdGamePause(std::make_shared<GamePauseCommand>(this)),
    m_cmdGameReset(std::make_shared<GameResetCommand>(this)),
    m_cmdPlayerGenerate(std::make_shared<PlayerGenerateCommand>(this)),
    m_cmdPlayerBulletShoot(std::make_shared<PlayerBulletShootCommand>(this)),
    m_cmdPlayerMove(std::make_shared<PlayerMoveCommand>(this)),
    m_cmdSkillUse(std::make_shared<SkillUseCommand>(this))
{}

void ViewModel::SetModel(const std::shared_ptr<model> &model_){
    m_model = model_;
    //m_model->AddPropertyNotification(std::static_pointer_cast<IPropertyNotification>(m_propertysink));
}

void ViewModel::SetView(View* & view_){
    m_view = view_;
m_propertysink = std::make_shared<ViewModelSink>(this, m_view);
}

bool ViewModel::CallModelAllBulletMove(){
    return m_model->allbulletmove();
}

bool ViewModel::CallModelBossGenerate(){
    return m_model->bossgenerate();
}

bool ViewModel::CallModelEnemyBulletShoot(){
    return m_model->enemybulletshoot();
}

bool ViewModel::CallModelEnemyGenerate(){
    return m_model->enemygenerate();
}

bool ViewModel::CallModelEnemyMove(){
    return m_model->enemymove();
}

bool ViewModel::CallModelGamePause(){
    return true;
    //return m_model->gamepause();
}

bool ViewModel::CallModelGameReset(){
    return m_model->gamereset();
}

bool ViewModel::CallModelPlayerGenerate(){
    return m_model->playergenerate();
}

bool ViewModel::CallModelPlayerBulletShoot(){
    return m_model->playerbulletshoot();
}

bool ViewModel::CallModelPlayerMove(char direction){
    return m_model->playermove(direction);
}

bool ViewModel::CallModelSkillUse(int skill_index){
    return m_model->skilluse(skill_index);
}

std::shared_ptr<ICommandBase> ViewModel::GetAllBulletMove(){
    return std::static_pointer_cast<ICommandBase>(m_cmdAllBulletMove);
}

std::shared_ptr<ICommandBase> ViewModel::GetBossGenerate(){
    return std::static_pointer_cast<ICommandBase>(m_cmdBossGenerate);
}

std::shared_ptr<ICommandBase> ViewModel::GetEnemyBulletShoot(){
    return std::static_pointer_cast<ICommandBase>(m_cmdEnemyBulletShoot);
}

std::shared_ptr<ICommandBase> ViewModel::GetEnemyGenerate(){
    return std::static_pointer_cast<ICommandBase>(m_cmdEnemyGenerate);
}

std::shared_ptr<ICommandBase> ViewModel::GetEnemyMove(){
    return std::static_pointer_cast<ICommandBase>(m_cmdEnemyMove);
}

std::shared_ptr<ICommandBase> ViewModel::GetGamePause(){
    return std::static_pointer_cast<ICommandBase>(m_cmdGamePause);
}

std::shared_ptr<ICommandBase> ViewModel::GetGameReset(){
    return std::static_pointer_cast<ICommandBase>(m_cmdGameReset);
}

std::shared_ptr<ICommandBase> ViewModel::GetPlayerGenerate(){
    return std::static_pointer_cast<ICommandBase>(m_cmdPlayerGenerate);
}

std::shared_ptr<ICommandBase> ViewModel::GetPlayerBulletShoot(){
    return std::static_pointer_cast<ICommandBase>(m_cmdPlayerBulletShoot);
}

std::shared_ptr<ICommandBase> ViewModel::GetPlayerMove(){
    return std::static_pointer_cast<ICommandBase>(m_cmdPlayerMove);
}

std::shared_ptr<ICommandBase> ViewModel::GetSkillUse(){
    return std::static_pointer_cast<ICommandBase>(m_cmdSkillUse);
}

std::shared_ptr<Object> ViewModel::GetMyPlane(){
    return m_model->GetMyPlane();
}

std::shared_ptr<OBJECTS> ViewModel::GetEnemiesPlane(){
    return m_model->GetEnemiesPlane();
}

std::shared_ptr<OBJECTS> ViewModel::GetBullets(){
    return m_model->GetBullets();
}

std::shared_ptr<OBJECTS> ViewModel::GetLifeSupplies(){
    return m_model->GetLifeSupplies();
}

std::shared_ptr<SCORE> ViewModel::GetPlayerScore(){
    return m_model->GetPlayerScore();
}

std::shared_ptr<BAR>  ViewModel::GetPlayerLife(){
    return m_model->GetPlayerLife();
}

std::shared_ptr<BAR>  ViewModel::GetPlayerSkill(){
    return m_model->GetPlayerSkill();
}
