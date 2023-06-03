#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (arr[low] <= pivot && low <= high) {
			low++;
		}
		while (arr[high] >= pivot && high >= left + 1) {
			high--;
		}
		if (low <= high) {
			Swap(arr, low, high);
		}
	}

	Swap(arr, high, left);
	return high;
}

void Quick_Sort(int arr[], int left, int right) {
	if (left < right) {
		int temp = Partition(arr, left, right);
		Quick_Sort(arr, left, temp - 1);
		Quick_Sort(arr, temp + 1, right);
	}
}

void Bubble_Sort(int arr[]) {
	for (int i = 0; i < MAX; i++) {
		for (int j = i + 1; j < MAX; j++) {
			if (arr[i] > arr[j]) {
				Swap(arr, i, j);
			}
		}
	}
}

void Insert_Sort(int arr[]) {
	for (int i = 1; i < MAX; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

void Display(int arr[]) {
	for (int i = 0; i < MAX; i++) {
		printf("  %d", arr[i]);
	}
	puts("");
	puts("");
}

void main() {
	srand(time(NULL));

	int B[MAX], I[MAX], Q[MAX];

	for (int i = 0; i < MAX; i++) {
		B[i] = rand() % 20 + 1;
		I[i] = Q[i] = B[i];

		for (int j = 0; j < i; j++) {
			if (B[i] == B[j]) {
				i--;
				break;
			}
		}
	}

	puts("------원본------");
	Display(Q);
	puts("------퀵 정렬------");
	Quick_Sort(Q, 0, MAX - 1);
	Display(Q);
	puts("------원본------");
	Display(B);
	puts("------버블 정렬------");
	Bubble_Sort(B);
	Display(B);
	puts("------원본------");
	Display(I);
	puts("------삽입 정렬------");
	Bubble_Sort(I);
	Display(I);
}