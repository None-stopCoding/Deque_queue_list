#include <iostream>
#include <conio.h>
#include <ctime>
#include "Queue.h"

using namespace std;
Queue queue;

// формируем очередь
void createQueue() {
	int tmp = 10;
	int value = 0;
	while (tmp--) {
		value = rand() % 5 + 1;
		queue.Enqueue(value);
	}
}

// подсчитываем произведение элементов очереди
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

// ставит элемент в голову очереди
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

// возвращает true, если элемент есть в очереди, false - иначе
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

// убирает из очереди неповторяющиеся элементы
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

// выбор задания
int Choose() {
	cout << "Выберите задание: ";
	int num = 0;
	cin >> num;
	return num;
}

// основная программа
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
		cout << "Такого у меня нет" << endl;
	}

	int n =_getch();
	return 0;
}