###  MyString类的实现

> MyString.h
>
> ```
> #include <iostream>
> using namespace std;
>
> //c中没有字符串   字符串类(c风格的字符串类)
> //空串   “”
> class MyString
> {
> 	friend ostream& operator<<(ostream &out,MyString &s);
> 	friend istream& operator>>(istream &in,MyString &s);
> public:
> 	MyString(int len = 0);
> 	MyString(const char *p);
> 	MyString(const MyString& s);
> 	~MyString();
>
> public:
> 	//重载 = 号 操作符
> 	MyString& operator=(const char *p);
> 	MyString& operator=(const MyString &s);
>
> 	char& operator[] (int index);
>
> public:
> 	//重载==  !=
> 	bool operator==(const char*p) const;
> 	bool operator==(const MyString &s) const;
> 	bool operator!=(const char*p) const;
> 	bool operator!=(const MyString &s) const;//加const this指针不能改变
>
> public:
> 	//重载 > <
> 	int operator<(const char*p);
> 	int operator>(const char*p);
> 	int operator<(const MyString& s);
> 	int operator>(const MyString& s);
>
> public:
> 	//把类的指针漏出来
> 	char *c_str()
> 	{
> 		return m_p;
> 	}
> 	const char *c_str2()
> 	{
> 		return m_p;
> 	}
> 	int length()
> 	{
> 		return m_len;
> 	}
>
> private: 
> 	int m_len;
> 	char *m_p;
> };
> ```


> MyString.cpp
>
> ```
> #include "MyString.h"
>
> //重载 <<  >>
> ostream& operator<<(ostream &out,MyString &s)
> {
> 	out<<s.m_p;
> 	return out;
> }
>
> istream& operator>>(istream &in,MyString &s)
> {
> 	cin>> s.m_p;
> 	return in;
> }
>
> //有参构造函数
> MyString::MyString(int len)
> {
> 	if (len == 0)
> 	{
> 		m_len = 0;
> 		m_p = new char[m_len + 1];
> 		strcpy(m_p,"");
> 	} 
> 	else
> 	{
> 		m_len = len;
> 		m_p = new char[m_len + 1];
> 		//strcpy(m_p,"");
> 		memset(m_p , 0 ,m_len);
> 	}
> }
>
> MyString::MyString(const char *p)
> {
> 	if (p == NULL)
> 	{
> 		m_len = 0;
> 		m_p = new char[m_len + 1];
> 		strcpy(m_p , "");
> 	}
> 	else
> 	{
> 		m_len = strlen(p);
> 		m_p = new char[m_len + 1];
> 		strcpy(m_p,p);
> 	}
> }
> //copy构造函数
> MyString::MyString(const MyString& s)
> {
> 	m_len = s.m_len;
> 	m_p = new char[m_len + 1];
> 	strcpy(m_p,s.m_p);
> }
> MyString::~MyString()
> {
> 	if (m_p != NULL)
> 	{
> 		delete [] m_p;
> 		m_p = NULL;
> 		m_len = 0;
> 	}
> }
>
>
> //s4 = "s2222"
> MyString& MyString::operator=(const char *p)
> {
> 	//1.释放就内存
> 	if (m_p != NULL)
> 	{
> 		delete [] m_p;
> 		m_len = 0;
> 	} 
>
> 	//根据p分配内存
> 	if (p == NULL)
> 	{
> 		m_len = 90;
> 		m_p = new char[m_len + 1];
> 		strcpy(m_p,"");
> 	} 
> 	else
> 	{
> 		m_len = strlen(p);
> 		m_p = new char[m_len + 1];
> 		strcpy(m_p,p);
> 	}
> 	return *this;
> }
> //s4 = s2;
> MyString& MyString::operator=(const MyString &s)
> {
> 	//1.释放就内存
> 	if (m_p != NULL)
> 	{
> 		delete [] m_p;
> 		m_len = 0;
> 	} 
>
> 	//根据s分配内存
>
> 	m_len = s.m_len;
> 	m_p = new char[m_len + 1];
> 	strcpy(m_p,s.m_p);
>
> 	return *this;
> }
>
> char& MyString::operator[] (int index)
> {
>
> 	return m_p[index];
> }
>
>
> //if (s2 == "s2")
> bool MyString::operator==(const char*p) const
> {
> 	//如果P是空的
> 	if (p == NULL)
> 	{
> 		//如果 自身长度为0 ，那么相等
> 		if (m_len == 0)
> 		{
> 			return true;
> 		}
> 		else
> 		{
> 			return false;
> 		}
>
> 	} 
> 	else
> 	{
> 		//如果自身的长度与p的长度相同
> 		if (m_len == strlen(p))
> 		{
> 			return !strcmp(m_p,p);
> 		} 
> 		else
> 		{
> 			return false;
> 		}
> 	}
> }
>
> bool MyString::operator!=(const char*p) const
> {
> 	return !(*this == p);
> }
>
> //if (s3 == s2)
> bool MyString::operator==(const MyString &s) const
> {
> 	if (m_len != s.m_len)
> 	{
> 		return false;
> 	} 
>
> 	return !strcmp(m_p,s.m_p);
> }
>
> bool MyString::operator!=(const MyString &s) const
> {
> 	return !(*this == s);
> }
>
> //if (s3 < "bbbb")
> int MyString::operator<(const char*p)
> {
> 	return strcmp(this->m_p , p);
> }
> //if (s3 > "bbbb")
> int MyString::operator>(const char*p)
> {
> 	return strcmp(p,this->m_p);
> }
> int MyString::operator<(const MyString& s)
> {
> 	return strcmp(this->m_p,s.m_p);
> }
> int MyString::operator>(const MyString& s)
> {
> 	return strcmp(s.m_p,this->m_p);
>
> }
> ```


