////ʵ��strncpy
//#include <stdio.h>
//#include <string.h>
//#include<assert.h>
//
//char* myStrncpy(char* dest, const char* src, size_t num) {
//	assert(dest != NULL);
//	assert(src != NULL);
//	assert(num != 0);
//	size_t i = 0;
//	while (src[i] != '\0' && i < num) {
//		dest[i] = src[i];
//		i++;
//	}
//	//�����ѭ���������������ѭ������
//	//(1)i==num,����ֱ�ӽ���
//	/*if (i == num) {
//		return dest;
//	}*/
//	//(2)src����\0,������destinationʣ��Ĳ��ֶ���Ϊ\0
//	while (i < num) {
//		dest[i] = '\0'; 
//		i++;
//	}
//	return dest;
//}
//
//
//int main() {
//	char str1[1024] = { 0 };
//	char str2[] = "hello";
//	myStrncpy(str1, str2,10);
//	printf("%s\n", str1);
//}


//ʵ��strncat
#include <stdio.h>
#include <string.h>
#include<assert.h>

char* myStrncat(char* dest, const char* src, size_t num) {
	assert(dest != NULL);
	assert(src != NULL);
	assert(num != 0);
	size_t destTail = 0;
	while (dest[destTail] != '\0') {
		destTail++;
	}
	size_t i = 0;
	while (src[i] != '\0' && i < num) {
		dest[destTail + i] = src[i];
		i++;
	}
	dest[destTail + i] = '\0';
	return dest;
}

