
#ifndef __BASE_OPERATIONS_
#define __BASE_OPERATIONS_

class BaseOperations
{
private:
	virtual double Add(double, double) = 0;
	virtual double Sub(double, double) = 0;
	virtual double Mul(double, double) = 0;
	virtual double Div(double, double) = 0;
public:
	virtual int Read() = 0;
	virtual int Display() = 0;
};

#endif
