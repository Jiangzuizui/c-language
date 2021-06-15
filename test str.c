////ʵ��srelen
//#include<stdio.h>
//#include<string.h>
//
//size_t strlen(const char* str) {
//	size_t size = 0;
//	while (str[size] != '\0') {
//		size++;
//	}
//	return size;
//}
//
//int main() {
//	printf("%d\n", strlen("abcd"));
//}

////ʵ��strcpy
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
//char* myStrcpy(char* dest, const char* src) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	int i = 0;
//	while (src[i] != '\0') {
//		dest[i] = src[i];
//		i++;
//	}
//	dest[i] = '\0';
//	return dest;
//}
//int main() {
//	char dest[1024] = { 0 };
//	char src[] = "hello";
//	myStrcpy(dest, src);
//	printf("%s\n", dest);
//	/*char dest[4] = { 0 };
//	char src[] = "abc";
//	strcpy(dest, src);
//	printf("%s\n", dest);*/
//
//}



//ʵ��strcmp
#include<stdio.h>
#include<string.h>
#include<assert.h>

int myStrcmp(const char* str1, const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	//���αȽ�ÿ���ַ�֮��Ĵ�С��ϵ
	const char* p1 = str1;
	const char* p2 = str2;
	while (*p1 != '\0 '&& *p2!='\0') {
		//�Ƚ�p1��p2ָ����ַ���С��ϵ
		if (*p1 < *p2) {
			return -1;
		}
		else if (*p1 > *p2) {
			return 1;
		}
		else {
			p1++;
			p2++;
		}
	}
	//p1��p2��һ����
	/*if (*p1 < *p2) {
		return -1;
	}
	else if(*p1 > *p2) {
		return 1;
	}
	else
		return 0;*/
	return *p1 - *p2;
}
int main() {
	char str1[] = "hello";
	char str2[] = "hallo";
	printf("%d\n", myStrcmp(str1, str2));
	//a��eС,����һ��<0����
	/*char str1[] = "hallo";
	char str2[] = "hello";
	printf("%d\n", strcmp(str1, str2));*/
}















////ʵ��strcat
//#include<stdio.h>
//#include<string.h> 
//#include<assert.h>
//
//char* myStrcat(char* dest, const char* src){
////�ж������Ϸ���
//	assert(dest != NULL);
//	assert(src != NULL);
//	//1.�ҵ�destination�Ľ���λ��
//	int destTail = 0;
//	while (dest[destTail] != '\0'){
//		destTail++;
//	}
//	//��ѭ��������ʱ��,destTail������ָ����
//	//destination��\0λ��
//	//myStrcpy(dest + destTail, src);
//	//2.�����ݿ�������
//	int i = 0;
//	while (src[i] != '\0') {
//		dest[destTail + i] = src[i];
//		i++;
//	}
//	//3.��dest����λ����Ϊ\0
//	dest[destTail + i] = '\0';
//	return dest;
//	}
//int main() {
//	char dest[1024] = "world";
//	char src[] = "hello";
//	myStrcat(dest, src);
//	printf("%s\n", dest);
//
//}
//

