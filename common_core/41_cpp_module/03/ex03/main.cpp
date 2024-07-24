#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void){
	ScavTrap c1("NEKO", 100, 2, 2);
	ClapTrap c3("DOG", 10, 2, 10);
	FragTrap c4("UMA", 30, 3, 4);
	DiamondTrap c5("NEZUMI", 10, 3, 5);
	c1.printStatus();
	c3.printStatus();
	c4.printStatus();
	c5.printStatus();

	std::cout <<"--------init--------" <<std::endl;

	c1.beRepaired(20);
	c1.attack("DOG");
	c3.attack("NEKO");
	c4.attack("DOG");
	c5.attack("DOG");
	c1.printStatus();
	c3.printStatus();
	c4.printStatus();
	c5.whoAmI();
}