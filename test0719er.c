#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main() {
	//整型数组
	//int a[4] = { 1,2,3,4 };

	//printf("%d\n", sizeof(a)); //16
	//printf("%d\n", sizeof(a+0));//4(一个指针int*)
	//printf("%d\n", sizeof(*a));//4 *a int
	//printf("%d\n", sizeof(a+1)); //4 int*
	//printf("%d\n", sizeof(a[1])); //4 a[1]=>int
	//printf("%d\n", sizeof(&a)); //4 数组指针 int(*)[4]
	//printf("%d\n", sizeof(*&a));//16 &a=>int(*)[4] *=>int[4]
	//printf("%d\n", sizeof(&*a));//4 *a=>int &=>int*
	//printf("%d\n", sizeof(&a+1));//4 数组指针+1跳过一个数组还是数组指针
	//printf("%d\n", sizeof(&a[0]+1));//4 a[0]=>int &=>int* +1=>int*

	//字符数组
	//char a[] = { 'a','b','c','d','e','f' };
	//printf("%d\n", sizeof(a));//6 有6个char
	//printf("%d\n", sizeof(a+0));//4  char*
	//printf("%d\n", sizeof(*a));//1 char*解引用=>char
	//printf("%d\n", sizeof(a[1]));//1 得到b这个字符 char
	//printf("%d\n", sizeof(&a));//4 数组指针char(*)[6]
	//printf("%d\n", sizeof(&a+1));//4 char(*)[6]
	//printf("%d\n", sizeof(&a[0]+1));//4 a[0]=>char &=>char* +1=>char*
	//printf("%d\n", sizeof(*&a));//6 &a=>char(*)[6] *=>char[6]
	//printf("%d\n", sizeof(&*a));//4 *a=>char &=>char*
	
	//只要当前 字符数组 不是字符串,就不能使用str系列函数
	//printf("%d\n", strlen(a));//未定义
	//printf("%d\n", strlen(a+0));//未定义
	//printf("%d\n", strlen(*a));//未定义 *a=>char,str要求的参数是const char* 
	//printf("%d\n", strlen(a[1]));//未定义 同上
	//printf("%d\n", strlen(&a));//未定义 &a=>char(*)[6]数组指针,str要求的参数是const char*,
	//// 这两个类型本来不匹配,c++中编译不了,c中就会把这个数组指针转成char* 相当于'a'的地址
	//printf("%d\n", strlen(&a+1));//未定义 +1跳过一个数组指针,指向数组末尾 找不到\0
	//printf("%d\n", strlen(&a[0]+1));//未定义 [0] char &=>char*再+1=>char*指向b 往后找还是找不到\0

	//字符串
	//char a[] = "abcdef";
	//printf("%d\n", sizeof(a));//7 加\0
	//printf("%d\n", sizeof(a+0));//4 char*
	//printf("%d\n", sizeof(*a));//1 char
	//printf("%d\n", sizeof(a[1]));//1 char
	//printf("%d\n", sizeof(a[1]+1));//4 a[1]=>char 'b' 再+1char和int进行计算,整型提升还是int
	//printf("%d\n", sizeof(a[1])+1);//2 sizeof(char)=>1再+1=>2
	//printf("%d\n", sizeof(&a));//4 数组指针char(*)[7]
	//printf("%d\n", sizeof(&a+1));//4 数组指针+1还是数组指针
	//printf("%d\n", sizeof(&a[0]+1));//4 a[0]=>char &=>char* 再+1char*
	//printf("%d\n", sizeof(*&a));//7 &a=>char(*)[7] *=>char[7]
	//printf("%d\n", sizeof(&*a));//4 *a=>char &=>char*
	//printf("%d\n", sizeof(*&a+1));//4 *&a=>数组 数组+1=>指针
	//printf("%d\n", sizeof(*&(a+1));//编译不了 a+1这个表达式不是左值(没在内存上创建空间),不能&

	//printf("%d\n", strlen(a));//6 不算\0
	//printf("%d\n", strlen(a+0));//6 从'a'这个位置开始找\0 找6步
	//printf("%d\n", strlen(*a));//未定义 *a=>char 与str参数类型const char*不匹配
	//printf("%d\n", strlen(a[1]));//未定义 取到'b' 同上
	//printf("%d\n", strlen(&a));//6 理论上讲编译不通过 &a=>char(*)[7] 与str参数类型const char*不匹配,
	////此处在c中会触发隐式类型转换,地址值不变,相当于从'a'开始找\0,找6步
	//printf("%d\n", strlen(&a+1));//未定义 数组指针+1跳过一个数组 已经跳过\0 找不到\0了
	//printf("%d\n", strlen(&a[0]+1));//5 &a[0]=>指向'a'的char*  再+1=>指向'b'的char* 5步找到\0

	
	//char* p = "abcdef";
	//printf("%d\n", sizeof(p));//4 char*
	//printf("%d\n", sizeof(p+1));//4 char*
	//printf("%d\n", sizeof(*p));//1 char
	//printf("%d\n", sizeof(p[0]));//1 char
	//printf("%d\n", sizeof(&p));//4 char**
	//printf("%d\n", sizeof(&p+1));//4 char**
	//printf("%d\n", sizeof(&p[0]+1));//4 p[0]=>char *=>char* 再+1=>char*
	//
	//printf("%d\n", strlen(p));//6
	//printf("%d\n", strlen(p+1));//5 指向'b'
	//printf("%d\n", strlen(*p));//未定义 *p=>char与strlen类型不匹配
	//printf("%d\n", strlen(&p));//未定义 &p=>char**与strlen类型不匹配
	//printf("%d\n", strlen(&p+1));//未定义 同上
	//printf("%d\n", strlen(&p[0]+1));//5 指向'b'的char*

	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48 3*4*4
	printf("%d\n", sizeof(a[0][0]));//4 int
	printf("%d\n", sizeof(a[0]));//16 a[0]=>int[4]
	printf("%d\n", sizeof(a[0]+1));//4 int[4]+1=>int*
	printf("%d\n", sizeof( *(a[0]+1) ));//4 对上一个int*解引用=>int
	printf("%d\n", sizeof(a+1));//4 a是int[3][4],+1就会隐式转换成指针,int(*)[4]数组指针
	printf("%d\n", sizeof( *(a+1) ));//16 对上一个解引用=>int[4] 或理解为*(a+1)=>a[1]=>int[4]
	printf("%d\n", sizeof(&a[0]+1));//4 a[0]=>int[4] &=>int(*)[4] +1=>int(*)[4]
	printf("%d\n", sizeof(* (&a[0]+1) ));//16 对上一个*=>int[4]
	printf("%d\n", sizeof(*a));//16 *a=>a[0] int[4]
	printf("%d\n", sizeof(a[3]));//16 看起来a[3]越界了 其实不是 因为sizeof是编译期求值 int[4]


	system("pause");
	return 0;
}