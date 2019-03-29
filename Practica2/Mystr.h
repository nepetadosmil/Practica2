#pragma once

#include <assert.h>
#include <cstdlib>
#include <cstring>

#define MEM_MULTIPLIER 2//Cuánto espacio de más se debe reservar para string (Multiplicador)
#define MEM_ADDER 0//Cuánto espacios de más se deben reservar para string (Sumador)

class Mystr
{
	int capacity;
	char *string;
public:
	Mystr();
	Mystr(const Mystr &other);
	Mystr(const char *other);

	/***********/
	/*OPERATORS*/
	/***********/

	inline bool operator == (const Mystr &other);
	inline bool operator != (const Mystr &other);
	inline bool operator < (const Mystr& other);
	inline bool operator > (const Mystr& other);

	inline bool operator <= (const Mystr& other);

	// Compares if a Mystr is greater than other.
	// @Param	Mystr	Mystr to compare
	// @Return	bool	result of the comparation
	inline bool operator >= (const Mystr& other);

	// Get the character at given index.
	// @Precond			index >= 0 && index < capacity
	// @Param	int		index to find
	// @Return	char	character at index
	inline char &operator [] (int index);

	~Mystr();
};

