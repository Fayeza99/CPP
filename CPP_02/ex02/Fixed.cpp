#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	// std::cout << "Int constructor called" << std::endl;
	this->value = intValue << fBits;
}

Fixed::Fixed (const float floatValue)
{
	// std::cout << "Float constructor called" << std::endl;
	this->value = roundf(floatValue * (1 << fBits));
}


Fixed::Fixed(const Fixed& p)
{
	this->setRawBits(p.getRawBits());
	*this = p;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
	{
		this->value = other.value;
	}
	return *this;
}


int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}


float Fixed::toFloat( void ) const
{
	return (static_cast<float> (this->getRawBits()) / (1 << fBits));
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


bool Fixed::operator>(const Fixed& other)const
{
	return (this->value > other.value);
}

bool Fixed::operator<(const Fixed& other)const
{
	return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed& other)const
{
	return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed& other)const
{
	return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed& other)const
{
	return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed& other)const
{
	return (this->value != other.value);
}


Fixed Fixed::operator+(const Fixed& other)
{
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other)
{
	return (this->toFloat() - other.toFloat());
}


Fixed Fixed::operator*(const Fixed& other)
{
	return (this->toFloat() * other.toFloat());
}


Fixed Fixed::operator/(const Fixed& other)
{
	return (this->toFloat() / other.toFloat());
}


Fixed& Fixed::operator++()
{
	++this->value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->value;
	return temp;
}

Fixed& Fixed::operator--()
{
	--this->value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->value;
	return temp;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}
