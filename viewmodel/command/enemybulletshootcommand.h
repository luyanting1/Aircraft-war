#ifndef ENEMYBULLETSHOOTCOMMAND_H
#define ENEMYBULLETSHOOTCOMMAND_H
#include "../../common/etlbase.h"
class ViewModel;

class EnemyBulletShootCommand : public ICommandBase
{
public:
    EnemyBulletShootCommand(ViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();
private:
    ViewModel* viewmodel_ptr;
    int m_param;

};

#endif // ENEMYBULLETSHOOTCOMMAND_H
