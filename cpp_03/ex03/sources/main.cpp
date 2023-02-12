#include "../includes/DiamondTrap.hpp"

int main() {

	DiamondTrap DiamondTrap("Ben");
    DiamondTrap.attack("Enemy1");
    DiamondTrap.takeDamage(5);
    DiamondTrap.beRepaired(2);
	DiamondTrap.highFivesGuys();
	DiamondTrap.guardGate();
	DiamondTrap.whoAmI();
    return 0;
}