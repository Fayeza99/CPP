#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
#include <algorithm>
class Fixed
{
private:
	int		value;
	static const int	fBits = 8;

public:
	Fixed();
	Fixed(const int intValue);
	Fixed(const float floatValue);
	Fixed(const Fixed &other);
	~Fixed();
	Fixed &operator = (const Fixed& other);

	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);

	int getRawBits() const;
	void setRawBits(int const raw); 

	float toFloat() const;
	int toInt() const;

	bool operator>(const Fixed& other)const;
	bool operator<(const Fixed& other)const;
	bool operator>=(const Fixed& other)const;
	bool operator<=(const Fixed& other)const;
	bool operator==(const Fixed& other)const;
	bool operator!=(const Fixed& other)const;

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);


};
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


#endif
