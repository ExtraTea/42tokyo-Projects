#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.h"

class HumanA{
	private:
		std::string name;
		Weapon *weapon;
	
	public:
		HumanA(void);
		HumanA(std::string new_name, Weapon &new_weapon);
		~HumanA(void);
		
		void attack(void);
};

#endif