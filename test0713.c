#include<stdio.h>
#include<stdlib.h>

 //����ֵ�趨Ϊint,����������1,���Ƿ���0
//int isPrime(int num) {
//	if (num == 1||num==0) {
//		return 0;
//	}
//	for (int i = 2; i < num; i++) {
//		if (num % i == 0) {
//			return 0;
//		}
//	}
//	return 1;
//}


int isLeapYear(int year) {
	if (year % 100 == 0) {
		//��������
		if (year % 400 == 0) {
			return 1;
		}return 0;
	}
	else {
		//��ͨ����
		if (year % 4 == 0) {
			return 1;
		}return 0;
	}
}


//���ֲ���
//arr��ʾ�����ҵ�����(��������)
//toFind��ʾҪ���ҵ�����
int binarySearch(int arr[],int size,int toFind) {
	int left = 0;
	int right = size-1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (toFind < arr[mid])  {
			right = mid - 1;
		}
		else if (toFind > arr[mid]) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

//ÿ����һ��num,num����1
void func(int* num) {
	(*num)++;
}

void printNum(unsigned int num) {
	if (num > 9) {
		printNum(num / 10);
	}
	printf("%d\n", num % 10);
}

int main() {
	//printf("%d\n", isPrime(20));
	//printf("%d\n", isLeapYear(2018));
	/*int arr[] = { 1,2,3,4,5,6,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret=binarySearch(arr,size,6);
	printf("%d\n", ret);*/
	/*int num = 0;
	func(&num);
	printf("%d\n", num);*/
	printNum(1234);
	system("pause");
}