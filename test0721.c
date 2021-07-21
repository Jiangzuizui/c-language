#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

size_t myStrlen(const char* str) {
	assert(str != NULL);
	size_t size = 0;
	while (str[size] != '\0') {
		size++;
	}
	return size;
}

char* myStrcpy(char* dest, const char* src) {
	assert(dest != NULL);
	assert(src != NULL);
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

char* myStrcat(char* dest, const char* src) {
	assert(dest != NULL);
	assert(src != NULL);
	int destTail = 0;
	while (dest[destTail] != '\0') {
		destTail++;
	}
	//myStrcpy(dest + destTail, src);
	int i = 0;
	while (src[i] != '\0') {
		dest[destTail + i] = src[i];
		i++;
	}
	dest[destTail + i] = '\0';
	return dest;
} 

int myStrcmp(const char* str1, const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	const char* p1 = str1;
	const char* p2 = str2;
	while (*p1 != '\0' && *p2 != '\0') {
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
	/*if (*p1 < *p2) {
		return -1;
	}
	else if(*p1>*p2){
		return 1;
	}
	else {
		return 0;
	}*/
	return *p1 - *p2;
}

char* myStrncpy(char* dest, char* src, size_t num) {
	assert(dest != NULL);
	assert(src != NULL);
	assert(num != 0);
	size_t i = 0;
	while (src[i] != '\0'&&i<num) {
		dest[i] = src[i];
		i++;
	}
	while (i < num) {
		dest[i] = '\0';
		i++;
	}
	return dest;
}

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

int myStrncmp(const char* str1, const char* str2, size_t num) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(num != 0);
	size_t i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && i < num) {
		if (str1[i] < str2[i]) {
			return -1;
		}
		else if (str1[i] > str2[i]) {
			return 1;
		}
		else {
			i++;
		}
	}
	if (i == num) {
		return 0;
	}
	return str1[i] - str2[i];
}

const char* myStrstr(const char* str1, const char* str2) {
	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(*str1 != '\0');
	assert(*str2 != '\0');

	const char* black = str1;
	while (*black != '\0') {
		const char* red = black;
		const char* sub = str2;
		while (*red!='\0'&&*sub!='\0'
			&&*red == *sub) {
			red++;
			sub++;
		}
		//以上循环结束,有3种可能
		//1.*red==\0 直接结束循环 进入下次
		//2.*sub==\0 找到了 返回black
		//3.*red!=*sub 直接进入下次循环
		/*if (*red == '\0' || *red == *sub) {
			black++;
			continue;
		}*/
		if (*sub == '\0') {
			return black; 
		}
		black++;
	}
	return NULL;
}

void* myMemcpy(void* dest, const void* src, size_t num) {
	assert(dest != NULL);
	assert(src != NULL);
	assert(num != 0);
	//按照字节为单位进行拷贝
	char* cdest = (char*)dest;
	const char* csrc = (const char*)src;
	for (size_t i = 0; i < num; i++) {
		cdest[i] = csrc[i];
	}
	return dest;
}

void* myMemmove(void* dest, const void* src, size_t num) {
	assert(dest != NULL);
	assert(src != NULL);
	assert(num != 0);
	//按照字节为单位进行拷贝
	char* cdest = (char*)dest;
	const char* csrc = (const char*)src;
	if (csrc <= cdest && cdest <= csrc + num) {
		//如果内存重叠了,倒着拷贝
		for (size_t i = num; i > num; i--) {
			cdest[i-1] = csrc[i-1];
		}
		return dest;
	}
	else {
		//如果不重叠 正着拷贝
		for (size_t i = 0; i < num; i++) {
			cdest[i] = csrc[i];
		}
		return dest;
	}
}

int myMemcmp(const void* ptr1, const void* ptr2, size_t num) {
	assert(ptr1 != NULL);
	assert(ptr2 != NULL);
	assert(num != 0);
	const char* cptr1 = (const char*)ptr1;
	const char* cptr2 = (const char*)ptr2;
	for (size_t i = 0; i < num; i++) {
		if (cptr1[i] < cptr2[i]) {
			return -1;
		}
		else if (cptr1[i] > cptr2[i]) {
			return 1;
		}
		else {
			continue;
		}
	}
	return 0;
}

void* myMemset(void* ptr, int value, size_t num) {
	assert(ptr != NULL);
	assert(num != 0);
	char* cptr = (char*)ptr;
	for (size_t i = 0; i < num; i++) {
		cptr[i] = (char)value;
	}
	return ptr;
}

#define MAX_ROW 3
#define MAX_COL 3
//返回1表示找到了 0表示没找到
int findNumInMatrix(int arr[MAX_ROW][MAX_COL], int toFind) {
	//先找到右上角的元素
	int row = 0;
	int col = MAX_COL - 1;
	//取出这个值,开始进行循环比较
	while (row>=0&&row<MAX_ROW
		&&col>0&&col<MAX_COL) {
		int cur = arr[row][col];
		if (cur < toFind) {
			//往下找
			row++;
		}
		else if(cur>toFind){
			//往左找
			col--;
		}
		else {
			//找到了
			return 1;
		}
	}
	return 0;
}

typedef struct Student {
	int id;
	char name[1024];

}Student;

int main() {
	int arr[MAX_ROW][MAX_COL] = {
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	int ret=findNumInMatrix(arr, 10);
	printf("%d\n", ret);

	/*char str[] = "hello";
	char str2[1024] = { 0 };
	myMemcpy(str2, str, sizeof(str));
	printf("%s\n", str2);*/

	/*Student s1 = { 1,"张三" };
	Student s2;
	myMemcpy(&s2, &s1, sizeof(Student));
	printf("%d,%s\n", s2.id, s2.name);*/

	/*int arr[] = { 1,2,3,4 };
	int arr2[100] = { 0 };
	myMemcpy(arr2, arr, sizeof(arr));
	for (int i = 0; i < 4; i++) {
		printf("%d\n", arr2[i]);
	}*/
	/*int a = 10;
	int b = 0;
	myMemcpy(&b, &a, sizeof(a));
	printf("b=%d\n", b);*/
	

	/*char str[] = "aaaa bbbb cccc dddd";
	char* pch = strtok(str, " ");
	while (pch != null) {
		printf("%s\n", pch);
		pch = strtok(null, " ");
	}*/

	/*char* str1 = "hello world";
	char* str2 = "llo";
	const char* result=myStrstr(str1, str2);
	printf("%c %s\n", *result,result);*/
	

	//char str1[1024] = "hello";
	//char str2[1024] = "hella";
	//printf("%d\n", myStrncmp(str1, str2,10));

	/*char str1[1024] = { 0 };
	char str2[] = "hello";
	myStrncpy(str1, str2, 10);
	printf("%s\n", str1);*/

	/*char dest[1024] = "world";
	char src[] = "hello";
	myStrcat(dest, src);*/
	
	//myStrcpy(dest, src);
	//printf("%s\n", dest);

	system("pause");
	return 0;
}