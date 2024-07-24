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
		Fixed operator+() const;
		Fixed operator-() const;
		Fixed operator+(const Fixed &obj) const;
		Fixed operator-(const Fixed &obj) const;
		Fixed operator*(const Fixed &obj) const;
		Fixed operator/(const Fixed &obj) const;
		bool operator>(const Fixed &obj) const;
		bool operator<(const Fixed &obj) const;
		bool operator>=(const Fixed &obj) const;
		bool operator<=(const Fixed &obj) const;
		bool operator==(const Fixed &obj) const;
		bool operator!=(const Fixed &obj) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed &obj1, Fixed &obj2) ;
		static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
		static Fixed &max(Fixed &obj1, Fixed &obj2) ;
		static const Fixed &max(const Fixed &obj1, const Fixed &obj2);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

#endif