#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�ַ�������(��ҵ)
void reverseString(char str[]) {
	int left = 0;
	int right = strlen(str) - 1;
	while (left < right) {
		char tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--; 
	}
}

void reverseString2(char str[]) {
	int len = strlen(str);
	if (len == 0||len==1) {
		return;
	}
	char tmp = str[0];
	str[0] = str[len - 1];
	str[len - 1] = '\0';
	reverseString2(str + 1);
	str[len - 1] = tmp;
}

//���λ֮��
int digitSum(unsigned int num) {
	int sum = 0;
	while (num != 0) {
		printf("%d\n", num % 10);
		sum+=num % 10;
		num /= 10;
	}
	return sum;
}

int digitSum2(unsigned int num) {
	if (num == 0) {
		return 0;
	}
	return num % 10 + digitSum2(num / 10);
}

int main() {
	int ret = digitSum2(1792);
	printf("ret=%d\n", ret);

	/*char str[] = "abcd";
	reverseString2(str);
	printf("%s\n", str);*/


	//ָ��Ƚ� 
	/*int num = 10;
	int* p = &num;
	if (p != NULL) {
		printf("��ʱ��һ����Ч�ĵ�ַ\n");
	}
	else {
		printf("��ʱ��һ����Ч�ĵ�ַ\n");
	}*/

	//char str1[] = "hello";
	//char str2[] = "hello";
	/*char* str1 = "hello";
	char* str2 = "hello";
	if (str1 == str2) {
		printf("haha\n");
	}
	else {
		printf("hehe\n");
	}*/

	////ͨ��ָ��������� 
	//int arr[] = { 9,5,2,7, };
	//int size = sizeof(arr) / sizeof(arr[0]);

	//for (int* p = arr; p < arr + size; p += 1) {
	//	printf("%d\n", *p);
	//}

	////ָ�����
	//int arr[] = { 9,5,2,7 };
	//int* p1 = arr;
	//int* p2 = &arr[2];
	//printf("%d\n", p2 - p1);

	/*double* p = NULL;
	printf("%p\n", p + 1);*/

	//printf("%d\n", sizeof(char*));//4

	system("pause");
	return 0;
}