#ifndef MACRO_COMMAND_INCLUDE
#define MACRO_COMMAND_INCLUDE

#include "Command/orderCommand.h"
#include <stack>
#include <vector>

class MacroCommand : public Command
{
public:
    MacroCommand() = default;

    void execute()override
    {
        for(auto& cmd : m_activeCommands)
        {
            cmd->execute();
            cmd->removed();
        }

        m_activeCommands.clear();
        clearStack();
    }

    void addCommand(OrderCommand* t_command)
    {
        m_activeCommands.push_back(t_command);
        t_command->added();

        if (m_removedCommands.size() > 0)
        {
            clearStack();
        }
    }

    void removeCommand(OrderCommand* t_command)
    {
        if (m_activeCommands.size() > 0)
        {
            for(auto i = m_activeCommands.begin(); i != m_activeCommands.end(); )
            {
                if (*i == t_command)
                {
                    t_command->removed();
                    m_activeCommands.erase(i);
                    return;
                }
                else{
                    ++i;
                }
            }
        }
    }

    void addLastCommand()
    {
        if (m_removedCommands.size() > 0)
        {
            m_activeCommands.push_back(m_removedCommands.top());
            m_removedCommands.top()->added();
            m_removedCommands.pop();
        }
    }

    void undo()override
    {
        if (m_activeCommands.size() > 0)
        {
            m_removedCommands.push(m_activeCommands.at(m_activeCommands.size()-1));
            m_activeCommands.pop_back();
            m_removedCommands.top()->removed();
        }
    }
private:

    void clearStack()
    {
        while(!m_removedCommands.empty())
            m_removedCommands.pop();
    }

    std::vector<OrderCommand*> m_activeCommands;
    std::stack<OrderCommand*> m_removedCommands;
};

#endif