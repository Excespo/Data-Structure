#include <iostream>
#include "time.h"

int main(){
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;
    
    cout << "fixing time = ";
    fixing.Show();
    cout << endl;
    
    total = coding + fixing;
    cout << "coding + fixing time = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);
    cout << "morefixing time = ";
    morefixing.Show();
    cout << endl;
    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;

    cout << "Total time: " << total << "(Tuesday)\n";

    return 0;
}

/* 
 * - compile with
 * g++ -c time.cpp usetime1.cpp && g++ -o usetime1.out time.o usetime1.o && ./usetime1.out
 */