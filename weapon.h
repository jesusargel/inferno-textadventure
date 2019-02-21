#ifndef WEAPON_H
#define WEAPON_H

#include "thing.h"

using namespace std;

class Weapon : public Thing
{
    private:
        int strength;
    public:
        int getStrength();
        void setStrength(int);
};

#endif
