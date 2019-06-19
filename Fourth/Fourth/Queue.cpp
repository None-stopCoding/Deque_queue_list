#include "Queue.h"
#include <iostream>
#include <conio.h>
using namespace std;


Queue::Queue() : run(NULL) {}

void Queue::Enqueue(int& val)
{
	if (run == NULL) {
		Elem* now = new Elem(val);
		run = now;
	}
	else {
		Elem* tmp = run;
			while (tmp->link != NULL) {
				tmp = tmp->link;
			}
		Elem* now = new Elem(val);
		tmp->link = now;
	}
}

void Queue::Dequeue()
{
	if (!this->isEmpty()) {
		Elem* tmp = run->link;
		delete run;
		run = tmp;
	}
}

void Queue::Print()
{
	if (!this->isEmpty()) {
		Elem* tmp = run;
		while (tmp != NULL) {
			cout << tmp->val << " ";
			tmp = tmp->link;
		}
	}
	cout << endl;
}

bool Queue::isEmpty() { return run == NULL; }

int Queue::Begin() { 
	if (this->isEmpty()) return NULL;
	return run->val;
}

int Queue::Count() {
	Elem* tmp = run;
	int res = 0;
	while (tmp != NULL) {
		tmp = tmp->link;
		res++;
	}
	return res;
}