#ifndef FACTORIES_INCLUDE
#define FACTORIES_INCLUDE

#include "Factory/factory.h"
#include "Materials/materials.h"

class ClayFactory : public Factory
{
public: 
    ClayFactory() = default;
    ~ClayFactory() = default;

    Clay* getMaterial() {return new Clay();}
};


class ConcreteFactory : public Factory
{
public: 
    ConcreteFactory()  = default;
    ~ConcreteFactory() = default;

    Concrete* getMaterial() {return new Concrete();}
};

class LegoFactory : public Factory
{
public: 
    LegoFactory() = default;
    ~LegoFactory() = default;

    Lego* getMaterial() {return new Lego();}
};

class WoodFactory : public Factory
{
public: 
    WoodFactory() = default;
    ~WoodFactory() = default;

    Wood* getMaterial() { return new Wood();}
};


#endif