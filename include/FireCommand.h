#ifndef FIRE_COMMAND_INCLUDE
#define FIRE_COMMAND_INCLUDE

#include "command.h"
#include "clayFactory.h"
#include <iostream>

class FireCommand : public Command
{
public: 
    FireCommand()
    {
        std::cout << "Fire Command Created\n";
    };

    virtual void execute(std::vector<Material*>& t_mats)
    {
        t_mats.push_back(m_clayFactory.getMaterial());
        m_counter = 0;
    }

    virtual void undo()
    {
    }

private:
    ClayFactory m_clayFactory;
};

#endif