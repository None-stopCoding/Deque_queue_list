#pragma once
#include "Elem.h"
class Queue
{
	Elem* run; // ������ �������
public:
	Queue(); // �����������
	void Enqueue(int&); // ��������� ������� � �������
	void Dequeue(); // �������� ������� �� �������
	void Print(); // ������� �������� �������
	bool isEmpty(); // ��������� ����� �� �������
	int Begin(); // ��������� ������ �������
	int Count(); // ������� ����� ��������� � �������
};

