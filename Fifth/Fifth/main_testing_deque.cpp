#include <iostream>
#include <conio.h>
#include <ctime>
#include "Deque.h"
using namespace std;
Deque deque, help;

// �������� ���� ��������� �����
void createDeque() {
	int tmp = 10;
	int value = 0;
	while (tmp--) {
		value = rand() % 10 + 1;
		deque.pushBack(value);
	}
}

// ������ ������������ ���� ����� �� ������ ����� � ����
void putNum(int tmp) {
	int new_tmp = deque.Count() - tmp - 2;
	int res = deque.Front();
	int work = deque.Back();
	res *= work;
	deque.popBack();
	deque.pushBack(res);
	deque.pushBack(work);
}

// ���� ����� ������� ���� ������������
int findNum() {
	int num = 0, flag = 0, tmp = deque.Count();
	int was = deque.Front();
	cout << "���� �����: "; cin >> num;
	while (tmp--) {
		if (num == deque.Front()) {
			putNum(tmp);
			flag += 1;
		}
		int work = deque.Front();
		deque.popFront();
		deque.pushBack(work);
	}
	return flag;
}

// ��������� ��������������� ���
void fillHelp() {
	int tmp = deque.Count();
	while (tmp--) {
		int work = deque.Front();
		deque.popFront();
		deque.pushBack(work);
		help.pushFront(work);
	}
}

// ����������� �������� ��� �� ������ ����������������
void increaseDeque() {
	int tmp = deque.Count();
	while (tmp--) {
		int work = help.Back();
		help.popBack();
		help.pushFront(work);
		deque.pushFront(work);
	}
}

// ����� ������� (6, 24)
int Choose() {
	cout << "�������� �������: ";
	int num = 0;
	cin >> num;
	system("cls");
	return num;
}

// �������� ���������
int main() {
	setlocale(LC_ALL, "rus");
	int choice = Choose();
	srand(time(NULL));
	createDeque();
	deque.Print();

	if (choice == 6) {
		if (!findNum()) cout << "������ ����� ���" << endl;
		deque.Print();
	}
	else if (choice == 24) {
		fillHelp();
		increaseDeque();
		deque.Print();
	}
	else {
		cout << "\n�� ��� �������)\n" << endl;
	}

	int n = _getch();
	return 0;
}