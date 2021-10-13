#ifndef LEGO_INCLUDE
#define LEGO_INCLUDE

#include "material.h"

class Lego : public Material
{
public:
    virtual std::string getType()override
    {
        return "Lego";
    }
private: 

};


#endif