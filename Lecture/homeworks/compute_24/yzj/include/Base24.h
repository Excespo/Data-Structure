#include <iostream>
#include "BaseOperations.h"
using namespace std;

#ifndef __BASE_24_
#define __BASE_24_

class Base24: public BaseOperations
{
private:
	virtual double Add(double, double) = 0;
	virtual double Sub(double, double) = 0;
	virtual double Mul(double, double) = 0;
	virtual double Div(double, double) = 0;

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
