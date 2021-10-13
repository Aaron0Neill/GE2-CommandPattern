#ifndef BALANCE_COMMAND_INCLUDE
#define BALANCE_COMMAND_INCLUDE

#include "command.h"
#include "woodFactory.h"
#include <iostream>

class BalanceCommand : public Command
{
public: 
    BalanceCommand()
    {
        std::cout << "Balance Command Created\n";
    };

    virtual void execute(std::vector<Material*>& t_mats)
    {
        t_mats.push_back(m_woodFactory.getMaterial());
        m_counter = 0;
    }

    virtual void undo()
    {
    }

private:
    WoodFactory m_woodFactory;
};

#endif