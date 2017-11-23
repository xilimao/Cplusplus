### day3（构造和析构）

### 对象的构造和析构

> ​	构造是创对象的时候调用
>
> ​	析构是释放对象的时候调用(对象生命周期结束时，被C++编译器自动调用)
>
> ​	后创建的先释放
>
> ```
> #define _CRT_SECURE_NO_WARNINGS
> #include <iostream>
> using namespace std;
>
> class Test
> {
> public:
> 	Test()//构造函数
> 	{	
> 		a = 10;//作用完成对属性的初始化工作
> 		p = (char *)malloc(100);
> 		strcpy(p,"aaaaafff");
> 		cout<<"我是构造函数,被调用了"<<endl;
> 	}
> 	void printP()
> 	{
> 		cout<<p<<endl;
> 		cout<<a<<endl;
> 	}
> 	~Test() //析构函数
> 	{
> 		if (p != NULL)
> 		{
> 			free(p);
> 		}
> 		cout<<"我是析构函数,被调用了"<<endl;
> 	}
> private:
> 	int a;
>
>
> 	char *p;
> };
>
> //给对象搭建一个舞台，研究对象的行为
> void objplay()
> {
> 	//先创建的对象，后释放
> 	Test t1;
> 	t1.printP();
> 	cout<<"t1t1t1t1t1t1t"<<endl;
> 	Test t2;
> 	t2.printP();
> }
>
>
> void main()
> {
> 	
> 	objplay();
>
>
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
>
> }
> ```

#### 分类

1.括号法 2.=号法 3.直接调用法 

```
#include <iostream>
using namespace std;

class Test2
{
public:
	//1.无参构造函数
	Test2()
	{
		m_a=0;
		m_b=0;
		cout<<"无参数构造函数"<<endl;

	}
	//2.有餐构造函数  	//3种方法
	Test2(int a,int b)
	{
		m_a = a;
		m_b = b;
		cout<<"有参数构造函数"<<endl;
	}
	//3.赋值构造函数(copy构造函数)
	Test2(const Test2& obj)
	{
		cout<<"我也是构造函数"
	}

	void printT()
	{
		cout<<"printf printf printf"<<endl;
	}
protected:
private:
	int m_a;
	int m_b;
};
//调用有参函数的三个方法
void main()
{

	Test2 t1;//无餐
	
	//1.括号法
	Test2 t2(2,3)//有参函数1

	//2.等号法 
	Test2 t3 = (3,4);//有参函数2 （，，，）逗号表达式，取最后一个数的值为表达式的值  

	//3.直接调用构造函数  手动的调用构造函数
	Test2 t4 = Test2(1,2);  //匿名对象（匿名对象的去和留）
	//完成t4 对象的初始化
	
	t1 = t4;
	//对象的初始化和对象的赋值是两个不同的概念
	
	cout<<"hello wordl"<<endl;
	system("pause");
	return 0;
}
```

#### 为什么需要构造和析构函数

构造函数的调用方法是：

1. 自动调用（按照规则调用）
2. 也可以显示的初始化类的属性或其他资源

显示初始化方案：

```
#include <iostream>
using namespace std;

class Test3
{
public:
	void init(int _a,int _b)
	{
		a = _a;
		b = _b;
	}
private:
	int a;
	int b;
}

void main()
{
	//类没有提供构造函数，C++编译器会自动给你提供一个默认的构造函数
	//类没有提供构造函数，copy构造函数，C++会自动给程序员提供一个默认的copy函数。
	Test3 t1;
	int a=10;
	int b=20;
	t1.init(a,b);

	//这种场景之下，满足不了编程的需要
	Test3 tArray[1999] = {t21, .....}


	cout<<"hello wordl"<<endl;
	system("pause");
	return 0;
}
```

#### copy构造函数的调用时机

4种场景

#### 1 和 2 场景

```
#include <iostream>
using namespace std;

class Test4
{
public:
	//1.无参构造函数
	Test4()
	{
		m_a=0;
		m_b=0;
		cout<<"无参数构造函数"<<endl;

	}
	//2.有餐构造函数  	//3种方法
	Test4(int a,int b)
	{
		m_a = a;
		m_b = b;
		cout<<"有参数构造函数"<<endl;
	}
	//3.赋值构造函数(copy构造函数)
	Test4(const Test4 &obj)
	{
		cout<<"我也是构造函数";
		m_a =obj.m_a +10;
		m_b =obj.m_b +10;
	}

	void printT()
	{
		cout<<"printf printf printf"<<endl;
		cout<<"m_b:  "<<m_b<<endl;
		cout<<"m_a:  "<<m_a<<endl;
	}
protected:
private:
	int m_a;
	int m_b;
};


//1.复制构造函数 用一个对象去初始化另外一个对象
//void main()
//{
//	Test4 t1(1,2);
//	Test4 t0(1,2);
//
//	//赋值操作，不会调用构造函数
//	t0 = t1;//用t1给t0赋值 赋值操作和初始化是两个不同的概念
//	t0.printT();
//
//	//第一种调用方法
//	Test4 t2 = t1;//用t1来初始化t2
//	t2.printT();
//
//
//	cout<<"hello wordl"<<endl;
//	system("pause");
//
//}

//第二种调用时机
//void main()
//{
//	Test4 t1(1,2);
//	t1.printT();
//
//
//	Test4 t2(t1);//用t1对象初始化t2对象,会调用t2的copy构造函数
//	t2.printT();
//
//
//	cout<<"hello wordl"<<endl;
//	system("pause");
//}
```

