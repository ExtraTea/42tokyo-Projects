#include "PhoneBook.h"
#include "Contact.h"

size_t ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int main(void)
{
	PhoneBook phonebook;
	std::string tmp;

	while (1)
	{
		std::cout <<"Available Command: ADD, SEARCH, EXIT." <<std::endl;
		std::getline(std::cin, tmp);
		if (tmp.compare("ADD") == 0)
			phonebook.add();
		else if (tmp.compare("SEARCH") == 0)
			phonebook.search();
		else if (tmp.compare("EXIT") == 0)
			break ;
	}
}