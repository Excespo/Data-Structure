#include "Student.hpp"

namespace sjtu {

    Student::Student()
    {
        std::cout << "A student created defaultly." << std::endl;
        m_name = "";
        m_age = -1;
        m_number = 0;
        m_email = "";
        m_class = -1;
    }

    
    Student::Student(const string & name, const int & age = -1, const ulong & number = 0, const string & email = "", const int & _class = -1)
    {
        std::cout << "A student created with params." << std::endl;
        m_name = name;
        m_age = age;
        m_number = number;
        m_email = email;
        m_class = _class;
    }

    void Student::print_info() {
        using std::cout;
        using std::endl;
        cout << "Student name: " << m_name;
        cout << ", age:" << m_age;
        cout << ", id:" << m_number;
        cout << ", email:" << m_email;
        cout << ", class:" << m_class;
        cout << endl;
    }

    std::ostream& operator>>(std::ostream& os, const sjtu::Student& stu) {
        os << "name: " << stu.m_name << " ,age: " << stu.m_age << ". ";
        return os;
    }

    std::ostream& operator<<(std::ostream& os, const sjtu::Student& stu) {
        os << "name: " << stu.m_name << " ,age: " << stu.m_age << ". ";
        return os;
    }
}



// int main() {
//     sjtu::Student jeff("Jefferson", 3, 51111111, "jeff@sjtu.edu.cn", 2);
//     jeff.print_info();
//     std::cout << jeff << std::endl;

//     return 1;
// }