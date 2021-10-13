#ifndef COMMAND_INCLUDE
#define COMMAND_INCLUDE

#include "material.h"
#include <vector>

class Command
{
public:
    virtual ~Command() {}

    virtual void execute(std::vector<Material*>& t_mats) =0;
    virtual void undo() = 0;
protected:
    Command() {};
};

#endif