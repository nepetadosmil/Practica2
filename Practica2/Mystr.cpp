#include "Mystr.h"

Mystr::Mystr(){
	this->capacity = 0;
	this->string = (char *) malloc(sizeof(char));
	this->string[0] = '\0';
}

Mystr::Mystr(const Mystr &other){

}


Mystr::Mystr(const char *other){

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
