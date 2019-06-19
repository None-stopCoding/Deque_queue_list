#pragma once
#include "Elem.h"
class Queue
{
	Elem* run; // голова очереди
public:
	Queue(); // конструктор
	void Enqueue(int&); // поставить элемент в очередь
	void Dequeue(); // вытащить элемент из очереди
	void Print(); // вывести элементы очереди
	bool isEmpty(); // проверяет пуста ли очередь
	int Begin(); // вовращает голову очереди
	int Count(); // считает колво элементов в очереди
};

