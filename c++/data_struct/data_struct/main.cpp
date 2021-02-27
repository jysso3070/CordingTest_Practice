// main
#include <iostream>
#include <stdio.h>

using namespace std;


//struct STACK {
//	int value;
//	STACK* next;
//};
//
//STACK* head = (STACK*)malloc(sizeof(STACK));
//STACK* tail = (STACK*)malloc(sizeof(STACK));
//
//void initStack() {
//	head->next = tail;
//}
//
//bool isEmpty() {
//	if (head->next == tail) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//void pushStack(STACK* newStack) {
//	newStack->next = head->next;
//	head->next = newStack;
//}
//
//STACK* popStack() {
//
//	if (isEmpty() == false) {
//		STACK* pop = head->next;
//		head->next = pop->next;
//		return pop;
//	}
//	else {
//		printf("stack is empty \n");
//	}
//}


//struct QUEUE {
//	int value;
//	QUEUE* next;
//};
//
//QUEUE* head = (QUEUE*)malloc(sizeof(QUEUE));
//QUEUE* tail = (QUEUE*)malloc(sizeof(QUEUE));
//
//void initQueue() {
//	head->next = tail;
//	tail->next = head;
//}
//
//bool isEmpty() {
//	if (head->next == tail) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//void Enqueue(QUEUE* newQueue) {
//	if (isEmpty() == true) {
//		tail->next = newQueue;
//		head->next = newQueue;
//		newQueue->next = tail;
//
//	}
//	else {
//		newQueue->next = tail;
//		tail->next->next = newQueue;
//		tail->next = newQueue;
//	}
//}
//
//QUEUE* Dequeue() {
//	if (isEmpty() == true) {
//		printf("empty \n");
//	}
//	else {
//		QUEUE* deq = head->next;
//		head->next = deq->next;
//		return deq;
//	}
//
//}


struct QUEUE {
	int value;
};

constexpr int queueSize = 10;
QUEUE* cQueue = (QUEUE*)malloc(sizeof(QUEUE) * queueSize);
int head = 0;
int tail = 0;

bool isEmpty() {
	if (head == tail) {
		return true;
	}
	else {
		return false;
	}
}
bool isFull() {
	if ((tail + 1) % queueSize == head){
		return true;
	}
	else {
		return false;
	}
}

void Enqueue(QUEUE* newQueue) {
	if (isFull() == true) {
		printf("queue is full \n");
	}
	else {
		tail = (tail + 1) % queueSize;
		cQueue[tail] = *newQueue;
	}
}

QUEUE* Dequeue() {
	if (isEmpty() == true) {
		printf("queue is empty");
	}
	else {
		head = (head + 1) % queueSize;
		QUEUE* q = &cQueue[head];
		return q;
	}
}

#include <queue>
int main() {
	for (int i = 0; i < 10; ++i) {
		printf("%d \n", i);
		QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
		q->value = i;
		Enqueue(q);
	}

	printf("----------------------------------- \n");

	for (int i = 0; i < 10; ++i) {
		if (isEmpty() == true) {
			break;
		}
		QUEUE* q = Dequeue();
		printf("%d \n", q->value);
	}

	printf("----------------------------------- \n");

	priority_queue<int> pq;
	pq.push(2);
	pq.push(3);
	pq.push(1);
	pq.push(5);

	while (pq.empty() == false) {
		cout << pq.top() << endl;
		pq.pop();
	}

}

