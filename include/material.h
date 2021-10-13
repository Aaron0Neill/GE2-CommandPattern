#ifndef MATERIAL_INCLUDE
#define MATERIAL_INCLUDE

#include <string>

class Material
{
public:
    
    virtual std::string getType() =0;
private:   
};

#endif