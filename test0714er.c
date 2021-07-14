#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int size) {
	//�Ӻ���ǰ����
	//ÿ���ܰ���С��ֵ������ǰ��
	//[0,bound)������  (bound,size]������
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
	//ð������
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

	////��һ��[]�е����ֿ�ʡ��,�ڶ���[]����
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