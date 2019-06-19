#include <iostream>
#include <conio.h>
#include <ctime>
#include "Dlist.h"
using namespace std;
Dlist dlist;

// �������� ������ ��������� �����
void createDlist() {
	int tmp = 2;
	int value = 0;
	while (tmp--) {
		value = rand() % 10 + 1;
		dlist.pushBack(value);
	}
}

// ������� ������������ ������� ������
void findMax(int& max) {
	int tmp = dlist.Count();
	while (tmp--) {
		int work = dlist.findByIndex(0);
		if (work > max) max = work;
		dlist.popFront();
		dlist.pushBack(work);
	}
}

// ���������� ���������������� ������ ������� �������
void insertionSort() {
	int size_ = dlist.Count();
	int buff = 0, i, j;
	for (i = 1; i < size_; i++) {
		buff = dlist.findByIndex(i);
		j = i - 1;
		while (j >= 0 && dlist.findByIndex(j) > buff) {
			// a[j + 1] = a[j];
			dlist.popAfter(j);
			int work = dlist.findByIndex(j);
			dlist.pushAfter(j, work);

			--j;
		}
		// a[j + 1] = buff;
		dlist.popAfter(j);
		dlist.pushAfter(j, buff);
	}
}

// ����� ������� (23, 33)
int Choose() {
	cout << "�������� �������: ";
	int num = 0;
	cin >> num;
	system("cls");
	return num;
}

void add() {
	int key = 0, choice = 0, pressed = 0;
	do
	{
		system("cls");
		if (pressed) {
			cout << "����������? (Esc - ���, Enter - ��)";
			key = _getch();
		}
		if (key != 27) {
			pressed = 1;
			system("cls");
			cout << "\n����� ������� ��������: "; int el = 0; cin >> el;

			cout << "�������� �������: " << endl;

			cout << "\t1.� ������ ������" << endl;
			cout << "\t2.� ����� ������" << endl;
			cout << "\t3.����� ����������" << endl;
			cout << "\t4.����� ���������" << endl;
			cout << "��� ����� : ";

			choice = _getch();
			system("cls");
			cout << "������ �� ���������: ";
			dlist.printNext();
			switch (choice)
			{
			case 49:
			{
				dlist.pushFront(el);
				break;
			}
			case 50:
			{
				dlist.pushBack(el);
				break;
			}
			case 51:
			{
				cout << "\n����� ������ (������): "; int after = 0; cin >> after;
				dlist.pushAfter(after, el);
				break;
			}
			case 52:
			{
				cout << "\n����� ����� (������): "; int before = 0; cin >> before;
				dlist.pushBefore(before, el);
				break;
			}
			default:
			{
				cout << "\n���������� �����. ������ ������ ���." << endl;
				break;
			}
			}
			cout << "������ ����� ���������: ";
			dlist.printNext();
			int n = _getch();
		}

	} while (key != 27);
}

void del() {
	int key = 0, choice = 0, pressed = 0;
	do
	{
		system("cls");
		if (pressed) {
			cout << "����������? (Esc - ���, Enter - ��)";
			key = _getch();
		}
		if (key != 27) {
			pressed = 1;
			system("cls");
			cout << "������� �������: " << endl;

			cout << "\t1.� ������ ������" << endl;
			cout << "\t2.� ����� ������" << endl;
			cout << "\t3.����� ����������" << endl;
			cout << "\t4.����� ���������" << endl;
			cout << "��� ����� : ";

			choice = _getch();
			system("cls");
			cout << "������ �� ���������: ";
			dlist.printNext();
			switch (choice)
			{
			case 49:
			{
				dlist.popFront();
				break;
			}
			case 50:
			{
				dlist.popBack();
				break;
			}
			case 51:
			{
				cout << "\n����� ������ (������): "; int after = 0; cin >> after;
				dlist.popAfter(after);
				break;
			}
			case 52:
			{
				cout << "\n����� ����� (������): "; int before = 0; cin >> before;
				dlist.popBefore(before);
				break;
			}
			default:
			{
				cout << "\n���������� �����. ������ ������ ���." << endl;
				break;
			}
			}
			if (dlist.isEmpty()) { cout << "������ ����" << endl; key = 27; }
			else {
				cout << "������ ����� ���������: ";
				dlist.printNext();
			}
			int n = _getch();
		}

	} while (key != 27 && dlist.Count());
	if (!dlist.Count()) cout << endl << "������ ����" << endl;
	int lj = _getch();
}

