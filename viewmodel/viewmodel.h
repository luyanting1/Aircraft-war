#pragma once
#include "./command/frameruncommand.h"
#include "./command/playermovecommand.h"
#include "./command/gameresetcommand.h"
#include "./command/buyitemscommand.h"
#include "./command/useboomcommand.h"
#include "./sink/viewmodelsink.h"
#include "../model/model.h"
#include "../common/precomp.h"
#include "../common/etlbase.h"



class ViewModel: public Proxy_PropertyNotification<ViewModel>
{
public:
    ViewModel();
    void SetModel(const std::shared_ptr<model>& model_);
    bool CallModelFrameRun();
    bool CallModelPlayerMove(std::string direction);
    bool CallModelGameReset();
    bool CallModelGamePause();
    bool CallModelSkillUse(int skill_index);

    std::shared_ptr<POS>    GetPlayerPosX();
    std::shared_ptr<POS>    GetPlayerPosY();
    std::shared_ptr<COINS>  GetPlayerScore();

    std::shared_ptr<POS>    GetBulletsPosX();
    std::shared_ptr<POS>    GetBulletsPosY();
    std::shared_ptr<TYPES>  GetBulletsType();
    std::shared_ptr<POS>    GetEmemiesPosX();
    std::shared_ptr<POS>    GetEmemiesPosY();
    std::shared_ptr<POS>    GetEmemiesType();

    std::shared_ptr<int>    GetPlayerLife();
    std::shared_ptr<int>    GetPlayerSkill();

    std::shared_ptr<ICommandBase> GetFrameRun();
    std::shared_ptr<ICommandBase> GetPlayerMove();
    std::shared_ptr<ICommandBase> GetGameReset();
    std::shared_ptr<ICommandBase> GetGamePause();
    std::shared_ptr<ICommandBase> GetSkillUse();

private:
    std::shared_ptr<model> m_model;
    std::shared_ptr<FrameRunCommand> m_cmdFrameRun;
    std::shared_ptr<PlayerMoveCommand> m_cmdPlayerMove;
    std::shared_ptr<GameResetCommand> m_cmdGameReset;
    std::shared_ptr<GamePauseCommand> m_cmdGamePause;
    std::shared_ptr<SkillUseCommand> m_cmdSkillUse;

    std::shared_ptr<ViewModelSink> m_sink;
};

