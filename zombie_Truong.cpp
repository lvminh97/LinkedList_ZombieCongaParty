#include "zombie_Truong.h"

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
    return out << '[' << zb.type << ']';
}

