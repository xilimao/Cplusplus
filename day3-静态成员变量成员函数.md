### day3静态成员变量、成员函数

> 静态成员变量（static） 在类中是公用的 ，只要是该类声明的对象 都能对 该静态成员变量 进行操作
>
> 静态成员函数里边    不能使用普通成员变量  普通成员函数。
>
> ```
> #include <iostream>
> using namespace std;
>
>
> class BB
> {
> public:
> 	void printC()
> 	{
> 		cout<<"c: "<<c<<endl;
> 	}
> 	void AddC()
> 	{
> 		c = c+1;
> 	}
>
> 	//静态成员函数
> 	static void getC()
> 	{
> 		cout<<"c: "<<c<<endl;
>
> 		//请问在静态成员函数中，能调用普通成员属性、方法吗???
>
> 		cout<<"a: "<< a<<endl;//对非静态成员“BB::a”的非法引用
> 							//因为具体的成员属性方法是在具体的对象中的，静态的无法分析是在哪个对象的
>
> 		
> 	}
> private:
> 	int a;
> 	int b;
> 	//静态成员变量
> 	//c在类中是公用的 ，只要是该类声明的对象 都能对C进行操作
> 	static int c;
> };
> int BB::c=10;
>
> void main()
> {
> 	BB b1,b2,b3;
> 	b1.printC();//10
> 	b2.AddC();//11
> 	b3.printC();//11
>
> 	//静态成员函数的调用方法
>
> 	b3.getC();//1. 用对象.
> 	BB::getC();//2. 用类名::
>
>
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
> }
> ```
>
> 

