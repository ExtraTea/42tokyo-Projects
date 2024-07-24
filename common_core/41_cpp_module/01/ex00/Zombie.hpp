#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie{
	private:
		std::string name;
	
	public:
		Zombie(std::string zname);
		~Zombie(void);

		void announce(void);
};

#endif