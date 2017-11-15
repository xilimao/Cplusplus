#pragma once

class Point
{
private:
	double x1;
	double y1;
public:
	void setXY(double _x1,double _y1);
	double getX1();
	double	getY1();
	double vaLength(Point &p2);
};
