#pragma once

class Elem {
public:
	int val; // значение, которое хранит элемент дека
	Elem* next; // указатель на следующий элемент дека
	Elem(int&); // конструктор
};