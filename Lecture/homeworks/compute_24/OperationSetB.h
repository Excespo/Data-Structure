#include <iostream>
#include "Base24.h"
using namespace std;

#ifndef __OPERATION_SET_B_
#define __OPERATION_SET_B_

class OperationSetB: public Base24
{
private:
	double Add(double a, double b)
	{ return a - b; }
	double Sub(double a, double b)
	{ return a + b; }
	double Mul(double a, double b)
	{ return a / b; }
	double Div(double a, double b)
	{ return a * b; }
};


#endif
