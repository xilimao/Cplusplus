### dya4 运算符重载

> **全局函数、类成员函数方法实现运算符重载3个步骤**
> **1.要承认操作符重载是一个函数，写出函数名称**
> **2.根据操作数，写出参数函数**
> **3.根据业务，完善函数返回值（看函数是返回引用 还是指针 元素），及实现函数业务**


> 运算符重载使得用户自定义的数据以一种更简洁的方式工作

```
#include <iostream>
using namespace std;

class Complex
{
public:
	int a;
	int b;
public:
	Complex(int a= 0, int b= 0)
	{
		this->a = a;
		this->b = b;
	
	}
	void printCom()
	{
		cout<<a<<" + "<<b<<" i "<<endl;
	}
};

//1.定义了全局函数
Complex myAdd(Complex &c1,Complex &c2)
{
	Complex tmp(c1.a + c2.a , c1.b + c2.b);
	return tmp;
}
//2. 对函数名进行升级 
Complex operator+(Complex &c1,Complex &c2)
{
	cout<<"12345  上山打老虎"<<endl;
	Complex tmp(c1.a + c2.a , c1.b + c2.b);
	return tmp;
}


void main()
{
	int a = 0,b = 0;
	int c;
	c = a + b; //1. 基础性数据类型 编译器已经知道了如何运算
	
	//a + bi 复数运算规则
	Complex c1(1,2),c2(3,4);
	
	Complex c3; //2. 类 也是一种数据类型  用户自定义数据类型 C++
				//   编译器 是不知道如何进行运算 
	

	//3. C++编译器应该给我们程序员提供一种机制
	//   让自定义数据类型，有机会进行运算符操作 ==>运算符重载机制

	//4 运算符重载机制


	//步骤1
	Complex c4 = myAdd(c1 ,c2);
	c4.printCom();
	
	//步骤2
	Complex c4 = operator+(c1,c2);
	c4.printCom();

	//步骤3
	Complex c4 = c1 + c2;
	c4.printCom();
	
	//总结：1.运算符重载的本质 是 函数调用

	cout<<"hello wordl"<<endl; 
	system("pause");

}
```

#### 运算符重载两种方法

> 用  **成员** or  **友元**  函数重载运算符
>
> 传递参数的方式不同，实现代码不同，应用场合也不同



> 二元运算符
>
> ```
> #include <iostream>
> using namespace std;
>
> class Complex
> {
> private:
> 	int a;
> 	int b;
> 	//全局函数 重载 + 运算符
> 	friend Complex operator+(Complex &c1,Complex &c2);
> public:
> 	Complex(int a= 0, int b= 0)
> 	{
> 		this->a = a;
> 		this->b = b;
>
> 	}
> 	void printCom()
> 	{
> 		cout<<a<<" + "<<b<<" i "<<endl;
> 	}
>
> public:
> 	//成员函数法  实现 - 运算符重载
> 	Complex operator-(Complex &c2)
> 	{
> 		Complex tmp(this->a - c2.a ,this->b - c2.b);
> 		
> 		return tmp; 
> 	}
> };
>
> //全局函数法 实现 + 运算符重载
> Complex operator+(Complex &c1,Complex &c2)
> {
> 	Complex tmp(c1.a + c2.a ,c1.b + c2.b);
> 		
> 	return tmp; 
> }
> /*
> 	全局函数、类成员函数方法实现运算符重载步骤
> 	1.要承认操作符重载是一个函数，写出函数名称
> 	2.根据操作数，写出参数函数
> 	3.根据业务，完善函数返回值（看函数是返回引用 还是指针 元素），及实现函数业务
> */
>
>
> void main()
> {
> 	Complex c1(1,2),c2(3,4);
>
> 	//1 全局函数法 实现 + 运算符重载(用了友元函数，可以访问私有成员变量)
> 	// Complex operator+(Complex &c1,Complex &c2);
>
> 	Complex c3 = c1 + c2;
> 	c3.printCom();
>
> 	//2 成员函数法  实现- 运算符重载
> 	//  c1.operator-(c2);
> 	//  Complex operator-(Complex &c2);
> 	
> 	Complex c4 = c1 - c2;
> 	c4.printCom();
>
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
> }
> ```



> 一元运算符    


