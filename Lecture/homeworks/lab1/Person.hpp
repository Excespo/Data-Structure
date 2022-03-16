#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>
#include <memory>

// typedef enum {MALE, FEMALE} sex_t;
using std::string;

namespace sjtu{

    class Person {
        public:
            /* constructor & destructor */
            Person(){
                std::cout << "A person created defaultly." << std::endl;
                m_name = "";
                m_age = -1;
                m_number = 0;
                m_email = "";
            }
            Person(string && name, int && age, ulong && number, string && email) {
                std::cout << "A person created with params." << std::endl;
                m_name = name;
                m_age = age;
                m_number = number;
                m_email = email;
            }
            ~Person(){std::cout << "A person killed." << std::endl;};
            /* interface */
            virtual void setName(const string &) = 0;
            virtual void setAge(const int &) = 0;
            virtual void setNumber(const ulong &) = 0;
            virtual void setEmail(const string &) = 0;
            virtual void print_info() = 0;
            // virtual void operator<<() = 0;
            // virtual friend std::ostream & operator<< () =0;


        protected:
            string m_name;
            int m_age;
            unsigned long m_number;
            string m_email;

    };

}


#endif