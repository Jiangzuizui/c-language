////дһ��������ӡarr���������(arr�����ε�һά����)
////��ʹ�������±�,ʹ��ָ��
//
//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	int size = sizeof(arr) / sizeof(arr[0]);//������鳤��
//	int* p = arr;//����ָ���������ʼ��,������������������Ԫ�صĵ�ַ
//	for (int i = 0; i < size; i++) {
//		printf("%d ",  *p);//ȡ��p��ָ��Ԫ�صĵ�ַ
//		p++;//��ȡ��p����һ��λ��
//	}
//	system("pause");
//	return 0;
//}


//дһ������,��������һ���ַ���������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int init(int arr[]) {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}
}
void reverse(int arr[]) {
	for (int i = 9; i >= 0; i--) {
		printf("%d\n", arr[i]);
	}
}
int main() {
	int arr[10];
	init(arr);
	reverse(arr);
	return 0;
}