> ```
> #include <iostream>
> using namespace std;
>
> class Complex
> {
> private:
> 	int a;
> 	int b;
> 	//全局函数 重载 + 运算符
> 	friend Complex operator+(Complex &c1,Complex &c2);
> 	//全局函数 重载 前置++ 运算符
> 	friend Complex& operator++(Complex &c1);
> 	//全局函数 重载 后置++ 运算符
> 	friend Complex operator++(Complex &c1,int);
> public:
> 	Complex(int a= 0, int b= 0)
> 	{
> 		this->a = a;
> 		this->b = b;
>
> 	}
> 	void printCom()
> 	{
> 		cout<<a<<" + "<<b<<" i "<<endl;
> 	}
>
> public:
> 	//成员函数法  实现 - 运算符重载
> 	Complex operator-(Complex &c2)
> 	{
> 		Complex tmp(this->a - c2.a ,this->b - c2.b);
> 		
> 		return tmp; 
> 	}
> 	//前置--
> 	Complex& operator--()
> 	{
> 		this->a --;
> 		this->b --;
> 		return *this;
> 	}
> 	//后置--
> 	Complex operator--(int )
> 	{
> 		Complex tmp = *this;
> 		this->a--;
> 		this->b--;
> 		return tmp;
> 	}
> };
>
> //全局函数法 实现 + 运算符重载
> Complex operator+(Complex &c1,Complex &c2)
> {
> 	Complex tmp(c1.a + c2.a ,c1.b + c2.b);
> 		
> 	return tmp; 
> }
>
> //全局函数法 实现 前置++ 运算符重载
> Complex& operator++(Complex &c1)
> {
> 	c1.a++;
> 	c1.b++;
> 	return c1;
> }
> //全局函数法 实现 后置++ 运算符重载		占位符语法
> Complex operator++(Complex &c1,int)
> {	
> 	//后置++  先使用 再让c1++
> 	Complex tmp = c1;
>
> 	c1.a++;
> 	c1.b++;
> 	return tmp;
> }
>
>
> /*
> 	全局函数、类成员函数方法实现运算符重载步骤
> 	1.要承认操作符重载是一个函数，写出函数名称
> 	2.根据操作数，写出参数函数
> 	3.根据业务，完善函数返回值（看函数是返回引用 还是指针 元素），及实现函数业务
> */
>
>
> void main()
> {
> 	Complex c1(1,2),c2(3,4);
>
> 	//1 全局函数法 实现 + 运算符重载(用了友元函数，可以访问私有成员变量)
> 	// Complex operator+(Complex &c1,Complex &c2);
>
> 	Complex c3 = c1 + c2;
> 	c3.printCom();
>
> 	//2 成员函数法  实现- 运算符重载
> 	//  c1.operator-(c2);
> 	//  Complex operator-(Complex &c2);
> 	
> 	Complex c4 = c1 - c2;
> 	c4.printCom();
>
> 	//3.前置++操作符 用全局函数实现
> 	// ++c1;
> 	//Complex& operator++(Complex &c1);
> 	++c1;
> 	c1.printCom();
>
> 	//4.前置-- 操作符  用成员函数
> 	//c1.operator--();
> 	//Complex& operator--()
> 	--c1;
> 	c1.printCom();
>
>
> 	//5.后置++操作符  用全局函数
> 	//Complex operator++(Complex &c1,int)
> 	c1++;
> 	c1.printCom();
>
> 	//6.后置--操作符  用成员函数
> 	//c1.operator--
> 	//Complex operator--();
> 	c1--;
> 	c1.printCom();
> 	
>
>
>
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
> }
> ```


> 运算符重载正规的写法（<< 左移操作符）


> ```
> #include <iostream>
> using namespace std;
>
> class Complex
> {
> private:
> 	int a;
> 	int b;
>
> 	//friend void operator<<(ostream &out,Complex &c1);
> 	friend ostream& operator<<(ostream &out ,Complex &c1);
> public:
> 	Complex(int a= 0, int b= 0)
> 	{
> 		this->a = a;
> 		this->b = b;
>
> 	}
> 	void printCom()
> 	{
> 		cout<<a<<" + "<<b<<" i "<<endl;
> 	}
>
> public:
>
> };
>
>
> /*
> 全局函数、类成员函数方法实现运算符重载步骤
> 1.要承认操作符重载是一个函数，写出函数名称
> 2.根据操作数，写出参数函数
> 3.根据业务，完善函数返回值（看函数是返回引用 还是指针 元素），及实现函数业务
> */
>
>
> //void operator<<(ostream &out ,Complex &c1)
> //{
> //	out<<"1232323  生活真是苦"<<endl;
> //	out << c1.a << " + "<<c1.b<<" i "<<endl;
> //}
>
>
> ostream& operator<<(ostream &out ,Complex &c1)
> {
> 	out<<"1232323  生活真是苦"<<endl;
> 	out << c1.a << " + "<<c1.b<<" i "<<endl;
> 	return out;
> }
>
>
> void main()
> {
> 	int a = 10;
> 	Complex c1(1,2),c2(3,4);
> 	//cout<< a <<endl;//按照数据类型
>
> 	//1  cout.operator
> 	cout<<c1;
>
>
>
> 	//2 函数返回值当左值，需要一个引用
> 	//ostream 类中 添加成员函数  operator<<
> 	//只能通过友元函数来实现
>
> 	//cout.operator<<(c1).operator<<("adadadada");
> 	//void.operator<<("adsadsadsa");
>
>
> 	cout<<c1 << "dasdsadsa";
> 	
>
> 	//operator<<(ostream &cout ,Complex &c1);
>
> 	system("pause");
>
> }
> ```


