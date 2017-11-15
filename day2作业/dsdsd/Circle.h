#pragma once
#include "Point.h"
class Circle
{
private:
	double r;
	double r_x;
	double r_y;
public:
	void setRXY(double _r,double _x,double _y);
	Point setPo();
	double juXJ(Circle &c2);
	double getR();
};
