#pragma once

#include <assert.h>
#include <cstdlib>
#include <cstring>

#define MEM_MULTIPLIER 2	//How much extra space shall be allocated (multiplier)
#define MEM_ADDER 0			//How much extra space shall be allocated (adder)

class Mystr
{
	int capacity;
	char *string;
public:

	/****************/
	/* CONSTRUCTORS */
	/****************/

	//Creates string with '\0' as the only character
	Mystr();
	
	//Copies another str object
	Mystr(const Mystr &other);
	
	//Creates a Mystr object from the given string
	//@Precond		other != NULL
	Mystr(const char *other);


	/*************/
	/* FUNCTIONS */
	/*************/

	// Size of char array
	// @Return	unsigned int	size of char array
	unsigned int Length();

	// Capacity of allocated memory
	// @Return	unsigned int	capacity
	unsigned int Capacity();

	// Search characters equal to find and replaces them by replaceBy
	// @Param	char find		character replaced
	// @Param	char replaceBy	new character
	// @Return	unsigned int	number of characters replaced
	int Replace(char find, char replaceBy);

	/*************/
	/* OPERATORS */
	/*************/

	// Compares if two Mystr are equal.
	// @Param	Mystr			Mystr to compare
	// @Return	bool			result of the comparation
	inline bool operator == (const Mystr &other);

	// Compares if two Mystr are different.
	// @Param	Mystr			Mystr to compare
	// @Return	bool			result of the comparation
	inline bool operator != (const Mystr &other);

	// Compares if a Mystr is smaller than other.
	// @Param	Mystr			Mystr to compare
	// @Return	bool			result of the comparation
	inline bool operator < (const Mystr& other);

	// Compares if a Mystr is greater than other.
	// @Param	Mystr			Mystr to compare
	// @Return	bool			result of the comparation
	inline bool operator > (const Mystr& other);

	// Compares if a Mystr is equal or smaller than other.
	// @Param	Mystr			Mystr to compare
	// @Return	bool			result of the comparation
	inline bool operator <= (const Mystr& other);

	// Compares if a Mystr is equal or greater than other.
	// @Param	Mystr			Mystr to compare
	// @Return	bool			result of the comparation
	inline bool operator >= (const Mystr& other);

	// Get the character at given index.
	// @Precond					index >= 0 && index < capacity
	// @Param	int				index to find
	// @Return	char			character at index
	inline char &operator [] (int index);

	/**************/
	/* DESTRUCTOR */
	/**************/
	~Mystr();
};

