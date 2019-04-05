#pragma once

#include <assert.h>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define MEM_MULTIPLIER 2	//How much extra space shall be allocated (multiplier) !!IF <= 0, NO SPACE WILL EVER BE ALLOCATED!!
#define MEM_ADDER	   0	//How many extra spaces shall be allocated (adder)

class Mystr
{
	unsigned capacity;
	char *string;

public:

	/****************/
	/* CONSTRUCTORS */
	/****************/

	//Creates string with '\0' as the only character
	Mystr();
	
	//Copies another str object
	//@Param	Mystr	Mystr object to copy
	Mystr(const Mystr &other);
	
	//Creates a Mystr object from the given string
	//@Precond		other != NULL
	Mystr(const char *other);


	/*************/
	/* FUNCTIONS */
	/*************/

	// Size of char array
	// @Return	unsigned		size of char array
	unsigned Length();

	// Capacity of allocated memory
	// @Return	unsigned		capacity of memory allocated
	unsigned Capacity();

	// Search characters equal to find and replaces them by replaceBy
	// @Param	char find		character replaced
	// @Param	char replaceBy	new character
	// @Return	int				number of characters replaced
	int Replace(char find, char replaceBy);

	// Compare two Mystr
	// @Param	const Mystr		Mystr to compare
	// @Return	unsigned int	0 if are equal, 1 if the first Mystr is greater, and -1 if it's smaller
	int Compare(const Mystr &other);

	// Compare two Mystr
	// @Param	char find		character to remove
	// @Return	unsigned int	number of characters removed
	int Remove(char find);

	// Gets the string of n characters from the end
	// @Param	unsigned int	Number of characters from the end

	void Print();


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

