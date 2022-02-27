#ifndef TIME_H_
#define TIME_H_

#include <iostream>

using std::ostream;

class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        // Time Sum(const Time & t) const;
        Time operator+(const Time & t) const;
        void Show() const;
        friend ostream & operator<<(ostream & os, const Time & t);
};

#endif