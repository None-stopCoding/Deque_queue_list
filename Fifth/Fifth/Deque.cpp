#include "Deque.h"
#include <iostream>
#include <conio.h>
using namespace std;

Deque::Deque() : top(NULL) {}

void Deque::pushBack(int& val) {
	Elem* tmp = new Elem(val);
	if (this->isEmpty()) top = tmp;
	else {
		Elem* run = top;
		while (run->next) run = run->next;
		run->next = tmp;
	}
}

void Deque::pushFront(int& val) {
	Elem* tmp = new Elem(val);
	if (this->isEmpty()) top = tmp;
	else { tmp->next = top; top = tmp; }
}

void Deque::popBack() {
	if (!this->isEmpty()) {
		Elem* run = top;
		if (run->next == NULL) { 
			delete run;
			run = NULL;
		}
		else {
			while (run->next->next) run = run->next;
			delete run->next;
			run->next = NULL;
		}
	}
}

void Deque::popFront() {
	if (!this->isEmpty()){
		Elem* tmp = top->next;
		delete top;
		top = tmp;
	}
}

void Deque::Print() {
	if (!this->isEmpty()){
		Elem* run = top;
		while (run->next) {
			cout << run->val << " ";
			run = run->next;
		}
		cout << run->val << endl;
	}
}

bool Deque::isEmpty() { return top == NULL; }

int Deque::Front() {
	if (!this->isEmpty()) {
		return top->val;
	}
}

int Deque::Back() {
	if (!this->isEmpty()){
		Elem* run = top;
		while (run->next) run = run->next;
		return run->val;
	}
}

int Deque::Count() {
	Elem* tmp = top;
	int res = 0;
	while (tmp != NULL) {
		tmp = tmp->next;
		res++;
	}
	return res;
}