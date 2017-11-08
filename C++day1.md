## C++day1

1. ##### 面向过程：加工的是一个一个的函数

2. ##### 面向对象：类似于java，加工的是一个一个的类

   ```
   class xxx{
     public :
     private :
   }
   ```

   - class 声明类

   - 在main()里实例化对象

   - 类也是一个数据类型，定义一个类，是一个抽象概念，不会分配内存。当实例化对象的时候才会分配内存。

   - c++编译器是如何区分一个类的多个对象的??

   - 为什么需要成员函数？

     > - 直接使用成员变量的话是直接从内存拿值，可能会有乱码。
     > - 不会执行变量里边写的计算比如 int a = b*c。不会去获取新的bc值去计算。***在你通过类型定义变量的时候，a的值就已经定义了。**要定义成员函数。

3. ##### 封装、继承、多态

4. ##### namespace命名空间

   - std:是标准的命名空间

   - 如果不加using namespace std;可以使用std::cin（cout）>>(<<)"sdsd">>std::endl;

   - 定义命名空间:

     ```
     namespace namspaceA{
       int a = 10;
     }
     namespace namspaceB{
       int a = 20;
       namespace namspaceC{
       	struct Teacher{
       char name[32];
       int age;
     }
     }
     }
     ```

   - 使用命名空间

     ```
     void main(){
       using namespace namespaceA;
       using namespace namespaceB;
       cout<<namespaceA::a<<endl;
       cout<<namespaceB::a<<endl;
       //路径写全
       namespaceB::namespaceC::Teacher t1;
       t1.age=33;
       //使用using
       using namespaceB::namespaceC::Teacher;
       Teacher t2;
       t2.age =10;
     }
     ```

   - iostream 与 iostream.h

     - iostream 速度快 是.h的优化版本

5. ##### C++相对于C的增强 

   1. C语言中的变量必须在初始位置声明，而C++不是

   2. register关键字增强(register请求“编译器”将局部变量存储在寄存器中，这样比直接从内存中获取要快)

      > C语言无法取得register变量地址
      >
      > C++中依然支持register关键字，可以取得register变量的地址

   3. 检测增强

   4. struct类型增强

      > C不认为struct是一个新的类型，C++则认为是一个新的类型。
      >
      > C++中struct 和class 完成的功能是一样的，**也有区别**。

   5. C++中的所有变量和函数必须有类型,C中默认的类型在C++中不允许。

   6. 新增 **bool**类型关键字

      > 分配一个字节的内存
      >
      > bool的值 **要么是1（true）要么是0(false)**

   7. 三目运算符的增强

      > C语言中，表达式的返回值是一个数，其结果放在寄存器。
      >
      > C++中，表达式的是变量的本身。 **<u>左值</u>**必须有内存空间。

      - C中如何做到让表达式返回一个内存空间

        > 不让表达式返回 a或者b的值，可以让其返回&a，&b（a，b）的地址 
        >
        > *（a<b ? &a:&b）= 30

      - C++编译器帮我们完成了取地址

6. C和C++中const的表现

   1.  指针所指向的内存空间不能被修改

      ```
      const Teacher *pT
      ```

   2. 指针变量本身，不能被修改

      ```
      Teacher * const pT
      ```

   3. 本身和指向的内存空间都不能被修改

      ```
      const Teacher * const pT
      ```

   4. C中的const是一个冒牌货(可以通过指针进行修改),C++中const是一个真的常亮。

      > 通过符号表的形式，a就对应他的值10。
      >
      > C中的const变量是只读变量，有自己的存储空间。
      >
      > C++中的const常量：
      >
      > 可能分配存储空间，也可能不分配存储空间
      >
      > 当const常量为全局，并且需要在其他文件中使用，会分配存储空间
      >
      > 当使用&操作符，取const常量的地址时，会分配存储空间
      >
      > 当const int&a=10;const修饰饮用时，也会分配存储空间.

   5. const分配内存的时机 编译器编译期间。

   6. const 用途

      - 和#define相同

        > ​

      - 和#define不同之处

        > define 宏定义由预处理器处理、单纯的文本替换
        >
        > const定义的变量，由编译器处理的、提供类型检查和作用域检查

7. ##### 引用

   - 普通引用

     - 引用可看作一个 **已定义变量**的别名

     - 引用是C++的概念、不能用C的想法去思考它

     - ```
       int a =10;
       int &b = a;//b就是a的别名,b就相当于a
       ```

     - **普通引用必须初始化（依附于一个变量）**

     - 引用作为函数参数时不用进行初始化，引用改变其原变量也发生改变

   - 复杂数据类型做引用

     -  

   - 引用的本质

     > 引用相对于指针来说有更好的可读性和实用性。
     >
     > 在一些场合可以替代指针。

     - 相当于对同一块内存空间起了个别名。

     - 普通引用占4个内存空间，和指针占用的内存空间一样。

     - 引用在C++内部实现是一个常量指针。C++自动帮我们使用指针，取了地址。 

     - 间接赋值成立的三个条件(引用是把间接赋值成立的三个条件的后两步合二为一。)

       > 1.定义两个变量
       >
       > 2.建立关联
       >
       > 3.*p

   - 引用的难点（函数返回值是个引用）

     - 函数返回值是基本引用 

     - 若返回

     - 函数当左值

       ```
       //返回变量的值
       int g(){
       	static int a = 10;
           a++;
           return a;
       }//不可以当左值

       //返回变量本身
       int& g2(){
         static int a =10;
         a++;
         return a;
       }//可以当左值

       ```

       ​