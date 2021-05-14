////计算求和
////求a+aa+aaa+aaaa+aaaaa   eg.2+22+222+2222+22222
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int main() {
//	int a = 0;
//	int n = 0;
//	int i = 0;
//	int tmp = 0;
//	int sum = 0;
//	printf("请分别输入数字和项数:\n");
//	scanf("%d %d", &a, &n);
//	for (i = 0; i < n; i++) {
//		tmp = tmp * 10 + a;
//		sum += tmp;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}


////求出0-100000之间所有的水仙花数
////水仙花数是指一个n位数
////其各位数字的n次方之和恰好等于该数本身
////eg.153=1^3+5^3+3^3,则153是一个水仙花数
//#include<stdio.h>
//#include<math.h>
//int main() {
//	int i = 0;
//	for (i = 0; i < 100000; i++) {
//		int count = 1;
//		int tmp = i;
//		int sum = 0;
//		//求出数字的位数
//		while (tmp / 10) {
//			count++;
//			tmp = tmp / 10;
//		}
//		//计算每一位的次方和
//		tmp = i;
//		while (tmp) {
//			sum += pow(tmp % 10, count);
//			tmp = tmp / 10;
//		}
//		//判断是否为水仙花数,是就打印
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}


//打印菱形 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int line = 0;
	int i = 0;
	scanf("%d", &line);//7
	//打印上半部分
	for (i = 0; i < line; i++) {
		int j = 0;
		for (j = 0; j < line - 1 - i; j++) {
			printf(" ");
		}
		for (j = 0; j < 2 * i + 1; j++) {
			printf("*");
		}
		printf("\n");
	}


	for (i = 0; i < line - 1; i++) {
		int j = 0;
		for (j = 0; j <= i; j++) {
			printf(" ");
		}
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
