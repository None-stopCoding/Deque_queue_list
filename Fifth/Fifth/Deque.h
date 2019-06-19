#pragma once
#include "Elem.h"
class Deque
{
	Elem* top; // ��������� �� ������ ����
public:
	Deque(); // �����������
	void pushBack(int&); // ��������� ������� � ����� ����
	void pushFront(int&); // ��������� ������� � ������ ����
	void popBack(); // ������� ������� �� ����� ����
	void popFront(); // ������� ������� �� ������ ����
	void Print(); // ������� ���
	bool isEmpty(); // ��������� ������ �� ���
	int Front(); // �������� ����
	int Back(); // ����� ����
	int Count(); // ������������ ����� ��������� � ����
};

