#include <bits/stdc++.h>

inline double square(double x) {return x*x;}

using namespace std;

int main(){
    double a, b;
    double c = 13.0;

    a = square(5);
    /* inline func provide a similar but more safe way as `#define` macro */
    /* can take expression as args */
    b = square(4.5+7.5);
    cout << "a= " << a << ", b= " << b << endl;
    cout << "c= " << c;
    cout << ", c squared = " << square(c++) << endl;
    cout << "Now c= " << c << endl;

    return 0;
}