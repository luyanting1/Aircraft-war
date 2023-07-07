#ifndef GAMEPAUSECOMMAND_H
#define GAMEPAUSECOMMAND_H

#include "../../common/etlbase.h"

class ViewModel;

class GamePauseCommand: public ICommandBase
{
public:
    GamePauseCommand(ViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();

private:
    ViewModel* viewmodel_ptr;
    int m_param;
};

#endif // GAMEPAUSECOMMAND_H
