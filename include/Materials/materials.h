#ifndef MATERIALS_INCLUDE
#define MATERIALS_INCLUDE

#include "Materials/baseMaterial.h"

class Clay : public Material
{
public:
    virtual std::string getType()override
    {
        return "Clay";
    }
};

class Concrete : public Material
{
public:
    virtual std::string getType()override
    {
        return "Concrete";
    }
};

class Wood : public Material
{
public:
    virtual std::string getType()override
    {
        return "Wood";
    }
};


class Lego : public Material
{
public:
    virtual std::string getType()override
    {
        return "Lego";
    }
};

#endif