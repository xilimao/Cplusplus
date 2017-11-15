#include "Circle.h"
#include "Point.h"
#include <iostream>
using namespace std;
void Circle::setRXY(double _r,double _x,double _y)
{
	r = _r;
	r_x = _x;
	r_y = _y;
}
double Circle::getR()
{
	return r;
}
Point Circle::setPo()
{
	Point p;
	p.setXY(r_x,r_y);
	return p;
}
double Circle::juXJ(Circle &cc)
{
	double len = setPo().vaLength(cc.setPo());
	double xx= cc.getR();
	double rpr = r + xx;
	if (rpr >= len)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}
