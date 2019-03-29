#pragma once

#include <assert.h>
#include <cstdlib>
#include <cstring>

#define MEM_MULTIPLIER 2//Cu�nto espacio de m�s se debe reservar para string (Multiplicador)
#define MEM_ADDER 0//Cu�nto espacios de m�s se deben reservar para string (Sumador)

class Mystr
{
	int capacity;
	char *string;
public:
	Mystr();
	Mystr(const Mystr &other);
	Mystr(const char *other);
	inline bool operator==(const Mystr &other);
	~Mystr();
};

