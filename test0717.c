#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int myPower(int n, int k) {
	if (k == 0) {
		return 1;
	}
	return n * myPower(n, k - 1);
}

void init(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

void print(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}
}

//#define SIZE 10
void reverse(int arr[], int size) {
	int left = 0;
	int right = size - 1;
	while (left < right) {
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

void swapArray(int arr1[], int arr2[], int size) {
	for (int i = 0; i < size; i++) {
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}
//
//struct Student {
//	int id;
//	char name[10];
//};
//typedef struct Student Student;

typedef struct Student {
	int id;
	char name[1024];
}Student;

struct A {
	int id;
};

struct B {
	struct A a;
};

struct C {
	struct B* b;
};

void printStudent(Student s) {
	printf("%d\n", s.id);
	printf("%s\n",s.name);
}

int main() {
	Student student = { 10,"张三" };
	printStudent(student);
	/*struct C c;
	c.b->a.id;*/

	
	/*Student* p = &student;
	printf("%d\n", p->id);
	printf("%d\n", (*p).id);*/

	/*student.id = 20;
	strcpy(student.name, "lisi");
	printf("%d\n", student.id);
	printf("%s\n", student.name);*/
	/*student.name[0] = 'l';
	student.name[1] = 'i';
	student.name[2] = 's';
	student.name[3] = 'i';
	student.name[4] = '\0';*/

	/*int a = 10;
	int b = 20;
	const int* p = &a;*/
	 

	/*int arr1[] = { 1,2,3,4 };
	int arr2[] = { 5,6,7,8 };
	swapArray(arr1, arr2, 4);
	for (int i = 0; i < 4; i++) {
		printf("%d\n", arr1[i]);
	}
	for (int j = 0; j < 4; j++) {
		printf("%d\n", arr2[j]);
	}*/
	
		
	/*int arr[] = { 9,5,2,7 };
	int size= sizeof(arr)/sizeof(arr[0]);
	reverse(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);*/
	/*int arr[SIZE];
		init(arr,SIZE);
		print(arr, SIZE);*/
	//k个n连乘
	//printf("%d\n", myPower(2, 10));

	//int num = 10;
	//int* p = &num;
	//printf("%p\n", p);
	//int** p2 = &p;
	//printf("%p\n", *p2);//p与*p2一致

	system("pause");
	return 0;
}

