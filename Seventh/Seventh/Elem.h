#pragma once
class Elem
{
public:
	int val; // значение, которое хранит элемент
	Elem* next, *prev; // указатель на адрес следующего элемента
	Elem(int&); // конструктор
};

