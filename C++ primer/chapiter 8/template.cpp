#include <iostream>
#include <string>

using namespace std;

template <typename T>
void _swap(T &a, T &b); // function template

template void _swap<int>(int &, int &); // explicit instantiation

typedef struct {
    int age;
    string name;
} job_t;

template < > void _swap(job_t &job1, job_t &job2); // explicit specialization

int main(){
    int x = 1, y = 0;
    double z = 1.01, t = 2.2;
    printf("Before swap, x = %d, y = %d, z = %.1f, t = %.1f\n", x, y, z, t);
    // _swap<int>(x,y);
    _swap(x,y); // implicit instantiation
    _swap<double>(z,t); // explicit instantiationq
    printf("After  swap, x = %d, y = %d, z = %.1f, t = %.1f\n", x, y, z, t);

    job_t job1, job2;
    job1.age = 1; job1.name = "xn";
    job2.age = 10; job2.name = "g";
    printf("Before swap, job1 age = %d, name = %s, job2 age = %d, name = %s\n", job1.age, job1.name.c_str(), job2.age, job2.name.c_str());
    _swap(job1, job2);
    printf("After  swap, job1 age = %d, name = %s, job2 age = %d, name = %s\n", job1.age, job1.name.c_str(), job2.age, job2.name.c_str());
    return 0;
}

template <typename T>
void _swap(T &a, T &b){
    T tmp = b;
    b = a;
    a = tmp;
}

template < > void _swap(job_t &job1, job_t &job2){
    int tmp = job1.age;
    job1.age = job2.age;
    job2.age = tmp;
}