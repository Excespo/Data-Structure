#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

typedef enum {UNKNOWN, PRIMARY, MIDDLE, HIGH} level_t;

namespace sjtu {
    
    class Professor: public sjtu::Person {
        public:
            Professor():
                m_name(""), m_age(-1), m_number(-1), m_email(""), m_level(UNKNOWN) {}
            Professor(string & name, int & age, ulong & number, string & email, level_t & level):
                m_name(name), m_age(age), m_number(number), m_email(email), m_level(level) {}
            ~Professor() {std::cout<<"A prof killed." << std::endl;}
        protected:

        private:
            level_t m_level;
    };


}

#endif