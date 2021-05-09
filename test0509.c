////写一个函数打印arr数组的内容(arr的整形的一维数组)
////不使用数组下标,使用指针
//
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	int size = sizeof(arr) / sizeof(arr[0]);//求出数组长度
//	int* p = arr;//定义指针变量并初始化,数组名代表着数组首元素的地址
//	for (int i = 0; i < size; i++) {
//		printf("%d ",  *p);//取到p所指向元素的地址
//		p++;//获取到p的下一个位置
//	}
//	system("pause");
//	return 0;
//}


//写一个函数,可以逆序一个字符串的内容
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int init(int arr[]) {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
}
void reverse(int arr[]) {
	for (int i = 9; i >= 0; i--) {
		printf("%d\n", arr[i]);
	}
}
int main() {
	int arr[10];
	init(arr);
	reverse(arr);
	return 0;
}