> testMyString.cpp
>
> ```
> #include <iostream>
> using namespace std;
> #include "MyString.h"
>
> void main01()
> {
> 	MyString s1;
> 	MyString s2("s2");
> 	MyString s2_2 = NULL;
> 	MyString s3 = s2;
>
> 	MyString s4 = "s444444444";
> 	//测试运算符重载 和 重载[]
> 	//
> 	s4 = s2;
> 	s4 = "s2222";
> 	//MyString& operator=(const char *p);
> 	//MyString& operator=(const MyString &s);
>
> 	//s4[0];
> 	//char& operator[] (int index);
> 	s4[1] = '4';
> 	cout<<s4<<endl;
> 	//MyString& operator<<(ostream &out,MyString &s);
>
> 	cout<<"hello wordl"<<endl;
> 	system("pause");
> }
>
> void main02()
> {
> 	MyString s1;
> 	MyString s2("s2");
> 	MyString s3 = s2;
>
> 	//bool operator==(const char*p);
> 	//bool operator==(const MyString &s);
> 	//bool operator!=(const char*p);
> 	//bool operator!=(const MyString &s);
>
> 	if (s2 == "s2")
> 	{
> 		printf("相等");
> 	}
> 	else
> 	{
> 		cout<<"不相等"<<endl;
> 	}
>
> 	if (s3 == s2)
> 	{
> 		cout<<"相等"<<endl;
> 	} 
> 	else
> 	{
> 		cout<<"不相等"<<endl;
> 	}
>
> 	system("pause");
> }
>
> void main03()
> {
> 	MyString s1;
> 	MyString s2("s2");
> 	MyString s3 = s2;
> 	s3 = "aaa";
>
> 	/*
> 	int operator<(const char*p);
> 	int operator>(const char*p);
> 	int operator<(const MyString& s);
> 	int operator>(const MyString& s);
> 	*/
>
> 	int tag = (s3 < "bbb");
> 	if (tag < 0)
> 	{
> 		cout<<"s3 < bbb"<<endl;
> 	}
> 	else
> 	{
> 		cout<<"s3 > bbb"<<endl;
> 	}
>
> 	if (s3 < s2)
> 	{
> 		cout<<"s3 < s2"<<endl;
> 	}
> 	else
> 	{
> 		cout<<"s3 > s2"<<endl;
> 	}
>
>
> 	MyString s4 = "dfsfsfe";
> 	strcpy(s4.c_str(),"aadasdsd");
> 	cout<<s4<<endl;
> 	system("pause");
>
> }
>
> void main()
> {
> 	MyString s1(128);
> 	cin >> s1;
> 	cout<<s1<<endl;
> 	//istream& operator>>(istream &in,MyString &s);
>
> 	system("pause");
> }
> ```