> 重载等号(=)操作符
>
> 结论: 
>
> 1. 先把旧的内存释放
> 2. 返回一个引用 （返回引用才能连等）
> 3. = 号操作符 从右到左
> 4. 看下面代码


> ```
> #include <iostream>
> using namespace std;
>
> class Name
> {
> public:
> 	Name(const char*myp)
> 	{
> 		m_len = strlen(myp);
> 		m_p = (char *)malloc(m_len + 1);
> 		strcpy(m_p ,myp);
> 	}
>
> 	Name(const Name& obj1)
> 	{
> 		m_len = obj1.m_len;
> 		m_p = (char *)malloc(m_len + 1);
> 		strcpy(m_p, obj1.m_p);
> 	}
> 	~Name()
> 	{
> 		if (m_p != NULL)
> 		{
> 			free(m_p);
> 			m_p = NULL;
> 			m_len = 0;
> 		}
> 	}
> 	
> 	//obj3 = obj1; 
> 	//obj3.operator = (obj1)
> 	Name& operator=(Name &obj1)
> 	{
> 		//1.先把旧的内存释放
> 		if (this->m_p != NULL)
> 		{
> 			delete[] m_p;
> 			m_len = 0;
> 		}
> 		//2. 根据obj1分配内存大小
> 		this->m_len = obj1.m_len;
> 		this->m_p = new char [m_len + 1];
>
> 		//3.把obj1赋值
> 		strcpy(this->m_p,obj1.m_p); 
> 		return *this;
> 	}
>
> private:
> 	char *m_p;
> 	int m_len;
> };
>
> void objplaymain()
> {
> 	Name obj1("abcdefg");
>
> 	Name obj2 = obj1;
>
> 	Name obj3("obj3");
>
> 	obj3 = obj1; 
> 	//obj3.operator = (obj1)
> 	//operator=(Name &obj1); 
>
> 	obj1 = obj2 = obj3;
>
> 	//obj2.operator=(obj3);
> 	//obj1 = void; //不能返回void  需要返回引用
> }
> void main()
> {
> 	objplaymain();
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
> }
> ```
>
> 


> 数组类的优化（通过重载）


> MyArray.h
>
> ```
>
> #pragma once
>
> #include <iostream>
> using namespace std;
>
> class Array
> {
> public:
> 	Array(int lengtn);
> 	Array(const Array& obj);
> 	~Array();
>
> public:
> 	void setDate(int index,int valude);
> 	int getDate(int index);
> 	int lengtn();
>
> protected:
> private:
> 	int m_length;//数组长度
> 	int *m_space;//内存空间
>
>
> public:
> 	//重载[] = == !=
> 	int& operator[](int i);
> 	Array& operator=(Array &a1);
> 	bool operator==(Array &a1);
> 	bool operator!=(Array &a1);
>
>
> };
>
> //要求重载以下操作符
> // [] ==  !=
> ```


