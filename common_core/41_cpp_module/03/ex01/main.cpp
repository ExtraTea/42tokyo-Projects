#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void){
	ScavTrap c1("NEKO", 100, 2, 2);
	ClapTrap c3("DOG", 10, 2, 10);
	c1.printStatus();
	c3.printStatus();

	std::cout <<"--------init--------" <<std::endl;

	c1.beRepaired(20);
	c1.attack("DOG");
	c3.attack("NEKO");
	c1.printStatus();
	c3.printStatus();
}