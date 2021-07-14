//函数递归
#include<stdio.h>
#include<stdlib.h>

//求字符串长度
int myStrlen(char* str) {
	if (str[0] == '\0') {
		return 0;
	}
	return 1 + myStrlen(str + 1);
}

//求n的阶乘
int factor(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factor(n - 1);
}

//斐波那契数 递归
int fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	return fib( n - 1) + fib(n - 2);
}

//斐波那契数列 循环
int fib2(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	//用i表示第i项
	int last1 = 1;//i-1的值
	int last2 = 1;//i-2的值
	int cur = 0;
	for (int i = 3; i <= n; i++) {
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}

int main() {
	//printf("%d\n", myStrlen("abcd"));
	//printf("%d\n", factor(5));
	printf("%d\n", fib2(5));
	system("pause");
	return 0;
}