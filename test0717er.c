#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int bitdiffCount(int a, int b) {
	int tmp = a ^ b;
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (tmp & (1 << i)) {
			count++;
		}
	}
	return count;
}

//打印一个数字所有的奇数位和偶数位
void getBits(int num) {
	for (int i = 1; i < 32; i += 2) {
		if (num & (1 << i)) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
	printf("\n");
	for (int i = 0; i < 32; i += 2) {
		if (num & (1 << i)) {
			printf("1");
		}
		else {
			printf("0");
		}
	}
	printf("\n");
}

//如果是大端返回1 不是0
int isBigEnd() {
	int num = 0x11223344;
	int* p = &num;
	char* p2 = (char*)p;
	if (*p2 == 0x11) {
		return 1;
	}
	return 0;
}

int main() {
	/*int ret=bitdiffCount(1,2);
	printf("%d\n", ret);*/
	//getBits(10);
	//int num = 10;
	printf("%d\n", isBigEnd());
	system("pause");
	return 0;
}