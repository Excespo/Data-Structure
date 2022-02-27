#include<iostream>

using namespace std;

void estimate(int, double (*)(int));
double func(int);
double (*fptr)(int);

typedef double (*p_f)(int);

int main(){
    fptr = func;
    p_f fptr2 = func;
    estimate(5, fptr);
    estimate(5, fptr2);
    cout << (*fptr)(1) << " " << fptr(1) << endl;
    return 0;
}

void estimate(int lines, double (*func_ptr)(int)) {
    cout << "This function uses " << (double)5*lines/1000 << " seconds.\n";
}

double func(int x){
    ;
    ;
    ;
    ;
    return (double)x/2;
}