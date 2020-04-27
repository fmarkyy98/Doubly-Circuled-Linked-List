#pragma once
#include <string>
#include <iostream>
#include "Node.h"

class C2L
{
private:
	Node* head;

	Node* out(Node* removeable);
	void remove(Node* removeable);

public:


	C2L();
	C2L(std::string filename);
	void preseed(Node* reference, Node* insertable);
	void add(int value);
	void symdiff(C2L& list);
	friend std::ostream& operator << (std::ostream& os, const C2L& l);
};

