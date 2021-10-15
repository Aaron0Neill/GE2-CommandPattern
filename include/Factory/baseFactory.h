#ifndef BASE_FACTORY_INCLUDE
#define BASE_FACTORY_INCLUDE

#include "Materials/baseMaterial.h"

class Factory
{
public:
    Factory(){};
    virtual ~Factory(){};

    virtual Material* getMaterial() = 0;
};


#endif