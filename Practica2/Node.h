#pragma once
#include "Mystr.h"

// Node of a Linked List
struct Node
{
	Mystr element; // Element of Node
	Node* next; // Pointer to the next Node
	Node* prev; // Pointer to the previous Node
};