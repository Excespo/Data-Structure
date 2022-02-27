#ifndef __STUDENTC_H
#define __STUDENTC_H

#include <iostream>
#include <string>
#include <valarray>

class Student
{
    private:
        typedef std::valarray<double> ArrayDb;
        std::string name;
        ArrayDb scores;
        // private method for scores output
        std::ostream & arr_out(std::ostream & os) const;
    public:
        Student(): name("Null Student"), scores() {}
        explicit Student(const std::string & s)
            : name(s), scores() {}
        explicit Student(const int n): name("Nully"), scores(n) {}
        Student (const std::string & s, int n)
            : name(s), scores(n) {}
        Student (const std::string & s, ArrayDb a)
            : name(s), scores(a) {}
        Student (const char *str, const double *pd, int n)
            : name(str), scores(pd, n) {}
        virtual ~Student() {}
        double Average() const;
        const std::string & Name() const;
        double & operator[] (int i);
        double operator[] (int i) const;

}

#endif