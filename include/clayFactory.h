#ifndef CLAY_FACTORY_INCLUDE
#define CLAY

#include "factory.h"
#include "clay.h"

class ClayFactory : public Factory
{
public: 
    ClayFactory() {};
    virtual~ ClayFactory() {};

    virtual Clay* getMaterial() {return new Clay();}
private:
};

#endif