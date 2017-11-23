### day6(虚析构，重载重写)

#### 虚析构

> ```
> #include <iostream>
> using namespace std;
>
>
> //虚析构函数
> class A
> {
> public:
> 	A()
> 	{
> 		p = new char[20];
> 		strcpy(p,"obja");
> 		cout<<"A()"<<endl;
> 	}
> 	virtual ~A()
> 	{
> 		delete [] p;
> 		cout<<"~A()"<<endl;
> 	}
> protected:
> private:
> 	char *p;
> };
>
>
> class B : public A
> {
> public:
> 	B()
> 	{
> 		p = new char[20];
> 		strcpy(p,"objb");
> 		cout<<"B()"<<endl;
> 	}
> 	~B()
> 	{
> 		delete [] p;
> 		cout<<"~B()"<<endl;
> 	}
> protected:
> private:
> 	char *p;
> };
>
>
> class C : public B
> {
> public:
> 	C()
> 	{
> 		p = new char[20];
> 		strcpy(p,"objb");
> 		cout<<"C()"<<endl;
> 	}
> 	~C()
> 	{
> 		delete [] p;
> 		cout<<"~C()"<<endl;
> 	}
> protected:
> private:
> 	char *p;
> };
>
> //只执行了 父类的析构函数 会发生内存泄漏
> //想通过父类指针  把所有的子类对象的析构函数 都执行一遍
> //想通过父类指针 释放所有的资源
> void howtodelete(A *base)
> {
> 	delete base;  //将不会显出多态 这种属性
> }
>
> void main()
> {
>
> 	C *myC = new C;//new delelte 匹配
>
> 	delete myC;//直接通过子类对象释放资源 不需要写virtual
> 	howtodelete(myC);//通过父类释放 所有  运用了多态
>
> 	
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
> }
> ```

#### 重载、重写

> **重载**
>
> 必须在同一个类中进行
>
> 子类无法重载父类的函数，父类同名函数将被名称覆盖
>
> 重载是在编译期间根据函数类型和个数决定函数调用


> **函数重写（1.虚函数重写（将发生多态） 2.非虚函数重写（重定义））**
>
> 必须发生于父类与子类之间
>
> 并且父类与子类中的函数必须有完全相同的原型
>
> 使用virtual声明之后能够产生多态（如果不使用virtual，那叫重定义）
>
> 多态是在运行期间，根据具体对象的类型决定函数调用