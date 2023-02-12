#include "../includes/ClapTrap.hpp"

int main() {
    ClapTrap Claptrap("Ben");
    Claptrap.attack("Enemy1");
    Claptrap.takeDamage(5);
    Claptrap.beRepaired(2);
    Claptrap.attack("Enemy2");
    Claptrap.takeDamage(8);
    Claptrap.beRepaired(4);
    Claptrap.attack("Enemy3");
    Claptrap.takeDamage(10);
    Claptrap.beRepaired(6);
    return 0;
}