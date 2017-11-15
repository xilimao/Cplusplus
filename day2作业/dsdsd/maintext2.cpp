#include <iostream>
using namespace std;
#include "Rectangle.h"
#include "tree.h"
void main()
{

	/*int lx,ly,rx,ry;
	Rectangle r1;
	cout<<"输入坐下坐标x，y"<<endl;
	cin>>lx>>ly;
	r1.setPl(lx,ly);


	cout<<"输入坐下坐标x，y"<<endl;
	cin>>rx>>ry;
	r1.setPr(rx,ry);
	


	cout<<"面积： "<<r1.getS()<<endl;*/


	tree t1;
	t1.setAges(10);
	t1.age();
	t1.grow(5);
	t1.age();
	cout<<"hellp "<<endl;
	system("pause");
}