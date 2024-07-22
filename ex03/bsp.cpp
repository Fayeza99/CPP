#include "Point.hpp"


Fixed area(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
	Fixed value = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / Fixed(2);
	return value.abs();
}

bool bsp(Point const a, Point const b, Point const c, Point const p
)
{
	Fixed A = area(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed A1 = area(p.getX(), p.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed A2 = area(a.getX(), a.getY(), p.getX(), p.getY(), c.getX(), c.getY());
	Fixed A3 = area(a.getX(), a.getY(), b.getX(), b.getY(), p.getX(), p.getY());

	return (A == A1 + A2 + A3);
}
