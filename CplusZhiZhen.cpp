#include <iostream>
using namespace std;

void main(){
	char ch = 'a',ch1 = 'b';
	//声明常量指针
	const char* ptr = &ch;
	//打印初始化指针所指向的值
	cout << *ptr<<endl;

	//尝试改变其所指向的值
	*ptr = 'c';

	//更改存储的地址
	ptr =&ch1;
	//打印更改地址后指针所指向的值
	cout << *ptr<<endl;
	system("pause");
}
/*
void main(){
	char ch = 'a',ch1 = 'b';
	//声明指针常量
	char * const ptr = &ch;
	//打印初始化指针所指向的值
	cout << *ptr<<endl;
	//改变其所指向的值
	*ptr = 'c';
	//打印更改后的值
	cout << *ptr<<endl;

	//尝试更改存储的地址
	//ptr =&ch1;
	
	system("pause");
}
*/
//指针的练习与理解
//void main()
//{
//	int v1;
//	char v2[10];
//
//	cout<< "var1变量的地址:  ";
//	cout<<&v1 <<endl;
//
//	cout<< "var2变量的地址:  ";
//	cout<<&v2 <<endl;
//
//	system("pause");
//}



//void main(){
//	int var = 10; //声明实际变量
//	int *ip;	  //声明指针变量
//
//	ip = &var;    //在指针变量中存储var的地址
//
//	//输出var的值
//	cout << "var: " <<var << endl; 
//
//	//输出var的地址
//	cout <<"&var: " << &var <<endl;
//
//	//输出指针变量中存储的地址
//	cout <<"ip: "<< ip <<endl;
//
//	//输出指针中地址对应的值
//	cout <<"*ip: "<<*ip <<endl;
//
//	//输出指针中地址对应的值的地址
//	cout <<"&*ip: "<< &*ip<<endl;
//
//	*ip = 20;
//	cout<<"a: "<<var<<endl;
//
//	system("pause");
//}