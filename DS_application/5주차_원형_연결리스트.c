#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Node;

typedef struct list {
	Node* tail;
	Node* cur;
	Node* bef;
}List;

void Insert(List* list, int val) {
	Node* newnode = malloc(sizeof(Node));
	newnode->data = val;
	newnode->link = NULL;
	
	if (list->tail == NULL) {
		list->tail = newnode;
		newnode->link = newnode;
	} //tail이 NULL일 때: 리스트에 노드가 하나도 없을 때
	else {
		newnode->link = list->tail->link;
		list->tail->link = newnode;
		list->tail = newnode;
	} //newnode의 링크에 기존 tail의 link가 가리키고 있던 것을 복사한다.  
	//기존 tail의 link에 newnode를 가리키게 하고, tail을 newnode로 옮긴다. 
}

void Del(List* list, int val) {
	if (list->tail == NULL) {
		puts("리스트가 없습니다. ");
		return;
	}
	
	list->cur = list->tail->link;
	list->bef = list->tail;

	while (list->cur->data != val) {
		if (list->cur == list->tail) {
			puts("삭제할 값이 없습니다.");
			return;
		}

		list->bef = list->cur;
		list->cur = list->cur->link;
		//삭제할 값이 아니라면 before과 current를 한 칸씩 옮겨준다. 
	}

	list->bef->link = list->cur->link;
	//삭제하려는 값이 맞다면 before에 current를 대입한다. 

	if (list->cur == list->tail) {
		list->tail = list->bef;
	} //삭제하려는 값이 tail에 있다면 tail을 before에 다시 연결

	if (list->cur->link == list->cur) {
		list->tail = NULL;
	} //리스트에 노드가 하나 남았다면
	free(list->cur);
}

void Display(List* list) {
	list->cur = list->tail->link;

	while (list->cur != list->tail) {
		printf("%d -> ", list->cur->data);
		list->cur = list->cur->link;
	}
	printf("%d\n", list->cur->data);
}

int main(void) {
	List* list = malloc(sizeof(List));
	int select = 1, val;

	list->tail = NULL;
	list->cur = NULL;
	list->bef = NULL;

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