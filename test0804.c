#define _CRT_SECURE_NO_WARNINGS
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

//#define	MAX_PERSONINFO_SIZE 200

typedef struct AddressBook {
	//指针形式 通过动态内存管理的方式
	PersonInfo* persons;
	//size表示persons数组中实际有效的元素个数
	//[0,size)有效
	int size;
	//capacity表示persons对应的空间的最大容量
	int capacity;
}AddressBook;

extern void save(AddressBook* addressbook);
extern void load(AddressBook* addressbook);


void init(AddressBook* addressbook) {
	/*memset(addressbook->persons, 0, sizeof(addressbook->persons));
	addressbook->size = 0;*/
	//显式申请内存空间
	addressbook->size = 0;
	addressbook->capacity = 200;
	addressbook->persons = (PersonInfo*)malloc
	(addressbook->capacity * sizeof(PersonInfo));
	//如果不对malloc初始化 在vs debug模式下会填充成屯屯屯
	//memset(addressbook->persons, 0, sizeof(PersonInfo) * addressbook->capacity);
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

	if (addressbook->size >= addressbook->capacity) {
		//printf("新增失败,联系人已满\n");
		//进行扩容
		addressbook->capacity += 100;
		//重新申请内存空间
		//直接使用relloc比较简单方便
		/*addressbook->persons = realloc(addressbook->persons,
			addressbook->capacity * sizeof(PersonInfo));*/
		
		//也可以用malloc手动模拟realloc 的过程
		PersonInfo* old = addressbook->persons;
		addressbook->persons = (PersonInfo*)malloc(
			addressbook->capacity * sizeof(PersonInfo));
		//把旧的内存空间的数据拷贝到新的空间上
		memcpy(addressbook->persons, old,
			sizeof(PersonInfo) * addressbook->size);
		//释放旧的空间
		free(old);
		
	}
	//把新增的联系人信息,放到下标size位置上
	PersonInfo*  p = &addressbook->persons[addressbook->size];
	printf("请输入新联系人的姓名: \n");
	scanf("%s", p->name);
	printf("请输入新联系人电话: \n");
	scanf("%s",p->phone);
	addressbook->size++;

	//保存数据到磁盘
	save(addressbook);

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
	//删除中间元素 把最后的元素拷贝过去再删最后一个
	addressbook->persons[id] = 
		addressbook->persons[addressbook->size - 1];
	addressbook->size--;

	save(addressbook);
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
		//用户输入的不是*
		strcpy(p->name, name);
	}
	printf("请输入新的联系人电话");
	char phone[1024] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(p->phone, phone);
	}

	save(addressbook);
	printf("\n修改联系人完成\n\n");
}

//void quit(AddressBook* addressbook) {
//	//结束当前进程
//	exit(0);
//}

typedef void(*Func)(AddressBook*);

//创建一组函数 保存到文件以及从文件中加载数据

void save(AddressBook* addressbook) {
	//把通讯录中的内容保存到文件中
	//1.打开文件
	FILE* f=fopen("d:/AddressBook.txt", "w");
	if (f == NULL) {
		perror("文件打开失败");
		return;
	}
	//2.写入内容
	/*for (int i = 0; i < addressbook->size; i++) {
		PersonInfo* p = &addressbook->persons[i];
		fwrite(p, sizeof(PersonInfo), 1, f);
	}*/
	fwrite(addressbook->persons,
		sizeof(PersonInfo), addressbook->size, f);
	//3.关闭文件
	fclose(f);

}

void load(AddressBook* addressbook) {
	//从文件中加载通讯录的内容
	//1.打开文件
	FILE* f = fopen("d:/AddressBook.txt", "r");
	if (f == NULL) {
		printf("当前文件尚未创建!\n");
		return;
	}
	//2.读取数据,最好用循环,随时进行扩容
	while (1) {
		PersonInfo personInfo = { 0 };
		size_t len = fread(&personInfo, sizeof(PersonInfo), 1, f);
		if (len == 0) {
			printf("读取完毕\n");
			break;
		}
		//把personInfo这个变量加到结构体里面去
		if (addressbook->size >= addressbook->capacity) {
			//先扩容,与上面类似
			PersonInfo* old = addressbook->persons;
			addressbook->capacity += 100;
			addressbook->persons = (PersonInfo*)malloc
			(addressbook->capacity * sizeof(PersonInfo));
			memcpy(addressbook->persons, old, addressbook->size * sizeof(PersonInfo));
			free(old);

		}
		//赋值数据
		addressbook->persons[addressbook->size] = personInfo;
		addressbook->size++;
	}
	fclose(f);
}

AddressBook addressbook;

int main() {
	//先在mian函数中创建这个结构体变量
	//针对这个结构体变量进行初始化
	init(&addressbook);

	//加上一个从文件加载数据的逻辑
	load(&addressbook);

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