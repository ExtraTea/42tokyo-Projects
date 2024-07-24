#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
	private:
		std::string name;

	protected:
		using FragTrap::hit_point;
		using ScavTrap::energy_point;
		using FragTrap::attack_damage;
	
	public:
		using FragTrap::attack;
		DiamondTrap();
		DiamondTrap(const std::string &name, int hit, int energy, int attack);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		void whoAmI();
} ;

#endif