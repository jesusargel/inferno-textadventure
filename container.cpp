#include "container.h"
#include <iostream>

using namespace std;

void Container::setDescription(std::string desc)
{
    description = desc;
}

std::string Container::getDescription()
{
    return description;
}

void Container::setName(std::string n)
{
    name = n;
}

std::string Container::getName()
{
    return name;
}
std::vector<Thing*> Container::getThingsInContainer()
{
   return thingsInContainer;
}

void Container::addToContainer(Thing* t)
{
    thingsInContainer.push_back(t);
}

void Container::removeFromContainer(Thing* thing)
{
    for(unsigned int i = 0; i < thingsInContainer.size(); i++)
    {
        if(thing->getLongName() == thingsInContainer.at(i)->getLongName())
        {
            std::swap(thingsInContainer.at(i), thingsInContainer.back());
            thingsInContainer.pop_back();
        }
    }
}
