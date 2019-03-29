#include "Mystr.h"

Mystr::Mystr()
{
	this->capacity = 0;
	this->string = (char *) malloc(sizeof(char));//Allocates space for '\0'
	this->string[0] = '\0';
}


Mystr::Mystr(const Mystr &other)
{
	this->capacity = other.capacity;
	this->string = (char *) malloc(sizeof(char) * (this->capacity + 1));//Space for string + '\0'
	assert(this->string != NULL);//Space was allocated

	strcpy(this->string, other.string);//Copies string
}


Mystr::Mystr(const char *other)
{
	assert(other != nullptr);//String exists

	this->capacity = strlen(other);//Capaity is length of string to copy
	this->string = (char *)malloc(sizeof(char) * (this->capacity + 1));//Space for string + '\0'
	assert(this->string != NULL);//Space was allocated

	strcpy(this->string, other);//Copies string
}
