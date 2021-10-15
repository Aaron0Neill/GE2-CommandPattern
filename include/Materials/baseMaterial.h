#ifndef BASE_MATERIAL_INCLUDE
#define BASE_MATERIAL_INCLUDE

#include <string>

class Material
{
public:
    
    virtual std::string getType() =0;
private:   
};

#endif