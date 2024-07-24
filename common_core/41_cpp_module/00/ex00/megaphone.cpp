#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
	else{
		for(int i = 1; i < ac; i++){
			std::string s(av[i]);
			for (size_t j = 0; j < s.length(); j++){
				std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(s[j])));
			}
		}
		std::cout <<std::endl;
	}
}