//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//通讯录
//1.有一个界面显示信息 控制台
//2.管理一些联系人信息 包含姓名 电话
//3.实现对若干个联系人的增删改查操作
// 增添联系人 查看所有联系人 根据名字查找某个联系人 删除联系人 修改联系人信息

typedef struct PersonInfo {
	char name[1024];
	char phone[1024];
}PersonInfo;

#define	MAX_PERSONINFO_SIZE 200

typedef struct AddressBook {
	PersonInfo persons[MAX_PERSONINFO_SIZE];
	//size表示persons数组中实际有效的元素个数
	//[0,size)有效
	int size;
}AddressBook;

void init(AddressBook* addressbook) {
	memset(addressbook->persons, 0, sizeof(addressbook->persons));
	addressbook->size = 0;
}

int menu() {
	printf("=====================\n");
	printf("欢迎使用通讯录程序\n");
	printf("0.退出\n");
	printf("1.查看所有联系人\n");
	printf("2.新增联系人\n");
	printf("3.根据名字查找联系人\n");
	printf("4.删除联系人\n");
	printf("5.修改联系人信息\n");
	printf("=====================\n");
	printf("请输入您的选择\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void showPersonInfo(AddressBook* addressbook) {
	assert(addressbook != NULL);
	//打印每个联系人的信息
	printf("查看所有联系人...\n\n");
	for (int i = 0; i < addressbook->size; i++) {
		PersonInfo* p = &addressbook->persons[i];
		printf("[%d] %s\t%s\n", i, p->name, p->phone);

	}
	printf("\n共显示了%d条数据\n", addressbook->size);
}

void addPersonInfo(AddressBook* addressbook) {
	printf("新增联系人...\n\n");
	//把新增的联系人信息,放到下标size位置上
	if (addressbook->size >= MAX_PERSONINFO_SIZE) {
		printf("新增失败,联系人已满\n");
		return;
	}
	PersonInfo* p = &addressbook->persons[addressbook->size];
	printf("请输入新联系人的姓名: \n");
	scanf("%s", p->name);
	printf("请输入新联系人电话: \n");
	scanf("%s",p->phone);
	addressbook->size++;
	printf("新增联系人成功!\n\n");
}

void findPersonInfo(AddressBook* addressbook) {
	//根据姓名找到对应的电话
	assert(addressbook != NULL);
	printf("根据姓名查找联系人!\n\n");
	printf("请输入要查找的姓名: \n");
	char name[1024] = { 0 };
	scanf("%s", &name);
	int count = 0;
	for (int i = 0; i < addressbook->size; i++) {
		PersonInfo* p = &addressbook->persons[i];
		if (strcmp(p->name, name) == 0) {
			//如果重名 就都打印出来
			printf("[%d] %s\t\t%s\n", i, p->name, p->phone);
			count++;
		}
	}
	printf("\n查找完毕! 共查找到了%d条信息\n\n",count);
}

//删最后一个人 size--
//删中间的人 把最后一个人放在该位置 size--
void deletePersonInfo(AddressBook* addressbook) {
	assert(addressbook != NULL);
	printf("删除联系人!\n\n");
	printf("请输入要删除联系人的序号\n");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addressbook->size) {
		printf("输入的id有误 请重新输入!\n");
		return;
	}
	if (id == addressbook->size - 1) {
		//此时要删除的是最后一个元素
		addressbook->size--;
		printf("\n删除成功\n\n");
		return;
	}
	addressbook->persons[id] = addressbook->persons[addressbook->size - 1];
	addressbook->size--;
	printf("\n删除成功\n\n");
}

void updatePersonInfo(AddressBook* addressbook) {
	assert(addressbook != NULL);
	printf("修改联系人信息\n\n");
	printf("请输入要修改的联系人序号\n");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addressbook->size) {
		printf("输入的id有误 请重新输入!\n");
		return;
	}
	PersonInfo* p = &addressbook->persons[id];
	printf("如果需要保持不变 请输入*");
	printf("请输入新的联系人姓名");
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(p->name, name);
	}
	printf("请输入新的联系人电话");
	char phone[1024] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(p->phone, phone);
	}

	printf("\n修改联系人完成\n\n");
}

//void quit(AddressBook* addressbook) {
//	//结束当前进程
//	exit(0);
//}

typedef void(*Func)(AddressBook*);

AddressBook addressbook;

int main() {
	//先在mian函数中创建这个结构体变量
	//针对这个结构体变量进行初始化
	init(&addressbook);
	//创建一个函数指针数组
	Func arr[]={
		NULL,
		showPersonInfo,
		addPersonInfo,
		findPersonInfo,
		deletePersonInfo,
		updatePersonInfo
	};

	while (1) {
		int choice = menu();
		if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0])) {
			printf("输入有误 请重新输入\n");
			continue;
		}
		if (choice == 0) {
			printf("goodbye\n");
			break;
		}
		arr[choice](&addressbook);
	}


	system("pause");
	return 0;
}