#ifndef ALLBULLETMOVECOMMAND_H
#define ALLBULLETMOVECOMMAND_H
#include "../../common/etlbase.h"
class ViewModel;

class AllBulletMoveCommand : public ICommandBase
{
public:
    AllBulletMoveCommand(ViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();
private:
    ViewModel* viewmodel_ptr;
    int m_param;

};
#endif // ALLBULLETMOVECOMMAND_H
