#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

void Insert_node(Node** head, int num) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = num;
	newNode->link = NULL;

	if ((*head) == NULL) {
		(*head) = newNode;
		return;
	}

	Node* iter = (*head);

	while (iter->link != NULL)
		iter = iter->link;
	iter->link = newNode;
}

void Display(Node* head) {
	if (head == NULL) {
		puts("연결리스트가 비었습니다.");
		return;
	}

	Node* iter = head;

	while (iter != NULL) {
		printf("%d", iter->data);
		if (iter->link != NULL)
			printf(" -> ");
		iter = iter->link;
	}
	puts("");
}

void Merge(Node** merge_head, Node* head1, Node* head2) {
	if (head1->data < head2->data) {
		(*merge_head) = head1;
		head1 = head1->link;
	}
	else if (head1->data == head2->data) {
		(*merge_head) = head1;
		head1 = head1->link;
		head2 = head2->link;
	}
	else {
		(*merge_head) = head2;
		head1 = head1->link;
		head2 = head2->link;
	}

	Node* iter = (*merge_head);

	while (head1 != NULL && head2 != NULL)
	{
		if (head1->data < head2->data) {
			iter->link = head1;
			iter = iter->link;
			head1 = head1->link;
		}
		else if (head1->data == head2->data) {
			iter->link = head2;
			iter = iter->link;
			head1 = head1->link;
			head2 = head2->link;
		}
		else {
			iter->link = head2;
			iter = iter->link;
			head2 = head2->link;
		}
	}

	/*while (head1 != NULL) {
		iter->link = head1;
		iter = iter->link;
		head1 = head1->link;
	}
	while (head2 != NULL) {
		iter->link = head2;
		iter = iter->link;
		head2 = head2->link;
	}*/
	//잔여 노드를 하나씩 붙이는 방법

	if (head1 != NULL) {
		iter->link = head1;
	}
	if (head2 != NULL) {
		iter->link = head2;
	}
	//잔여 노드를 한 번에 붙이는 방법
}

void main()
{
	srand(time(NULL));
	Node* head1 = NULL, * head2 = NULL, * merge_head = NULL;

	int num1 = rand() % 10 + 1;
	int num2 = rand() % 10 + 1;

	for (int k = 0; k < 5; k++)
	{
		Insert_node(&head1, num1); //문제
		Insert_node(&head2, num2); //문제
		num1 += rand() % 10 + 1;
		num2 += rand() % 10 + 1;
	}

	printf("Head1 : ");
	Display(head1); //문제
	printf("Head2 : ");
	Display(head2); //문제

	printf("합치기(merge_head) : ");

	Merge(&merge_head, head1, head2); //문제
	Display(merge_head); //문제
}