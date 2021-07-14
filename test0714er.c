#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int size) {
	//从后往前遍历
	//每次能把最小的值放在最前面
	//[0,bound)已排序  (bound,size]待排序
	int bound = 0;
	for (; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			if (arr[cur - 1] > arr[cur]) {
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
}

int main() {
	//冒泡排序
	int arr[ ] = { 9,5,2,7,3,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr,size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	
	//int arr[3][4] = { 1,2,3,4,5};
	/*int arr[3][4] = {
		{1,2},
		{3,4},
		{5}
	};*/

	////第一个[]中的数字可省略,第二个[]不可
	//int arr[][4] = {
	//	3,4,5
	//};

	/*for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 4; col++) {
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}*/
	system("pause");
	return 0;
}