void find() {
	int key = 0, choice = 0, pressed = 0;
	do
	{
		system("cls");
		if (pressed) {
			cout << "����������? (Esc - ���, Enter - ��)";
			key = _getch();
		}
		if (key != 27) {
			pressed = 1;
			system("cls");
			cout << "����� �������: " << endl;

			cout << "\t1.�� �������" << endl;
			cout << "\t2.�� ��������" << endl;
			cout << "��� ����� : ";

			choice = _getch();
			system("cls");
			cout << "������: ";
			dlist.printNext();
			switch (choice)
			{
			case 49:
			{
				cout << "\n������: "; int index = 0; cin >> index;
				int val = dlist.findByIndex(index);
				if (val) printf("������� � �������� %d ����� �������� %d", index, val);
				else cout << "�������� � ����� �������� ���";
				break;
			}
			case 50:
			{
				cout << "\n��������: "; int val = 0; cin >> val;
				int* index = dlist.findByVal(val);
				if (index) {
					for (int i = 0; i < dlist.Count(); i++)
						if (index[i] != -1)
							printf("������ �������� %d ����� %d\n", val, index[i]);
				}
				else cout << "������ �������� ���";
				break;
			}
			default:
			{
				cout << "\n���������� �����. ������ ������ ���." << endl;
				break;
			}
			}
			int n = _getch();
		}

	} while (key != 27);
}

void print() {
	system("cls");

	cout << "��������� Next: "; dlist.printNext();
	cout << "��������� Prev: "; dlist.printPrev();
	int n = _getch();
}

void solve() {
	int key = 0, choice = 0, pressed = 0;
	do
	{
		system("cls");
		if (pressed) {
			cout << "����������? (Esc - ���, Enter - ��)";
			key = _getch();
		}
		if (key != 27) {
			pressed = 1;
			system("cls");
			cout << "������: " << endl;

			cout << "\t1.����� ������������ ������� � ������" << endl;
			cout << "\t2.������������� ������" << endl;
			cout << "��� ����� : ";

			choice = _getch();
			system("cls");
			cout << "������ �� ���������: ";
			dlist.printNext();
			switch (choice)
			{
				case 49:
				{
					int max = 0;
					findMax(max);
					printf("������������ �������: %d", max);
					break;
				}
				case 50:
				{
					insertionSort();
					cout << "������ ����� ���������: ";
					dlist.printNext();
					break;
				}
				default:
				{
					cout << "\n���������� �����. ������ ������ ���." << endl;
					break;
				}
			}
			int n = _getch();
		}
	} while (key != 27);
}

// �������� ���������
int main() {
	setlocale(LC_ALL, "rus");
	int key = 0, fin = 0;
	srand(time(NULL));
	createDlist();
	do
	{
		system("cls");
		cout << "����: " << endl;

		cout << "\t1.�������� �������" << endl;
		cout << "\t2.������� �������" << endl;
		cout << "\t3.����� �������" << endl;
		cout << "\t4.������� ������" << endl;
		cout << "\t5.������ ������" << endl;
		cout << "\tEsc. ���������\n" << endl;
		cout << "��� ����� : ";

		key = _getch();
		switch (key)
		{
		case 49:
		{
			add();
			break;
		}
		case 50:
		{
			if (dlist.isEmpty()) {
				system("cls");
				cout << "������ ����" << endl;
				int n = _getch();
			}
			else del();
			break;
		}
		case 51:
		{
			find();
			break;
		}
		case 52:
		{
			print();
			break;
		}
		case 53:
		{
			solve();
			break;
		}
		default:
		{
			if (key != 27) cout << "\n���������� �����. ������ ������ ���." << endl;
			break;
		}
		}

	} while (key != 27);
	system("cls");
	return 0;
}