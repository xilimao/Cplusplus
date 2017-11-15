#include "Rectangle.h"

void Rectangle::setPl(int _x,int _y)
{
	l_x = _x;
	l_y = _y;
}
void Rectangle::setPr(int _x,int _y)
{
	r_x = _x;
	r_y = _y;
}
int Rectangle::getLx()
{
	return l_x;
}
int Rectangle::getLy()
{
	return l_y;
}
int Rectangle::getRx()
{
	return r_x;
}
int	Rectangle::getRy()
{
	return r_y;
}
int Rectangle::getS()
{
	int d_x = r_x - l_x;
	int d_y = r_y - l_y;
	return d_x*d_y;
}
