#pragma once
#include "Node.h"

class C2L
{
private:
	Node* head;

public:
	C2L();
	void preseed(Node* reference, Node* insertable);
	void add(int value);
	void symdiff(C2L l);
};

