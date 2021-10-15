#ifndef ORDER_COMMAND_INCLUDE
#define ORDER_COMMAND_INCLUDE

#include "Command/baseCommand.h"
#include "Factory/baseFactory.h"
#include <vector>
#include <cstdio>

class OrderCommand : public Command
{
public:
    OrderCommand(Factory* t_fact,std::vector<Material*>& t_mats, int& t_count) :
        m_factory(t_fact), m_mats(t_mats), m_count(t_count){}
    ~OrderCommand() = default;

    void execute()override
    {
        m_mats.push_back(m_factory->getMaterial());
    }

    void undo()override
    {
        printf("Sorry No Returns\n");
    }

    void added()
    {
        m_count++;
    }

    void removed()
    {
        m_count--;
    }

private:
    int& m_count;
    Factory* m_factory;
    std::vector<Material*>& m_mats;
};

#endif