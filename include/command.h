#ifndef COMMAND_INCLUDE
#define COMMAND_INCLUDE

#include "material.h"
#include <vector>

class Command
{
public:
    virtual ~Command() {}

    virtual void execute(std::vector<Material*>& t_mats) =0;
    virtual void undo() = 0;

    virtual void added(){ m_counter++; }

    virtual void removed(){ m_counter--; }

    virtual int getCount(){ return m_counter; }
protected:
    int m_counter;
    Command() : m_counter(0) {};
};

#endif