> MyArray.cpp
>
> ```
>
> #include "MyArray.h"
>
> //int m_length;   数组长度
> //int *m_space;  内存空间
> Array::Array(int lengtn)
> {
> 	if (lengtn < 0)
> 	{
> 		lengtn = 0;
> 	}
> 	m_length = lengtn;
> 	m_space = new int[m_length];//分配内存空间
> }
> //Array a2 = a1;
> Array::Array(const Array& obj)
> {
> 	this->m_length = obj.m_length;
> 	this->m_space = new int[this->m_length];//分配内存空间
>
> 	for (int i=0;i<m_length;i++)//数组元素复制
> 	{
> 		this->m_space[i] = obj.m_space[i];
> 	}
> }
> Array::~Array()
> {
> 	if (m_space != NULL)
> 	{
> 		delete[] m_space;
> 		m_length = 0;
> 	}
> }
>
> //a1.setDate(i,i);
> void Array::setDate(int index,int valude)
> {
> 	m_space[index] = valude;
> }
> int Array::getDate(int index)
> {
> 	return m_space[index];
> }
> int Array::lengtn()
> {
> 	return m_length;
> }
>
>
> //1.  a[i] 的值 
> //因为要当左值 应该返回一个引用（元素本身），而不是一个值
> int& Array::operator[](int i)
> {
> 	return m_space[i];
> }
>
> //3.重载=号操作符
> //a3 = a1;
> Array& Array::operator=(Array &a1)
> {
> 	//释放原来的内存空间
> 	if (this->m_space != NULL)
> 	{
> 		delete[] m_space;
> 		m_length = 0;
> 	}
> 	//根据a1大小分配内存
> 	m_length = a1.m_length;
> 	m_space = new int [m_length];
>
> 	//copy数据
> 	for (int i=0;i<m_length;i++)
> 	{
> 		m_space[i] = a1.m_space[i];
> 		//m_space[i] = a1[i];
> 	}
>
> 	return *this;
> }
>
> //重载 == 
> bool Array::operator==(Array &a1)
> {
>
> 	if (this->m_length != a1.m_length)
> 	{
> 		return false;
> 	} 
>
> 	for (int i = 0;i<m_length;i++)
> 	{
> 		if (this->m_space[i] != a1[i])
> 		{
> 			return false;
> 		}
> 	}
>
> 	return true;
> }
> //重载 != 
> bool Array::operator!=(Array &a1)
> {
> 	/*
> 	if (*this == a1)
> 	{
> 		return true;
> 	} 
> 	else
> 	{
> 		return false
> 	}
> 	*/
> 	return !(*this == a1);
> }
> ```


> TestArray.cpp
>
> ```
> #include <iostream>
> using namespace std;
> #include "MyArray.h"
>
>
> //类的框架设计完毕
> //类的测试案例
>
> //重载[]
> //void operator[](int i);
> //int  operator[](int i);
> //int& operator[](int i);
> void main()
> {
> 	Array a1(10);
> 	
> 	for (int i = 0; i<a1.lengtn(); i++)
> 	{
> 		a1.setDate(i,i);
> 		//2.函数返回值当左值,需要一个饮用
> 		a1[i] = i;
> 		//a1.operator [i]
> 		
> 	}
>
> 	cout<<"打印a1"<<endl;
> 	for (int i = 0; i<a1.lengtn(); i++)
> 	{
> 		cout<<a1.getDate(i)<<" ";
> 		//1.需要优化
>
> 		cout<<a1[i]<<endl;
>
>
> 	}
> 	cout<<endl;
>
>
>
> 	Array a2 = a1;
> 	cout<<"打印a2"<<endl;
>
> 	for (int i = 0; i<a2.lengtn(); i++)
> 	{
> 		a1.setDate(i,i);
> 	}
> 	for (int i = 0; i<a2.lengtn(); i++)
> 	{
> 		cout<<a1.getDate(i)<<" ";
> 	}
>
> 	cout<<endl;
>
> 	//3. 优化  =
> 	Array a3(5);
> 	
> 	{
> 		a3 = a1;
>
> 		a3 = a2 = a1;
>
> 		//a3.operator=(a1)
> 		//Array& operator=(Array &a1);
>
> 		cout<<"打印a3"<<endl;
> 		for (int i = 0; i<a2.lengtn(); i++)
> 		{
> 			cout<<a3[i]<<" ";
> 		}
> 	}
> 	
>
> 	//4.优化  ==   !=
> 	
> 	if (a3 == a1)
> 	{
> 		cout<<"相等"<<endl;
> 	}
> 	else
> 	{
> 		cout<<"不相等"<<endl;
> 	}
> 	
> 	if (a3 != a1)
> 	{
> 	cout<<"不相等"<<endl;
> 	} 
> 	else
> 	{
> 	cout<<"相等"<<endl;
> 	}
> 	
> 	//a3.operator==(a1)
> 	
> 	//bool operator==(Array &a1);
>
> 	//a3.operator!=(a1)
>
> 	//bool operator!=(Array &a1);
>
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
> 	return ;
> }
> ```


> #### 为什么不要重载 && 和 || 操作符
>
> 1. 内置短路规则
> 2. 操作符重载是靠函数重载完成的
> 3. 操作数作为函数参数传递
> 4. C++的函数参数都会被求值，无法实现短路规则


> ##### 重载 && || 他们 不会产生短路效果
>
> ```
> (t1 + t2) && t1
> ```
>
> ##### && 运算符重载的结合性
>
> - 两个逻辑与运算符 在一起的时候，才去谈 运算符的结合性
>
> - 从左到右 (t1 + t2) && t1 ; 运算结果 && t2
>
>   ```
>   (t1 + t2) && t1 && t2
>   ```
>
>   ​