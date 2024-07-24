#include "Zombie.h"

Zombie *newZombie(std::string name){
	try
	{
		Zombie *new_zombie = new Zombie(name);
		return (new_zombie);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	
}