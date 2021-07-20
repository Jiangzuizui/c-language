#include<stdio.h>
#include<stdlib.h>
#include<string.h>

////p的类型是struct Test*
//
//struct Test {
//	int Num;
//	char* pname;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;

//n表示打印多少行
void printYanghui(int n) {
	int arr[100][100] = { 0 };
	for (int row = 0; row < n; row++) {
		if (row == 0) {
			arr[0][0] = 1;
			continue;
		}
		if (row == 1) {
			arr[1][0] = 1;
			arr[1][1] = 1;
			continue;
		}
		for (int col = 0; col <= row; col++) {
			if (col == 0 || col == row) {
				arr[row][col] = 1;
			}
			else {
				arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];

			}
		}
	}
	for (int row = 0; row < n; row++) {
		for (int col = 0; col <= row; col++) {
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}
}

//size_t strlen(const char* str) {
//	size_t size = 0;
//	while (str[size] != '\0') {
//		size++;
//	}
//	return size;
//}



int main() {
	


	/*int a[] = { 2,4,6,8,10,12,14,16,18,20,22,24 }, * q[4], k;
	for (k = 0; k < 4; k++) {
		q[k] = &a[k * 3];
	} 
	
	printf("%d\n", q[3][1]);*/
	//printf("%d\n", strlen("abcd"));

	//printYanghui(5);

	//printf("%p\n", p + 0x1);//00000014
	//printf("%p\n", (unsigned long)p + 0x1);//00000001
	//printf("%p\n", (unsigned int*)p + 0x1);//00000004

	//char* a[] = { "work","at","alibaba" };
	//char** pa = a;
	//pa++;
	//printf("%s\n", *pa);//at


	//int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	////&aa=>int(*)[2][5]
	//int* p1 = (int*)(&aa + 1);
	////aa+1=>int(*)[5]
	////*(aa+1)相当于aa[1]=>{6,7,8,9,10}
	////接下来的赋值就是把这个一维数组的首元素6的地址取出来赋给p2
	//int* p2 = (int*)(*(aa + 1));
	//printf("%d %d", (p1 - 1), *(p2 - 1));//10 5

	//int a[5][5] = { 0 };
	//int(*p)[4];
	//p = a;
	//printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//fffffffc  -4

	//int a[3][2] = { (0,1),(2,3),(4,5) };
	//int* p;
	//p = a[0];
	//printf("%d\n", p[0]);//1 a[0][0]是1

	//int a[] = { 1,2,3,4 };
	//int* ptr1 = (int*)(&a + 1);
	//int* ptr2 = (int*)((int)a + 1);
	//printf("%x,%x", ptr1[-1], *ptr2);//4 和 20 00 00 00

	

	//int a[] = { 1,2,3,4,5 };
	//int* p = (int*)(&a + 1);//指向5后面的int*
	//printf("%d %d\n", *(a + 1), *(p - 1));//2 5




	system("pause");
	return 0;
}