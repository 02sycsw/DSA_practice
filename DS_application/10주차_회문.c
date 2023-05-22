#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct Q {
	char queue[MAX];
	int front;
	int rear;
}Q;

typedef struct S {
	char stack[MAX];
	int top;
}S;

void Push(S* s, char data) {
	if (s->top == MAX - 1) {
		puts("스택이 가득!!");
		return;
	}
	s->stack[++(s->top)] = data;
}

char Pop(S* s) {
	if (s->top == -1)
		return 0;
	return s->stack[(s->top)--];
}

void Enq(Q* q, char data) {
	if ((q->rear + 1) % MAX == q->front) {
		puts("큐가 가득!!");
		return;
	}

	q->rear = (q->rear + 1) % MAX;
	q->queue[q->rear] = data;
}

char Deq(Q* q) {
	if ((q->front + 1) % MAX == q->rear)
		return -1;
	
	q->front = (q->front + 1) % MAX;
	return q->queue[q->front];
}

void main() {
	char str[MAX];

	Q q;
	S s;

	q.front = 0;
	q.rear = 0;

	s.top = -1;

	printf("문자열 입력: ");
	scanf("%s", str);

	for (int i = 0; i < strlen(str); i++) {
		Push(&s, str[i]);
		Enq(&q, str[i]);
	}

	//둘 중 하나라도 비었으면 반복문 종료
	while (s.top != -1 && q.front + 1 != q.rear) {
		if (Pop(&s) != Deq(&q)) {
			puts("회문이 아니다");
			return;
		}
	}
	puts("회문이다.");
}