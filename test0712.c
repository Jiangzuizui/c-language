#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//计算1!+...+10!(2)
//int factor(int n) {
//	int result = 1;
//	for (int i = 1; i <= n; i++) {
//		result *= i;
//	}
//	return result;
//}

int main() {
	////打印n的阶乘
	//int n = 0;
	//scanf("%d", &n);
	//int result = 1;
	//for (int i = 1; i <= n; i++) {
	//	result = result * i;
	//}
	//printf("%d\n", result);
	
	//计算1!+...+10!(1)
	/*int sum = 0;
	for (int i = 1; i <= 10; i++) {
		int result = 1;
		for (int j = 1; j <= i; j++) {
			result = result * j;
		}
		sum = sum + result;
	}
	printf("%d\n", sum);*/


	/*int sum = 0;
	for (int i = 1; i <= 10; i++) {
		sum += factor(i);
	}
	printf("sum=%d\n", sum);*/

	//查找变量在数组中的位置
	int num = 0;
	printf("请输入要查找的数字:\n");
	scanf("%d", &num);
	int i = 0;
	int arr[7] = { 1,2,3,4,5,6,7 };
	//二分查找
	int left = 0;
	int right = 6;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (num < arr[mid]) {
			right = mid - 1;
		}
		else if (num > arr[mid]) {
			left = mid + 1;
		}
		else {
			printf("%d", mid);
			break;
		}
	}

	//普通查找
	/*for (; i <7; i++) {
		if (num == arr[i]) {
			printf("该num所处的下标是%d\n", i);
			break;
		}
	}if (i < 7) {
		printf("刚才找到了\n");
	}
	else {
		printf("没找到\n");
	}*/
}
