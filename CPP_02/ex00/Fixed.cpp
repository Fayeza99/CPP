#include "Fixed.hpp"

Fixed::Fixed() : value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.value;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed&other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
	{
		this->value = other.value;
	}
	return (*this);
}

int Fixed::getRawBits()const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
