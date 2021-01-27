#include <iostream>
#include <stdio.h>

using namespace std;

constexpr int maxStackSize = 100;

int myStack[maxStackSize];
int stackTop = -1;

bool stackFull() {
	if (stackTop >= maxStackSize - 1) {
		return true;
	}
	else {
		return false;
	}
}

bool stackEmpty() {
	if (stackTop < 0) {
		return true;
	}
	else {
		return false;
	}
}

void pushStack(int val) {
	if (stackFull() == true) {
		printf("myStack is full");
	}
	else {
		myStack[++stackTop] = val;
	}
}

int popStack() {
	if (stackEmpty() == true) {
		printf("myStack is empty");
	}
	else {
		return myStack[stackTop--];
	}
}

int main() {
	pushStack(10);
	pushStack(9);
	pushStack(5);
	pushStack(1);
	pushStack(11);

	printf("%d \n", popStack());
	printf("%d \n", popStack());
	printf("%d \n", popStack());
	printf("%d \n", popStack());
	printf("%d \n", popStack());




}