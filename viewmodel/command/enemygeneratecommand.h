#ifndef ENEMYGENERATECOMMAND_H
#define ENEMYGENERATECOMMAND_H
#include "../../common/etlbase.h"
class ViewModel;

class EnemyGenerateCommand : public ICommandBase
{
public:
    EnemyGenerateCommand(ViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();
private:
    ViewModel* viewmodel_ptr;
    int m_param;

};

#endif // ENEMYGENERATECOMMAND_H
