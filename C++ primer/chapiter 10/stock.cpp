#include <iostream>
#include "stock.h"

Stock::Stock() // default constructor
{
    std::cout << "Default constructor called" << std::endl;
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
    std::cout << "Constructor using " << co << " called" << std::endl;
    company = co;
    
    if (n < 0) {
        std::cout << "Numbers of shares can't be negative; "
                    << company << "shares set to 0." << std::endl;
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock() // verbose class destructor
{
    std::cout << "Bye, " << company << "!\n";
}

void Stock::buy(long num, double price)
{
    if (num < 0) {
        std::cout << "Numbers of shares purchased can't be negative. "
                    << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0) {
        std::cout << "Numbers of shares sold can't be negative. "
                    << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }

}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    using std::cout;
    using std::ios_base;

    // set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company 
        << " Shares: " << shares << std::endl;
    cout << "  Share Price: $" << share_val;
    
    // set format to #.##
    cout.precision(2);
    cout << "  Total Worth $" << total_val << std::endl;

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s; // argument object
    else
        return *this; // invoking object 
}
