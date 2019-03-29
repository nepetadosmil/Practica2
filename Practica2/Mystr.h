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

	/************/
	/*DESTRUCTOR*/
	/************/
	~Mystr();
};

