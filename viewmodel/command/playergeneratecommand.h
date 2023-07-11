#ifndef PLAYERGENERATECOMMAND_H
#define PLAYERGENERATECOMMAND_H
#include "../../common/etlbase.h"
class ViewModel;

class PlayerGenerateCommand : public ICommandBase
{
public:
    PlayerGenerateCommand(ViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();
private:
    ViewModel* viewmodel_ptr;
    int m_param;

};

#endif // PLAYERGENERATECOMMAND_H
