#include "Mystr.h"

Mystr::Mystr(){
	this->capacity = MEM_MULTIPLIER + MEM_ADDER;// [1 * (MEM_MULTIPLIER + MEM_ADDER)], where 1 is the number of characters to write including '\0'
	this->string = (char *)malloc(sizeof(char) * this->capacity);
	
	assert(this->string != NULL);//Memory was allocated
	this->string[0] = '\0';
}

Mystr::Mystr(const Mystr &other){
	this->capacity = other.capacity;//Will be exact copy. Capacity includes '\0' and any extra space
	this->string = (char *)malloc(sizeof(char) * this->capacity);
	
	assert(this->string != NULL);//Memory was allocated
	strcpy_s(this->string, sizeof(char) * this->capacity, other.string);
}

Mystr::Mystr(const char *other){
	assert(other != nullptr);//String exists

	this->capacity = ((strlen(other) + 1) * MEM_MULTIPLIER) + MEM_ADDER;//Includes '\0' and extra space(s)
	this->string = (char *)malloc(sizeof(char) * this->capacity);

	assert(this->string != NULL);//Memory was allocated
	strcpy_s(this->string, sizeof(char) * this->capacity, other);
}

unsigned Mystr::Length(){
	return (unsigned)strlen(string);
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

	if (Length() <= Capacity() / 4){
		// REDUCE CAPACITY
		capacity /= 2;
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

Mystr::~Mystr(){
	free(this->string);
}
