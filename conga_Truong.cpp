#include "conga_Truong.h"

void Conga::engine_action(Zombie randomZomb) {
    zombieList.AddToFront(randomZomb);
}

void Conga::caboose_action(Zombie randomZomb) {
    zombieList.AddToEnd(randomZomb);
}

void Conga::jump_in_action(Zombie randomZomb) {
    int X = rand() % (zombieList.Length() + 1);
    zombieList.AddAtIndex(randomZomb, X);
}

void Conga::everyone_out_action(Zombie randomZomb) {
    zombieList.RemoveAllOf(randomZomb);
}

void Conga::you_out_action(Zombie randomZomb) {
    zombieList.RemoveTheFirst(randomZomb);
}

void Conga::brains_action(Zombie randomZomb) {
    Zombie zb1(randomZomb), zb2(randomZomb);
    engine_action(zb1);
    caboose_action(zb2);
    jump_in_action(randomZomb);
}

void Conga::rainbow_action(Zombie randomZomb) {
    engine_action(randomZomb);
    caboose_action(Zombie('R'));
    caboose_action(Zombie('Y'));
    caboose_action(Zombie('G'));
    caboose_action(Zombie('B'));
    caboose_action(Zombie('C'));
    caboose_action(Zombie('M'));
}

void Conga::friend_action(Zombie randomZomb) {
    Node<Zombie>* find = zombieList.Find(randomZomb);
    if(find == NULL) {
        caboose_action(randomZomb);
    }
    else if(rand() % 2 == 0) {
        zombieList.AddBefore(find, randomZomb);
    }
    else {
        zombieList.AddAfter(find, randomZomb);
    }
}