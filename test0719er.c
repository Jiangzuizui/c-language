#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main() {
	//��������
	//int a[4] = { 1,2,3,4 };

	//printf("%d\n", sizeof(a)); //16
	//printf("%d\n", sizeof(a+0));//4(һ��ָ��int*)
	//printf("%d\n", sizeof(*a));//4 *a int
	//printf("%d\n", sizeof(a+1)); //4 int*
	//printf("%d\n", sizeof(a[1])); //4 a[1]=>int
	//printf("%d\n", sizeof(&a)); //4 ����ָ�� int(*)[4]
	//printf("%d\n", sizeof(*&a));//16 &a=>int(*)[4] *=>int[4]
	//printf("%d\n", sizeof(&*a));//4 *a=>int &=>int*
	//printf("%d\n", sizeof(&a+1));//4 ����ָ��+1����һ�����黹������ָ��
	//printf("%d\n", sizeof(&a[0]+1));//4 a[0]=>int &=>int* +1=>int*

	//�ַ�����
	//char a[] = { 'a','b','c','d','e','f' };
	//printf("%d\n", sizeof(a));//6 ��6��char
	//printf("%d\n", sizeof(a+0));//4  char*
	//printf("%d\n", sizeof(*a));//1 char*������=>char
	//printf("%d\n", sizeof(a[1]));//1 �õ�b����ַ� char
	//printf("%d\n", sizeof(&a));//4 ����ָ��char(*)[6]
	//printf("%d\n", sizeof(&a+1));//4 char(*)[6]
	//printf("%d\n", sizeof(&a[0]+1));//4 a[0]=>char &=>char* +1=>char*
	//printf("%d\n", sizeof(*&a));//6 &a=>char(*)[6] *=>char[6]
	//printf("%d\n", sizeof(&*a));//4 *a=>char &=>char*
	
	//ֻҪ��ǰ �ַ����� �����ַ���,�Ͳ���ʹ��strϵ�к���
	//printf("%d\n", strlen(a));//δ����
	//printf("%d\n", strlen(a+0));//δ����
	//printf("%d\n", strlen(*a));//δ���� *a=>char,strҪ��Ĳ�����const char* 
	//printf("%d\n", strlen(a[1]));//δ���� ͬ��
	//printf("%d\n", strlen(&a));//δ���� &a=>char(*)[6]����ָ��,strҪ��Ĳ�����const char*,
	//// ���������ͱ�����ƥ��,c++�б��벻��,c�оͻ���������ָ��ת��char* �൱��'a'�ĵ�ַ
	//printf("%d\n", strlen(&a+1));//δ���� +1����һ������ָ��,ָ������ĩβ �Ҳ���\0
	//printf("%d\n", strlen(&a[0]+1));//δ���� [0] char &=>char*��+1=>char*ָ��b �����һ����Ҳ���\0

	//�ַ���
	//char a[] = "abcdef";
	//printf("%d\n", sizeof(a));//7 ��\0
	//printf("%d\n", sizeof(a+0));//4 char*
	//printf("%d\n", sizeof(*a));//1 char
	//printf("%d\n", sizeof(a[1]));//1 char
	//printf("%d\n", sizeof(a[1]+1));//4 a[1]=>char 'b' ��+1char��int���м���,������������int
	//printf("%d\n", sizeof(a[1])+1);//2 sizeof(char)=>1��+1=>2
	//printf("%d\n", sizeof(&a));//4 ����ָ��char(*)[7]
	//printf("%d\n", sizeof(&a+1));//4 ����ָ��+1��������ָ��
	//printf("%d\n", sizeof(&a[0]+1));//4 a[0]=>char &=>char* ��+1char*
	//printf("%d\n", sizeof(*&a));//7 &a=>char(*)[7] *=>char[7]
	//printf("%d\n", sizeof(&*a));//4 *a=>char &=>char*
	//printf("%d\n", sizeof(*&a+1));//4 *&a=>���� ����+1=>ָ��
	//printf("%d\n", sizeof(*&(a+1));//���벻�� a+1������ʽ������ֵ(û���ڴ��ϴ����ռ�),����&

	//printf("%d\n", strlen(a));//6 ����\0
	//printf("%d\n", strlen(a+0));//6 ��'a'���λ�ÿ�ʼ��\0 ��6��
	//printf("%d\n", strlen(*a));//δ���� *a=>char ��str��������const char*��ƥ��
	//printf("%d\n", strlen(a[1]));//δ���� ȡ��'b' ͬ��
	//printf("%d\n", strlen(&a));//6 �����Ͻ����벻ͨ�� &a=>char(*)[7] ��str��������const char*��ƥ��,
	////�˴���c�лᴥ����ʽ����ת��,��ֵַ����,�൱�ڴ�'a'��ʼ��\0,��6��
	//printf("%d\n", strlen(&a+1));//δ���� ����ָ��+1����һ������ �Ѿ�����\0 �Ҳ���\0��
	//printf("%d\n", strlen(&a[0]+1));//5 &a[0]=>ָ��'a'��char*  ��+1=>ָ��'b'��char* 5���ҵ�\0

	
	//char* p = "abcdef";
	//printf("%d\n", sizeof(p));//4 char*
	//printf("%d\n", sizeof(p+1));//4 char*
	//printf("%d\n", sizeof(*p));//1 char
	//printf("%d\n", sizeof(p[0]));//1 char
	//printf("%d\n", sizeof(&p));//4 char**
	//printf("%d\n", sizeof(&p+1));//4 char**
	//printf("%d\n", sizeof(&p[0]+1));//4 p[0]=>char *=>char* ��+1=>char*
	//
	//printf("%d\n", strlen(p));//6
	//printf("%d\n", strlen(p+1));//5 ָ��'b'
	//printf("%d\n", strlen(*p));//δ���� *p=>char��strlen���Ͳ�ƥ��
	//printf("%d\n", strlen(&p));//δ���� &p=>char**��strlen���Ͳ�ƥ��
	//printf("%d\n", strlen(&p+1));//δ���� ͬ��
	//printf("%d\n", strlen(&p[0]+1));//5 ָ��'b'��char*

	//��ά����
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48 3*4*4
	printf("%d\n", sizeof(a[0][0]));//4 int
	printf("%d\n", sizeof(a[0]));//16 a[0]=>int[4]
	printf("%d\n", sizeof(a[0]+1));//4 int[4]+1=>int*
	printf("%d\n", sizeof( *(a[0]+1) ));//4 ����һ��int*������=>int
	printf("%d\n", sizeof(a+1));//4 a��int[3][4],+1�ͻ���ʽת����ָ��,int(*)[4]����ָ��
	printf("%d\n", sizeof( *(a+1) ));//16 ����һ��������=>int[4] �����Ϊ*(a+1)=>a[1]=>int[4]
	printf("%d\n", sizeof(&a[0]+1));//4 a[0]=>int[4] &=>int(*)[4] +1=>int(*)[4]
	printf("%d\n", sizeof(* (&a[0]+1) ));//16 ����һ��*=>int[4]
	printf("%d\n", sizeof(*a));//16 *a=>a[0] int[4]
	printf("%d\n", sizeof(a[3]));//16 ������a[3]Խ���� ��ʵ���� ��Ϊsizeof�Ǳ�������ֵ int[4]


	system("pause");
	return 0;
}