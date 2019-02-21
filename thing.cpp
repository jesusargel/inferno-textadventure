#include "thing.h"
#include <iostream>

using namespace std;

std::string Thing::getLongName()
{
    return longName;
}

void Thing::setLongName(std::string name)
{
    longName = name;
}

std::string Thing::getDescription()
{
    return description;
}

void Thing::setDescription(std::string des)
{
    description = des;
}

int Thing::getType()
{
    return type;
}

void Thing::setType(int t)
{
    type = t;
}
