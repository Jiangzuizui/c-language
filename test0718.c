#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void func() {
	int sum = 0;
	int cur = 0;
	for (int i = 0; i < 5; i++) {
		cur = cur * 10 + 2;
		sum += cur;
	}
	printf("%d\n", sum);
}


int calcDecimalCount(int num) {
	int count = 0;
	while (num != 0) {
		num /= 10;
		count++;
	}
	return count;
}

int isShuixian(int num) {
	int oldNum = num;
	int n = calcDecimalCount(num);
	int sum = 0;
	while (num != 0) {
		int tmp = num % 10;
		num /= 10;
		sum += (int)(tmp, n);
	}
	if (sum == oldNum) {
		return 1;
	}
	return 0;
}

void printLine(int starCount, int spaceCount) {
	for (int i = 0; i < spaceCount; i++) {
		printf(" ");
	}
	for (int i = 0; i < starCount; i++) {
		printf("*");
	}
	printf("\n");
}

void printLingxing() {
	for (int row = 1; row <= 6; row++) {
		printLine(2 * row - 1, 7 - row);
	}
	printLine(13, 0);
	for (int row = 6; row >= 1; row--) {
		printLine(2 * row - 1, 7 - row);
	}
}

int minGongbei(int x, int y) {
	int maxNum = x > y ? x : y;
	for(int i = maxNum; i <= x * y; i++) {
		if (i % x == 0 && i % y == 0) {
			return i;
		}
	}
	return 0;
}

void reverse(char* str,int len) {
	char* left = str;
	char* right = str + len - 1;
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}

void reverseWord(char* input) {
	reverse(input, strlen(input));
	char* start = input;
	while (*start != '\0') {
		char* end = start;
		while (*end != ' ' && *end != '\0') {
			end++;
		}
		reverse(start, end - start);
		if (*end == '\0') {
			break;
		}
		else {
			start = end + 1;
		}
	}
}

int main() {
	//获取函数指针
	printf("%p\n", reverse);
	printf("%p\n", &reverse);
	//创建一个函数指针变量，让它指向reverse函数
	void(*p)(char*, int) = reverse;


	/*while (1) {
		char input[101] = { 0 };
		char* ret=gets(input);
		if (ret == NULL) {
			break;
		}
		reverseWord(input);
		printf("%s\n", input);
	}*/

	/*while (1) {
		int x = 0;
		int y = 0;
		int n=scanf("%d %d", &x, &y);
		if (n < 2) {
			break;
		}
		int result = minGongbei(x, y);
		printf("%d\n", result);
	}*/

	//int arr[] = { 1,2,3,4 };
	////arr和&arr得到的是两个不同类型的指针
	////arr能够得到int*  &arr得到的是int(*)[4]
	//printf("%p\n", arr);
	//printf("%p\n", &arr);
	//printf("%p\n", arr+1);
	//printf("%p\n", &arr+1);

	/*float a = 0.1f;
	float b = 0.2f;
	printf("%f\n", a * b);*/

	/*char a = -128;
	printf("%u\n", a);*/

	//printLingxing();

	/*for (int i = 0; i < 100000; i++) {
		if (isShuixian(i)) {
			printf("%d\n", i);
		}
	}*/
	//func();
	/*int arr[] = { 1,2,3,4,5 };
	short* p = (short*)arr;
	for (int i = 0; i < 5; i++) {
		printf("%d\n", arr[i]);
	}*/

	system("pause");
	return 0;
}