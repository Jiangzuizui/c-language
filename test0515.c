//����ˮ����
//1ƿ��ˮ1Ԫ,2����ƿ���Ի�1ƿ��ˮ,��20Ԫ,�����������ˮ
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
	printf("�������Ǯ��:\n");
	scanf("%d", &money);
	int ret = popNumber(money);
	printf("���������ƿ��ˮ:%d\n", ret);
	system("pause");
	return 0;
}