#### 第三种调用时机

```

#include <iostream>
using namespace std;

class Location
{
public:
	Location(int xx =0,int yy =0)
	{
		X = xx;
		Y = yy;
		cout<<"构造构造构造"<<endl;
	}
	//copy构造函数 完成对象的初始化
	Location(const Location & obj)//copy构造函数
	{
		X = obj.X;
		Y = obj.Y;
	}

	~Location()
	{
		cout<< X <<","<<Y<<"析构析构析构"<<endl;
	}
	int GetX()
	{
		return X;
	}
	int GetY()
	{
		return Y;
	}
private:
	int X;
	int Y;
};
//业务函数 形参是一个元素
void f(Location p)
{
	cout<<p.GetX()<<endl;

}
void playobj()
{
	Location a(1,2);
	Location b = a;
	cout<<"b对象已经初始化完毕"<<endl;

	f(b);//b实参取初始化形参p，会调用copy构造函数

}
void main()
{
	playobj();
	cout<<"hello wordl"<<endl;
	system("pause");

}
```

> 构造构造构造
> b对象已经初始化完毕
> 1
> 1,2析构析构析构
> 1,2析构析构析构
> 1,2析构析构析构
> hello wordl
> 请按任意键继续. . .

#### 第四种时机(匿名对象去和留)

```
#include <iostream>
using namespace std;

class Location
{
public:
	Location(int xx =0,int yy =0)
	{
		X = xx;
		Y = yy;
		cout<<"构造构造构造"<<endl;
	}
	//copy构造函数 完成对象的初始化
	Location(const Location & obj)//copy构造函数
	{
		X = obj.X;
		Y = obj.Y;
	}

	~Location()
	{
		cout<< X <<","<<Y<<"析构析构析构"<<endl;
	}
	int GetX()
	{
		return X;
	}
	int GetY()
	{
		return Y;
	}
private:
	int X;
	int Y;
};

//g函数 返回一个元素 

//结论1：函数的返回值是一个元素（复杂类型的）,
//返回的是一个新的匿名对象（所以会调用匿名对象类的copy构造函数）


//结论2：有关 匿名对象的去和留
//如果用匿名对象 初始化另外一个同类型的对象  那匿名对象    直接转成有名对象
//如果用匿名对象 赋值给另外一个同类型的对象  那么匿名对象  马上被析构

//
//这么写代码，设计编译器的牛人们：
//我就给你返回一个新对象（没有名字 匿名对象）
Location g()
{
	Location A(1,2);  
	return A;
}

void objplay2()
{
	g();
}

void objplay3()
{
	//匿名对象初始化m，此时C++编译器 直接把匿名对象转成m;（扶正）从匿名转成有名字了
	Location m = g();
	cout<<"匿名对象呗扶正，不会析构掉"<<endl;
	cout<<m.GetX()<<endl;
}

void objplay4()
{
	//匿名对象 赋值给m2  匿名对象会被析构
	Location m2(1,2);
	m2 = g();
	cout<<"因为用匿名对象=给m2（没有转成新对象），匿名对象被析构"<<endl;
	cout<<m2.GetX()<<endl;
}

void main()
{
	//objplay2();
	//objplay3();
	objplay4();
	cout<<"hello wordl"<<endl;
	system("pause");
}
```

> //g函数 返回一个元素
>
> //结论1：函数的返回值是一个元素（复杂类型的）,
>
> //返回的是一个新的匿名对象（所以会调用匿名对象类的copy构造函数）
>
> //结论2：有关 匿名对象的去和留//如果用匿名对象 初始化另外一个同类型的对象  那匿名对象    直接转成有名对象
>
> //如果用匿名对象 赋值给另外一个同类型的对象  那么匿名对象  马上被析构

#### 构造 析构 函数 总结

1. 当勒种没有定义任何一个构造函数时，C++编译器会提供默认无参构造函数和默认拷贝构造函数

2. 当类中定义了拷贝构造函数时，C++编译器不会提供无参数构造函数

3. 当类中定义了任意非拷贝构造函数（即：当类中提供了有参构造函数或有参构造函数），C++编译器不会提供无参构造函数

4. 默认拷贝构造函数成员变量简单赋值

   **在定义类时，只要你写了构造函数，那么你必须用**

   ​