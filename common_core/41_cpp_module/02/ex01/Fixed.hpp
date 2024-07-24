#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed;

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

class Fixed{
	private:
		int num;
		static const int bits = 8;
	
	public:
		Fixed(void);
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif