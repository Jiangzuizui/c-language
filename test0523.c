////����Ļ�ϴ�ӡ�������
////1
////1 1
////1 2 1
////1 3 3 1
////����
//#include<stdio.h>
//#include<stdlib.h>
//void yangHui(int n) {
//	int data[30][30] = { 1 };
//	int i, j;
//	for (i = 1; i < n; i++) {
//		data[i][0] = 1;
//		for (j = 1; j <= i; j++) {
//			data[i][j] = data[i - 1][j] + data[i - 1][j - 1];
//		}
//	}
//	for (i = 0; i < n; i++) {
//		for (j = 0; j <= i; j++) {
//			printf("%d ", data[i][j]);
//		}
//		putchar('\n');
//	}
//}
//int main() {
//	yangHui(6);//��ӡ6��
//	return 0;
//}


////������
////A˵�������ҡ�
////B˵����C��
////C˵����D��
////D˵��C�ں�˵
////��֪3����˵���滰��1����˵���Ǽٻ�
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int murder[4] = { 0 };
//	int i;
//	for (i = 0; i < 4; i++) {
//		murder[i] = 1;
//		if ((murder[0] != 1) +
//			(murder[2] == 1) +
//			(murder[3] == 1) +
//			(murder[3] != 1) == 3)
//		{
//			break;
//		}
//		murder[i] = 0;
//	}
//	putchar('A' + 1);
//	return 0;
//}

//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����Ρ�
#include<stdio.h>
#include<stdlib.h>
int checkData(int* p) {
	int tmp[7] = { 0 };
	int i;
	for (i = 0; i < 5; i++) {
		if (tmp[p[i]]) {
			return 0;
		}
		tmp[p[i]] = 1;
	}
	return 1;
}
int main() {
	int p[5];
	for (p[0] = 1; p[0] <= 5; p[0]++) {
		for (p[1] = 1; p[1] <= 5; p[1]++) {
			for (p[2] = 1; p[2] <= 5; p[2]++) {
				for (p[3] = 1; p[3] <= 5; p[3]++) {
					for (p[4] = 1; p[4] <= 5; p[4]++) {
						if ((p[1] == 2) + (p[0] == 3) == 1 &&
							(p[1] == 2) + (p[4] == 4) == 1 &&
							(p[2] == 1) + (p[3] == 2) == 1 &&
							(p[2] == 5) + (p[3] == 3) == 1 &&
							(p[4] == 4) + (p[0] == 1) == 1 &&
							checkData(p)
							)
						{
							for (int i = 0; i < 5; i++) {
								printf("%d", p[i]);
							}
							putchar('\n');
						}
					}
				}
			}
		}
	}
	return 0;
}
