#include "parser.h"

#include <iostream>
using namespace std;

bool Parser::readInput(Player* p, GameMap* gm)
{
    cout << "-> ";
    string verb;
    cin >> verb;
    if(verb == "help") {
        cout << "Commands that you can use:" << endl;
        cout << " -stats(Shows your player stats)" << endl;
        cout << " -look (Describes what is around you)" << endl;
        cout << " -go [dir] (north, east, south, west)" << endl;
        cout << " -inventory (Check what are you carrying)" << endl;
        cout << " -get [object name](Pick up objects)" << endl;
        cout << " -drop [object name] (Drop something in your inventory)" << endl;
        cout << " -equip [object name](Equip weapons to improve your power)" << endl;
        cout << " -unequip [object name] (Unequip weapons)" << endl;
        cout << " -equiped (Check what you have equiped)" << endl;
        cout << " -attack [target] (Attack the monsters)" << endl;
        cout << " -quit" << endl;
        cout << endl;
    } else if(verb == "quit") {
        return false;
    } else if(verb == "stats") {
        cout << "Player Name: " << p->getLongName() << endl;
        cout << "Stats: " << endl;
        cout << " -Health Points: " << p->getHp() << endl;
        cout << " -Attack Power: " << p->getAttackPower() << endl; 
        cout << endl;
    } else if(verb == "inventory") {
        if(p->getInventory()->getThingsInContainer().empty()){
            cout << "Your inventory seems to be empty" << endl;
            cout << endl;
        } else {
            cout << "Inventory: " << endl;
            for(unsigned int i = 0; i < p->getInventory()->getThingsInContainer().size(); i++)
            {
                cout << "- "<< p->getInventory()->getThingsInContainer().at(i)->getLongName() << endl;
            }
            cout << endl;
        }   
    } else if(verb == "go") {
        string direction;
        cin >> direction;
        if(direction == "north" || direction == "west" || direction == "south" || direction == "east") {
            Container* currentroom = new Container;
            currentroom = p->getCurrentContainer();
            p->move(direction, *gm);
            if(p->getCurrentContainer()->getName() == "empty"){
                p->setCurrentContainer(currentroom);
                cout << "There is nothing that way" << endl;
                cout << endl;
            } else {
                cout << "You are now in " << p->getCurrentContainer()->getName() << endl;
                cout << endl;
            }
        } else {
            cout << "Seems like you typed a wrong direction" << endl;
            cout << "Type 'help' for commands" << endl;
            cout << endl;
        }
    } else if(verb == "look") {
        cout << "In " << p->getCurrentContainer()->getName() << endl;
        cout << "    " << p->getCurrentContainer()->getDescription() << endl;
        if(p->getCurrentContainer()->getThingsInContainer().empty())
        {
            cout << "Room seems to be empty. " << endl;
            cout << endl;
        } else {
            cout << "Things in this room: " << endl;
            for(unsigned int i = 0; i < p->getCurrentContainer()->getThingsInContainer().size(); i++)
            {
                if(p->getCurrentContainer()->getThingsInContainer().at(i)->getType() == 1) {
                cout << "- "<< p->getCurrentContainer()->getThingsInContainer().at(i)->getLongName() << endl;
                }
            }
            cout << endl;
            cout << "Monsters in this room: " << endl;
            for(unsigned int i = 0; i < p->getCurrentContainer()->getThingsInContainer().size(); i++)
            {
                if(p->getCurrentContainer()->getThingsInContainer().at(i)->getType() == 2) {
                cout << "- "<< p->getCurrentContainer()->getThingsInContainer().at(i)->getLongName() << endl;
                }

            }
            cout << endl; 
        }
    } else if(verb == "get") {
        string object;
        cin >> object;
        bool in = false;
        if(p->getCurrentContainer()->getThingsInContainer().empty()){
            cout << "There is no " << object << " in this room" << endl;
            cout << endl;
        } else {
            for(unsigned int i = 0; i < p->getCurrentContainer()->getThingsInContainer().size(); i++)
            {
                if(p->getCurrentContainer()->getThingsInContainer().at(i)->getLongName() == object)
                {
                    cout << "You picked up a " << object << endl;
                    p->pickup((*p).getCurrentContainer()->getThingsInContainer().at(i));
                    p->getCurrentContainer()->removeFromContainer(p->getCurrentContainer()->getThingsInContainer().at(i));
                    cout << endl;
                    in = true;
                }
            }
            if(!in) {
                cout << "You don't have a "<< object << " in your inventory." << endl;
            }   
        }
    } else if(verb == "drop") {
        string object;
        cin >> object;
        bool in = false;
        if(p->getInventory()->getThingsInContainer().empty()){
            cout << "There is no " << object << " in your inventory" << endl;
            cout << endl;
        } else {
            for(unsigned int i = 0; i < p->getInventory()->getThingsInContainer().size(); i++)
            {
                if(p->getInventory()->getThingsInContainer().at(i)->getLongName() == object){
                    if(p->getEquiped() != NULL && p->getEquiped()->getLongName() == object){
                        cout << "Unequip object first!" << endl;
                        cout << endl;
                    } else {
                        cout << "You dropped a " << object << endl;
                        p->getCurrentContainer()->addToContainer(p->getInventory()->getThingsInContainer().at(i));
                        p->getInventory()->removeFromContainer(p->getInventory()->getThingsInContainer().at(i));
                        cout << endl;
                    }
                }
                in = true;
            }
            if(!in) {
                cout << "You don't have a "<< object << " in your inventory." << endl;
            }   
        }
    } else if (verb == "equip") {
        string w;
        cin >> w;
        bool in = false;
        if(p->getInventory()->getThingsInContainer().empty()){
            cout << "Seems like your inventory is empty..." << endl;
            cout << endl;
        } else {
            for(unsigned int i = 0; i < p->getInventory()->getThingsInContainer().size(); i++) {
                if(p->getInventory()->getThingsInContainer().at(i)->getLongName() == w) {
                    if( p->getEquiped() == NULL) {
                    cout << "You equiped a " << w << endl;
                    p->equip((Weapon*)p->getInventory()->getThingsInContainer().at(i));
                    cout << endl;
                    } else {
                        cout << "You already have something equiped" << endl;
                        cout << endl;
                    }
                in = true;
                }
            }
            if(!in) {
                cout << "You don't have a "<< w << " in your inventory." << endl;
            }   
        }       
    } else if (verb == "unequip") {
        string w;
        cin >> w;
        if(p->getInventory()->getThingsInContainer().empty()){
            cout << "Seems like you don't have anything..." << endl;
            cout << endl;
        } else {
            for(unsigned int i = 0; i < p->getInventory()->getThingsInContainer().size(); i++) {
                if(p->getInventory()->getThingsInContainer().at(i)->getLongName() == w && p->getEquiped()->getLongName() == w) {
                    cout << "Unequiped " << w << endl;
                    p->unequip((Weapon*)p->getInventory()->getThingsInContainer().at(i));
                    cout << endl;
                }
            }   
        }
    } else if(verb == "equiped"){
        if(p->getEquiped() == NULL) {
            cout << "All you got are your hands..." << endl;
            cout << endl;
        } else {
            cout << "You have a " << p->getEquiped()->getLongName() << " equiped" << endl;
            cout << endl;
        }
    } else if (verb == "attack") {
        string target;
        cin >> target;
        bool tgt = false;
        if(p->getCurrentContainer()->getThingsInContainer().empty()) {
            cout << "Nothing to attack here... You are seeing things..." << endl;
            cout << endl;
        } else {
            for (unsigned int i = 0; i < p->getCurrentContainer()->getThingsInContainer().size(); i++) { 
                if(p->getCurrentContainer()->getThingsInContainer().at(i)->getLongName() == target){
                    cout << "You attacked " << target << endl;  
                    p->attack((LifeForm*)p->getCurrentContainer()->getThingsInContainer().at(i));
                    if(((Monster*)p->getCurrentContainer()->getThingsInContainer().at(i))->getHp() > 0) {
                        cout << target << "'s hp is now " << ((Monster*)p->getCurrentContainer()->getThingsInContainer().at(i))->getHp() << "."<<endl;
                    cout << endl;
                    } else {
                        cout << target << " is now dead." << endl;
                        cout << endl;
                        p->getCurrentContainer()->removeFromContainer(p->getCurrentContainer()->getThingsInContainer().at(i));
                    }
                    tgt = true;
                } 
            }
            if(!tgt) {
                cout << "There is no " << target << " in this room" << endl;
            }
        }
    } else {
        cout << "UNKOWN COMMAND, type 'help'" << endl;
    }
    return true;
}

