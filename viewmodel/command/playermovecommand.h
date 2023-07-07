#ifndef PLAYERMOVECOMMAND_H
#define PLAYERMOVECOMMAND_H
#include "../../common/etlbase.h"
class ViewModel;

class PlayerMoveCommand : public ICommandBase
{
public:
    PlayerMoveCommand(ViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();
private:
    ViewModel* viewmodel_ptr;
    int m_param;

};

#endif // PLAYERMOVECOMMAND_H
