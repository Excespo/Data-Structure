#include<iostream>
#include<cmath> // sometimes use -lm to compile

using namespace std;

#define pi M_PI

int main(){
    cout << "Give x and y: ";
    double x, y;
    cin >> x >> y;
    cout << "arctan is: " << atan2(y,x)/pi*180 << " degrees" << endl;
    return 0;
}