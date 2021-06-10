////дһ���������ж�һ���ַ����Ƿ�Ϊ��һ���ַ�����ת֮����ַ�����
////���磺����s1 = AABCD��s2 = BCDAA������1
////����s1 = abcd��s2 = ACBD������0.
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//int findRound(const char* str, char* find) {
//	char tmp[256] = { 0 };
//	strcpy(tmp, str);
//	strcat(tmp, str);
//	return strstr(tmp, find) != NULL;
//}
//	
//int main() {
//		printf("%d\n", findRound("AABCD", "BCDAB"));
//		return 0;
//	}

////���Ͼ���
////��һ�����־��󣬾����ÿ�д������ǵ����ģ�
////������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
//#include<stdio.h>
//int findNum(int a[][3], int x, int y, int f) {
//	int i = 0, j = x - 1;
//	while (j >= 0 && i < y) {
//		if (a[i][j] < f) {
//			i++;
//		}
//		else if (a[i][j] > f) {
//			j--;
//		}
//		else {
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main() {
//	int a[][3] = { {2,4,6},{3,5,7},{4,8,9} };
//	if (findNum(a, 3, 3, 2)) {
//		printf("It has been found!\n");
//	}
//	else {
//		printf("It hasn't been found!\n");
//	}
//	return 0;
//}


////ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int compar(int* x, int* y) {
//	return (*x > *y ? 1 : 0);
//}
//void myQsort(void* base, size_t nitems, size_t size,
//	int(*compar)(const void*, const void*)) {
//	int i=0;
//	char* st = (char*)base;
//	int tmp[16];
//	for (int i = 0; i < nitems - 1; i++) {
//		for (int j = 0; j < nitems - 1 - i; j++) {
//			if (compar(st + j * size, st + (j + 1) * size)) {
//				memcpy(tmp, st + j * size, size);
//				memcpy(st + j * size, st + (j + 1) * size, size);
//				memcpy(st + (j + 1) * size, tmp, size);
//			}
//		}
//	}
//}
//
//int main() {
//	int arr[] = { 41,3,52,26,78,90 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	myQsort(arr, size, sizeof(int), compar);
//	for (int i = 0; i < size; i++) {
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//}

//����qsort����ʵ�ֽṹ���ڲ���Ա����

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct imag {
	char name[1024];
	double grade;
	int age;
};//����ṹ��
int comparNum(const void* p, const void* q) {
	//�Ƚ��������Ĵ�С
	return *((int*)p) - *((int*)q);
}
int structIntCompar(const void* p, const void* q) {
	//�ṹ��������Ƚ�
	return ((struct imag*)p)->age - ((struct imag*)q)->age;
}
int structStrCompar(const void* p, const void* q) {
	//�ṹ�����ַ����Ƚ�
	return (strcmp((*(struct imag*)p).name, (*(struct imag*)q).name));
}
int structDoubleCompar(const void* p, const void* q) {
	//�ṹ�帡�����Ƚ�
	return ((*(struct imag*)p).grade > ((struct imag*)q)->grade);
}
void swapNum(void* p, void* q, int size) {
	//����������
	for (int i = 0; i < size; i++) {
		char tmp = *((char*)p + 1);
		*((char*)p + i) = *((char*)p + 1);
		*((char*)q + i) = tmp;
	}
}
void bubbleSort(void* arr,//Ҫ��������
	int num,//����Ԫ�صĸ���
	int size,//ÿ��Ԫ��ռ���ֽ���
	int (*compar)(const void*, const void*))//����ָ��,���ڱȽ�����Ԫ�صĴ�С
{
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (compar((char*)arr + j * size, (char*)arr + (j + 1) * size) > 0) {
				swapNum((char*)arr + j * size, (char*)arr + (j + 1) * size, size);
			}
		}
	}
}
void printNum(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void printStruct(struct imag arr[], int size) {
	printf("����\t        �ɼ�\t         ����\n");
	for (int i = 0; i < size; i++) {
		printf("%s\t       %.2f\t         %d\n", arr[i].name, arr[i].grade, arr[i].age);
	}
	printf("\n");
}
int main() {
	int i = 0;
	int arrInt[10] = { 1,4,7,8,22,68,90,47,35,88 };
	char* arrStr[] = { "bcdef","abcde","defgh","cdefg" };
	struct imag arrStu[3] = { {"xiaoming",96.5,18},{"liuhuan",88.3,20},{"zhangsan",66.9,19} };
	//������������
	printf("<��������������>\n");
	bubbleSort(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), sizeof(arrInt[0]), comparNum);
	printNum(arrInt, sizeof(arrInt) / sizeof(arrInt[0]));
	printf("\n");
	//���нṹ���е�(����)
	printf("<���ṹ���е�(����)����\n");
	bubbleSort(arrInt, sizeof(arrStu) / sizeof(arrStu[0]), sizeof(arrStu[0]), structStrCompar);
	printStruct(arrStu, sizeof(arrStu) / sizeof(arrStu[0]));
	//���нṹ���еĸ���������
	printf("<���ṹ���е�(�ɼ�)����>\n");
	bubbleSort(arrInt, sizeof(arrStu) / sizeof(arrStu[0]), sizeof(arrStu[0]), structStrCompar);
	printStruct(arrStu, sizeof(arrStu) / sizeof(arrStu[0]));
	system("pause");
	return 0;
}