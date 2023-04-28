#include <stdio.h>

#define MAX 5

int front = 0;
int rear = 0;
int Q[MAX];

int isFull() {
	if (front == (rear + 1) % MAX)
		return 1;
	else
		return 0;
}

int isEmpty() {
	if (front == rear)
		return 1;
	else
		return 0;
}

void Enq(int num) {
	if (IsFull()) {
		puts("큐가 가득 찼습니다.");
		return;
	}

	rear = (rear + 1) % MAX;
	Q[rear] = num;
}

int Deq() {
	if (IsEmpty()) {
		puts("큐가 비었습니다.");
		return;
	}
	int num = Q[front];
	front = (front + 1) % MAX;

	return num;
}

void main() {
	int num = 1;
	for (int i = 0; i < 5; i++) {
		printf("입력: %d\n", num);
		Enq(num++);
	}

	puts("--------------------------");
	for (int i = 0; i < 3; i++) {
		printf("출력: %d\n", Deq());
	}

	puts("--------------------------");
	for (int i = 0; i < 5; i++) {
		printf("입력: %d\n", num);
		Enq(num++);
	}

	puts("--------------------------");
	for (int i = 0; i < 3; i++) {
		printf("출력: %d\n", Deq());
	}

}