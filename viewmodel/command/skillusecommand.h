#ifndef FRAMERUNCOMMAND_H
#define FRAMERUNCOMMAND_H

#include "../../common/etlbase.h"

class ViewModel;
// use for player skill, such as shoot mode change, bomb
class SkillUseCommand: public ICommandBase
{
public:
    SkillUseCommand(ViewModel* p) throw();
    virtual void SetParameter(const std::any &param);
    virtual void Exec();
private:
    ViewModel* viewmodel_ptr;
    int m_param;
};

#endif SKILLUSECOMMAND_H