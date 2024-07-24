#include "PhoneBook.h"
#include "PhoneBook.hpp"

std::string	PhoneBook::input_no_empty(std::string prompt)
{
	std::string target_string;

	std::cout <<"Enter " <<prompt << ": ";
	std::getline(std::cin, target_string);
	while (target_string.empty())
	{
		std::cout <<"No empty input is tolerated. Try again." <<std::endl;
		std::cout <<"Enter " <<prompt << ": ";
		std::getline(std::cin, target_string);
	}
	return (target_string);
}

void	PhoneBook::display_exactly_10(std::string s)
{
	std::cout <<"| ";
	if (s.length() > 10)
	{
		std::cout <<s.substr(0, 9) <<"." <<" ";
	}
	else
	{
		std::cout <<std::setw(10) <<s <<" ";
	}
}

void	PhoneBook::display_basic_info(size_t id)
{
	std::cout <<"| " <<std::setw(10) <<id <<" ";
	display_exactly_10(contacts[id].get_first());
	display_exactly_10(contacts[id].get_last());
	display_exactly_10(contacts[id].get_nickname());
	std::cout <<"|" <<std::endl;
	std::cout <<"-----------------------------------------------------" <<std::endl;
}

void	PhoneBook::display_all_info(size_t id)
{
	std::cout <<"-----------------------------------------------------" <<std::endl;
	std::cout <<"ID: " <<id <<std::endl;
	std::cout <<"First Name    : " <<contacts[id].get_first() <<std::endl;
	std::cout <<"Last Name     : " <<contacts[id].get_last() <<std::endl;
	std::cout <<"Nickname      : " <<contacts[id].get_nickname() <<std::endl;
	std::cout <<"Phone Number  : " <<contacts[id].get_phone_number() <<std::endl;
	std::cout <<"Darkest secret: " <<contacts[id].get_darkest_secret() <<std::endl;
	std::cout <<"-----------------------------------------------------" <<std::endl;
}

PhoneBook::PhoneBook(void)
{
	current_id = 0;
}

void    PhoneBook::add(){
	size_t id;

	id = current_id % 8;
	contacts[id].set_first(input_no_empty("First Name"));
	contacts[id].set_last(input_no_empty("Last Name"));
	contacts[id].set_nickname(input_no_empty("Nickname"));
	contacts[id].set_phone_number(input_no_empty("Phone Number"));
	contacts[id].set_darkest_secret(input_no_empty("Darkest secret"));
	current_id++;
}

void	PhoneBook::search(void){
	if (current_id == 0)
	{
		std::cout <<"No Entry is saved." <<std::endl;
		return ;
	}
	std::cout <<"Below is latest 8 saved contacts." <<std::endl;
	std::cout <<"-----------------------------------------------------" <<std::endl;
	std::cout <<"|      index | first name |  last name |   nickname |" <<std::endl;
	std::cout <<"-----------------------------------------------------" <<std::endl;
	for(size_t i = 0; i < ft_min(current_id, 8); i++)
	{
		display_basic_info(i);
	}
	std::cout <<std::endl;
	std::cout <<"Choose which to display: 0 to " << ft_min(current_id - 1, 7) <<"." <<std::endl;
	while (1)
	{
		std::string id_s = input_no_empty("id");
		if (id_s.length() == 1 && (48 <= id_s[0] && id_s[0] <= 48 + (char)ft_min(current_id - 1, 7)))
		{
			display_all_info(id_s[0] - 48);
			break ;
		}
		else
		{
			std::cout <<"Invalid Input: Try Again." <<std::endl;
			std::cout <<"Choose which to display: 0 to " << ft_min(current_id - 1, 7) <<"." <<std::endl;
		}
	}
}