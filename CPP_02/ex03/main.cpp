<<<<<<< HEAD
#include "HumanA.hpp"
#include "HumanB.hpp"


int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		// jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
=======
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
>>>>>>> cpp02/master
