### day4 友元函数、友元类  

>  友元函数
>
> 友元类 : 通过类成员，访问A类的私有数据成员

```
#include <iostream>
using namespace std;

class A
{
public:
	friend class B;//B类是A的好朋友 ，在B中可以访问A类的私有成员、私有函数

	//声明的位置和public private 没有关系
	friend void modifA(A *pA, int _a); //函数modifyA 是 类A的好朋友

	A(int a= 0,int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	int getA()
	{
		return this->a;
	}
private:
	int a;
	int b;
};

class B
{
public:
	void Set(int a)
	{
		Aobject.a = a;

	}
	void printB()
	{
		cout<<Aobject.a<<endl;
	}
private:
	A Aobject;
};


void modifA(A *pA, int _a)
{
	//pA->a = 100;
	pA->a = _a;
}

//为什么设计友元类函数
void main()
{
	B b1;
	b1.Set(300);
	b1.printB();
	system("pause");
}
void main021()
{
	A a1(1,2);

	cout<<a1.getA()<<endl;
	modifA(&a1, 300);
	cout<<a1.getA()<<endl;

	cout<<"hello wordl"<<endl;
	system("pause");
}
```

> 

