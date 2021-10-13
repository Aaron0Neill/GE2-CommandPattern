#ifndef LEGO_FACTORY_INCLUDE
#define LEGO_FACTORY_INCLUDE

#include "factory.h"
#include "lego.h"

class LegoFactory : public Factory
{
public: 
    LegoFactory() {};
    virtual~ LegoFactory() {};

    virtual Lego* getMaterial() {return new Lego();}
private:
};

#endif