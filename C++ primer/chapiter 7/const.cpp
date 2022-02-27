#include <iostream>

using namespace std;

int main(){
    int v1 = 1, v2 = 2;
    const int* ptr1 = &v1;
    int* ptr2;
    // *ptr1 = 4;
    *ptr2 = 5;
    v1 = 3;
    // ptr1 = &v2;
    cout << *ptr1 << " " << *ptr2 << endl;
    return 0;
}