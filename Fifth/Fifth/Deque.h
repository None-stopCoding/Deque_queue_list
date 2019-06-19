#pragma once
#include "Elem.h"
class Deque
{
	Elem* top; // указатель на начало дека
public:
	Deque(); // конструктор
	void pushBack(int&); // добавляет элемент в конец дека
	void pushFront(int&); // добавляет элемент в начало дека
	void popBack(); // удаляет элемент из конца дека
	void popFront(); // удаляет элемент из начала дека
	void Print(); // выводит дек
	bool isEmpty(); // проверяет пустой ли дек
	int Front(); // верхушка дека
	int Back(); // хвост дека
	int Count(); // подсчитывает колво элементов в деке
};

