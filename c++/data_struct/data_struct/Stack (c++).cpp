#include <iostream>
#include <stdio.h>

using namespace std;

struct QUEUE {
	int data;
	QUEUE* next;
};

class MyQueue {
public:
	MyQueue() {
		head = new QUEUE;
		tail = new QUEUE;
		head->next = tail;
	};
	~MyQueue() {
		delete head;
		delete tail;
	};
	bool IsEmpty() {
		if (head->next == tail) {
			return true;
		}
		else {
			return false;
		}
	}
	void Enqueue(QUEUE* newStack) {
		newStack->next = head->next;
		head->next = newStack;
	}
	QUEUE* Dequeue() {
		if (IsEmpty() == true) {
			cout << "Stack is empty \n";
		}
		else {
			QUEUE* pop = head->next;
			head->next = head->next->next;
			return pop;
		}
	}

private:
	QUEUE* head;
	QUEUE* tail;
};


int main() {
	MyQueue s;

	for (int i = 0; i < 10; ++i) {
		QUEUE* st = new QUEUE;
		st->data = i;
		s.Enqueue(st);
	}

	while (s.IsEmpty() == false) {
		QUEUE* pop = s.Dequeue();
		cout << pop->data << endl;
		delete pop;
	}
}

