#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
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
	int getRawBits() const;
	void setRawBits(int const raw); 

	float toFloat() const;
	int toInt() const;

	friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

};


#endif
