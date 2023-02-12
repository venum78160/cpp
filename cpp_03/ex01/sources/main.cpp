#include "../includes/ScavTrap.hpp"

int main() {
    ScavTrap ScavTrap("Ben");
    ScavTrap.attack("Enemy1");
    ScavTrap.takeDamage(5);
    ScavTrap.beRepaired(2);
	ScavTrap.guardGate();
    ScavTrap.attack("Enemy2");
    ScavTrap.takeDamage(8);
    ScavTrap.beRepaired(4);
    ScavTrap.attack("Enemy3");
    ScavTrap.takeDamage(10);
    ScavTrap.beRepaired(6);
    return 0;
}