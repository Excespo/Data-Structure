#include <iostream>

using namespace std;

void swap(int &, int &);
void sum(int ele1, int ele2, int ele3 = 0);

int main(){
    int x = 0, y = 1;
    cout << "Before swap: x= " << x << ",y= " << y << endl;
    swap(x,y);
    cout << "After  swap: x= " << x << ",y= " << y << endl;
    sum(x,y);
    sum(x,y,1);
    return 0;
}

void swap (int &ele1, int &ele2) {
    int tmp = ele2;
    ele2 = ele1;
    ele1 = tmp;
}

void sum (int ele1, int ele2, int ele3) {
    cout << "sum of ele1, 2, 3(default 0) is " << ele1+ele2+ele3 <<endl;
}