#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(Fixed x, Fixed y);
	Point(const float x, const float y);
	Point(const Point& other);
	~Point();

	Point& operator=(const Point& other);

	Fixed getX() const;
	Fixed getY() const;

};

std::ostream& operator<<(std::ostream& out, const Point& point);


#endif