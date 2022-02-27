#include <iostream>
#include "BaseOperations.h"
using namespace std;

#ifndef __BASE_24_
#define __BASE_24_

class Base24: public BaseOperations
{
private:
	double Add(double, double){}
	double Sub(double, double){}
	double Mul(double, double){}
	double Div(double, double){}

	double num[4];
	/*
	 *
	 *
	 *
	 *
	 */
public:
	int Read();
	int Display();
};

#endif
