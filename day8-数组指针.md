### day8数组指针

#### 数组指针

```
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//数组类型基本语法知识梳理
//定义一个数组类型
//int a[10];

//定义一个指针数组类性

//定义一个指向 数组类性的指针  数组类的指针

void main01()
{


	int a[10]; //a代表的是数组首元素的地址  &a代表真个数组的地址  a+1 4 &a+1 步长40

	{
		//定义一个数组类性
		typedef int (myTypeArray)[10];
		myTypeArray myArray;
		myArray[0] = 10;
		printf("%d \n",myArray[0]);

	} 

	{

		//定义一个指针数组类型
		typedef int (*PTypArray)[10]; //int *p

		PTypArray myPArray;//sizeof(int) *10

		myPArray = &a;

		//int b = 10;
		//int *p = NULL;

		//p = &b;
		(*myPArray)[0] = 20;

		printf("a[0]: %d \n",a[0]);

	}

	{
		//定义一个指向 数组类性的指针  数组类的指针

		int (*MyPointer)[10]; //变量 告诉C编译器 给我分配内存
		MyPointer = &a;
		(*MyPointer)[0] = 40;
		printf("a[0]: %d \n",a[0]);
	}

	system("pause");
	return ;
}

//函数指针基本语法
//1.定义一个函数类型
//2.定义一个函数指针类型
//3.定义一个函数指针 （指向一个函数的入口地址）


int add(int a, int b)
{
	printf("func add ... \n");
	return a+b;
}
void main()
{
	add(1,2); //直接调用 //函数名就是函数的入口地址

	//定义一个函数类型
	{
		typedef int (MyFuncType) (int a,int b);//定义了一个类型
		MyFuncType *myPointerFunc = NULL;//定义了一个指针，执行某一种类的函数

		myPointerFunc = &add;//细节
		myPointerFunc(3,4);//间接调用


		myPointerFunc = add;//细节加不加&都可以通过  //C是过程 是逐渐完善的  兼容历史版本的原因
		myPointerFunc(3,4);//间接调用
	}

	//定义一个函数指针类型
	{
		typedef int (*MyPointerFuncType)(int a,int b); //int * a = NULL;
		MyPointerFuncType myPonterFunc; //定义一个指针

		myPonterFunc = add;
		myPonterFunc(5,6);

	}


	//函数指针
	{
		int (*MyPointerFunc)(int a,int b);//定义了一个变量
		MyPointerFunc = add;
		MyPointerFunc(7,8);

	}

	system("pause");
}
```

#### 函数指针做函数参数的思想剖析

```
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int myadd(int a,int b)  //子任务的实现者
{
	printf("func add() do... \n");
	return a+ b;
}
int myadd2(int a,int b)  //子任务的实现者
{
	printf("func add()2 do... \n");
	return a+ b;
}
int myadd3(int a,int b)  //子任务的实现者
{
	printf("func add()3 do... \n");
	return a+ b;
}

//定义了一个类型
typedef int (*MyTypeFuncAdd)(int a,int b);

//函数指针类型起到的作用：
	//把函数的参数、函数返回值提前约定

//函数指针 做  函数参数
int MainOp(MyTypeFuncAdd myFuncAdd)
{
	int c = myFuncAdd(5,6);
	return c;
}


//int(*MyPointerFuncAdd) (int a,int b)
int MainOp2(int(*MyPointerFuncAdd) (int a,int b))
{
	int c = MyPointerFuncAdd(5,6);  //间接调用
	return c;
}


//间接调用

//任务的调用 和 任务的编写可以分开
void main()
{
	MyTypeFuncAdd myFuncAdd = NULL;
	//myadd(1,2); //直接调用


	myFuncAdd = myadd;
	myFuncAdd(3,4);//间接调用

	//MainOp2(myadd);
	MainOp(myadd);
	
	MainOp(myadd2);
	MainOp(myadd3);


	system("pause");
	return ;
}
```

#### 函数指针的正向调用

留坑