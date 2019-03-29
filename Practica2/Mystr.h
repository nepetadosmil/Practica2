#pragma once

#include <assert.h>
#include <cstdlib>
#include <cstring>

#define MEM_MULTIPLIER 2//How much extra space shall be allocated (multiplier)
#define MEM_ADDER 0//How much extra space shall be allocated (adder)

class Mystr
{
	int capacity;
	char *string;
public:
	/**************/
	/*CONSTRUCTORS*/
	/**************/
	//Creates string with '\0' as the only character
	Mystr();
	
	//Copies another str object
	Mystr(const Mystr &other);
	
	//Creates a Mystr object from the given string
	//@Precond		other != NULL
	Mystr(const char *other);


	/***********/
	/*FUNCTIONS*/
	/***********/


	/************/
	/*DESTRUCTOR*/
	/************/
	~Mystr();
};

