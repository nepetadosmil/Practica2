/********************/
/*    PRÁCTICA 2    */
/*   NÉSTOR PÉREZ   */
/*   RAÚL  SANCHO   */
/********************/

#include "Mystr.h"
#include "LinkedList.h"
#include <iostream>

int main() {
	/**************/
	std::cout << "-- Create 3 main strings --" << std::endl;
	Mystr a("Kha\'Zix");
	std::cout << "String a: ";
	std::cout << a << std::endl;

	Mystr b("son las");
	std::cout << "String b: ";
	std::cout << b << std::endl;

	Mystr c("Tresh");
	std::cout << "String c: ";
	std::cout << c << std::endl;
	/**************/
	Mystr d(a.Concatenate(Mystr("ola que Ashe")));
	std::cout << "Copied string 'a' and concatenated 'ola que Ashe': ";
	std::cout << d << std::endl;

	Mystr e(d.Substring(11, d.Length() - 7));
	std::cout << "11 characters cut from left and 7 from right: ";
	std::cout << e << std::endl;

	Mystr f(e.Concatenate(Mystr("Ketchup")));
	std::cout << "Concatenated 'Ketchup': ";
	std::cout << f << std::endl;

	std::cout << "Made it all uppercase (" << f.ToUpper() << " characters changed): ";
	std::cout << f << std::endl;
	/**************/
	std::cout << "Made string 'a' all lowercase (" << a.ToLower() << " characters changed): ";
	std::cout << a << std::endl;

	Mystr g(a.Concatenate(b.Concatenate(c)));
	std::cout << "Concatenated strings 'a', 'b' and 'c': ";
	std::cout << g << std::endl;

	if (g > f) {//Imprime primero la cadena mayor
		std::cout << g << std::endl;
		std::cout << f << std::endl;
	}
	else {
		std::cout << f << std::endl;
		std::cout << g << std::endl;
	}

	LinkedList list;
	list.insert(0, Mystr(" DOWN DOWN END_ "));
	list.insert(1, Mystr(" RULETA MOLA MAZO EHHH "));
	list.insert(2, Mystr(" NOOO CONFUNDAS ESTA TAREA "));
	list.insert(3, Mystr(" PEPE PAPA PIPI POPO PUPU "));
	list.insert(4, Mystr(" UP__ UP__ UP__ "));

	int i = 0;
	bool flag = true;

	while (list.getValue(i) != " ") {
		Mystr temp = list.getValue(i);
		temp.TrimLeft();
		list.setValue(i, temp);
		std::cout << list.getValue(i) << std::endl;

		if (list.getValue(i).StartsWith("DOWN")){
			flag = true;
		}
		else if (list.getValue(i).StartsWith("UP__")){
			flag = false;
		}

		temp = list.getValue(i).Right(list.getValue(i).Length() - 4);
		list.setValue(i, temp);
		
		if (flag)
			++i;
		else
			--i;

	}

	system("pause");

	return 0;
}