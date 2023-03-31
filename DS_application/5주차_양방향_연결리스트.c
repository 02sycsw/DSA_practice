#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* left;
	int data;
	struct node* right;
}Node;

typedef struct list {
	Node* head;
	Node* cur;
}List;

void Insert(List* list, int val) {
	Node* newnode = malloc(sizeof(Node));
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;

	if (list->head == NULL) {
		list->head = newnode;
	} //리스트에 노드가 없다면 newnode를 head로
	else {
		newnode->right = list->head;
		list->head->left = newnode;
		list->head = newnode;
	} //새 노드를 head 앞에 삽입
}

void Del(List* list, int val) {
	if (list->head == NULL) {
		puts("리스트가 없습니다. ");
		return;
	}

	list->cur = list->head;

	while (list->cur->data != val) {
		if (list->cur->right == NULL) {
			puts("값이 없습니다.");
			return;
		}
		list->cur = list->cur->right;
	}

	if (list->cur->left == NULL) {
		if (list->cur->right == NULL) {
			list->head = NULL;
		} //노드가 하나 밖에 없을 때
		else {
			list->head = list->head->right;
			list->head->left = NULL;
		} //삭제하려는 노드가 첫 노드일 때
	}
	else if (list->cur->right == NULL) {
		list->cur->left->right = NULL;
	} //삭제하려는 노드가 마지막 노드일 때
	else {
		list->cur->left->right = list->cur->right;
		list->cur->right->left = list->cur->left;
	} //삭제하려는 노드가 중간 노드일 때
	free(list->cur);
}

void Display(List* list) {
	if (list->head == NULL) {
		puts("리스트가 없습니다. ");
		return;
	}
	list->cur = list->head;
	
	printf("왼쪽 > 오른쪽: ");
	while (list->cur->right != NULL) {
		printf("%d -> ", list->cur->data);
		list->cur = list->cur->right;
	}
	printf("%d\n", list->cur->data);

	printf("오른쪽 > 왼쪽: ");
	while (list->cur->left != NULL) {
		printf("%d -> ", list->cur->data);
		list->cur = list->cur->left;
	}
	printf("%d\n", list->cur->data);
}

int main(void) {
	List* list = malloc(sizeof(List));
	int select = 1, val;

	list->head = NULL;
	list->cur = NULL;

	while (select) {
		puts("1. 삽입 | 2. 삭제 | 3. 출력 | 0. 종료");
		printf("입력: ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("삽입할 값 입력: ");
			scanf("%d", &val);
			Insert(list, val);
			break;

		case 2:
			printf("삭제할 값 입력: ");
			scanf("%d", &val);
			Del(list, val);
			break;

		case 3:
			Display(list);
			break;

		default:
			break;
		}
	}
}