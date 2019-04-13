#include "LinkedList.h"
#include "Node.h"

#include <stdlib.h>

LinkedList::LinkedList() {
	list = nullptr;
	n = 0;
	lastConsultedNodePosition = -1;
	lastConsultedNode = nullptr;
}

Node* LinkedList::getNode(int pos) {
	Node* temp = list;

	for (int i = 0; i < pos; i++)
		temp = temp->next;
	lastConsultedNode = temp;
	return temp;
}

Mystr LinkedList::getValue(int pos) {
	return getNode(pos)->element;
}

void LinkedList::setValue(int pos, Mystr newValue) {
	getNode(pos)->element = newValue;
}

int LinkedList::getN() {
	return n;
}

void LinkedList::insert(int pos, Mystr newValue) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->element = newValue;

	if (pos == 0 && n == 0) {
		newNode->prev = newNode;
		newNode->next = newNode;
		list = newNode;
	}
	else if (pos == 0 && n != 0) {
		Node* temp = list;
		newNode->next = list;
		newNode->prev = list->prev;
		list->prev->next = newNode;
		list = newNode;
	}
	else if (pos == n) {
		newNode->prev = getNode(pos - 1);
		newNode->next = list;
		newNode->prev->next = newNode;
		list->prev = newNode;
		if (pos == 1)
			list->next = newNode;
	}
	else {
		Node* temp = getNode(pos);
		temp->prev->next = newNode;
		newNode->prev = temp->prev;
		temp->prev = newNode;
		newNode->next = temp;
	}
	++n;
	lastConsultedNodePosition = -1;
	lastConsultedNode = nullptr;
}

void LinkedList::deleteNode(int pos) {
	if (pos == 0 && n == 0) {
		list = nullptr;
		n = 0;
		lastConsultedNodePosition = -1;
		lastConsultedNode = nullptr;
	}
	else if (pos == 0 && n != 0) {
		Node* tmp = list;
		list->prev->next = list->next;
		list->next->prev = list->prev;
		list = list->next;
		free(tmp);
	}
	else if (pos == n) {
		Node* tmp = list->prev;
		list->prev->prev->next = list;
		list->prev = list->prev->prev;
		free(tmp);
	}
	else {
		Node* tmp = getNode(pos);
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	lastConsultedNodePosition = -1;
	lastConsultedNode = nullptr;
	--n;
}

LinkedList::~LinkedList() {
	free(list);
}
