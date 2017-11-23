### day6多态

面向对象新需求:

- 根据实际的对象类型来判断重写函数的调用
- 如果父类指针指向的是父类对象则调用父类重定义的函数
- 如果父类指针指向的是子类对象则调用子类中定义的重写函数

#### 解决方案:

- 通过virtual（如果父类中函数前加了virtual ，子类中可写可不写）


> **实现多态的三个条件**
> 1.要有继承
> 2.要有虚函数重写
> 3.用父类指针(父类引用)指向子类对象

#### 案例

```
#include <iostream>
using namespace std;


class HeroFighter
{
public:
	virtual int power() //C++会对这个函数特殊处理
	{
		return 10;
	}
protected:
private:
};

class EnemyFighter
{
public:
	int attack()
	{
		return 15;
	}

protected:
private:
};

class  AdvHeroFighter : public HeroFighter
{
public:
	virtual int power()
	{
		 return 20;
	}
protected:
private:
};

class  AdvHeroFighter3 : public HeroFighter
{
public:
	virtual int power()
	{
		return 30;
	}
protected:
private:
};



//多态威力
//1.给对象搭建舞台  可以看成一个框架
//
void PlayObj(HeroFighter *hf,EnemyFighter *ef)
{
	//不写virtual关键字  是静态联编   C++编译器根据类型，去执行这个类型的power函数
	//在编译器编译阶段就决定了函数的调用
	//动态联编： 迟绑定,函数执行时（根据具体对象）再决定具体对象，执行不同对象的函数，变现成多态
	if (hf->power() > ef->attack()) //hf->power()函数调用会有多态发生
	{
		cout<<"主角 win"<<endl;
	} 
	else
	{
		cout<<"主角挂了"<<endl;
	}
}

//多态思想
//面向对象3大概念
//封装：突破c函数的概念... 用类做函数参数的时候 可以使用对象的属性 和对象的方法
//继承: A B 代码复用
//多态： 可以使用未来


//C语言中 间接赋值是指针存在的最大意义
//是C语言特有的现象(1 定义两个变量  2  建立关联  3 *p在被调用函数中 去间接的修改实参的值)
//
//多态很重要
//实现多态的三个条件
//1.要有继承
//2.要有虚函数重写
//3.用父类指针(父类引用)指向子类对象
void main()
{
	HeroFighter hf;
	EnemyFighter ef;
	AdvHeroFighter advhf;
	AdvHeroFighter3 adv3;

	PlayObj(&hf, &ef);
	PlayObj(&advhf, &ef);

	PlayObj(&adv3, &ef);//这个框架 能把我们后来人写的代码 给调用起来

	cout<<"hello wordl"<<endl;
	system("pause");
}
```

