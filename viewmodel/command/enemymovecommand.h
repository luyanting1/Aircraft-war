#ifndef ENEMYMOVECOMMAND_H
#define ENEMYMOVECOMMAND_H
#include "../../common/etlbase.h"
class ViewModel;

class EnemyMoveCommand : public ICommandBase
{
public:
    EnemyMoveCommand(ViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();
private:
    ViewModel* viewmodel_ptr;
    int m_param;

};

#endif // ENEMYMOVECOMMAND_H
