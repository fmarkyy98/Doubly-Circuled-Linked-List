#include "Node.h"
#include "C2L.h"

C2L::C2L()
{
	this->head = new Node();
	this->head->next = this->head;
	this->head->prev = this->head;
}

void C2L::preseed(Node* reference, Node* insertable)
{
	insertable->next = reference;
	insertable->prev = reference->prev;
	reference->prev->next = insertable;
	reference->prev = insertable;
}

void C2L::add(int value)
{
	Node* result = new Node;
	result->value = value;
	for (Node* cur = this->head->next; true; cur = cur->next) // Na ezt nevezem barkácsolásnak :D
	{
		if (cur == head || cur->value > value)
		{
			this->preseed(cur, result);
			return;
		}
	}
}