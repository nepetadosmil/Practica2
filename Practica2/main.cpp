/********************/
/*    PRÁCTICA 2    */
/*   NÉSTOR PÉREZ   */
/*   RAÚL  SANCHO   */
/********************/

#include "Mystr.h"
#include <iostream>

int main() {

	Mystr a("Kha\'Zix");
	std::cout << "String a: ";
	a.Print();

	Mystr b("son las");
	std::cout << "String b: ";
	b.Print();

	Mystr c("Tresh");
	std::cout << "String c: ";
	c.Print();

	Mystr copia(a);
	std::cout << "Copied string: ";
	copia.Print();

	std::cout << "Concatenated 'ola que Ashe': ";
	copia.Concatenate(Mystr("ola que Ashe")).Print();

	a.Remove('a');
	a.Print();


	system("pause");

	return 0;
}