#include<stdio.h>
#include<stdlib.h>

 //返回值设定为int,是素数返回1,不是返回0
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
		//世纪闰年
		if (year % 400 == 0) {
			return 1;
		}return 0;
	}
	else {
		//普通闰年
		if (year % 4 == 0) {
			return 1;
		}return 0;
	}
}


//二分查找
//arr表示待查找的数组(有序数组)
//toFind表示要查找的数字
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

//每调用一次num,num自增1
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