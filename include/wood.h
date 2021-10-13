#ifndef WOOD_INCLUDE
#define WOOD_INCLUDE

#include "material.h"

class Wood : public Material
{
public:
    virtual std::string getType()override
    {
        return "Wood";
    }
private: 

};


#endif