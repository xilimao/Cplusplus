### day6

#### 继承

> 派生类继承了基类的所有成员变量和成员方法（除了构造和析构函数），但是这些成员的访问属性，在派生过程中可以调整。

#### 3看原则

> C++中的继承方式（public 、private、protected）会影响子类的对外访问属性
>
> 1. 看调用语句，这句话写在子类的内部、外部
> 2. 看子类如何从父类继承（public、protected、private）
> 3. 看父类中的访问级别（public、private、protected）

#### 类型兼容性原则

> 兼容规则中所指的替代包括以下情况
>
> - 子类对象可以当做父类对象使用
> - 子类对象可以直接赋值给父类对象
> - 子类对象可以直接初始化父类对象
> - 父类指针可以直接指向子类对象
> - 父类引用可以直接引用子类对象  

#### 继承中的构造和析构：

> 1. 子类对象在创建时 首先会调用父类的构造函数
>
> 2. 父类构造函数执行结束后，执行子类的构造函数
>
> 3. 当父类的构造函数有参数时，需要在子类的初始化列表中显示调用
>
> 4. 析构函数调用的先后顺序与构造函数相反
>
> ```
> #include <iostream>
> using namespace std;
>
> //结论 
> //先调用父类构造函数 在调用 子类构造函数
> //析构的顺序  和 构造相反
>
> class Parent
> {
> public:
> 	Parent(int a,int b)
> 	{
> 		this->a = a;
> 		this->b = b;
> 		cout<<"父类构造函数....."<<endl;
> 	} 
>
> 	~Parent()
> 	{
> 		cout<<"父类析构函数"<<endl;
> 	} 
>
> 	void printP(int a,int b)
> 	{
> 		this->a = a;
> 		this->b = b;
> 		cout<<"我说爹..."<<endl;
> 	}
>
> private:
> 	int a;
> 	int b;
> };
>
> class Child : public Parent
> {
> public:
> 	Child(int a, int b,int c) : Parent(a,b)
> 	{
> 		cout<<"子类构造函数"<<endl;
> 		this->c = c;
> 	}
> 	~Child()
> 	{
> 		cout<<"子类析构函数"<<endl;
> 	}
> 	void printC()
> 	{
> 		cout<<"我是儿子...."<<endl;
> 	}
> protected:
> private:
> 	int c;
> };
>
> void display()
> {
> 	Child c1(1,2,3);
> }
> void main()
> {
> 	display();
>
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
> 	return ;
> }
> ```

#### 继承和组合混搭情况下，构造和析构的调用规则

> 先构造父类，再构造成员变量，最后构造自己
>
> 先析构自己，再析构成员变量，最后析构父类
>
> ```
> #include <iostream>
> using namespace std;
>
> class Object
> {
> public:
> 	Object(int a,int b)
> 	{
> 		this->a = a;
> 		this->b = b;
> 		cout<<"object 构造函数 执行"<<"a"<<a<<"b"<<b<<endl;
> 	}
> 	~Object()
> 	{
> 		cout<<"析构函数objjjj"<<endl;
> 	}
> protected:
> 	int a;
> 	int b;
> private:
> };
>
> class Parent : public Object
> {
> public:
> 	Parent(char *p): Object(1 , 2)
> 	{
> 		this->p = p;
> 		cout<<"父类构造函数....."<<p<<endl;
> 	} 
>
> 	~Parent()
> 	{
> 		cout<<"父类析构函数"<<p<<endl;
> 	} 
>
> 	void printP(int a,int b)
> 	{
> 		cout<<"我说爹..."<<endl;
> 	}
> protected:
> 	char *p;
> private:
> };
>
> class Child : public Parent
> {
> public:
> 	Child(char *p) : Parent(p),obj1(3,4),obj2(5,6)
> 	{
> 		this->myp = p;
> 		cout<<"子类构造函数"<<myp<<endl;
> 		
> 	}
> 	~Child()
> 	{
> 		cout<<"子类析构函数"<<myp<<endl;
> 	}
> 	void printC()
> 	{
> 		cout<<"我是儿子...."<<endl;
> 	}
> protected:
> 	char *myp;
> 	Object obj1;
> 	Object obj2;
> };
>
> void display()
> {
> 	Child c1("继承测试");
> }
> void main()
> {
> 	
> 	display();
>
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
> 	return ;
> }
> ```
>
> object 构造函数 执行a1b2
> 父类构造函数.....继承测试
> object 构造函数 执行a3b4
> object 构造函数 执行a5b6
> 子类构造函数继承测试
> 子类析构函数继承测试
> 析构函数objjjj
> 析构函数objjjj
> 父类析构函数继承测试
> 析构函数objjjj

#### 继承中的同名成员变量和函数处理方法

> 基类中的成员变量和函数 会 派生到子类
>
> 子类默认使用的是 子类中的 成员变量函数  
>
> 要想使用基类中的 则需用 基类调用 如（parent::a1）  ::域作用符

#### 派生类中的static关键字

> 基类定义的静态成员，将被所有派生类共享
>
> 1.	static关键字 遵守 派生类的访问控制规则 
>
> 2.int A::a = 100; //这句话不是简单的变量赋值，更重要的是告诉编译器分配内存，我在继承类中用到了a，不然会报错
>
> 1. A类中添加构造函数、
>
> -  A类的构造函数中，A的构造函数是私有的构造函数（erro）
>
>
> - 被别的类继承要小心
>
>
> - 单例场景之下 可以是私有



> ```
> #include <iostream>
> using namespace std;
>
>
> class A
> {
> public:
> 	A()
> 	{
> 		cout<<"A的构造函数"<<endl;
> 	}
> public:
> 	static int a;
> 	int b;
> protected:
> private:
> };
>
> int A::a = 100; //这句话不是简单的变量赋值，更重要的是告诉编译器分配内存，
> //我在继承类中用到了a，不然会报错
>
> class B : private A
> {
> public:
> 	int b;
> 	int c;
> public:
> 	void get_child()
> 	{
> 		cout<<"b "<<b<<endl;
> 		cout<< a <<endl;
> 	}
> 	void print()
> 	{
> 		cout<<"BBBB  "<<endl;
> 	}
> protected:
> private:
> };
>
>
> //   1.	static关键字 遵守 派生类的访问控制规则 
>
> //   2	A::a = 100; //这句话不是简单的变量赋值，更重要的是告诉编译器分配内存，
> //		我在继承类中用到了a，不然会报错
>
> //   3	A类中添加构造函数
> 	//  A类的构造函数中，A的构造函数是私有的构造函数（erro）
> 	//	被别的类继承要小心
> 	//	单例场景之下 可以是私有
>
>
> void main()
> {
>
> 	B b1;
> 	b1.get_child();
> 	cout<<b1.a<<endl;//失败 因为是私有继承，私有的在类外不能使用，在类内可以
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
> 	return ;
> }
> ```
>

#### 多继承（被摒弃）

> 可以继承多个类

#### 继承的二义性

> 祖宗类：B     int b
>
> 父类：B1  B2  继承 B
>
> 子类：继承B1、B2    但是调用b的时候出错

#### 虚继承(virtual) 

​	加virtual后，C++编译器会给变量偷偷的增加属性

> 在 父类 继承 祖宗类的时候 加个 : virtual  public B
>
> 如果一个派生类从多个基类派生，而这些基类又有一个共同的基类 ，则在对该类基类中声明的名字进行访问时，可能产生二义性。  
>
> 只能解决有共同老祖先的问题，不能解决没有老祖先的多继承，只能用 域作用符来解决



