#include <string>
#include <iostream>

int main(void){
	std::string s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;

	std::cout <<"Address of s: " <<&s <<std::endl;
	std::cout <<"Address held by stringPTR: " <<stringPTR <<std::endl;
	std::cout <<"Address held by stringPTR: " <<&stringREF <<std::endl;

	std::cout <<"value of s: " <<s <<std::endl;
	std::cout <<"value pointed to by stringPTR: " <<*stringPTR <<std::endl;
	std::cout <<"value pointed to by stringREF: " <<stringREF <<std::endl;
}