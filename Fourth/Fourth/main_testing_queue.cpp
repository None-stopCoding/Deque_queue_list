#include <iostream>
#include <conio.h>
#include <ctime>
#include "Queue.h"

using namespace std;
Queue queue;

// ��������� �������
void createQueue() {
	int tmp = 10;
	int value = 0;
	while (tmp--) {
		value = rand() % 5 + 1;
		queue.Enqueue(value);
	}
}

// ������������ ������������ ��������� �������
int countMult(){
	int mult = 1, tmp_size = queue.Count();
	while (tmp_size--) {
		int work = queue.Begin();
		mult *= work;
		queue.Dequeue();
		queue.Enqueue(work);
	}
	return mult;
}

// ������ ������� � ������ �������
void pushMult(int& mult) {
	int tmp_size = queue.Count() - 1;
	queue.Dequeue();
	queue.Enqueue(mult);
	while (tmp_size--) {
		int work = queue.Begin();
		queue.Dequeue();
		queue.Enqueue(work);
	}
}

// ���������� true, ���� ������� ���� � �������, false - �����
bool hasElem(int& el, int tmp) {
	int tmp_size = tmp;
	bool flag = false;
	while (tmp_size--) {
		int work = queue.Begin();
		if (work == el) flag = true;
		queue.Dequeue();
		queue.Enqueue(work);
	}
	return flag;
}

// ������� �� ������� ��������������� ��������
void takeOutWithNoRepeat() {
	int tmp_size = queue.Count(), tmp = queue.Count();
	while (tmp_size--) {
		int work = queue.Begin();
		queue.Dequeue(); tmp--;
		if (hasElem(work, tmp)) {
			queue.Enqueue(work); tmp++;
		}
	}
}

// ����� �������
int Choose() {
	cout << "�������� �������: ";
	int num = 0;
	cin >> num;
	return num;
}

// �������� ���������
int main() {
	setlocale(LC_ALL, "rus");
	int choice = Choose();
	srand(time(NULL));
	createQueue();
	queue.Print();

	
	if (choice == 12) {
		int pr = countMult();
		pushMult(pr);
		queue.Print();
	}

	else if (choice == 22) {
		takeOutWithNoRepeat();
		queue.Print();
	}

	else {
		cout << "������ � ���� ���" << endl;
	}

	int n =_getch();
	return 0;
}