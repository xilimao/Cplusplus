### 类和对象

基本概念

#### 类的封装(类似于java)

> 1. 把属性和方法进行封装
>
> 三种1. 通过指针
>
> ​	2.引用
>
> ​	3.直接声明对象
>
> 1.  对属性和方法进行访问控制
>
> 2.  类的内部和外部
>
> 3.  类的访问控制关键字
>
> 不写的话默认是私有的
>
> > public: 可以再类的内部和外部访问
> >
> > private: 只能在类的内部被访问，不能在类的外部被访问
> >
> > protected: 只能在类的内部被访问，不能在类的外部被访问，用在继承里面。

### struct 和 class 关键字的区别

1. 不加访问控制关键字的话，默认是public

### 类的声明和类的实现分开

> 编译器的类向导：右键项目名字，添加一个类，生成一个.h 一个.cpp
>
> .h 中  #pragma once  代表只能被include包含一次，相当于#ifndef #define #endif这三句加起来
>
> .cpp 中实现函数时 需要加类的声明符 比如 void Teacher::setAge(int age){m_age = age;}

### 面向过程向面向对象转变

1. ​

```
#include "iostream"
using namespace std;

class Vaaa
{
public:
	void setA(int a)
	{
		m_a=a;
	}
	void setB(int b)
	{
		m_b=b;
	}
	void setC(int c)
	{
		m_c=c;
	}
	void setABC(int a=0,int b=0,int c=0)
	{
		m_a=a;
		m_b=b;
		m_c=c;
	}
	int getA()
	{	
		return m_a;
	}
	int getB()
	{
		return m_b;
	}
	int getC()
	{
		return m_c;
	}
	int getV()
	{
		m_v = m_a*m_b*m_c;
		return m_v;
	}
	int getS()
	{
		m_s=2*(m_a*m_b+m_a*m_c+m_b*m_c);
		return m_s;
	}
	//冗余点的方法
	int judge(Vaaa &v1,Vaaa &v2)
	{
		if( (v1.getA()==v2.getA())&&
			(v1.getB()==v2.getB())&&
			(v1.getC()==v2.getC()))
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}
	//重载
	//简洁点的方法
	int judge(Vaaa &v2)
	{
		//好多学员分不清这个场景下的m_a是属于v1还是属于v2
		if( (m_a==v2.getA())&&
			(m_b==v2.getB())&&
			(m_c==v2.getC()))
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}
protected:
private:
	int m_a;
	int m_b;
	int m_c;
	int m_v;
	int m_s;
};

//全局函数的方法
//int judge(Vaaa &v1,Vaaa &v2)
//{
//	if( (v1.getA()==v2.getA())&&
//		(v1.getB()==v2.getB())&&
//		(v1.getC()==v2.getC()))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//
//}

void main()
{
	Vaaa v1,v2;

	/*v1.setA(2);
	v1.setB(2);
	v1.setC(2);*/

	v1.setABC(1,2,2);
	v2.setABC(1,2,2);

	//面向对象的方法
	if (v1.judge(v2)==1)
	{
		cout<<"相等"<<endl;
	} 
	else
	{
		cout<<"不相等"<<endl;
	}
	
	//全局函数的方法
	/*if (judge(v1,v2)==1)
	{
		cout<<"相等"<<endl;

	} 
	else
	{
		cout<<"不相等"<<endl;
	}*/

	//
	//cout<<"sss: "<<v1.getS()<<endl;
	//cout<<"vvv: "<<v1.getV()<<endl;
	system("pause");
}

```

1. ```
   //一个圆类一个点类，判断点在圆的哪个位置
   #include<iostream>
   using namespace std;

   class Point
   {
   public:
   	void setPoint(int _x1,int _y1)
   	{
   		x1 = _x1;
   		y1 = _y1;
   	}
   	int getX1()
   	{
   		return x1;
   	}
   	int getY1()
   	{
   		return y1;
   	}

   private:
   	int x1;
   	int y1;
   };

   class Circle
   {
   private:
   	int r;
   	int x0;
   	int y0;
   public:
   	void setCircle(int _r,int _x0,int _y0)
   	{
   		r = _r;
   		x0 = _x0;
   		y0 = _y0;
   	}
   	int jude(Point &p)
   	{
   		int d =(p.getX1()-x0)*(p.getX1()-x0)+(p.getY1()-y0)*(p.getY1()-y0);
   		if (d<r*r)
   		{
   			return 1;//在圆内
   		} 
   		else if(d==r*r)
   		{
   			return 2;//在圆上
   		}
   		else{
   			return 0;//在圆外
   		}
   	}
   };

   void main()
   {
   	Circle c1;
   	Point p1;

   	c1.setCircle(2,3,3);
   	p1.setPoint(7,7);
   	//在圆内 1,不在圆内 0
   	int tag = c1.jude(p1);
   	if (tag ==1)
   	{
   		cout<<"在园内"<<endl;
   	} 
   	else if(tag == 0)
   	{
   		cout<<"在园外"<<endl;
   	}
   	else
   	{
   		cout<<"在园上"<<endl;
   	}
   	system("pause");
   }
   ```

2. 把类的声明和类的实现分开

   ```
   注意加上  Teacher：：
   3个作业

   ```

   ​



