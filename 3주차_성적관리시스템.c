//무작위로 시험성적을 입력받아서 총점이 높은 순서대로 출력하는 프로그램을 작성한다.
//1단계: malloc으로 학생 수에 딱맞게 구조체 배열을 만들어서 위의 상황에 맞게 해결한다.
//2단계: realloc으로 학생 수를 추가해서 같은 방법으로 해결해보자. 
#include <stdio.h>
#include <stdlib.h> //malloc, calloc, realloc이 포함된 헤더

typedef struct Student {
	int no;
	char name[20];
	int mid;
	int fi;
}Student; //typedef는 별명을 짓기 위해서 사용. 

void Insert(Student* stu, int i) {
	printf("학번 : ");
	scanf("%d", &(stu + i)->no); //시작주소에 i번째만큼 더한 곳의 배열에 입력을 받는다. 
	printf("이름 : ");
	scanf("%s", (stu + i)->name); //문자열이라서 & 필요 x
	printf("중간 : ");
	scanf("%d", &(stu + i)->mid);
	printf("기말 : ");
	scanf("%d", &(stu + i)->fi);
}

void Display(Student* stu, int n) { //배열 전체와 학생수를 인수로 받는다. 
	printf("%10s%10s%10s%10s\n", "학번", "이름", "중간", "기말");

	for (int i = 0; i < n; i++) { //학생 수만큼 반복하면서 하나씩 출력
		printf("%10d", (stu+i)->no);
		printf("%10s", (stu + i)->name);
		printf("%10d", (stu + i)->mid);
		printf("%10d", (stu + i)->fi);
		puts("");
	}
}

void Sort(Student* stu, int n) {
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) { //0부터 i번째까지 반복하면서
			if (stu[j].mid + stu[j].fi < stu[j + 1].mid + stu[j + 1].fi) { //자기보다 뒤에 있는 데이터가 크면 자리를 교체
				Student temp; //같은 구조체 변수로 임시 저장소 변수를 선언한다. 
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	} //버블정렬: 알고리즘은 단순하지만 퀵 정렬에 비하면 속도가 느리다. 
}
int main(void) {
	int n, extra;
	Student* stu = NULL;

	printf("학생 수 입력 : ");
	scanf("%d", &n);

	stu = malloc(sizeof(Student) * n);

	for (int i = 0; i < n; i++) {
		Insert(stu, i);
	}

	puts("---------------------원본---------------------");
	Display(stu, n);
	puts("----------------------------------------------");

	Sort(stu, n);

	puts("---------------------정렬---------------------");
	Display(stu, n);
	puts("----------------------------------------------");

	printf("추가 학생 수 입력 : ");
	scanf("%d", &extra);

	stu = realloc(stu, sizeof(Student) * (n + extra)); //기존학생수+추가학생수 만큼 배열 공간을 재할당한다.

	for (int i = n; i < extra + n; i++) {
		Insert(stu, i);
	}

	puts("---------------------원본---------------------");
	Display(stu, n + extra);
	puts("----------------------------------------------");

	Sort(stu, n + extra);

	puts("---------------------정렬---------------------");
	Display(stu, n + extra);
	puts("----------------------------------------------");
}