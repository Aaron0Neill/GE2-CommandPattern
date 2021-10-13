#ifndef CLAY_INCLUDE
#define CLAY_INCLUDE

#include "material.h"

class Clay : public Material
{
public:
    virtual std::string getType()override
    {
        return "Clay";
    }
private: 

};


#endif