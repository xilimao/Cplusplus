### day7 多态原理探究、抽象类

### 多态原理实现

> 当类中声明虚函数时，编译器会在类中生成一个虚函数表
>
> 虚函数表是一个存储类成员函数指针的数据结构
>
> 虚函数表是由编译器自动生成与维护的
>
> virtual 成员函数会被编译器放入虚函数表中
>
> 存在虚函数时，每个对象中都有一个指向虚函数表的指针（vptr 指针）

```
#include <iostream>
using namespace std;

//多态成立的三个条件
//要有继承  虚函数重写  父类指针指向子类对象

class Parent
{
public:
	Parent(int a  = 0)
	{
		this->a = a;
	}
	virtual void print()		//1. 动手脚  写virtual关键字 会特殊处理//虚函数表
	{
		cout<<"我是爹"<<endl;
	}
protected:
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int a = 0,int b = 0):Parent(a)
	{
		this->b = b;
	}
	virtual void print()
	{
		cout<<"我是儿子"<<endl;
	}
protected:
private:
	int b;
};


void HowToPlay(Parent *base)
{
	base->print();		//2. 动手脚  传来子类对象 执行子类的print函数
						//传来父类 执行父类的print函数
						//C++编译器根本不需要区分是子类对象 还是父类对象
						//父类 子类对象分别有vptr指针，通过指针去找虚函数表，再找函数的入口地址
						//达成了迟绑定的效果（运行的时候编译器采取判断 ）


}



void main01()
{
	Parent p1;			//3.动手脚  提前布局  
						//用类定义对象的时候C++编译器会在对象中添加一个vptr指针
	Child c1;			//子类中也有一个vptr指针
	
	HowToPlay(&p1);
	HowToPlay(&c1);

	cout<<"hello wordl"<<endl;
	system("pause");

}
```

#### vptr指针是分布初始化的

```
#include <iostream>
using namespace std;


//构造函数中调用虚函数能发生多态吗


class Parent
{
public:
	Parent(int a  = 0)
	{
		this->a = a;
		print();
	}
	virtual void print()		
	{
		cout<<"我是爹"<<endl;
	}
protected:
private:
	int a;
};

class Child : public Parent
{
public:
	Child(int a = 0,int b = 0):Parent(a)
	{
		this->b = b;
			print();
	}
	virtual void print()
	{
		cout<<"我是儿子"<<endl;
	
	}
protected:
private:
	int b;
};
void HowToPlay(Parent *base)
{
	base->print();	

}
void main()
{

	Child c1;   //定义一个子类对象，在这个过程中，
				//在父类构造函数中 调用虚函数print 能发生多态吗
	//1.要初始化c1.vptr 指针，初始化是分布
	//2. 当执行父类的构造函数时，c1.vptr指向父类的虚函数表，当父类的构造函数运行完毕后
		//会把c1.vptr指向 子类的虚函数表
	//3. 结论 ： c1.vptr 指针分布完成

	cout<<"hello wordl"<<endl;
	system("pause");

}
```

对多态的理解

 ![对多态的理解](C:\Users\chengang\Desktop\截图\对多态的理解.png)

#### 子类和父类的指针步长不一样

> 结论：
> 子类和父类的指针步长不一样的问题
>
> 多态是用父类指针指向子类对象 和 父类步长++，是两个不同的概念

```
#include <iostream>
using namespace std;


class Parent
{
public:
	Parent(int a  = 0)
	{
		this->a = a;
		//print();
	}
	virtual void print()		
	{
		cout<<"我是爹"<<endl;
	}
protected:
private:
	int a;
};

//一次偶然的成功,必然的失败更可怕

//结论：
//子类和父类的指针步长不一样的问题
//多态是用父类指针指向子类对象 和 父类步长++，是两个不同的概念

class Child : public Parent
{
public:
	Child(int a = 0,int b = 0):Parent(a)
	{
		//this->b = b;
		//print();
	}
	virtual void print()
	{
		cout<<"我是儿子"<<endl;

	}
protected:
private:
	int b;
};

void HowToPlay(Parent *base)
{
	base->print();	

}

void main()
{
	Child c1;

	Parent *pP = NULL;
	Child *pC = NULL;

	Child array[] = {Child(1),Child(2),Child(3)};

	pP = array;
	pC = array;

	pP->print();
	pC->print();

	pP++;
	pC++;
	pP->print();
	pC->print();

	pP++;
	pC++;
	pP->print();
	pC->print();
	
	cout<<"hello wordl"<<endl;
	system("pause");

}
```

### 抽象类

小案例

> ```
> #include <iostream>
> using namespace std;
>
> //程序员
> class programmer
> {
> public:
> 	virtual void getSal() = 0;
> protected:
>
> private:
> };
>
> //初级
> class juior_programmer : public programmer
> {
> public:
> 	juior_programmer(char *name,char *job ,int sal)
> 	{
> 		this->name = name;
> 		this->job = job;
> 		this->sal = sal;
> 	}
> 	virtual void getSal()
> 	{
> 		cout<<name<<" "<<job<<" "<<sal<<endl;
> 	}
> protected:
> private:
> 	char *name;
> 	char *job ;
> 	int sal;
> };
>
> //中级
> class mid_programmer : public programmer
> {
> public:
> 	mid_programmer(char *name,char *job ,int sal)
> 	{
> 		this->name = name;
> 		this->job = job;
> 		this->sal = sal;
> 	}
> 	virtual void getSal()
> 	{
> 		cout<<name<<" "<<job<<" "<<sal<<endl;
> 	}
> protected:
> private:
> 	char *name;
> 	char *job ;
> 	int sal;
> };
>
> //高级
> class adv_programmer : public programmer
> {
> public:
> 	adv_programmer(char *name,char *job ,int sal)
> 	{
> 		this->name = name;
> 		this->job = job;
> 		this->sal = sal;
> 	}
> 	virtual void getSal()
> 	{
> 		cout<<name<<" "<<job<<" "<<sal<<endl;
> 	}
> protected:
> private:
> 	char *name;
> 	char *job ;
> 	int sal;
> };
>
>
> class architect : public programmer
> {
> public:
> 	architect(char *name,char *job ,int sal)
> 	{
> 		this->name = name;
> 		this->job = job;
> 		this->sal = sal;
> 	}
> 	virtual void getSal()
> 	{
> 		cout<<name<<" "<<job<<" "<<sal<<endl;
> 	}
> protected:
> private:
> 	char *name;
> 	char *job ;
> 	int sal;
> };
>
> void CallProgSal(programmer *base)
> {
> 	base->getSal();
> }
>
> void main()
> {
> 	juior_programmer jp("小李","初级",4000);
> 	mid_programmer mp("小王","中级",8600);
> 	adv_programmer ap("小张","高级",10000);
>
> 	architect ar("高水平","架构师",15000);
>
>
> 	CallProgSal(&jp);
> 	CallProgSal(&mp);
> 	CallProgSal(&ap);
> 	CallProgSal(&ar);
> 	
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
> 	return ;
> }
> ```

