#include <iostream>
#include <stdio.h>

using namespace std;

struct QUEUE {
	int data;
	QUEUE* next;
};

class MyQueue {
private:
	QUEUE* head;
	QUEUE* tail;
public:
	MyQueue() {
		head = new QUEUE;
		tail = new QUEUE;
		head->next = tail;
		tail->next = head;
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
	void Enqueue(QUEUE* newQueue) {
		tail->next->next = newQueue;
		tail->next = newQueue;
		newQueue->next = tail;
	}
	QUEUE* Dequeue() {
		if (IsEmpty() == true) {
			cout << "Stack is empty \n";
		}
		else {
			QUEUE* q = head->next;
			head->next = head->next->next;
			return q;
		}
	}
};


int main() {
	MyQueue queue;

	for (int i = 0; i < 10; ++i) {
		QUEUE* q = new QUEUE;
		q->data = i;
		queue.Enqueue(q);
	}

	while (queue.IsEmpty() == false) {
		QUEUE* q = queue.Dequeue();
		cout << q->data << endl;
		delete q;
	}
}

