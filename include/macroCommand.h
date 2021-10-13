#ifndef MACRO_COMMAND_INCLUDE
#define MACRO_COMMAND_INCLUDE

#include "command.h"
#include <vector>
#include <stack>

class MacroCommand : public Command
{
public:

    MacroCommand();
    virtual ~MacroCommand();

    virtual void addCommand(Command* t_command);
    virtual void removeCommand(Command* t_command);
    virtual void execute(std::vector<Material*>& t_mats);

private:
    std::vector<Command*> m_commandList;
    std::stack<Command*> m_removedCommands;
};
#endif