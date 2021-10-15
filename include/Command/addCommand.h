#ifndef ADD_COMMAND_INCLUDE
#define ADD_COMMAND_INCLUDE

#include "Command/baseCommand.h"
#include "macroCommand.h"

class AddCommand : public Command
{
public:
    AddCommand(MacroCommand* t_macro, OrderCommand* t_command) : 
        m_macro(t_macro), m_command(t_command){}

    ~AddCommand()
    {
        delete m_command;
    }

    void execute()override
    {
        m_macro->addCommand(m_command);
    }

    void undo()override
    {
        m_macro->removeCommand(m_command);
    }

private:
    MacroCommand* m_macro;
    OrderCommand* m_command;
};

#endif