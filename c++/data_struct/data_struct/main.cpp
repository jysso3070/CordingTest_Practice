// main
#include <iostream>
#include <stdio.h>

using namespace std;

struct STACK {
	int data;
	STACK* next;
};

class MyStack {
public:
	MyStack() {
		head = new STACK;
		tail = new STACK;
		head->next = tail;
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
	void PushStack(STACK* newStack) {
		newStack->next = head->next;
		head->next = newStack;
	}
	STACK* PopStack() {
		if (IsEmpty() == true) {
			cout << "Stack is empty \n";
		}
		else {
			STACK* pop = head->next;
			head->next = head->next->next;
			return pop;
		}
	}

private:
	STACK* head;
	STACK* tail;
};


int main() {
	MyStack s;

	for (int i = 0; i < 10; ++i) {
		STACK* st = new STACK;
		st->data = i;
		s.PushStack(st);
	}

	while (s.IsEmpty() == false) {
		STACK* pop = s.PopStack();
		cout << pop->data << endl;
		delete pop;
	}
}

