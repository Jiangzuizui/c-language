#define _CRT_SECURE_NO_WARNINGS
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

//#define	MAX_PERSONINFO_SIZE 200

typedef struct AddressBook {
	//ָ����ʽ ͨ����̬�ڴ����ķ�ʽ
	PersonInfo* persons;
	//size��ʾpersons������ʵ����Ч��Ԫ�ظ���
	//[0,size)��Ч
	int size;
	//capacity��ʾpersons��Ӧ�Ŀռ���������
	int capacity;
}AddressBook;

extern void save(AddressBook* addressbook);
extern void load(AddressBook* addressbook);


void init(AddressBook* addressbook) {
	/*memset(addressbook->persons, 0, sizeof(addressbook->persons));
	addressbook->size = 0;*/
	//��ʽ�����ڴ�ռ�
	addressbook->size = 0;
	addressbook->capacity = 200;
	addressbook->persons = (PersonInfo*)malloc
	(addressbook->capacity * sizeof(PersonInfo));
	//�������malloc��ʼ�� ��vs debugģʽ�»�����������
	//memset(addressbook->persons, 0, sizeof(PersonInfo) * addressbook->capacity);
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

	if (addressbook->size >= addressbook->capacity) {
		//printf("����ʧ��,��ϵ������\n");
		//��������
		addressbook->capacity += 100;
		//���������ڴ�ռ�
		//ֱ��ʹ��relloc�Ƚϼ򵥷���
		/*addressbook->persons = realloc(addressbook->persons,
			addressbook->capacity * sizeof(PersonInfo));*/
		
		//Ҳ������malloc�ֶ�ģ��realloc �Ĺ���
		PersonInfo* old = addressbook->persons;
		addressbook->persons = (PersonInfo*)malloc(
			addressbook->capacity * sizeof(PersonInfo));
		//�Ѿɵ��ڴ�ռ�����ݿ������µĿռ���
		memcpy(addressbook->persons, old,
			sizeof(PersonInfo) * addressbook->size);
		//�ͷžɵĿռ�
		free(old);
		
	}
	//����������ϵ����Ϣ,�ŵ��±�sizeλ����
	PersonInfo*  p = &addressbook->persons[addressbook->size];
	printf("����������ϵ�˵�����: \n");
	scanf("%s", p->name);
	printf("����������ϵ�˵绰: \n");
	scanf("%s",p->phone);
	addressbook->size++;

	//�������ݵ�����
	save(addressbook);

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
	//ɾ���м�Ԫ�� ������Ԫ�ؿ�����ȥ��ɾ���һ��
	addressbook->persons[id] = 
		addressbook->persons[addressbook->size - 1];
	addressbook->size--;

	save(addressbook);
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
		//�û�����Ĳ���*
		strcpy(p->name, name);
	}
	printf("�������µ���ϵ�˵绰");
	char phone[1024] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0) {
		strcpy(p->phone, phone);
	}

	save(addressbook);
	printf("\n�޸���ϵ�����\n\n");
}

//void quit(AddressBook* addressbook) {
//	//������ǰ����
//	exit(0);
//}

typedef void(*Func)(AddressBook*);

//����һ�麯�� ���浽�ļ��Լ����ļ��м�������

void save(AddressBook* addressbook) {
	//��ͨѶ¼�е����ݱ��浽�ļ���
	//1.���ļ�
	FILE* f=fopen("d:/AddressBook.txt", "w");
	if (f == NULL) {
		perror("�ļ���ʧ��");
		return;
	}
	//2.д������
	/*for (int i = 0; i < addressbook->size; i++) {
		PersonInfo* p = &addressbook->persons[i];
		fwrite(p, sizeof(PersonInfo), 1, f);
	}*/
	fwrite(addressbook->persons,
		sizeof(PersonInfo), addressbook->size, f);
	//3.�ر��ļ�
	fclose(f);

}

void load(AddressBook* addressbook) {
	//���ļ��м���ͨѶ¼������
	//1.���ļ�
	FILE* f = fopen("d:/AddressBook.txt", "r");
	if (f == NULL) {
		printf("��ǰ�ļ���δ����!\n");
		return;
	}
	//2.��ȡ����,�����ѭ��,��ʱ��������
	while (1) {
		PersonInfo personInfo = { 0 };
		size_t len = fread(&personInfo, sizeof(PersonInfo), 1, f);
		if (len == 0) {
			printf("��ȡ���\n");
			break;
		}
		//��personInfo��������ӵ��ṹ������ȥ
		if (addressbook->size >= addressbook->capacity) {
			//������,����������
			PersonInfo* old = addressbook->persons;
			addressbook->capacity += 100;
			addressbook->persons = (PersonInfo*)malloc
			(addressbook->capacity * sizeof(PersonInfo));
			memcpy(addressbook->persons, old, addressbook->size * sizeof(PersonInfo));
			free(old);

		}
		//��ֵ����
		addressbook->persons[addressbook->size] = personInfo;
		addressbook->size++;
	}
	fclose(f);
}

AddressBook addressbook;

int main() {
	//����mian�����д�������ṹ�����
	//�������ṹ��������г�ʼ��
	init(&addressbook);

	//����һ�����ļ��������ݵ��߼�
	load(&addressbook);

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