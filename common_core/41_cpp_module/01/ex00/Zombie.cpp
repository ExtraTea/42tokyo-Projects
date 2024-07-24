#include "Zombie.h"

void Zombie::announce(void){
	std::cout <<name <<": BraiiiiiiinnnzzzZ..." <<std::endl;
}

Zombie::Zombie(std::string zname){
	name = zname;
}

Zombie::~Zombie(void){
	std::cout <<name <<": see ya!" <<std::endl;
}