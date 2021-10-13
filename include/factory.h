#ifndef FACTORY_INCLUDE
#define FACTORY_INCLUDE

#include "material.h"

class Factory
{
public:
    Factory(){};
    virtual ~Factory(){};

    virtual Material* getMaterial() = 0;
};

#endif