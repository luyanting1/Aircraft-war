#ifndef FRAMERUNCOMMAND_H
#define FRAMERUNCOMMAND_H

#include "../../common/etlbase.h"

class ViewModel;
// use for player and enemy's bullet, enemy generate, enemy move
class FrameRunCommand: public ICommandBase
{
public:
    FrameRunCommand(ViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();
private:
    ViewModel* viewmodel_ptr;
    int m_param;
};

#endif  //   FRAMERUNCOMMAND_H
