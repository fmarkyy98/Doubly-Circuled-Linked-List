#include <string>
#include <fstream>
#include "Node.h"
#include "C2L.h"

Node* C2L::out(Node* removeable)
{
	removeable->prev->next = removeable->next;
	removeable->next->prev = removeable->prev;
	return removeable;
}

void C2L::remove(Node* removeable)
{
	removeable->prev->next = removeable->next;
	removeable->next->prev = removeable->prev;
	delete(removeable);
}

C2L::C2L()
{
	this->head = new Node();
	this->head->next = this->head;
	this->head->prev = this->head;
}

C2L::C2L(std::string filename) : C2L()
{
	std::ifstream ifs(filename);
	for (int item; ifs >> item;)
	{
		this->add(item);
	}
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

void C2L::symdiff(C2L& list)
{
	Node* cur1 = this->head->next;
	Node* cur2 = list.head->next;
	while (cur1 != this->head && cur2 != list.head)
	{
		if (cur1->value == cur2->value)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
			this->remove(cur1->prev);
			list.remove(cur2->prev);
		}
		else if (cur1->value < cur2->value)
		{
			cur1 = cur1->next;
		}
		else // cur1->value > cur2->value
		{
			cur2 = cur2->next;
			this->preseed(cur1, list.out(cur2->prev));
		}
	}
	//while (cur1 != this->head) // Unnecessary
	//{

	//}
	while (cur2 != list.head)
	{
		cur2 = cur2->next;
		this->preseed(this->head, list.out(cur2->prev));
	}
}

std::ostream& operator << (std::ostream& os, const C2L& l)
{
	os << '[';
	bool isFirst = true;
	for (Node* cur = l.head->next; cur != l.head; cur = cur->next)
	{
		if (isFirst)
		{
			os << cur->value;
			isFirst = false;
		}
		else
		{
			os << ',' << cur->value;
		}
	}
	os << ']';
	return os;
}