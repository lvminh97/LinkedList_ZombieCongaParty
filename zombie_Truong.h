#ifndef _ZOMBIE_H
#define _ZOMBIE_H

#include <ostream>

class Zombie {
private:
    char type;
public:
    Zombie();
    Zombie(char type);
    Zombie(const Zombie& zomb);
    
    char getType();
    bool operator==(const Zombie zb);

    friend std::ostream& operator<<(std::ostream& out, const Zombie& zb);
};

#endif
