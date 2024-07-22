#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);
	Point point1(15.0f, 5.0f);
	// Point point2(15.0f, 5.0f);
	
	std::cout << "Triangle vertices: " << a << ", " << b << ", " << c << std::endl;
	std::cout << "Point inside: " << point1 << " -> " << (bsp(a, b, c, point1) ? "true" : "false") << std::endl;
	// std::cout << "Point outside: " << point2 << " -> " << (bsp(a, b, c, point2) ? "true" : "false") << std::endl;
	
	return 0;
}
