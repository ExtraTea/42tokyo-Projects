#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name){
	if (N < 1)
		return (NULL);
	Zombie *horde;
	try
	{
		horde = new Zombie[N];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	for(int i = 0; i < N; i++){
		horde[i].set_name(name);
	}
	return (horde);
}