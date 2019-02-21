#include "parser.h"
#include "room.h"
#include "gamemap.h"
#include "player.h"
#include "monster.h"
#include "weapon.h"
#include <iostream>

using namespace std;
int main()
{
    Room* ctspawn = new Room;
    ctspawn->setName("Counter-Terrorist base");
    ctspawn->setDescription("There is no roof here. Your partners are all gone, you seem to be on your own.");
    Room* construction = new Room;
    construction->setName("Construction");
    construction->setDescription("Something destroyed this place, there are some remainders of what it seems to be an old chapel");
    Room* bsite = new Room;
    bsite->setName("Bomb site B");
    bsite->setDescription("A beautiful fountain in the middle with a red X marking a target for someone");
    Room* banana = new Room;
    banana->setName("Banana");
    banana->setDescription("Long curved hallway, seems like a really strategic point during a battle");
    Room* tspawn = new Room;
    tspawn->setName("Terrorist base");
    tspawn->setDescription("Base for a revulsive group, a lot of bullet and knife marks on the walls");
    Room* mid = new Room;
    mid->setName("Mid");
    mid->setDescription("Wide room with a great vision to every direction");
    Room* oldmid = new Room;
    oldmid->setName("Secondary Mid");
    oldmid->setDescription("Ruins of what it seemed to be a very busy room in this place");
    Room* aps = new Room;
    aps->setName("Apartments");
    aps->setDescription("No one lives here anymore, this is all turned into war territory");
    Room* asite = new Room;
    asite->setName("Bomb site A");
    asite->setDescription("Small plaza, there is a big red X on the floor next to some boxes");
    Room* library = new Room;
    library->setName("Library");
    library->setDescription("This room is tiny, no time for reading during war");
    Room* empty = new Room;
    empty->setName("empty");    

    GameMap* gm = new GameMap;
   
    gm->setExit(ctspawn, construction, "west");
    gm->setExit(ctspawn, bsite, "south");
    gm->setExit(ctspawn, library, "east");
    gm->setExit(ctspawn, empty, "north");
    gm->setExit(library, ctspawn, "west");
    gm->setExit(library, asite, "east");
    gm->setExit(library, empty, "north");
    gm->setExit(library, empty, "south");
    gm->setExit(asite, library, "west");
    gm->setExit(asite, mid, "south");
    gm->setExit(asite, aps, "east");
    gm->setExit(asite, empty, "north");
    gm->setExit(aps, asite, "north");
    gm->setExit(aps, mid, "west");
    gm->setExit(aps, oldmid, "east");
    gm->setExit(aps, empty, "south");
    gm->setExit(mid, asite, "west");
    gm->setExit(mid, aps, "north");
    gm->setExit(mid, oldmid, "east");
    gm->setExit(mid, tspawn, "south");
    gm->setExit(oldmid, mid, "west");
    gm->setExit(oldmid, tspawn, "south");
    gm->setExit(oldmid, aps, "north");
    gm->setExit(oldmid, empty, "east");
    gm->setExit(tspawn, oldmid, "east");
    gm->setExit(tspawn, mid, "north");
    gm->setExit(tspawn, banana, "west");
    gm->setExit(tspawn, empty, "south");
    gm->setExit(banana, tspawn, "south");
    gm->setExit(banana, bsite, "west");
    gm->setExit(banana, empty, "north");
    gm->setExit(banana, empty, "east");
    gm->setExit(construction, ctspawn, "east");
    gm->setExit(construction, bsite, "south");
    gm->setExit(construction, empty, "west");
    gm->setExit(construction, empty, "north");
    gm->setExit(bsite, ctspawn, "north");
    gm->setExit(bsite, construction, "west");
    gm->setExit(bsite, banana, "east");
    gm->setExit(bsite, empty, "south");

    Player* player1 = new Player;
    player1->setCurrentContainer(ctspawn);
    player1->setHp(100);
    player1->setAttackPower(10);
    player1->setEquiped(NULL);    

    Monster* brando = new Monster;
    brando->setHp(20);
    brando->setLongName("Brando");
    brando->setType(2);
    banana->addToContainer(brando);

    Monster* zekirido = new Monster;
    zekirido->setHp(50);
    zekirido->setLongName("Zekirido");
    zekirido->setType(2);
    tspawn->addToContainer(zekirido);
    
    Monster* jose = new Monster;
    jose->setHp(50);
    jose->setLongName("Josequiel");
    jose->setType(2);
    aps->addToContainer(jose);

    Monster* juanma = new Monster;
    juanma->setHp(50);
    juanma->setLongName("Juanma");
    juanma->setType(2);
    oldmid->addToContainer(juanma);
    
    Weapon* knife = new Weapon;
    knife->setLongName("knife");
    knife->setStrength(15);
    knife->setType(1);
    ctspawn->addToContainer(knife);
    

    Weapon* deagle = new Weapon;
    deagle->setLongName("deagle");
    deagle->setStrength(30);
    deagle->setType(1);
    aps->addToContainer(deagle);

    Weapon* granade = new Weapon;
    granade->setLongName("hegranade");
    granade->setStrength(20);
    granade->setType(1);
    asite->addToContainer(granade);

    Weapon* flashbang = new Weapon;
    flashbang->setLongName("flashbang");
    flashbang->setStrength(5);
    flashbang->setType(1);
    banana->addToContainer(flashbang);

    Weapon* molotov = new Weapon;
    molotov->setLongName("molotov");
    molotov->setStrength(10);
    molotov->setType(1);
    tspawn->addToContainer(molotov);
    
    Parser p;
    cout << "Welcome to Inferno soldier!" << endl;
    cout << "What is your name?" << endl;
    cout << "-> ";
    string name;
    cin >> name;
    player1->setLongName(name);
    cout << endl;
    cout << "Okay " << player1->getLongName() << ", time to get things done around here. Get to work!" << endl;
    cout << endl;
    cout << "You are in: " << ctspawn->getName() << endl;
    cout << "Type 'help' for commands" << endl;
    cout << endl;
    while(p.readInput(player1, gm));

    return 0;
}


