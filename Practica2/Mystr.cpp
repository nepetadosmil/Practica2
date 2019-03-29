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
