#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.h"

class HumanB{
	private:
		std::string name;
		Weapon *weapon;
	
	public:
		HumanB(void);
		HumanB(std::string new_name);
		~HumanB(void);
		
		void attack(void);
		void setWeapon(Weapon &newWeapon);
};

#endif