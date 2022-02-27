#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <string>

class Stock
{
    private:
        std::string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot() {total_val = shares * share_val;} // definition of member function inside class declaration means that this function is defaultly set to inline.
    public:
        Stock();
        Stock(const std::string &co, long n = 0, double pr =0.0); // cannot use a same name for member var (here company) with formal arg (here co). Otherwise co = co, assignment failed.
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show() const;
        const Stock & topval(const Stock & s) const; // the last const promises not to change invoking object.
};

#endif