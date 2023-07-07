#ifndef PLAYERBULLETSHOOTCOMMAND_H
#define PLAYERBULLETSHOOTCOMMAND_H
#include "../../common/etlbase.h"
class ViewModel;

class PlayerBulletShootCommand : public ICommandBase
{
public:
    PlayerBulletShootCommand(ViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();
private:
    ViewModel* viewmodel_ptr;
    int m_param;

};

#endif // PLAYERBULLETSHOOTCOMMAND_H
