#include <iostream>
#include <stdio.h>

using namespace std;


struct QUEUE {
	int data;
};

class MyCircularQueue {
private:
	int head;
	int tail;
	QUEUE* CircularQueue;
	int maxSize;

public:
	MyCircularQueue(int maxSize) {
		CircularQueue = new QUEUE[maxSize];
		this->maxSize = maxSize;
		head = 0;
		tail = 0;
	}
	~MyCircularQueue() {
		delete[] CircularQueue;
	}
	bool IsEmpty() {
		if (head == tail) {
			return true;
		}
		else {
			return false;
		}
	}
	bool IsFull() {
		if ((tail + 1) % maxSize == head) {
			return true;
		}
		else {
			return false;
		}
	}
	void Enqueue(int data) {
		if (IsFull() == true) {
			cout << "Queue is full \n";
		}
		else {
			tail = (tail + 1) % maxSize;
			CircularQueue[tail].data = data;
		}
	}
	int Dequeue() {
		if (IsEmpty() == true) {
			cout << "Queue is empty \n";
		}
		else {
			head = (head + 1) % maxSize;
			return CircularQueue[head].data;
		}
	}
};

int main() {

	MyCircularQueue q(10);
	q.Enqueue(1);
	q.Enqueue(3);
	q.Enqueue(2);
	q.Enqueue(4);
	q.Enqueue(5);
	q.Enqueue(1);

	while (q.IsEmpty() == false) {
		cout << q.Dequeue() << endl;
	}

}

