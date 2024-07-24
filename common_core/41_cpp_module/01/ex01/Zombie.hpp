#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie{
	private:
		std::string name;
	
	public:
		Zombie(void);
		Zombie(std::string zname);
		~Zombie(void);

		void announce(void);
		void set_name(std::string zname);
};

#endif