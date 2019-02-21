#ifndef CONTAINER_H
#define CONTAINER_H

#include "thing.h"
#include <vector>

class Container {
    private:
        std::vector<Thing*> thingsInContainer;
        std::string description;
        std::string name;
    public:
        std::string getDescription();
        void setDescription(std::string);
        std::string getName();
        void setName(std::string);
        std::vector<Thing*> getThingsInContainer();
        void addToContainer(Thing*);
        void removeFromContainer(Thing*);
};

#endif

