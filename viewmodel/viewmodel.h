#ifndef VIEWMODEL_H
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
#include "../common/precomp.h"
#include "../base/Bullet.h"
#include "../base/EnemyPlane.h"
#include "../base/MyPlane.h"

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

    std::shared_ptr<POS>    GetPlayerPosX();
    std::shared_ptr<POS>    GetPlayerPosY();
    std::shared_ptr<SCORE>    GetPlayerScore();

    std::shared_ptr<POSES>    GetBulletsPosX();
    std::shared_ptr<POSES>    GetBulletsPosY();
    std::shared_ptr<BULLETTYPES>    GetBulletsType();

    std::shared_ptr<POSES>    GetEmemiesPosX();
    std::shared_ptr<POSES>    GetEmemiesPosY();
    std::shared_ptr<ENEMYTYPES>    GetEmemiesType();

    std::shared_ptr<POSES>  GetLifeSuppliesPosX();
    std::shared_ptr<POSES>  GetLifeSuppliesPosY();

    std::shared_ptr<BAR>    GetPlayerLife();
    std::shared_ptr<BAR>    GetPlayerSkill();

    std::shared_ptr<ICommandBase> GetAllBulletMove();
    std::shared_ptr<ICommandBase> GetBossGenerate();
    std::shared_ptr<ICommandBase> GetEnemyBulletShoot();
    std::shared_ptr<ICommandBase> GetEnemyGenerate();
    std::shared_ptr<ICommandBase> GetEnemyMove();
    std::shared_ptr<ICommandBase> GetGamePause();
    std::shared_ptr<ICommandBase> GetGameReset();
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
    std::shared_ptr<PlayerBulletShootCommand> m_cmdPlayerBulletShoot;
    std::shared_ptr<PlayerMoveCommand> m_cmdPlayerMove;
    std::shared_ptr<SkillUseCommand> m_cmdSkillUse;

    std::shared_ptr<ViewModelSink> m_sink;
};

#endif // VIEWMODEL_H
