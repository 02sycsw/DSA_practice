#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

typedef struct fr {
	Node* front, * rear;
}FR;

void Enq(FR* fr, int num) {
	Node* newNode = malloc(sizeof(Node));
	newNode->data = num;
	newNode->link = NULL;

	if (fr->front == NULL && fr->rear == NULL) {
		fr->front = newNode;
		fr->rear = newNode;
	}
	else {
		fr->rear->link = newNode;
		fr->rear = newNode;
	}
}

int Deq(FR* fr) {
	if (fr->front == NULL && fr->rear == NULL) {
		puts("없음");
		return -1;
	}

	Node* temp = fr->front;
	int num = temp->data;

	fr->front = fr->front->link;

	free(temp);

	if (fr->front == NULL) {
		fr->rear = NULL;
	}

	return num;
}

int main(void) {
	FR fr;
	fr.front = NULL;
	fr.rear = NULL;

	int num = 1;
	for (int i = 0; i < 5; i++) {
		Enq(&fr, num++);
		printf("입력: %d\n", fr.rear->data);
	}

	for (int i = 0; i < 3; i++) {
		int temp = Deq(&fr);
		if(temp != -1)
			printf("출력: %d\n", temp);
	}

	for (int i = 0; i < 5; i++) {
		Enq(&fr, num++);
		printf("입력: %d\n", fr.rear->data);
	}

	for (int i = 0; i < 3; i++) {
		int temp = Deq(&fr);
		if (temp != -1)
			printf("출력: %d\n", temp);
	}
}