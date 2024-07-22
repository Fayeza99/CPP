#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = intValue << fBits;
}

Fixed::Fixed (const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(floatValue * (1 << fBits));
}


Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
	{
		this->value = other.value;
	}
	return *this;
}


int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat() const
{
	return (static_cast<float>(value) / (1 << fBits));
}

int Fixed::toInt () const
{
	return (value >> fBits);
}


std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
