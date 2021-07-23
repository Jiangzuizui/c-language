//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//ͨѶ¼
//1.��һ��������ʾ��Ϣ ����̨
//2.����һЩ��ϵ����Ϣ �������� �绰
//3.ʵ�ֶ����ɸ���ϵ�˵���ɾ�Ĳ����
// ������ϵ�� �鿴������ϵ�� �������ֲ���ĳ����ϵ�� ɾ����ϵ�� �޸���ϵ����Ϣ

typedef struct PersonInfo {
	char name[1024];
	char phone[1024];
}PersonInfo;

#define	MAX_PERSONINFO_SIZE 200

typedef struct AddressBook {
	PersonInfo persons[MAX_PERSONINFO_SIZE];
	//size��ʾpersons������ʵ����Ч��Ԫ�ظ���
	//[0,size)��Ч
	int size;
}AddressBook;

void init(AddressBook* addressbook) {
	memset(addressbook->persons, 0, sizeof(addressbook->persons));
	addressbook->size = 0;
}

int menu() {
	printf("=====================\n");
	printf("��ӭʹ��ͨѶ¼����\n");
	printf("0.�˳�\n");
	printf("1.�鿴������ϵ��\n");
	printf("2.������ϵ��\n");
	printf("3.�������ֲ�����ϵ��\n");
	printf("4.ɾ����ϵ��\n");
	printf("5.�޸���ϵ����Ϣ\n");
	printf("=====================\n");
	printf("����������ѡ��\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void showPersonInfo(AddressBook* addressbook) {
	assert(addressbook != NULL);
	//��ӡÿ����ϵ�˵���Ϣ
	printf("�鿴������ϵ��...\n\n");
	for (int i = 0; i < addressbook->size; i++) {
		PersonInfo* p = &addressbook->persons[i];
		printf("[%d] %s\t%s\n", i, p->name, p->phone);

	}
	printf("\n����ʾ��%d������\n", addressbook->size);
}

void addPersonInfo(AddressBook* addressbook) {
	printf("������ϵ��...\n\n");
	//����������ϵ����Ϣ,�ŵ��±�sizeλ����
	if (addressbook->size >= MAX_PERSONINFO_SIZE) {
		printf("����ʧ��,��ϵ������\n");
		return;
	}
	PersonInfo* p = &addressbook->persons[addressbook->size];
	printf("����������ϵ�˵�����: \n");
	scanf("%s", p->name);
	printf("����������ϵ�˵绰: \n");
	scanf("%s",p->phone);
	addressbook->size++;
	printf("������ϵ�˳ɹ�!\n\n");
}

void findPersonInfo(AddressBook* addressbook) {
	//���������ҵ���Ӧ�ĵ绰
	assert(addressbook != NULL);
	printf("��������������ϵ��!\n\n");
	printf("������Ҫ���ҵ�����: \n");
	char name[1024] = { 0 };
	scanf("%s", &name);
	int count = 0;
	for (int i = 0; i < addressbook->size; i++) {
		PersonInfo* p = &addressbook->persons[i];
		if (strcmp(p->name, name) == 0) {
			//������� �Ͷ���ӡ����
			printf("[%d] %s\t\t%s\n", i, p->name, p->phone);
			count++;
		}
	}
	printf("\n�������! �����ҵ���%d����Ϣ\n\n",count);
}

//ɾ���һ���� size--
//ɾ�м���� �����һ���˷��ڸ�λ�� size--
void deletePersonInfo(AddressBook* addressbook) {
	assert(addressbook != NULL);
	printf("ɾ����ϵ��!\n\n");
	printf("������Ҫɾ����ϵ�˵����\n");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addressbook->size) {
		printf("�����id���� ����������!\n");
		return;
	}
	if (id == addressbook->size - 1) {
		//��ʱҪɾ���������һ��Ԫ��
		addressbook->size--;
		printf("\nɾ���ɹ�\n\n");
		return;
	}
	addressbook->persons[id] = addressbook->persons[addressbook->size - 1];
	addressbook->size--;
	printf("\nɾ���ɹ�\n\n");
}

void updatePersonInfo(AddressBook* addressbook) {
	assert(addressbook != NULL);
	printf("�޸���ϵ����Ϣ\n\n");
	printf("������Ҫ�޸ĵ���ϵ�����\n");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addressbook->size) {
		printf("�����id���� ����������!\n");
		return;
	}
	PersonInfo* p = &addressbook->persons[id];
	printf("�����Ҫ���ֲ��� ������*");
	printf("�������µ���ϵ������");
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0) {
		strcpy(p->name, name);
	}
	printf("�������µ���ϵ�˵绰");
	char phone[1024] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(p->phone, phone);
	}

	printf("\n�޸���ϵ�����\n\n");
}

//void quit(AddressBook* addressbook) {
//	//������ǰ����
//	exit(0);
//}

typedef void(*Func)(AddressBook*);

AddressBook addressbook;

int main() {
	//����mian�����д�������ṹ�����
	//�������ṹ��������г�ʼ��
	init(&addressbook);
	//����һ������ָ������
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
			printf("�������� ����������\n");
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