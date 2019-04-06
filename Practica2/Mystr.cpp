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
	return (unsigned)strlen(this->string);
}



unsigned Mystr::Capacity(){
	return this->capacity;
}


int Mystr::Replace(char find, char replaceBy){
	int replaced = 0;//Counts characters replaced
	unsigned length = this->Length();//Only get the length once

	for (unsigned i = 0; i < length; ++i) {//Iterates over string
		if (string[i] == find) {//If matches character to search
			string[i] = replaceBy;
			++replaced;
		}
	}

	return replaced;
}


int Mystr::Compare(const Mystr & other){
	/*if ((*this) == other)//Son iguales
		return 0;
	else if ((*this) > other)//Esta es mayor que other
		return 1;
	return -1;//Other es mayor que esta*/

	//Más eficiente (En ejercicio pone que SE PUEDE USAR strcmp)
	return strcmp(this->string, other.string);
}


int Mystr::Remove(char find){
	int removed = 0;//Counts characters that get removed
	unsigned length = this->Length();

	for (unsigned i = 0; i < length; ++i) {//Replaces all matches with '\0'. We'll later move all characters to their new places
		//By doing it this way, we only need to iterate the string twice and not once per match
		if (this->string[i] == find){
			this->string[i] = '\0';
			++removed;
		}
	}

	unsigned i;
	unsigned last_pos;//We need it out of loop to add the new '\0' at the end
	for (i = 0, last_pos = 0; i < length; ++i) {//Replace all characters to be replaced
		if (this->string[i] != '\0') {
			this->string[last_pos++] = this->string[i];
		}
	}
	this->string[last_pos] = '\0';
	length = last_pos++;

	if (last_pos <= (this->Capacity() / (MEM_MULTIPLIER * 2))){//If string (including '\0') uses less than (1/2)*(MEM_MULTIPLIER) of the capacity, free MEM_MULTIPLIER size
		// REDUCE CAPACITY
		capacity /= MEM_MULTIPLIER;
		this->string = (char *)realloc(this->string, sizeof(char) * this->capacity);
		assert(this->string != NULL);
	}

	return removed;
}


Mystr Mystr::Left(unsigned num){
	assert(num <= this->Length());
	
	char* temp = (char *)malloc(sizeof(char) * (num + 1));
	assert(temp != NULL);
	strncpy_s(temp, num + 1, this->string, num);

	Mystr nueva(temp);//Crea objeto
	free(temp);//Libera cadena temporal
	return nueva;
}

Mystr Mystr::Right(unsigned num) {
	unsigned length = this->Length();
	assert(num <= length);

	unsigned start_index = length - num;//Index of first character
	length = length - start_index;
	
	char* temp = (char*)malloc(sizeof(char) * (length + 1));
	assert(temp != NULL);

	strncpy_s(temp, num + 1, this->string + start_index, num);

	Mystr nueva(temp);//Crea objeto
	free(temp);//Libera cadena temporal
	return nueva;
}


void Mystr::Print(){
	std::cout << string << std::endl;
}



/*************/
/* OPERATORS */
/*************/
bool Mystr::operator==(const Mystr &other){
	return (!strcmp(string, other.string));
}

bool Mystr::operator!=(const Mystr &other){
	return !((*this) == other);
}

bool Mystr::operator<(const Mystr & other){
	return (strcmp(this->string, other.string) < 0);
}

bool Mystr::operator>(const Mystr & other) {
	return (strcmp(this->string, other.string) > 0);
}

bool Mystr::operator<=(const Mystr & other) {
	return ((*this) > other);
}

bool Mystr::operator>=(const Mystr & other) {
	return !((*this) < other);
}

char & Mystr::operator[](unsigned index){
	assert(index < this->capacity);
	return this->string[index];
}

Mystr::~Mystr(){
	free(this->string);
}
