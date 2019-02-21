#ifndef PARSER_H
#define PARSER_H

#include "gamemap.h"
#include "player.h"
#include "container.h"
#include "monster.h"

class Parser {
    public:
        bool readInput(Player*, GameMap*);
};

#endif

