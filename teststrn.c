////实现strncpy
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
//	//上面的循环有两种情况导致循环结束
//	//(1)i==num,函数直接结束
//	/*if (i == num) {
//		return dest;
//	}*/
//	//(2)src遇到\0,后续把destination剩余的部分都设为\0
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


//实现strncat
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

