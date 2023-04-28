#include <stdio.h>
#include <string.h>

#define Max_SIZE 100
typedef double element;
element stack[Max_SIZE];
int top = -1;

int isFUll() {
	return top == Max_SIZE - 1;
}

int isEmpty() {
	return top == -1;
}

void PUSH(element item) {
	if (isFUll()) {
		puts("스택이 가득!!");
		return;
	}

	top++;
	stack[top] = item;
}

element POP() {
	if (isEmpty()) {
		puts("스택이 비었다!");
		return -1;
	}

	element temp = stack[top];
	top--;
	return temp;
}

void Rp(char* postfix, int* p_index) {
	char temp;

	while (1) {
		temp = POP();
		if (temp != '(') {
			postfix[*p_index] = temp;
			(*p_index)++;
		}
		else {
			break;
		}
	}
}

int E(char temp) {
	switch (temp)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	default:
		return 0;
		break;
	}
}

void Oper(char* postfix, int* p_index, char temp) {
	while (1) {
		if (E(temp) <= E(stack[top])) {
			postfix[*p_index] = POP();
			(*p_index)++;
		}
		else {
			break;
		}
	}

	PUSH(temp);
}

void Infix_to_Postfix(char* infix, char* postfix) {
	char temp;
	int p_index = 0;

	for (int i = 0; i < strlen(infix); i++) {
		temp = infix[i];

		switch (temp)
		{
		case '(':
			PUSH(temp);
			break;
			
		case ')':
			Rp(postfix, &p_index);
			break;

		case '+':
		case '-':
		case '*':
		case '/':
			Oper(postfix, &p_index, temp);
			break;

		default:
			postfix[p_index] = temp;
			p_index++;
			break;
		}
	}

	while (top != -1) {
		postfix[p_index] = POP();
		p_index++;
	}
	postfix[p_index] = '\0';
}

double Result(char* postfix) {
	element A, B;
	char temp;

	for (int i = 0; i < strlen(postfix); i++) {
		temp = postfix[i];

		if (temp >= '0' && temp <= '9') {
			PUSH(temp - '0');
		}
		else {
			B = POP();
			A = POP();

			switch (temp)
			{
			case '+':
				PUSH(A + B);
				break;
			case '-':
				PUSH(A - B);
				break;
			case '*':
				PUSH(A * B);
				break;
			case '/':
				PUSH(A / B);
				break;
			default:
				break;
			}
		}
	}
	
	return POP();
}

void main() {
	char infix[Max_SIZE], postfix[Max_SIZE];

	while (1) {
		printf("중위식 입력 : ");
		scanf("%s", infix);

		Infix_to_Postfix(infix, postfix);
		printf("후위식: %s\n", postfix);

		printf("결과: %.1lf\n", Result(postfix));
	}
}