#include <iostream>

using namespace std;

void print(int);
void print(double);

int main(){
    print(1);
    print(1.222);
    return 0;
}

void print(int x){
    printf("Integer %d\n", x);
}

void print(double f){
    printf("Float %.2f\n", f);
}