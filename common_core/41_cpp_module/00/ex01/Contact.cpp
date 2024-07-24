#include "Contact.h"
#include "Contact.hpp"

std::string Contact::get_first()
{
	return (first);
}

std::string Contact::get_last()
{
	return (last);
}

std::string Contact::get_nickname()
{
	return (nickname);
}

std::string Contact::get_phone_number()
{
	return (phone_number);
}

std::string Contact::get_darkest_secret()
{
	return (darkest_secret);
}

void	Contact::set_first(std::string s)
{
	first = s;
}

void	Contact::set_last(std::string s)
{
	last = s;
}

void	Contact::set_nickname(std::string s)
{
	nickname = s;
}

void	Contact::set_phone_number(std::string s)
{
	phone_number = s;
}

void	Contact::set_darkest_secret(std::string s)
{
	darkest_secret = s;
}