#include <stdio.h>
#include <string.h> //strcpy 쓰려고
typedef struct info_book
{
	int num;
	char name[20];
	int rent_day;
	int return_day;
}ib; //구조체 선언

int Insert_book(ib book[100], int n) {
	int i_no;
	printf("학번 : ");
	scanf("%d", &i_no);
	book[n].num = i_no;

	char i_name[20];
	printf("도서명 : ");
	scanf("%s", i_name);
	strcpy(book[n].name, i_name);

	int i_rent;
	printf("대여일 : ");
	scanf("%d", &i_rent);
	book[n].rent_day = i_rent;

	int i_return;
	printf("반납일 : ");
	scanf("%d", &i_return);
	book[n].return_day = i_return;

	return ++n; //반드시 전위증감연산자로 해야함 후위증감연산자로 하면 오류남
}

void Display(ib b1) {
	printf("%10d%10s%10d%10d\n", b1.num, b1.name, b1.rent_day, b1.return_day);
}

/*
void Display(ib* b1) {
	printf("%10d%10s%10d%10d\n", b1->num, b1->name, b1->rent_day, b1->return_day);
}*/
//이렇게 포인터로 받아오면 주소를 받아와서 하는 거라서 지역 변수를 안 만들어도 돼서 
//타이트하게 메모리를 쓸 때는 이렇게 하는 게 더 좋다.

void Search(ib* book, int n, int select, int value) {
	printf("%10s%10s%10s%10s\n", "학번", "도서정보", "대여일", "반납일");

	switch (select)
	{
	case 1: //학번으로 검색
		for (int i = 0; i < n; i++) {
			if (book[i].num == value) {
				Display(book[i]);
			}
		}
		break;
	case 2: //대여일로 검색
		for (int i = 0; i < n; i++) {
			if (book[i].rent_day == value) {
				Display(book[i]);
			}
		}
		break;
	case 3: //반납일로 검색
		for (int i = 0; i < n; i++) {
			if (book[i].return_day == value) {
				Display(book[i]);
			}
		}
		break;
	default:
		break;
	}
}

int main(void) {
	ib book[100];
	int menu = 1, n = 0, select, value;

	while (menu) {
		printf("1: 입력\n2. 검색\n3. 출력\n4.종료\n");
		printf("-----------------------------------\n");
		printf("선택 : ");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			n = Insert_book(book, n);
			break;

		case 2:
			printf("-----------------------------------\n");
			printf("1. 학번\n2.대여일\n3.반납일\n선택 : ");
			scanf("%d", &select);
			printf("값 : ");
			scanf("%d", &value);
			Search(book, n, select, value);
			break;

		case 3:
			printf("-----------------------------------\n");
			printf("%10s%10s%10s%10s\n", "학번", "도서정보", "대여일", "반납일");
			for (int i = 0; i < n; i++) {
				Display(book[i]);
			}
			break;
		case 4:
			menu = 0;

		default:
			break;
		}
	}
}