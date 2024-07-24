#include "Zombie.h"

int main(void)
{
	int N = 100;
	
	Zombie *horde = zombieHorde(N, "Sarah");
	if (horde == NULL)
		return (1);
	for(int i = 0; i < N; i++){
		horde[i].announce();
	}
	delete[] horde;
}