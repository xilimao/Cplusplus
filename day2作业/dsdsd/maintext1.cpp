#include <iostream>
using namespace std;
#include "Point.h"
#include "Circle.h"

void main()
{

	double r1,x1,y1;
	double r2,x2,y2;
	Circle c1,c2;
	cout<<"输入R1、X1、y1"<<endl;
	cin>>r1>>x1>>y1;
	c1.setRXY(r1,x1,y1);

	cout<<"输入R2、X2、y2"<<endl;
	cin>>r2>>x2>>y2;
	c2.setRXY(r2,x2,y2);

	double juli = c1.juXJ(c2);
	if (juli ==1)
	{
		cout<<"橡胶"<<endl;
	} 
	else
	{
		cout<<"不想交"<<endl;
	}

	cout<<"hello"<<endl;
	system("pause");
}