#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

//C99中，结构体 中 最后一个元素允许是未知大小的数组，这就叫做 柔性数组 成员。

// 语法形式：

// 写法1：
//typedef struct st_type
//{
//	int i;
//	int arr[];// 柔性数组成员
//}type_a;

// 写法2： 这个写法在某些编译器会报错
//{
//	int i;
//	int arr[0];// 柔性数组成员
//}type_a;
//

//柔性数组的特点：
// 结构体中的柔性数组成员前面必须至少有一个其他成员
// sizeof返回的这种结构体的大小不包括柔性数组的内存
// 包含柔性数组的结构体在创建变量时，不要使用struct type_a s 创建结构体变量
// 应该使用malloc() 函数
// 包含柔性数组成员的结构体用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构体的大小，以适应柔性数组的预期大小。
// 根据所需要空间的大小，行可以通过realloc() 函数来改变空间大小
// 柔性数组在一个结构体中最多只有一个
//int main()
//{
//	printf("%d\n", sizeof(type_a));//4
//
//	// 柔性数组的使用：
//	type_a* ptr1=(type_a*)malloc(sizeof(type_a) + 40);//前4个字节给 i ,剩下的后40个字节给柔性数组arr
//	if (ptr1 != NULL)
//	{
//		type_a* ps = ptr1;
//		ps->i = 100;
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			ps->arr[i] = i;
//		}
//		printf("%d\n", ps->i);
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d\n", ps->arr[i]);
//		}
//		type_a*ptr2=(type_a*)realloc(ps, sizeof(type_a) + 80);
//		if (ptr2 != NULL)
//		{
//			ps = ptr2;
//		}
//		free(ps);//释放ps指向的空间，由于ptr1、ptr2和ps指向的是同一块空间，所以只需要释放ps指向的空间就可以了
//		ps = NULL;
//	}
//	return 0;
//}
//柔性数组的好处：
// 1.方便内存的释放
// 2.有利于访问速度