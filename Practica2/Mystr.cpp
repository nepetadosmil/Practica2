#include "Mystr.h"

Mystr::Mystr(){
	this->capacity = 0;
	this->string = (char *) malloc(sizeof(char));//Allocates space for '\0'
	this->string[0] = '\0';
}

Mystr::Mystr(const Mystr &other){
	this->capacity = other.capacity;
	this->string = (char *)malloc(sizeof(char) * (this->capacity + 1));//Space for string + '\0'
	assert(this->string != NULL);//Space was allocated
}

Mystr::Mystr(const char *other){
	assert(other != nullptr);//String exists

	this->capacity = (int)strlen(other);//Capaity is length of string to copy

	size_t space = sizeof(char) * (this->capacity + 1);//Size of memory to allocate
	this->string = (char *)malloc(space);//Space for string + '\0'
	assert(this->string != NULL);//Space was allocated

	strcpy_s(this->string, space, other);//Copies string
}

unsigned int Mystr::Length(){
	return (unsigned int)strlen(string);
}

unsigned int Mystr::Capacity(){
	return capacity;
}

int Mystr::Replace(char find, char replaceBy){
	int replaced = 0;


	for (unsigned i = 0; i < Length(); ++i){
		if (string[i] == find){
			string[i] = replaceBy;
			++replaced;
		}
	}

	return replaced;
}

int Mystr::Compare(const Mystr & other){
	if ((*this) == other)
		return 0;
	else if ((*this) > other)
		return 1;
	return -1;
}

int Mystr::Remove(char find){
	int removed = 0;

	for (unsigned int i = 0; i < Length(); i++) {
		if (string[i] == find) {
			for (i; i < Length(); i++){
				string[i] = string[i+1];
			}
			++removed;
		}
	}

	return removed;
}

void Mystr::Print(){
	std::cout << string << std::endl;
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

Mystr::~Mystr()
{
}
