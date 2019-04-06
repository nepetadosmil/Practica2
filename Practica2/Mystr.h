#pragma once

#include <assert.h>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define MEM_MULTIPLIER 2	//How much extra space shall be allocated (multiplier) !!MUST BE >0!!
#define MEM_ADDER	   0	//How many extra spaces shall be allocated (adder) !!MUST BE >=0!!

class Mystr
{
	unsigned capacity;
	char *string;

	// (Re)allocates memory where/when necessary
	// !!IT DOES NOT FREE MEMORY COMPLETELY!! - It will always add an extra space for terminator '\0'
	// @Param	unsigned	Current number of characters to be stored (not counting terminator)
	// @Return	char *		Memory location to store needed number of characters + '\0'
	void check_mem(unsigned needed);
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
	//@Param	char[]	string to copy/create from
	//@Precond			other != NULL
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

	// Gets the string of n characters from the left
	// @Param	unsigned		Number of characters from the start
	// @Precond					num <= length
	// @Return	Mystr			Object with the string of length given
	Mystr Left(unsigned num);

	// Gets the string of n characters from the right
	// @Param	unsigned		Number of characters from the end
	// @Precond					num <= length
	// @Return	Mystr			Object with the string of length given
	Mystr Right(unsigned num);

	// Gets the string from indicated start to indicated end
	// @Param	unsigned		First index
	// @Param	unsigned		Last index
	// @Precond					initialIndex >= 0 && initialIndex <= finalIndex
	// @Precond					finalIndex < length
	// @Return	Mystr			Object with the string requested
	Mystr Substring(unsigned initialIndex, unsigned finalIndex);

	// Removes any spaces from the right side of the string
	// @Return	unsigned		Number of spaces removed
	unsigned TrimRight();

	// Removes any spaces from the left side of the string
	// @Return	unsigned		Number of spaces removed
	unsigned TrimLeft();

	// Removes any spaces from the left AND the right of the string
	// @Return	unsigned		Total number of spaces removed
	unsigned Trim();

	// Converts the string to uppercase
	// @Return	unsigned		Total number of characters converted to uppercase
	unsigned ToUpper();

	// Converts the string to uppercase
	// @Return	unsigned		Total number of characters converted to uppercase
	unsigned ToLower();

	// Checks if the string starts with parameter given
	// @Param	const &Mystr	String to compare the beginning
	// @Returns	bool			true if string starts with the one given
	bool StartsWith(const Mystr& other);

	// Prints the string
	void Print();



	/*************/
	/* OPERATORS */
	/*************/

	// Compares if two Mystr are equal.
	// @Param	Mystr			Mystr to compare
	// @Return	bool			result of the comparation
	bool operator == (const Mystr &other);

	// Compares if two Mystr are different.
	// @Param	Mystr			Mystr to compare
	// @Return	bool			result of the comparation
	bool operator != (const Mystr &other);

	// Compares if a Mystr is smaller than other.
	// @Param	Mystr			Mystr to compare
	// @Return	bool			result of the comparation
	bool operator < (const Mystr& other);

	// Compares if a Mystr is greater than other.
	// @Param	Mystr			Mystr to compare
	// @Return	bool			result of the comparation
	bool operator > (const Mystr& other);

	// Compares if a Mystr is equal or smaller than other.
	// @Param	Mystr			Mystr to compare
	// @Return	bool			result of the comparation
	bool operator <= (const Mystr& other);

	// Compares if a Mystr is equal or greater than other.
	// @Param	Mystr			Mystr to compare
	// @Return	bool			result of the comparation
	bool operator >= (const Mystr& other);

	// Get the character at given index.
	// @Precond					index >= 0 && index < capacity
	// @Param	int				index to find
	// @Return	char			character at index
	char &operator [] (unsigned index);

	/**************/
	/* DESTRUCTOR */
	/**************/
	~Mystr();
};

