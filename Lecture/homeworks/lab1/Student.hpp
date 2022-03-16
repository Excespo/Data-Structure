#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

namespace sjtu{

    class Student: virtual public sjtu::Person {
        public:
            // constructor & destructor
            Student();
            Student(const string & name, const int & age, const ulong & number, const string & email, const int & _class); // const lvalue ref or rvalue ref
            ~Student() {std::cout<<"A student killed." << std::endl;}
            // setter
            void setName(const string & name) {m_name = name;}
            void setAge(const int & age) {m_age = age;}
            void setNumber(const ulong & number) {m_number = number;}
            void setEmail(const string & email) {m_email = email;}
            void setClass(const int & _class) {m_class = _class;}

            // getter
            void print_info();
            // operators
            bool operator== (const Student & stu) { return m_number==stu.m_number;}
            friend std::ostream & operator >> (std::ostream & os, const Student & stu);
            friend std::ostream & operator << (std::ostream & os, const Student & stu);

        protected:
            int m_class;
    };

}

#endif