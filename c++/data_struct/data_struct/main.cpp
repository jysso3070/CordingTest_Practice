#include <iostream>
#include <stdio.h>

using namespace std;

struct STACK {
	int data;
	STACK* next;
};

class MyStack {
public:
	MyStack() {};
	~MyStack() {};
private:

};


struct NODE {
	int data;
};

class MyCircularQueue {
private:
	int head;
	int tail;
	NODE* CircularQueue;
	int maxSize;

public:
	MyCircularQueue(int maxSize) {
		CircularQueue = new NODE[maxSize];
		this->maxSize = maxSize;
		head = 0;
		tail = 0;
	}
	~MyCircularQueue(){}
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

	MyCircularQueue q(3);


}