#ifndef CLICK_COMMAND_INCLUDE
#define CLICK_COMMAND_INCLUDE

#include "command.h"
#include "legoFactory.h"
#include <iostream>

class ClickCommand : public Command
{
public: 
    ClickCommand()
    {
        std::cout << "Click Command Created\n";
    };

    virtual void execute(std::vector<Material*>& t_mats)
    {
        t_mats.push_back(m_legoFact.getMaterial());
    }

    virtual void undo()
    {

    }
private:
    LegoFactory m_legoFact;
};

#endif