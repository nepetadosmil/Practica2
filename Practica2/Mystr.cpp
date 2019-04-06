#include "Mystr.h"

void Mystr::check_mem(unsigned chars) {
	if (chars >= this->Capacity()) {//If not enough memory
		this->capacity = ((chars + 1) * MEM_MULTIPLIER) + MEM_ADDER;

		realloc(this->string, sizeof(char) * this->Capacity());
		assert(this->string != NULL);
	}
	else if (chars < (this->Capacity() / (MEM_MULTIPLIER * 2))) {//If enough memory is not used free some of it
		this->capacity /= MEM_MULTIPLIER;
		
		realloc(this->string, sizeof(char) * this->Capacity());
		assert(this->string != NULL);
	}
}


Mystr::Mystr(){
	this->capacity = MEM_MULTIPLIER + MEM_ADDER;// [(1 * MEM_MULTIPLIER) + MEM_ADDER], where 1 is the number of characters to write including '\0'
	
	this->string = (char *)malloc(sizeof(char) * this->capacity);
	assert(this->string != NULL);//Memory was allocated

	this->string[0] = '\0';
}


Mystr::Mystr(const Mystr &other){
	this->capacity = ((strlen(other.string) + 1) * MEM_MULTIPLIER) + MEM_ADDER;
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

	this->check_mem(last_pos);//Reallocates memory if necessary 

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

	strncpy_s(temp, length + 1, this->string + start_index, length);

	Mystr nueva(temp);//Crea objeto
	free(temp);//Libera cadena temporal
	return nueva;
}


Mystr Mystr::Substring(unsigned initialIndex, unsigned finalIndex) {
	unsigned length = this->Length();
	assert(initialIndex >= 0 && initialIndex <= finalIndex);
	assert(finalIndex < length);
	
	length = finalIndex - initialIndex;
	char* temp = (char*)malloc(sizeof(char) * (length + 1));
	assert(temp != NULL);

	strncpy_s(temp, length + 1, this->string + initialIndex, length);
	Mystr nueva(temp);

	free(temp);

	return nueva;
}


unsigned Mystr::TrimRight() {
	int last = this->Length() - 1;//Last index
	unsigned count = 0;

	for (last; last >= 0 && this->string[last] == ' '; --last, ++count);//Find where the last character is
	this->string[++last] = '\0';//Go right after it and add the terminator

	this->check_mem(last);//Reallocates memory if necessary
	return count;
}


unsigned Mystr::TrimLeft() {
	int length = this->Length();//Last index
	unsigned first;

	for (first = 0; this->string[first] == ' '; ++first, --length);//Find where the first character is

	strncpy_s(this->string, length + 1, this->string + first, length);//Move the string to its new position without spaces

	this->check_mem(length);//Reallocates memory if necessary
	return first;
}


unsigned Mystr::Trim() {
	//We trim right first for efficiency (because TrimLeft will have to move less characters if any removed from the right)
	unsigned removed = this->TrimRight();
	removed += this->TrimLeft();
	return removed;
}


unsigned Mystr::ToUpper() {
	unsigned count = 0;
	char tmp;
	for (unsigned i = 0; this->string[i] != '\0'; ++i) {
		tmp = toupper(this->string[i]);
		
		if (tmp == this->string[i])
			continue;
		//If not ~UPPERCASE~ already
		this->string[i] = tmp;
		++count;
	}
	return count;
}


unsigned Mystr::ToLower() {
	unsigned count = 0;
	char tmp;
	for (unsigned i = 0; this->string[i] != '\0'; ++i) {
		tmp = tolower(this->string[i]);

		if (tmp == this->string[i])
			continue;
		//If not ~lowercase~ already
		this->string[i] = tmp;
		++count;
	}
	return count;
}


bool Mystr::StartsWith(const Mystr& other) {
	unsigned length = ((Mystr)other).Length();
	assert(length <= this->Length());
	return (!strncmp(this->string, other.string, length));
}


bool Mystr::EndsWith(const Mystr& other) {
	unsigned len_this = this->Length();
	unsigned len_other = ((Mystr)other).Length();
	assert(len_other <= len_this);

	return (!strcmp(this->string + len_this - len_other + 1, other.string));
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
