﻿#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "./command/allbulletmovecommand.h"
#include "./command/bossgeneratecommand.h"
#include "./command/enemybulletshootcommand.h"
#include "./command/enemygeneratecommand.h"
#include "./command/enemymovecommand.h"
#include "./command/gamepausecommand.h"
#include "./command/gameresetcommand.h"
#include "./command/playergeneratecommand.h"
#include "./command/playerbulletshootcommand.h"
#include "./command/playermovecommand.h"
#include "./command/skillusecommand.h"
#include "./sink/viewmodelsink.h"
#include "../model/model.h"
#include "../common/etlbase.h"
#include "../common/common.h"

class ViewModelSink;
class ViewModel: public Proxy_PropertyNotification<ViewModel>
{
public:
    ViewModel();
    void SetModel(const std::shared_ptr<model>& model_);
    bool CallModelAllBulletMove();
    bool CallModelBossGenerate();
    bool CallModelEnemyBulletShoot();
    bool CallModelEnemyGenerate();
    bool CallModelEnemyMove();
    bool CallModelGamePause();
    bool CallModelGameReset();
    bool CallModelPlayerGenerate();
    bool CallModelPlayerBulletShoot();
    bool CallModelPlayerMove(char direction);
    bool CallModelSkillUse(int skill_index);

    std::shared_ptr<Object> GetMyPlane();

    std::shared_ptr<OBJECTS> GetEnemiesPlane();

    std::shared_ptr<OBJECTS> GetBullets();

    std::shared_ptr<OBJECTS> GetLifeSupplies();

    std::shared_ptr<SCORE> GetPlayerScore();

    std::shared_ptr<BAR> GetPlayerLife();
    std::shared_ptr<BAR> GetPlayerSkill();

    std::shared_ptr<ICommandBase> GetAllBulletMove();
    std::shared_ptr<ICommandBase> GetBossGenerate();
    std::shared_ptr<ICommandBase> GetEnemyBulletShoot();
    std::shared_ptr<ICommandBase> GetEnemyGenerate();
    std::shared_ptr<ICommandBase> GetEnemyMove();
    std::shared_ptr<ICommandBase> GetGamePause();
    std::shared_ptr<ICommandBase> GetGameReset();
    std::shared_ptr<ICommandBase> GetPlayerGenerate();
    std::shared_ptr<ICommandBase> GetPlayerBulletShoot();
    std::shared_ptr<ICommandBase> GetPlayerMove();
    std::shared_ptr<ICommandBase> GetSkillUse();

private:
    std::shared_ptr<model> m_model;
    std::shared_ptr<AllBulletMoveCommand> m_cmdAllBulletMove;
    std::shared_ptr<BossGenerateCommand> m_cmdBossGenerate;
    std::shared_ptr<EnemyBulletShootCommand> m_cmdEnemyBulletShoot;
    std::shared_ptr<EnemyGenerateCommand> m_cmdEnemyGenerate;
    std::shared_ptr<EnemyMoveCommand> m_cmdEnemyMove;
    std::shared_ptr<GamePauseCommand> m_cmdGamePause;
    std::shared_ptr<GameResetCommand> m_cmdGameReset;
    std::shared_ptr<PlayerGenerateCommand> m_cmdPlayerGenerate;
    std::shared_ptr<PlayerBulletShootCommand> m_cmdPlayerBulletShoot;
    std::shared_ptr<PlayerMoveCommand> m_cmdPlayerMove;
    std::shared_ptr<SkillUseCommand> m_cmdSkillUse;

    std::shared_ptr<ViewModelSink> m_propertysink;
};

#endif // VIEWMODEL_H
