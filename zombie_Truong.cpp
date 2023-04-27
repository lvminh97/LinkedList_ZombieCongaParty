#include <windows.h>
#include "zombie_Truong.h"

HANDLE ZombieHandle = GetStdHandle(STD_OUTPUT_HANDLE);

Zombie::Zombie(): type('\0') {}

Zombie::Zombie(char type): type(type) {}

Zombie::Zombie(const Zombie& zomb) : type(zomb.type) {}

char Zombie::getType() {
    return type;
}

bool Zombie::operator==(const Zombie zb) {
    return this->type == zb.type;
}

std::ostream& operator<<(std::ostream& out, const Zombie& zb) {
    int color = 0;
    switch(zb.type) {
        case 'R': color = 4; break;
        case 'Y': color = 14; break;
        case 'G': color = 2; break;
        case 'B': color = 1; break;
        case 'C': color = 3; break;
        case 'M': color = 13; break;
    }
    out << '[';
    SetConsoleTextAttribute(ZombieHandle, color);       // set color for zombie
    out << zb.type;
    SetConsoleTextAttribute(ZombieHandle, 15);          // reset to default color
    out << ']';
    return out;
}

