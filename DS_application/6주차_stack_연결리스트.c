#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
}StackNode;

StackNode** PUSH(element item, StackNode** top) { 
	//top의 위치를 직접 변경하는 것이기 때문에 더블 포인터로 top를 받는다. 
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = (*top);
	(*top) = temp;

	return (*top);
}

void Display(StackNode* top, int size) {
	if (top == NULL) {
		puts("Stack is empty.");
		return;
	}

	for (int i = size - 1; i >= 0; i--) {
		printf("[ %2d ] ", i);

		if (i == size - 1) {
			printf("|   %2d    |  ← top\n", top->data);
		}
		else if (i < top) {
			printf("|   %2d    |\n", top->data);
		}
		top = top->link;
	}
	puts("       -----------");
}

element POP(StackNode** top, int count) {
	//top의 위치를 직접 변경하는 것이기 때문에 더블 포인터로 top를 받는다.
	element item;
	StackNode* temp;

	if (*top != NULL) {
		temp = *top;  
		item = temp->data;
		*top = (*top)->link;  
		//POP을 하고 나면 top이 다음 노드를 가리키게 옮긴다. 
		free(temp);
		//해당 노드의 메모리를 해제한다. 

		Display(*top, count);

		return item; //POP했던 데이터 부분
	}
	else {
		puts("Stack is empty.");
		return;
	}
}

element PEEK(StackNode* top) {
	//top의 데이터를 POP하지 않고 값만 전달해준다. 
	if (top != NULL) {
		return top->data;
	}
	else {
		puts("Stack is empty.");
	}
}

int main(void) {
	srand(time(NULL));

	StackNode* top = NULL;

	int select = 1, flag = 0;
	int selectDe, value;

	element data;

	while (select) {
		puts("1. PUSH | 2. POP | 3. PEEK | 4. All Display only | 0. exit");
		printf("select Menu: ");
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			puts("1. random PUSH | 2. select PUSH");
			//랜덤으로 값을 넣을지, 선택해서 값을 넣을지
			printf("select: ");
			scanf("%d", &selectDe);

			if (selectDe == 1)
				top = PUSH(rand() % 99 + 1, &top);
			else {
				printf("value input: ");
				scanf("%d", &value);
				top = PUSH(value, &top);
			}
			flag++;
			//배열과 다르게 전체 개수가 유동적이기 때문에 개수를 따로 세어준다. 

			break;

		case 2:
			data = POP(&top, flag - 1);
			printf("POP: %d\n", data);
			flag--;
			//POP하고 나면 전체 개수도 같이 줄인다. 
			break;

		case 3:
			data = PEEK(top);
			printf("PEEK: %d\n", data);
			break;

		case 4:
			Display(top, flag);
			//stack 전체를 출력한다.

		default:
			break;
		}
		puts("");
	}
}