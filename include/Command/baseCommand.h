#ifndef BASE_COMMAND_INCLUDE
#define BASE_COMMAND_INCLUDE

#include <Materials/baseMaterial.h>
#include <vector>

class Command
{
public:

    virtual void execute() = 0;

    virtual void undo() = 0;
protected:
    Command() = default;
};

#endif