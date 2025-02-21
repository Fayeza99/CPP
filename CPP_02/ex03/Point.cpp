#include "Point.hpp"
#include "Fixed.hpp"
Point::Point() : x(0), y(0){}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(Fixed x, Fixed y) : x(x), y(y){}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point() {}


Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}


std::ostream& operator<<(std::ostream& out, const Point& point)
{
	out << "(" << point.getX() << ", " << point.getY() << ")";
	return out;
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->getX() = other.x;
		this->getY() = other.y;
	}
	return *this;
}
