#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int isFull(int top) {
	return top == SIZE - 1;
}

int isEmpty(int top) {
	return top == -1;
}

void Display(int* stack, int top) {
	for (int i = SIZE - 1; i >= 0; i--) {
		printf("[ %2d ] ", i);

		if (i == top) {
			printf("|   %2d    |  ← top\n", stack[i]);
		}
		else if (i < top) {
			printf("|   %2d    |\n", stack[i]);
		}
		else {
			printf("|         |\n");
		}
	}
	puts("       -----------");
}

void PUSH(int* stack, int* top, int data) {
	if (isFull(*top)) {
		puts("스택이 가득 찼습니다.");
		return;
	}

	++(*top);
	stack[(*top)] = data;

	Display(stack, *top);
}

int POP(int* stack, int* top) {
	if (isEmpty(*top)) {
		puts("스택이 비었다.");
		return -1;
	}

	int temp = stack[(*top)];
	--(*top);

	Display(stack, *top);
	return temp;

	//return stack[(*top)--];
}

void main() {
	srand(time(NULL));

	int stack[SIZE];
	int top = -1;

	for(int i = 0; i<=SIZE; i++)
		PUSH(stack, &top, rand() % 99 + 1);

	int data;
	
	for (int i = 0; i <= SIZE; i++) {
		data = POP(stack, &top);
		if (data != -1)
			printf("POP : %d\n", data);
	}

}