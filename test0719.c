#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void func() {
	//return;
//}
//
//int add(int x, int y) {
//	return x + y;
//}

//�ص�������������
//x y��������Ҫ�󷵻�1�����򷵻�0
typedef int(*Cmp)(int x, int y);

void bubbleSort(int arr[], int len,Cmp cmp) {
	for (int bound = 0; bound < len; bound++) {
		for (int cur = len - 1; cur > bound; cur--) {
			//if (arr[cur - 1] > arr[cur]) {
			if(cmp(arr[cur-1],arr[cur])!=1){
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
}

//����
int less(int x, int y) {
	//x��yС���Ƿ���Ҫ��
	return x < y ? 1 : 0;
}

//����
int greater(int x, int y) {
	return x > y ? 1 : 0;
}

//typedef struct Student {
//	int id;
//	char name[100];
//	int score;
//}Student;
//
//typedef int(*CmpStudent)(Student* x, Student* y);
//
//void bubbleSortStudent(Student arr[],
//	int len,CmpStudent cmp) {
//	for (int bound = 0; bound < len; bound++) {
//		for (int cur = len - 1; cur > bound; cur--) {
//			if (cmp(&arr[cur-1],&arr[cur]) != 1) {
//				Student tmp = arr[cur - 1];
//				arr[cur - 1] = arr[cur];
//				arr[cur] = tmp;
//			}
//		}
//	}
//
//}
//
//int cmpIdDesc(Student* x, Student* y) {
//	return x->id > y->id ? 1 : 0;
//}
//
//int cmpScoreDesc(Student* x, Student* y) {
//	return x->score > y->score ? 1 : 0;
//}
//
////������ͬ,����id����
//int cmpScoreDescAndIdAsc(Student* x, Student* y) {
//	if (x->score == y->score) {
//		return x->id < y->id ? 1 : 0;
//	}
//	return x->score > y->score ? 1 : 0;
//}

//typedef int(*Cmp)(void*, void*);
//
////ͨ��void*ʵ��һ����������֧�ֶ�������
////len��ʾ������Ԫ�صĸ���
////unitLen��ʾ������ÿ��Ԫ�صĴ�С
//void bubbleSortGeneral(void* arr,
//	int len,int unitLen,Cmp cmp) {
//	for (int bound = 0; bound < len; bound++) {
//		for (int cur = len - 1; cur > bound; cur--) {
//			//Ϊ����arr���void*�ܹ�������,��Ҫǿ������ת��
//			//ͳһת��char*
//			char* carr = (char*)arr;
//			char* p1 = carr + (cur - 1) * unitLen;
//			char* p2 = carr + cur * unitLen;
//			if (cmp(p1, p2) != 1) {
//				char tmp[1024] = { 0 };
//				memcpy(tmp, p1, unitLen);
//				memcpy(p1, p2, unitLen);
//				memcpy(p1, tmp, unitLen);
//			}
//		}
//	}
//}
//
////����������������
//int cmpInt(void* x, void* y) {
//	int* ix = (int*)x;
//	int* iy = (int*)y;
//	return *ix < *iy ? 1 : 0;
//}
//
////��ѧ�����շ���������
//int cmpStudent(void* x, void* y) {
//	Student* sx = (Student*)x;
//	Student* sy = (Student*)y;
//	return sx->score > sy->score ? 1 : 0;
//}

////дһ������ʵ���������ļӼ��˳�
//int add(int x, int y) {
//	return x + y;
//}
//
//int sub(int x, int y) {
//	return x - y;
//}
//
//int mul(int x, int y) {
//	return x * y;
//}
//
//int division(int x, int y) {
//	return x / y;
//}
//
//typedef int(*Func)(int, int);

int main() {
	/*int x = 0;
	int y = 0;
	printf("��������������\n");
	scanf("%d %d", &x, &y);
	printf("�������������Ĺ���\n");
	printf("1.�ӷ� 2.���� 3.�˷� 4.����\n");
	int choice = 0;
	scanf("%d", &choice);
	Func arr[] = {
		NULL,
		add,
		sub,
		mul,
		division
	};
	int ret = arr[choice](x, y);
	printf("ret=%d\n", ret);*/

	/*int ret = 0;
	if (choice == 1) {
		ret = add(x, y);
	}
	else if (choice == 2) {
		ret = sub(x, y);
	}
	else if (choice == 3) {
		ret = mul(x, y);
	}
	else if (choice == 4) {
		ret = division(x, y);
	}
	else {
		printf("������������ ����������\n");
	}
	printf("���Ϊ%d\n", ret);*/

	//int arr[] = { 9,5,2,7,3,6 };
	//int len = sizeof(arr) / sizeof(arr[0]);
	//bubbleSortGeneral(arr,len,sizeof(arr[0]))

	/*Student students[] = {
		{1,"����",96},
		{2,"����",90},
		{3,"����",86},
		{4,"����",98},
		{5,"����",90},
	};
	int len = sizeof(students) / sizeof(students[0]);
	bubbleSortStudent(students, len,cmpScoreDescAndIdAsc);
	for (int i = 0; i < len; i++) {
		printf("%s\n", students[i].name);
	}*/


	int arr[] = { 9,5,2,7,3,6,8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, len, greater);
	for (int i = 0; i < len; i++) {
		printf("%d\n", arr[i]);
	}


	/*void(*p)() = func;
	int(*p2)(int, int) = add;
	p = p2;*/

	////��ʼ��ƿ��
	//int bottle = 20;
	////�ȵ�����ƿ��
	//int total = 20;
	//while (bottle > 1) {
	//	total += bottle / 2;
	//	bottle = bottle / 2 + bottle % 2;
	//}
	//printf("%d\n", total);

	system("pause");
	return 0;
}