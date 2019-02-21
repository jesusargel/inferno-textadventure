#include "lifeform.h"
#include <iostream>
#include "container.h"

using namespace std;

void LifeForm::setCurrentContainer(Container* r)
{
    currentContainer = r;   
}

Container* LifeForm::getCurrentContainer()
{
    return currentContainer;
}

void LifeForm::move(std::string& dir, GameMap& gm)
{
    currentContainer = gm.getGameMap()[currentContainer][dir];        
}

Container* LifeForm::getInventory()
{
    return inventory;
}

void LifeForm::pickup(Thing* thing)
{
    getInventory()->addToContainer(thing);    
}

int LifeForm::getHp()
{
    return hp;
}

void LifeForm::setHp(int health)
{
    hp = health;
}

int LifeForm::getAttackPower()
{
    return attackPower;
}

void LifeForm::setAttackPower(int ap)
{
    attackPower = ap;
}

void LifeForm::attack(LifeForm* lf)
{
    lf->setHp(lf->getHp() - this->getAttackPower());
}

void LifeForm::equip(Weapon* weapon)
{
    for(unsigned int i = 0; i < inventory->getThingsInContainer().size(); i++) {
        if(weapon->getLongName() == inventory->getThingsInContainer().at(i)->getLongName()) {
            attackPower = attackPower + weapon->getStrength();
            equiped = (Weapon*)inventory->getThingsInContainer().at(i);
        }
    }
}

void LifeForm::unequip(Weapon* weapon)
{
    for(unsigned int i = 0; i < inventory->getThingsInContainer().size(); i++) {
        if(weapon->getLongName() == inventory->getThingsInContainer().at(i)->getLongName()) {
            attackPower = 10;
            equiped = NULL;
        }
    }
}

Weapon* LifeForm::getEquiped()
{
    return equiped;
}

void LifeForm::setEquiped(Weapon* w)
{
    equiped = w;    
}
