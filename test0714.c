//�����ݹ�
#include<stdio.h>
#include<stdlib.h>

//���ַ�������
int myStrlen(char* str) {
	if (str[0] == '\0') {
		return 0;
	}
	return 1 + myStrlen(str + 1);
}

//��n�Ľ׳�
int factor(int n) {
	if (n == 1) {
		return 1;
	}
	return n * factor(n - 1);
}

//쳲������� �ݹ�
int fib(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	return fib( n - 1) + fib(n - 2);
}

//쳲��������� ѭ��
int fib2(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	//��i��ʾ��i��
	int last1 = 1;//i-1��ֵ
	int last2 = 1;//i-2��ֵ
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