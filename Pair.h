#pragma once
#include <iostream>
using namespace std;
class Pair
{
	int _INT;
	double _DOUBLE;
public:
	//constructors
	Pair()
	{
		_INT = 0;
		_DOUBLE = 0;
	}
	Pair(int _INT, double _DOUBLE)
	{
		this->_INT = _INT;
		this->_DOUBLE = _DOUBLE;
	}
	Pair(const Pair& P)
	{
		_INT = P._INT;
		_DOUBLE = P._DOUBLE;
	}
	//methods
	void Show()
	{
		cout << this->_INT << " : " << this->_DOUBLE << endl;
	}
	void Set_int(int a)
	{
		_INT = a;
	}
	void Set_double(double a)
	{
		_DOUBLE = a;
	}
	//overloads
	Pair operator+(int constant);
	Pair operator+(double constant);
	Pair operator-(Pair arg);
	void operator-=(Pair arg1);
	void operator +=(int constant);
	void operator +=(double constant);
	//destructor
	~Pair() {};
};
Pair Pair::operator+(int constant)
{
	return Pair(_INT + constant, _DOUBLE);
}
Pair Pair::operator+(double constant)
{
	return Pair(_INT, _DOUBLE + constant);
}
Pair Pair::operator-(Pair arg)
{
	return Pair(_INT - arg._INT, _DOUBLE - arg._DOUBLE);
}
void Pair::operator-=(Pair arg)
{
	_INT = _INT - arg._INT;
	_DOUBLE = _DOUBLE - arg._DOUBLE;
}
void Pair::operator +=(int constant)
{
	_INT = _INT + constant;
}
void Pair::operator +=(double constant)
{
	_DOUBLE = _DOUBLE + constant;
}
