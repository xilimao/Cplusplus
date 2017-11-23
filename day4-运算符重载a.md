### dya4 运算符重载

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

