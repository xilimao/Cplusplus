
#include "cmath"
#include "Point.h"

void Point::setXY(double _x1,double _y1)
{
	x1 = _x1;
	y1 = _y1;
}
double Point::getX1()
{
	return x1;
}
double	Point::getY1()
{
	return y1;
}
double Point::vaLength(Point &p2)
{
	double d_x = p2.getX1() - x1;
	double d_y = p2.getY1() - y1;
	double len =sqrt(d_x*d_x + d_y*d_y);
	return len;
}