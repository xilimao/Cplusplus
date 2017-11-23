### day4

#### this的const修饰

> **const 修饰的是谁 ?**       
>
> const修饰的是this指针所指向的内存空间,修饰的是this指针
>
> ```
> void OpVar(int a,int b) const   //== void OpVar(const Test *this, int a, int b)
> 						//== void OpVar(const Test *const  this, int a, int b)
> {
>   
> }
> ```

#### 全局函数PK成员函数

1. 把全局函数转换为成员函数，通过this指针隐藏左操作符

   > Test add(Test &t1,Test &t2) ==>  Test add(Test  &t2)

2. 把成员函数转换为全局函数，多了一个参数

   > void printAB()   ==>  void printAB(Test *pthis)

3. 函数返回元素和返回引用

   > ???
   >
   > ​