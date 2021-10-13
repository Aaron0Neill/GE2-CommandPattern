#ifndef CONCRETE_FACTORY_INCLUDE
#define CONCRETE_FACTORY_INCLUDE

#include "factory.h"
#include "concrete.h"

class ConcreteFactory : public Factory
{
public: 
    ConcreteFactory() {};
    virtual~ ConcreteFactory() {};

    virtual Concrete* getMaterial() {return new Concrete();}
private:
};

#endif