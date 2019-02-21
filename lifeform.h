#ifndef LIFEFORM_H
#define LIFEFORM_H

#include "container.h"
#include "gamemap.h"
#include "weapon.h"
using namespace std;
class LifeForm : public Thing{
    private:
        int hp;
        int attackPower;
        Container* currentContainer;
        Container* inventory = new Container;
        Weapon* equiped;
        bool alive;
    public:
        void setCurrentContainer(Container*);
        Container* getCurrentContainer();
        Container* getInventory();
        void pickup(Thing*);
        void move(std::string&, GameMap&);
        int getHp();
        void setHp(int);
        int getAttackPower();
        void setAttackPower(int);
        void attack(LifeForm*);
        void equip(Weapon*);
        void unequip(Weapon*);
        Weapon* getEquiped();
        void setEquiped(Weapon*);
};

#endif
