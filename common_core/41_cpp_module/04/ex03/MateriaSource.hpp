#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
	protected:
		AMateria *inventory[4];

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);

		AMateria * getInventory(int id) const;

		void learnMateria(AMateria* mat);
		AMateria* createMateria(std::string const & type);
};

#endif