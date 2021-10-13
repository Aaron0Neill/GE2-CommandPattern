#ifndef CONCRETE_INCLUDE
#define CONCRETE_INCLUDE

#include "material.h"

class Concrete : public Material
{
public:
    virtual std::string getType()override
    {
        return "Concrete";
    }
private: 

};


#endif