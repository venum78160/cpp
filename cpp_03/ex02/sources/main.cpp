#include "../includes/FragTrap.hpp"

int main() {
    FragTrap FragTrap("Ben");
    FragTrap.attack("Enemy1");
    FragTrap.takeDamage(5);
    FragTrap.beRepaired(2);
	FragTrap.highFivesGuys();
    FragTrap.attack("Enemy2");
    FragTrap.takeDamage(8);
    FragTrap.beRepaired(4);
    FragTrap.attack("Enemy3");
    FragTrap.takeDamage(10);
    FragTrap.beRepaired(6);
    return 0;
}