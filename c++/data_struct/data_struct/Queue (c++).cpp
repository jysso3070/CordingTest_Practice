#include <iostream>
#include <stdio.h>

using namespace std;

struct STACK {
	int data;
	STACK* next;
};

class MyStack {
private:
	STACK* head;
	STACK* tail;
public:
	MyStack() {
		head = new STACK; // (QUEUE*)malloc(sizeof(QUEUE));
		tail = new STACK;
		head->next = tail;
		tail->next = head;
	};
	~MyStack() {
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
	void PushStack(STACK* newQueue) {
		tail->next->next = newQueue;
		tail->next = newQueue;
		newQueue->next = tail;
	}
	STACK* PopStack() {
		if (IsEmpty() == true) {
			cout << "Stack is empty \n";
		}
		else {
			STACK* q = head->next;
			head->next = q->next;
			return q;
		}
	}
};


int main() {
	MyStack queue;

	for (int i = 0; i < 10; ++i) {
		STACK* q = new STACK;
		q->data = i;
		queue.PushStack(q);
	}
	for (int i = 0; i < 5; ++i) {
		STACK* q = queue.PopStack();
		cout << q->data << endl;
		delete q;
	}
	cout << "------------" << endl;
	for (int i = 0; i < 5; ++i) {
		STACK* q = new STACK;
		q->data = i;
		queue.PushStack(q);
	}

	while (queue.IsEmpty() == false) {
		STACK* q = queue.PopStack();
		cout << q->data << endl;
		delete q;
	}
	STACK* q = queue.PopStack();
}

