#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter{
    protected:
        std::string name;
        AMateria *inventory[4];

    public:
        Character();
        Character(std::string name);
        ~Character();
        Character(const Character &other);
        Character &operator=(const Character &other);

        std::string const & getName() const;
        AMateria * getInventory(int id) const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif
