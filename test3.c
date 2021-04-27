//冒泡排序(升序)
//#include<stdio.h>
//#include<stdlib.h>
//
//void bubbleSort(int arr[], int size) {
//	//写一下从后往前遍历的版本
//	//每次从后往前遍历比较相邻元素
//	//每一趟能把最小的值放到最前面
//	//bound是边界 已排序和待排序的分界线
//	//[0,bound]已排序  [bound,size]待排序
//	int bound = 0;
//	for (; bound < size; bound++) {
//		for (int cur = size - 1; cur > bound;cur--) {
//			//由于cur是从size-1向左开始的
//			//所以就不能使用cur+1作为相邻元素了,必须用cur-1
//			if (arr[cur - 1]>arr[cur]) {
//				//不符合升序条件,就进行交换
//				int tmp = arr[cur - 1];
//				arr[cur - 1] = arr[cur];
//				arr[cur] = tmp;
//			}
//		 }
//	}
//}
//int main() {
//	int arr[] = { 9,5,2,7,3,6,8 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	bubbleSort(arr,size);
//	for (int i = 0; i < size; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//
//
//
//	system("pause");
//	return 0;
//}


////交换数组
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int arr1[4] = { 1,2,3,4 };
//	int arr2[4] = { 5,6,7,8 };
//	int tmp[4] = { 0 };
//	int i = 0;
//	printf("交换前:\n");
//	printf("arr1[]的值为:");
//	for (i = 0; i < 4; i++) {
//		printf("%d", arr1[i]);
//	}
//	printf("\n");
//	printf("arr2[]的值为:");
//	for (i = 0; i < 4; i++) {
//		printf("%d", arr2[i]);
//	}
//	printf("\n");
//
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
//		tmp[i] = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp[i];
//	}
//	printf("交换后:\n");
//	printf("arr1[]的值为:");
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
//		printf("%d", arr1[i]);
//	}
//	printf("\n");
//	printf("arr2[]的值为:");
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
//		printf("%d", arr2[i]);
//	}
//	printf("\n");
//		return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int init(int arr[]) {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
}
int print(int arr[]) {
	for (int i = 0; i < 10; i++) {
		printf("arr[%d]=%d\n");
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
	print(arr);
	reverse(arr);
	return 0;
}