
#include "include/Character.hpp"
#include "include/ICharacter.hpp"
#include "include/MateriaSource.hpp"
#include "include/IMateriaSource.hpp"
#include "include/Ice.hpp"
#include "include/Cure.hpp"
#include <cstdio>

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// } 


int main ()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	ICharacter* me = new Character("faiza");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	ICharacter* bob  = new Character("bob");

	Character ash("ash");
	Character dem("dem");
	AMateria* tmp1;
	tmp1 = src->createMateria("ice");
	ash.equip(tmp1);
	dem = ash;
	Character som = ash;
	tmp1 = src->createMateria("cure");
	som.equip(tmp1);

	som.use(0, *bob); // should use ice 
	som.use(1, *bob); // should use cure
	ash.use(0, *bob); // should use ice 
	ash.use(1, *bob); // should not use cure since it is deep copy.

	me->use(0, *bob);
	me->use(0, *bob);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(-4, *bob);
	me->use(2, *bob);

	delete bob;
	delete me;
	delete src;


	return (0);
}
