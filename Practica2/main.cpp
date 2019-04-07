/********************/
/*    PRÁCTICA 2    */
/*   NÉSTOR PÉREZ   */
/*   RAÚL  SANCHO   */
/********************/

#include "Mystr.h"
#include <iostream>

int main() {
	/**************/
	std::cout << "-- Create 3 main strings --" << std::endl;
	Mystr a("Kha\'Zix");
	std::cout << "String a: ";
	a.Print();

	Mystr b("son las");
	std::cout << "String b: ";
	b.Print();

	Mystr c("Tresh");
	std::cout << "String c: ";
	c.Print();
	/**************/
	Mystr d(a.Concatenate(Mystr("ola que Ashe")));
	std::cout << "Copied string 'a' and concatenated 'ola que Ashe': ";
	d.Print();

	Mystr e(d.Substring(11, d.Length() - 7));
	std::cout << "11 characters cut from left and 7 from right: ";
	e.Print();

	Mystr f(e.Concatenate(Mystr("Ketchup")));
	std::cout << "Concatenated 'Ketchup': ";
	f.Print();

	std::cout << "Made it all uppercase (" << f.ToUpper() << " characters changed): ";
	f.Print();
	/**************/
	std::cout << "Made string 'a' all lowercase (" << a.ToLower() << " characters changed): ";
	a.Print();

	Mystr g(a.Concatenate(b.Concatenate(c)));
	std::cout << "Concatenated strings 'a', 'b' and 'c': ";
	g.Print();

	if (g > f) {//Imprime primero la cadena mayor
		g.Print();
		f.Print();
	}
	else {
		f.Print();
		g.Print();
	}

	system("pause");

	return 0;
}