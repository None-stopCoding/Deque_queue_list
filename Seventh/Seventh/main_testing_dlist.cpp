#include <iostream>
#include <conio.h>
#include <ctime>
#include "Dlist.h"
using namespace std;
Dlist dlist;

// создание списка случайных чисел
void createDlist() {
	int tmp = 2;
	int value = 0;
	while (tmp--) {
		value = rand() % 10 + 1;
		dlist.pushBack(value);
	}
}

// находит максимальный элемент списка
void findMax(int& max) {
	int tmp = dlist.Count();
	while (tmp--) {
		int work = dlist.findByIndex(0);
		if (work > max) max = work;
		dlist.popFront();
		dlist.pushBack(work);
	}
}

// сортировка двунаправленного списка методом вставок
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

// выбор задания (23, 33)
int Choose() {
	cout << "Выберите задание: ";
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
			cout << "Продолжаем? (Esc - нет, Enter - да)";
			key = _getch();
		}
		if (key != 27) {
			pressed = 1;
			system("cls");
			cout << "\nКакой элемент добавить: "; int el = 0; cin >> el;

			cout << "Добавить элемент: " << endl;

			cout << "\t1.В начало списка" << endl;
			cout << "\t2.В конец списка" << endl;
			cout << "\t3.После указанного" << endl;
			cout << "\t4.Перед указанным" << endl;
			cout << "Ваш выбор : ";

			choice = _getch();
			system("cls");
			cout << "Список до обработки: ";
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
				cout << "\nПосле какого (индекс): "; int after = 0; cin >> after;
				dlist.pushAfter(after, el);
				break;
			}
			case 52:
			{
				cout << "\nПеред каким (индекс): "; int before = 0; cin >> before;
				dlist.pushBefore(before, el);
				break;
			}
			default:
			{
				cout << "\nПопробуйте снова. Такого номера нет." << endl;
				break;
			}
			}
			cout << "Список после обработки: ";
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
			cout << "Продолжаем? (Esc - нет, Enter - да)";
			key = _getch();
		}
		if (key != 27) {
			pressed = 1;
			system("cls");
			cout << "Удалить элемент: " << endl;

			cout << "\t1.В начале списка" << endl;
			cout << "\t2.В конце списка" << endl;
			cout << "\t3.После указанного" << endl;
			cout << "\t4.Перед указанным" << endl;
			cout << "Ваш выбор : ";

			choice = _getch();
			system("cls");
			cout << "Список до обработки: ";
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
				cout << "\nПосле какого (индекс): "; int after = 0; cin >> after;
				dlist.popAfter(after);
				break;
			}
			case 52:
			{
				cout << "\nПеред каким (индекс): "; int before = 0; cin >> before;
				dlist.popBefore(before);
				break;
			}
			default:
			{
				cout << "\nПопробуйте снова. Такого номера нет." << endl;
				break;
			}
			}
			if (dlist.isEmpty()) { cout << "Список пуст" << endl; key = 27; }
			else {
				cout << "Список после обработки: ";
				dlist.printNext();
			}
			int n = _getch();
		}

	} while (key != 27 && dlist.Count());
	if (!dlist.Count()) cout << endl << "Список пуст" << endl;
	int lj = _getch();
}

void find() {
	int key = 0, choice = 0, pressed = 0;
	do
	{
		system("cls");
		if (pressed) {
			cout << "Продолжаем? (Esc - нет, Enter - да)";
			key = _getch();
		}
		if (key != 27) {
			pressed = 1;
			system("cls");
			cout << "Найти элемент: " << endl;

			cout << "\t1.По индексу" << endl;
			cout << "\t2.По значению" << endl;
			cout << "Ваш выбор : ";

			choice = _getch();
			system("cls");
			cout << "Список: ";
			dlist.printNext();
			switch (choice)
			{
			case 49:
			{
				cout << "\nИндекс: "; int index = 0; cin >> index;
				int val = dlist.findByIndex(index);
				if (val) printf("Элемент с индексом %d имеет значение %d", index, val);
				else cout << "Элемента с таким индексом нет";
				break;
			}
			case 50:
			{
				cout << "\nЗначение: "; int val = 0; cin >> val;
				int* index = dlist.findByVal(val);
				if (index) {
					for (int i = 0; i < dlist.Count(); i++)
						if (index[i] != -1)
							printf("Индекс элемента %d равен %d\n", val, index[i]);
				}
				else cout << "Такого элемента нет";
				break;
			}
			default:
			{
				cout << "\nПопробуйте снова. Такого номера нет." << endl;
				break;
			}
			}
			int n = _getch();
		}

	} while (key != 27);
}

void print() {
	system("cls");

	cout << "Используя Next: "; dlist.printNext();
	cout << "Используя Prev: "; dlist.printPrev();
	int n = _getch();
}

void solve() {
	int key = 0, choice = 0, pressed = 0;
	do
	{
		system("cls");
		if (pressed) {
			cout << "Продолжаем? (Esc - нет, Enter - да)";
			key = _getch();
		}
		if (key != 27) {
			pressed = 1;
			system("cls");
			cout << "Задача: " << endl;

			cout << "\t1.Найти максимальный элемент в списке" << endl;
			cout << "\t2.Отсортировать список" << endl;
			cout << "Ваш выбор : ";

			choice = _getch();
			system("cls");
			cout << "Список до обработки: ";
			dlist.printNext();
			switch (choice)
			{
				case 49:
				{
					int max = 0;
					findMax(max);
					printf("Максимальный элемент: %d", max);
					break;
				}
				case 50:
				{
					insertionSort();
					cout << "Список после обработки: ";
					dlist.printNext();
					break;
				}
				default:
				{
					cout << "\nПопробуйте снова. Такого номера нет." << endl;
					break;
				}
			}
			int n = _getch();
		}
	} while (key != 27);
}

// основная программа
int main() {
	setlocale(LC_ALL, "rus");
	int key = 0, fin = 0;
	srand(time(NULL));
	createDlist();
	do
	{
		system("cls");
		cout << "Меню: " << endl;

		cout << "\t1.Добавить элемент" << endl;
		cout << "\t2.Удалить элемент" << endl;
		cout << "\t3.Найти элемент" << endl;
		cout << "\t4.Вывести список" << endl;
		cout << "\t5.Решить задачи" << endl;
		cout << "\tEsc. Завершить\n" << endl;
		cout << "Ваш выбор : ";

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
				cout << "Список пуст" << endl;
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
			if (key != 27) cout << "\nПопробуйте снова. Такого номера нет." << endl;
			break;
		}
		}

	} while (key != 27);
	system("cls");
	return 0;
}