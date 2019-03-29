#include "Mystr.h"

Mystr::Mystr(){
	this->capacity = 0;
	this->string = (char *) malloc(sizeof(char));//Allocates space for '\0'
	this->string[0] = '\0';
}

Mystr::Mystr(const Mystr &other)
{
	this->capacity = other.capacity;
	this->string = (char *)malloc(sizeof(char) * (this->capacity + 1));//Space for string + '\0'
	assert(this->string != NULL);//Space was allocated
}

Mystr::Mystr(const char *other){
	assert(other != nullptr);//String exists

	this->capacity = strlen(other);//Capaity is length of string to copy
	this->string = (char *)malloc(sizeof(char) * (this->capacity + 1));//Space for string + '\0'
	assert(this->string != NULL);//Space was allocated

	strcpy(this->string, other);//Copies string
}

inline bool Mystr::operator==(const Mystr &other){
	if (strcmp(string, other.string) == 0)
		return true;
	return false;
}

inline bool Mystr::operator!=(const Mystr &other){
	return !((*this) == other);
}

inline bool Mystr::operator<(const Mystr & other){
	if (strcmp(string, other.string) < 0)
		return true;
	return false;
}

inline bool Mystr::operator>(const Mystr & other) {
	if (strcmp(string, other.string) > 0)
		return true;
	return false;
}

inline bool Mystr::operator<=(const Mystr & other) {
	return ((*this) > other);
}

inline bool Mystr::operator>=(const Mystr & other) {
	return !((*this) < other);
}

inline char & Mystr::operator[](int index){
	assert(index >= 0 && index < capacity);
	return this->string[index];
}
