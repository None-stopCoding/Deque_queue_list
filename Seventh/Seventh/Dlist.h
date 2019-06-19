#pragma once
#include "Elem.h"
class Dlist
{
	Elem* head; // ������� ������
	Elem* tail; // ����� ������
public:
	Dlist(); //  �����������
	void pushBack(int&);
	void pushFront(int&);
	void printNext();
	void printPrev();
	int* findByVal(int&);
	int findByIndex(int);
	void pushAfter(int&, int&);
	void pushBefore(int&, int&);
	void popBack();
	void popFront();
	void popAfter(int&);
	void popBefore(int&);
	bool isEmpty();
	int Count();
};

