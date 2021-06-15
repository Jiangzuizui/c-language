////实现srelen
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

////实现strcpy
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



//实现strcmp
#include<stdio.h>
#include<string.h>
#include<assert.h>

int myStrcmp(const char* str1, const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	//依次比较每个字符之间的大小关系
	const char* p1 = str1;
	const char* p2 = str2;
	while (*p1 != '\0 '&& *p2!='\0') {
		//比较p1和p2指向的字符大小关系
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
	//p1和p2不一样长
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
	//a比e小,返回一个<0的数
	/*char str1[] = "hallo";
	char str2[] = "hello";
	printf("%d\n", strcmp(str1, str2));*/
}















////实现strcat
//#include<stdio.h>
//#include<string.h> 
//#include<assert.h>
//
//char* myStrcat(char* dest, const char* src){
////判定参数合法性
//	assert(dest != NULL);
//	assert(src != NULL);
//	//1.找到destination的结束位置
//	int destTail = 0;
//	while (dest[destTail] != '\0'){
//		destTail++;
//	}
//	//当循环结束的时候,destTail变量就指向了
//	//destination的\0位置
//	//myStrcpy(dest + destTail, src);
//	//2.把数据拷贝过来
//	int i = 0;
//	while (src[i] != '\0') {
//		dest[destTail + i] = src[i];
//		i++;
//	}
//	//3.把dest最后的位置设为\0
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

