#ifndef _CONGA_H
#define _CONGA_H

#include "linkedlist_Truong.hpp"
#include "zombie_Truong.h"

class Conga {
public:
    LinkedList<Zombie> zombieList;

    void engine_action(Zombie randomZobm);
    void caboose_action(Zombie randomZomb);
    void jump_in_action(Zombie randomZomb);
    void everyone_out_action(Zombie randomZomb);
    void you_out_action(Zombie randomZomb);
    void brains_action(Zombie randomZomb);
    void rainbow_action(Zombie randomZomb);
    void friend_action(Zombie randomZomb);
};

#endif
