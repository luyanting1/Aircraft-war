#ifndef BOSSGENERATECOMMAND_H
#define BOSSGENERATECOMMAND_H
#include "../../common/etlbase.h"
class ViewModel;

class BossGenerateCommand : public ICommandBase
{
public:
    BossGenerateCommand(ViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();
private:
    ViewModel* viewmodel_ptr;
    int m_param;

};

#endif // BOSSGENERATECOMMAND_H
