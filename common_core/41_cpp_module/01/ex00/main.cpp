#include "Zombie.h"

int main(void){
	randomChump("John");
	Zombie *bob = newZombie("Bob");
	if (bob == NULL)
		return (1);
	bob->announce();
	delete(bob);
}