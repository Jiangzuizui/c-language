//喝汽水问题
//1瓶汽水1元,2个空瓶可以换1瓶汽水,给20元,可以买多少汽水
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int popNumber(unsigned int money) {
	int pop = money;
	int empty = money;
	while (empty > 1) {
		pop += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	return pop;
}
int main() {
	unsigned int money = 0;
	printf("请输入金钱数:\n");
	scanf("%d", &money);
	int ret = popNumber(money);
	printf("可以买多少瓶汽水:%d\n", ret);
	system("pause");
	return 0;
}
