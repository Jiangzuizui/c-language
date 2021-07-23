#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//这个写法完全错误 套娃
//struct A {
//	int id;
//	struct A a;
//};

//struct A {
//	int id;
//	struct A* a;
//};
////链表 二叉树 
//struct LinkedNode {
//	int value;
//	struct LinkedNode* next;
//};
//
//struct TreeNode {
//	int value;
//	struct TreeNode* leftChild;
//	struct TreeNode* rightChild;
//};

//struct A {
//	int a;
//	int b;
//	int c;
//};

struct A {
	char a;
	int b;
	int c;
};

struct IpPacket {
	int version : 4;
	int headerLen : 4;
	int tos : 8;
	int length : 16;
};

enum Sex {
	MALE,
	FAMALE,
	UNKNOWN
};

enum Week {
	Monday,
	tuesday,
	Wednesday,
};



int main() {
	enum Sex s = MALE;
	s = Monday;

	/*struct A h = { 10,20,30 };
	printf("%p\n", &h);
	printf("%p\n", &h.a);
	printf("%p\n", &h.b);
	printf("%p\n", &h.c);
	printf("%p\n", sizeof(h));*/
	
	//printf("%d\n", sizeof(struct A));

	system("pause");
	return 0;
}