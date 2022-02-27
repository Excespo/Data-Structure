#include <iostream>
#include "stock.h"

int main(){
    { // big kuohao leads to a call of destructor function when code runs out this big kuohao
        using std::cout;
        using std::endl;
        cout << "Using constrcutors to create new object" << endl;
        // syntax 1
        Stock stock1("NanoSmart", 12, 20.0);
        stock1.show();
        // syntax 2
        Stock stock2 = Stock("Boffo Objects", 2, 2.0);
        stock2.show();
        /* 
         * - initialize with
         *  1 Stock stock = Stock(args)
         *  2 Stock stock(args)
         *  3 Stock *stock_ptr = new Stock(args)
         *  4 use C++11, 
         *      Stock stock = {args}
         */

        cout << "Assigning stock1 to stock2:" << endl;
        stock2 = stock1;
        cout << "Listing stock and stock2:" << endl;
        stock1.show();
        stock2.show();

        cout << "Using a constrctor to reset an object" << endl;
        stock1 = Stock("Nifty Foods", 10, 50.0);
        cout << "Revised stock1:" << endl;
        stock1.show();
        cout << "Done." << endl;

    }
    return 0;
}

/* 
 * Compile under working directory with
 * g++ -c stock.cpp usestock.cpp && g++ -o usestock.out stock.o usestock.o && ./usestock.out
 */