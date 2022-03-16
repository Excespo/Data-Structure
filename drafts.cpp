#include <bits/stdc++.h>

using std::vector;

typedef vector < vector <double> >  darray;

template <typename T> class father{
public:
    virtual void method1(const T&) = 0;
    virtual void method2(T&&) = 0;
private:
    T m_data;
};

template <typename T> class son: public father<T>{
public:
    void method1(const T& data) {std::cout << m_son_data << ", " << data << std::endl;}
    void method2(T&& data) {std::cout << data << ", " << m_son_data << std::endl;}
    son(T data): m_son_data(data) {};
private:
    T m_son_data;
};

class TestTool
{
    private:
        clock_t sTime;
        clock_t eTime;

    public:
        void countS() {sTime = clock();};
        void countE() {eTime = clock();};
        void operator() (){
            std::cout << "Use time: " << double(eTime-sTime)/CLOCKS_PER_SEC << "s" << std::endl;
        }
};

int main(int argc, char **argv){

    TestTool tt;
    tt.countS();
    /* Draft code begins */

    class son<int> child(1);
    int d = 2;
    child.method1(d);
    child.method2(7);
    child.method1(5);
    child.method2(std::move(5));

    std::string s1 = "";

    std::cout << s1 << std::endl;
    std::stack<int> stk({1});
    stk.push(2);
    stk.pop();
    int elem = stk.top();
    std::cout << elem << std::endl;
    // char s2 = s1[0];
    // std::cout << s1.c_str() << s2 << (s2=='n') << (s2=="n") << std::endl;

    /* Draft code ends */
    tt.countE();
    tt();
    return 0;
}