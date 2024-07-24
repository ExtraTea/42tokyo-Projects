#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "PhoneBook.h"

class PhoneBook{
	private:
		Contact	contacts[8];
		size_t	current_id;

		std::string	input_no_empty(std::string prompt);

		void	display_exactly_10(std::string s);

		void	display_basic_info(size_t id);

		void	display_all_info(size_t id);

	public:
		PhoneBook(void);

		void    add();

		void	search(void);
};

#endif