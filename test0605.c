////写一个函数，判断一个字符串是否为另一个字符串旋转之后的字符串。
////例如：给定s1 = AABCD和s2 = BCDAA，返回1
////给定s1 = abcd和s2 = ACBD，返回0.
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

////杨氏矩阵
////有一个数字矩阵，矩阵的每行从左到右是递增的，
////矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
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


////模仿qsort的功能实现一个通用的冒泡排序
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

//利用qsort函数实现结构体内部成员排序

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct imag {
	char name[1024];
	double grade;
	int age;
};//定义结构体
int comparNum(const void* p, const void* q) {
	//比较两个数的大小
	return *((int*)p) - *((int*)q);
}
int structIntCompar(const void* p, const void* q) {
	//结构体中年龄比较
	return ((struct imag*)p)->age - ((struct imag*)q)->age;
}
int structStrCompar(const void* p, const void* q) {
	//结构体中字符串比较
	return (strcmp((*(struct imag*)p).name, (*(struct imag*)q).name));
}
int structDoubleCompar(const void* p, const void* q) {
	//结构体浮点数比较
	return ((*(struct imag*)p).grade > ((struct imag*)q)->grade);
}
void swapNum(void* p, void* q, int size) {
	//交换两个数
	for (int i = 0; i < size; i++) {
		char tmp = *((char*)p + 1);
		*((char*)p + i) = *((char*)p + 1);
		*((char*)q + i) = tmp;
	}
}
void bubbleSort(void* arr,//要排序数组
	int num,//数组元素的个数
	int size,//每个元素占的字节数
	int (*compar)(const void*, const void*))//函数指针,用于比较两个元素的大小
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
	printf("姓名\t        成绩\t         年龄\n");
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
	//排序整形数组
	printf("<给整型数组排序>\n");
	bubbleSort(arrInt, sizeof(arrInt) / sizeof(arrInt[0]), sizeof(arrInt[0]), comparNum);
	printNum(arrInt, sizeof(arrInt) / sizeof(arrInt[0]));
	printf("\n");
	//排列结构体中的(年龄)
	printf("<按结构体中的(年龄)排序\n");
	bubbleSort(arrInt, sizeof(arrStu) / sizeof(arrStu[0]), sizeof(arrStu[0]), structStrCompar);
	printStruct(arrStu, sizeof(arrStu) / sizeof(arrStu[0]));
	//排列结构体中的浮点型数字
	printf("<按结构体中的(成绩)排序>\n");
	bubbleSort(arrInt, sizeof(arrStu) / sizeof(arrStu[0]), sizeof(arrStu[0]), structStrCompar);
	printStruct(arrStu, sizeof(arrStu) / sizeof(arrStu[0]));
	system("pause");
	return 0;
}