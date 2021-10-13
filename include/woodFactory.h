#ifndef WOOD_FACTORY_INCLUDE
#define WOOD_FACTORY_INCLUDE

#include "factory.h"
#include "wood.h"

class WoodFactory : public Factory
{
public: 
    WoodFactory() {};
    virtual~ WoodFactory() {};

    virtual Wood* getMaterial() {return new Wood();}
private:
};

#endif