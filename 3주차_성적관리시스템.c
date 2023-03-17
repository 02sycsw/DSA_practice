//�������� ���輺���� �Է¹޾Ƽ� ������ ���� ������� ����ϴ� ���α׷��� �ۼ��Ѵ�.
//1�ܰ�: malloc���� �л� ���� ���°� ����ü �迭�� ���� ���� ��Ȳ�� �°� �ذ��Ѵ�.
//2�ܰ�: realloc���� �л� ���� �߰��ؼ� ���� ������� �ذ��غ���. 
#include <stdio.h>
#include <stdlib.h> //malloc, calloc, realloc�� ���Ե� ���

typedef struct Student {
	int no;
	char name[20];
	int mid;
	int fi;
}Student; //typedef�� ������ ���� ���ؼ� ���. 

void Insert(Student* stu, int i) {
	printf("�й� : ");
	scanf("%d", &(stu + i)->no); //�����ּҿ� i��°��ŭ ���� ���� �迭�� �Է��� �޴´�. 
	printf("�̸� : ");
	scanf("%s", (stu + i)->name); //���ڿ��̶� & �ʿ� x
	printf("�߰� : ");
	scanf("%d", &(stu + i)->mid);
	printf("�⸻ : ");
	scanf("%d", &(stu + i)->fi);
}

void Display(Student* stu, int n) { //�迭 ��ü�� �л����� �μ��� �޴´�. 
	printf("%10s%10s%10s%10s\n", "�й�", "�̸�", "�߰�", "�⸻");

	for (int i = 0; i < n; i++) { //�л� ����ŭ �ݺ��ϸ鼭 �ϳ��� ���
		printf("%10d", (stu+i)->no);
		printf("%10s", (stu + i)->name);
		printf("%10d", (stu + i)->mid);
		printf("%10d", (stu + i)->fi);
		puts("");
	}
}

void Sort(Student* stu, int n) {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) { //0���� i��°���� �ݺ��ϸ鼭
			if (stu[j].mid + stu[j].fi < stu[j + 1].mid + stu[j + 1].fi) { //�ڱ⺸�� �ڿ� �ִ� �����Ͱ� ũ�� �ڸ��� ��ü
				Student temp; //���� ����ü ������ �ӽ� ����� ������ �����Ѵ�. 
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	} //��������: �˰����� �ܼ������� �� ���Ŀ� ���ϸ� �ӵ��� ������. 
}
int main(void) {
	int n, extra;
	Student* stu = NULL;

	printf("�л� �� �Է� : ");
	scanf("%d", &n);

	stu = malloc(sizeof(Student) * n);

	for (int i = 0; i < n; i++) {
		Insert(stu, i);
	}

	puts("---------------------����---------------------");
	Display(stu, n);
	puts("----------------------------------------------");

	Sort(stu, n);

	puts("---------------------����---------------------");
	Display(stu, n);
	puts("----------------------------------------------");

	printf("�߰� �л� �� �Է� : ");
	scanf("%d", &extra);

	stu = realloc(stu, sizeof(Student) * (n + extra)); 
	//�����л���+�߰��л��� ��ŭ �迭 ������ ���Ҵ��Ѵ�.

	for (int i = n; i < extra + n; i++) {
		Insert(stu, i);
	}

	puts("---------------------����---------------------");
	Display(stu, n + extra);
	puts("----------------------------------------------");

	Sort(stu, n + extra);

	puts("---------------------����---------------------");
	Display(stu, n + extra);
	puts("----------------------------------------------");
}