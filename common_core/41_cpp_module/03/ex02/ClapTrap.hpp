#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <limits>

class ClapTrap{
	protected:
		std::string		name;
		unsigned int	hit_point;
		unsigned int	energy_point;
		unsigned int	attack_damage;
		ClapTrap		*next;
		static ClapTrap *now;
		std::string codename; 

	public:
		ClapTrap();
		ClapTrap(const std::string &name, const int hit, const int energy, const int attack);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void printStatus();
};

#endif
