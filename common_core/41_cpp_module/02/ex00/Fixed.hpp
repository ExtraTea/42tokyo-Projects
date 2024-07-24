#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed{
	private:
		int num;
		static const int bits = 8;
	
	public:
		Fixed(void);
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif