### day3(浅拷贝深拷贝)

```
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Name
{
public:
	Name(const char *myp)
	{
		m_len = strlen(myp);
		m_p =(char *)malloc( m_len + 1);
		strcpy(m_p,myp);
	}
	//解决方案  ：  手工的编写拷贝构造函数 使用深copy
	Name(const Name& obj1)
	{
		m_len = obj1.m_len;
		m_p=(char *)malloc(m_len+1);
		strcpy(m_p,obj1.m_p);
	}

	~Name()
	{
		if (m_p!= NULL)
		{
			free(m_p);
			m_p = NULL;
			m_len = 0;
		}
	}
private:
	char *m_p;
	int m_len;
};

//对象析构的时候 出现coredump
void objectmain()
{
	Name obj1("dsfsdfds");
	Name obj2 = obj1; //如果没有写copy函数，则使用默认的copy构造函数，但是只执行的浅拷贝
	//浅拷贝只是拷贝的值，没有重新开辟新的内存空间（两个对象使用同一块内存空间）
	
	Name obj3("obj3");
	obj3 = obj1; //等号操作 obj3也指向了obj1 （两次析构 造成奔溃）  也是浅copy  （需要重载 = 号操作符）
}
void main()
{
	objectmain();

	cout<<"hello wordl"<<endl;
	system("pause");
}

```



### 构造函数的初始化列表

```
#include <iostream>
using namespace std;

class A
{
public:
	A(int _a)
	{
		a = _a;
		cout << "构造函数"<<"a" << a <<endl;
	}
	~A()
	{
		cout << "析构函数" << a <<endl;
	}
private:
	int a;
};
//构造函数的初始化列表  解决：在B类中 组合一个A类对象（A类设计了构造函数的）
//根据构造函数的调用规则 写了A的构造函数，必须要用 ，没有机会初始化A
//新的语法派上用场
class B
{
public:
	B(int _b1,int _b2) : a1(1),a2(2),c(0)
	{

	}
	B(int _b1,int _b2,int m,int n) : a1(m),a2(n),c(0)
	{
		b1 = _b1;
		b2 = _b2;
		cout<<"B的构造函数"<<endl;
	}
	~B()
	{
		cout<<"B的析构函数"<<endl;
	}
private:
	int b1;
	int b2;
	A a1;
	A a2;

	const int c;
};

//2 先执行 被组合对象的构造函数
//如果组合对象有多个，按照定义顺序（不是按照初始化列表的顺序）

//析构函数：和构造函数的调用顺序相反

//3.被组合对象的构造顺序，与定义顺序有关系，与初始化列表的顺序没有关系。


//初始化列表 用来给const 进行赋值

void objplay()
{
	//A a1(10);

	//1.参数传递
	//B objB(1,2);

	//2.调用顺序
	B objB2(1,2,3,4);


}

void main()
{
	objplay();

	cout<<"hello wordl"<<endl;
	system("pause");

}
```

### new 和 delete 的基本语法

> malloc 和 free 函数 是C的
>
> new 和 delete函数是C++的 ，不仅分配释放内存 还能调用对应的构造和析构函数
>
> ```
> #include <iostream>
> using namespace std;
>
>
> //1 malloc  free    C语言中的语法
> //  new     delete	C++的语法
>
> //2  基础类型变量  分配数组变量 分配类对象
>
> //3.   
>
> //分配对象 new delete
> //相同和不同 new能执行类型构造函数 delete操作符 能执行类的析构函数
> class Test
> {
> public:
> 	Test(int _a)
> 	{
> 		a = _a;
> 	}
> 	~Test()
> 	{
> 		cout<<"析构函数执行"<<endl;
> 	}
> private:
> 	int a;
> };
> void main()
> {
> 	//c语言中的
> 	Test *pT1 = (Test *)malloc(sizeof(Test));
> 	free(pT1);
>
> 	//C++
> 	Test *pT2 = new Test(10);
> 	delete pT2();
>
> }
>
> //分配数组变量
>
> void main02()
> {
> 	//c语言分配数组
> 	int *p = (int *)malloc (sizeof(int) *10);
> 	p[0] = 1;
> 	free(p);
>
> 	//c++分配数组
> 	int *pArray = new int[10];
> 	pArray[1] = 2;
>
> 	delete [] pArray;//数组不要把[] 忘记
>
>
> }
> //分配基础类型   可以
> void main01()
> {
>
> 	int *p = (int *)malloc(sizeof(int));
> 	*p = 10;
> 	free(p);
>
> 	int *p2 = new int;//分配基础类型
> 	*p2 = 20;
> 	free(p2);
>
> 	int *p3 = new int(30);
> 	cout<<*p3<<endl;
>
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
> }
> ```
>
>  

