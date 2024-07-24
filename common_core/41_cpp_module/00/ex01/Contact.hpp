#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "Contact.h"

class Contact{
	private:
		std::string first;
		std::string last;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	
	public:
		std::string get_first();

		std::string get_last();

		std::string get_nickname();
			
		std::string get_phone_number();

		std::string get_darkest_secret();

		void	set_first(std::string s);

		void	set_last(std::string s);

		void	set_nickname(std::string s);

		void	set_phone_number(std::string s);

		void	set_darkest_secret(std::string s);
};

#endif