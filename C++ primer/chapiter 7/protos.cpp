#include <iostream>
#include <cstdarg> // va_list 可变参数

void cheers(int);
double cube(double);
int sum (int, double, ...);

int main(){
    using namespace std;
    cheers(5);
    cout << "Give me a number: ";
    double side;
    cin >> side;
    double volume = cube(side);
    cout << "A " << side << "-foot cube has a volume of " << volume << " cubic feet.\n";
    cheers(cube(2));
    cout << "Give me x: ";
    double x;
    cin >> x;
    cout << "3 times side plus x is: " << sum(3,x,side,side,side) << endl;
    return 0;
}

void cheers(int n){
    using namespace std;
    for (int i = 0; i < n; ++i) {
        cout << "Cheers! ";
    }
    cout << endl;
}

double cube(double x){
    return x*x*x;
}

int sum(int n, double x, ...){
	va_list arg_ptr;
	va_start(arg_ptr, x);

	int CountSum = 0;
	for (int i = 0; i < n; ++i)
	{
		CountSum += va_arg(arg_ptr, double);
	}
	va_end(arg_ptr);

	return CountSum+x;
}