#ifndef MACRO_COMMAND_INCLUDE
#define MACRO_COMMAND_INCLUDE

#include "command.h"
#include <vector>
#include <stack>

class MacroCommand : public Command
{
public:

    MacroCommand()
    {

    };
    virtual ~MacroCommand()
    {

    };

    virtual void addCommand(Command* t_command)
    {
        t_command->added();
        m_commandList.push_back(t_command);
    };

    virtual void removeCommand()
    {
        if (m_commandList.size() > 0)
        {
            m_removedCommands.push(m_commandList.at(m_commandList.size()-1));
            m_commandList.pop_back();
            m_removedCommands.top()->removed();
        }
    };
    virtual void execute(std::vector<Material*>& t_mats)override
    {
        for(auto& cmd : m_commandList)
            cmd->execute(t_mats);

        m_commandList.clear();
        while(!m_removedCommands.empty())
            m_removedCommands.pop();
    };

    virtual void undo()override
    {
        if (m_removedCommands.size() > 0 )
        {
            m_removedCommands.top()->added();
            m_commandList.push_back(m_removedCommands.top());
            m_removedCommands.pop();
        }
    };

private:
    std::vector<Command*> m_commandList;
    std::stack<Command*> m_removedCommands;
};
#endif