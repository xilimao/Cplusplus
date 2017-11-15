#include "tree.h"
#include <iostream>
using namespace std;
void tree::setAges(int age)
{
	ages = age;
}
void tree::grow(int years)
{
	ages = ages + years;
}
void tree::age()
{
	cout<<"age: "<<ages<<endl;
}