#include "Dlist.h"
#include <iostream>
#include <conio.h>
using namespace std;
Dlist::Dlist() : head(NULL), tail(NULL) {}

void Dlist::pushBack(int& val) {

	Elem* tmp = new Elem(val);

	if (this->isEmpty()) {
		head = tmp;
		tail = head;
	}
	else {
		Elem* tmp2 = tail;

		tail->next = tmp;
		tail = tmp;
		tail->prev = tmp2;
	}
}

void Dlist::pushFront(int& val) {

	Elem* tmp = new Elem(val);

	if (this->isEmpty()) {
		head = tmp;
		tail = head;
	}
	else {
		Elem* tmp2 = head;

		head->prev = tmp;
		head = tmp;
		head->next = tmp2;
	}
}

void Dlist::popBack() {
	if (!this->isEmpty()) {

		if (head == tail) { // если в списке один элемент
			head = NULL; tail = NULL;
		}
		else {
			tail = tail->prev;
		}
	}
}

void Dlist::popFront() {
	if (!this->isEmpty()) {

		if (head == tail) { // если в списке один элемент
			head = NULL; tail = NULL;
		}
		else {
			head = head->next;
		}
	}
}

void Dlist::printNext() {
	if (!this->isEmpty()) {

		Elem* run = head;
		while (run != tail) {
			cout << run->val << " ";
			run = run->next;
		}
		cout << run->val << endl;
	}
}

void Dlist::printPrev() {
	if (!this->isEmpty()) {

		Elem* run = tail;
		while (run != head) {
			cout << run->val << " ";
			run = run->prev;
		}
		cout << run->val << endl;
	}
}

bool Dlist::isEmpty() { return head == NULL; }

int* Dlist::findByVal(int& val) {
	Elem* run = head;
	int* index_mas = new int[this->Count() + 1];
	for (int i = 0; i <= this->Count(); i++) index_mas[i] = -1;
	int index = 0, i = 0;

	while (run->next) {
		if (run->val == val) index_mas[i++] = index;
		run = run->next;
		index++;
	}
	if (run->val == val) index_mas[i++] = index;
	return index_mas;
}

int Dlist::findByIndex(int ix) {
	Elem* run = head;
	int index = 0;
	while (run != tail) {
		if (ix == index++) return run->val;
		run = run->next;
	}
	if (ix == index) return run->val;
	return NULL;
}

void Dlist::pushAfter(int& after, int& val) {
	int ix = after;
	if (ix == -1) this->pushFront(val);
	if (ix >= 0 && ix < this->Count()) {
		if (ix == this->Count() - 1) this->pushBack(val);
		else {
			Elem* run = head;
			int index = 0;
			while (ix != index++) {
				run = run->next;
			}
			Elem* tmp = new Elem(val);
			tmp->next = run->next;
			tmp->prev = run;
			if (run->next) run->next->prev = tmp;
			run->next = tmp;
		}
	}
}

void Dlist::pushBefore(int& before, int& val) {
	int ix = before;
	if (ix >= 0 && ix < this->Count()) {
		if (!ix) this->pushFront(val);
		else {
			Elem* run = head;
			int index = 0;
			while (ix != index++) {
				run = run->next;
			}
			Elem* tmp = new Elem(val);
			tmp->prev = run->prev;
			if (run->prev) run->prev->next = tmp;
			tmp->next = run;
			run->prev = tmp;
		}
	}
}

void Dlist::popAfter(int& after) {
	int ix = after;
	if (ix == -1) this->popFront();
	if (ix >= 0 && ix < this->Count()) {
		if (ix == this->Count() - 2) this->popBack();
		else {
			Elem* run = head;
			int index = 0;
			while (ix != index++) {
				run = run->next;
			}
			if (run->next) {
				Elem* tmp = run->next->next;
				delete run->next;
				if (tmp) tmp->prev = run;
				run->next = tmp;
			}
		}
	}
}

void Dlist::popBefore(int& before) {
	int ix = before;
	if (ix >= 0 && ix < this->Count()) {
		if (ix == 1) this->popFront();
		else if (ix) {
			Elem* run = head;
			int index = 0;
			while (ix != index++) {
				run = run->next;
			}
			Elem* tmp = run->prev->prev;
			delete run->prev;
			if (tmp) tmp->next = run;
			run->prev = tmp;
		}
	}
}

int Dlist::Count() {
	Elem* tmp = head;
	int res = 0;
	while (tmp != tail) {
		tmp = tmp->next;
		res++;
	}
	return ++res;
}