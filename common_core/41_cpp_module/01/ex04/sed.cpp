#include "sed.h"

size_t ft_max(long a, long b){
	if (a > b)
		return ((size_t)a);
	return ((size_t)b);
}

size_t ft_min(size_t a, size_t b){
	if (a < b)
		return (a);
	return (b);
}

int sed_init(int ac){
	if (ac != 4){
		std::cerr <<"usage: <filename> <s1> <s2>" <<std::endl;
		return (-1);
	}
	return (0);
}

int sed_open_file(std::string filename, std::fstream &inputfile, std::ofstream &outputfile){
	inputfile.open(filename.c_str());
	if (!inputfile){
		std::cerr<<"File " <<filename << "does not exist." <<std::endl;
		return (-1);
	}
	filename.append(".replace");
	outputfile.open(filename.c_str());
	if (!outputfile){
		std::cerr<<"File " <<filename <<" could not be opened." <<std::endl;
		return (-1);
	}
	return (0);
}

int sed_loop(std::fstream &inputfile, std::ofstream &outputfile, std::string s1, std::string s2){
	char *buf;
	std::size_t n_words_left = 0;
	std::string buf_s;
	std::size_t found;

	try{
		buf = new char[s1.length() * 2 + 1];
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
		return (-1);
	}
	while (inputfile.read(&buf[n_words_left], s1.length() * 2 - n_words_left) || n_words_left + inputfile.gcount() > 0){
		size_t n_read = n_words_left + inputfile.gcount();
		buf[n_read] = 0;
		buf_s = buf;
		found = buf_s.find(s1);
		if (found == std::string::npos){
			outputfile <<buf_s.substr(0, ft_min(s1.length(), n_read));
			n_words_left = ft_max((long)n_read - (long)s1.length(), 0);
			memmove(buf, &buf[s1.length()], n_words_left + 1);
		}
		else{
			outputfile <<buf_s.substr(0, found) <<s2;
			n_words_left = s1.length() * 2 - s1.length() - found;
			memmove(buf, &buf[found + s1.length()], n_words_left + 1);
		}
	}
	delete[] buf;
	return (0);
}

int sed (int ac, char **av){
	if (sed_init(ac) == -1)
		return (1);
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	
	std::fstream inputfile;
	std::ofstream outputfile;
	if (sed_open_file(filename, inputfile, outputfile) == -1)
		return (1);
	if (sed_loop(inputfile, outputfile, s1, s2) == -1)
		return (1);
	return (0);
}