#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//����1!+...+10!(2)
//int factor(int n) {
//	int result = 1;
//	for (int i = 1; i <= n; i++) {
//		result *= i;
//	}
//	return result;
//}

int main() {
	////��ӡn�Ľ׳�
	//int n = 0;
	//scanf("%d", &n);
	//int result = 1;
	//for (int i = 1; i <= n; i++) {
	//	result = result * i;
	//}
	//printf("%d\n", result);
	
	//����1!+...+10!(1)
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

	//���ұ����������е�λ��
	int num = 0;
	printf("������Ҫ���ҵ�����:\n");
	scanf("%d", &num);
	int i = 0;
	int arr[7] = { 1,2,3,4,5,6,7 };
	//���ֲ���
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

	//��ͨ����
	/*for (; i <7; i++) {
		if (num == arr[i]) {
			printf("��num�������±���%d\n", i);
			break;
		}
	}if (i < 7) {
		printf("�ղ��ҵ���\n");
	}
	else {
		printf("û�ҵ�\n");
	}*/
}
