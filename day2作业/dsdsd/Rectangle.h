#pragma once

class Rectangle
{
private:
	int l_x;
	int l_y;
	int r_x;
	int r_y;
public:
	void setPl(int _x,int _y);
	void setPr(int _x,int _y);
	int getLx();
	int getLy();
	int getRx();
	int getRy();
	int getS();
};
