////�������
////��a+aa+aaa+aaaa+aaaaa   eg.2+22+222+2222+22222
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
//	printf("��ֱ��������ֺ�����:\n");
//	scanf("%d %d", &a, &n);
//	for (i = 0; i < n; i++) {
//		tmp = tmp * 10 + a;
//		sum += tmp;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}


////���0-100000֮�����е�ˮ�ɻ���
////ˮ�ɻ�����ָһ��nλ��
////���λ���ֵ�n�η�֮��ǡ�õ��ڸ�������
////eg.153=1^3+5^3+3^3,��153��һ��ˮ�ɻ���
//#include<stdio.h>
//#include<math.h>
//int main() {
//	int i = 0;
//	for (i = 0; i < 100000; i++) {
//		int count = 1;
//		int tmp = i;
//		int sum = 0;
//		//������ֵ�λ��
//		while (tmp / 10) {
//			count++;
//			tmp = tmp / 10;
//		}
//		//����ÿһλ�Ĵη���
//		tmp = i;
//		while (tmp) {
//			sum += pow(tmp % 10, count);
//			tmp = tmp / 10;
//		}
//		//�ж��Ƿ�Ϊˮ�ɻ���,�Ǿʹ�ӡ
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}


//��ӡ���� 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int line = 0;
	int i = 0;
	scanf("%d", &line);//7
	//��ӡ�ϰ벿��
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
