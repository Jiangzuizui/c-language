//#include <stdio.h>
//#include<string.h>
//#include<assert.h>
//
//const char* myStrstr(const char* str1, const char* str2) {
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	assert(*str1 != '\0');
//	assert(*str2 != '\0');
//
//	const char* black = str1;
//	//���ѭ��ͨ��black���ƴ�str1���ĸ�λ�ÿ�ʼ���Ӵ�
//	while (*black != '\0') {
//		char* red = black;
//		char* sub = str2;
//		//���ѭ�����Ǵ�black��ʼ���ж���ǰ����Ӵ���str2�Ƿ����
//		while (*red!='\0'&&*sub!='\0'&&
//			*red == *sub) {
//			red++;
//			sub++;
//		}
//		//1.*red==\0
//		//2.*sub!=\0
//		//3.*red!=*sub
//		/*if (*red == '\0' || *red == *sub) {
//			black++;
//			continue;
//		}*/
//		if (*sub == '\0') {
//			return black;
//		}
//		black++;
//	}
//	return NULL;
//}
//
//int main() {
//	char* str1 = "hello world";
//	char* str2 = "llo";
//	const char* result=myStrstr(str1, str2);
//	printf("%c\n", *result);
//	system("pause");
//	return 0;
//}
