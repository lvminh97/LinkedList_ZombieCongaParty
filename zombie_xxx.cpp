#include "zombie_xxx.h"

Zombie::Zombie(): type(' ') {}

Zombie::Zombie(char type): type(type) {}

char Zombie::getType() {
    return type;
}

bool Zombie::operator==(const Zombie zb) {
    return this->type == zb.type;
}

std::ostream& operator<<(std::ostream& out, const Zombie& zb) {
    return out << zb.type;
}

