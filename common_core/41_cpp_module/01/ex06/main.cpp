#include "Harl.h"
#include "Harl.hpp"

int main(int ac, char **av){
	Harl harl;
	if (ac == 1){
		std::cerr <<"usage: DEBUG, INFO, WARNING, ERROR" <<std::endl;
		return (1);
	}
	for(int i = 1; i < ac; i++){
		harl.complain(av[i]);
	}
}