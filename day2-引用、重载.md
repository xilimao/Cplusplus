### C++day2	

> 当使用引用语法的时候，不去关心编译器饮用时怎么做的
>
> 当分析奇怪的语法现象时的时候，采取考虑C++编译器是怎么做的

##### 指针的引用

```
#include <iostream>
using namespace std;


struct Teacher
{
	char name[64];
	int age;
};
//释放指针指向的内存空间
int FreeTeacher(Teacher *pT1)
{
	if (pT1 == NULL)
	{
		return -1;
	}
	free(pT1);
}


//在被调用的函数即该函数分配空间，然后让传进来的参数 即*pT1获取tmp资源
int getTeacher(Teacher **p)//**p 二级指针，是指向指针地址的指针
{
	Teacher *tmp =NULL;

	if (p == NULL)//这里指如果&pT1 == null
	{	
		return -1;
	}

	tmp = (Teacher *)malloc(sizeof(Teacher));
	//void* malloc (int size) 向系统申请分配指定size个字节的内存空间。
	//返回类型是void*，void*可以强制转换为其余类型的指针。
	//malloc必须由我们计算字节数，并且在返回后强行转换为实际类型的指针。
	//int *p；
	//p=(int *)malloc(sizeof(int));

	if (tmp == NULL)
	{
		return -2;
	}
	
	tmp->age= 33;

	//p是实参的地址 *实参的地址  去间接的修改实参的值
	//*p指的是传入的指针的地址（即 pT1），另其=tmp,即pT1 = tmp;
	*p = tmp;
}

//指针的引用，相当于C的二级指针
//指针的引用做函数参数
int getTeacher2(Teacher * &myp)
{
	//给myp赋值相当于给main函数中的pT1赋值
	myp = (Teacher *)malloc(sizeof(Teacher));
	if (myp == NULL)
	{
		return -1;
	}
	myp->age = 36;

}


void main()
{
	Teacher *pT1 = NULL;

	//1.C语言中的二级指针
	//	传入的是该指针的地址
	getTeacher(&pT1);

	cout<<"age: "<<pT1->age<<endl;
	
	FreeTeacher(pT1);


	//2.C++中的引用（指针的引用）
	//引用的本质 间接赋值后的两个条件，让C++编译器帮我们做了
	getTeacher2(pT1);

	cout<<"age: "<<pT1->age<<endl;

	FreeTeacher(pT1);

	cout << "hello  " << endl;
	system("pause");
}
```

#### 常量引用

##### 常引用的初始化

- 用变量初始化常引用

  ```
  int x = 20;
  const int &y = x;//常引用 让变量拥用只读属性，不能通过y去修改x
  ```

- 用字面量去初始化常引用

  ```
  const int a = 40;	//C++编译器把a放在符号表中
  int &m = 41;		//普通引用引用一个字面量
  //报错，因为41没有内存，
  //引用就是给内存起别名
  const int &m = 43;	//可以通过，C++编译器会单独分配内存空间给m，内存里是43
  ```



### C++对C的函数拓展

1. #### inline内联函数

   > 用内联函数来替代宏代码片段

   ```
   inline void printA(){
     int a = 10;
     cout<<"a: "<<a<<endl;
   }
   ```

   > 内联函数和函数体的实现写在一块，不能去声明
   >
   > **直接将函数体插入在函数调入的地方**
   >
   > inline只是一种请求，编译器不一定允许 	 
   >
   > 没有普通函数的额外开销（压栈入栈跳转和返回的开销）
   >
   > 不能有任何形式的循环语句、不能有过多的条件判断

   #### 宏片段

   ```
   //带参数的宏
   #define MYFUNC(a,b) ((a)<(b) ? (a):(b))

   int c = MYFUNC(++a,b);
   //宏替换并展开((++a)<(b) ? (++a):(b)) //a=3,b=3,c=3
   ```

2. #### 参数

   1. #### 函数占位参数

      > 函数调用时必须写够参数

      ```
      void fun(int a,int b,int ){}
      fun(1,2); //这样不行
      fun(1,2,3);
      ```
   2. #### 默认函数参数

      > 若填写了默认参数，使用填写的，如果不填写就用默       认的如果有默认参数，默认参数必须位于最后
   3. 默认参数and占位参数

3. ### 函数重载（Overroad）

   > 函数名字相同，但是参数的个数或者类型或者顺序不同
   >
   > 函数的返回值不是重载的判断标准

   #### 调用重载的准则

   本质上是 相互独立的不同函数（静态链编）

   ##### 函数默认参数 和 函数重载 在一起

   > 函数调用时会产生二义性

   ```
   void fun(int a,int b,int c = 0)
   void fun(int a,int b)

   fun(1,2);//会产生二义性，不知道调用哪一个
   ```

   #### 函数重载 and 函数指针

   - 函数指针基础的语法:

     ```
     //1.声明一个函数的类型
     typedef void (myTypeFunc)(int a,int b);//int

     //myTypeFunc *myfuncp = NULL; //定义一个函数指针，这个指针指向函数的入口地址

     //2.声明一个函数指针类型
     typedef void (*myPTypeFunc)(int a,int b);//声明了一个指针的数据类型
     //myPTypeFunc fp = NULL;//通过  函数指针类型 定义了一个函数指针

     //3.定义一个函数指针  变量
     void (*myVarPFunc)(int a,int b);
     ```


     void main()
     {
     	myTypeFunc *myfuncp = NULL;  //定义一个函数指针，这个指针指向函数的入口地址
     	
     	myPTypeFunc fp = NULL;//通过函数指针类型 定义了一个函数指针


     }
     ```
    
     ​

## 视角

跳进来  看编译器是如何实现的

跳出去  当做工具

##  具体的

1. 一个对象的生命周期
2. 两个对象的生命周期
   1. 类和类之间的关系
3. n个对象的生命周期
   1. 一族对象
4. C++面向编程思想
   1. 面向抽象类编程（面向借口/软件分层）