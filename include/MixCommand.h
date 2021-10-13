#ifndef MIX_COMMAND_INCLUDE
#define MIX_COMMAND_INCLUDE

#include "command.h"
#include "concreteFactory.h"
#include <iostream>

class MixCommand : public Command
{
public: 
    MixCommand()
    {
        std::cout << "Mix Command Created\n";
    };

    virtual void execute(std::vector<Material*>& t_mats)
    {
        t_mats.push_back(m_concreteFactory.getMaterial());
        m_counter = 0;
    }

    virtual void undo()
    {
    }

private:
    ConcreteFactory m_concreteFactory;
};

#endif