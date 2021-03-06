#include <bits/stdc++.h>
#include <unistd.h>

using std::vector;
using intptr = int*;

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

// lvalue reference
int test_ref1(int & num) { return num; }
int test_ref2(int const & num) { return num; }
int test_ref3(int && num) { return num; }

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

    // open draft.txt and write
    std::fstream outfile;
    outfile.open("1.txt", std::ios_base::in);
    if (outfile.is_open()) std::cout << 1;
    for (int i = 0; i < 10; i++) outfile << '2';
    // pause(); // system("pause");
    outfile << '4';
    
    char state[] = "Eu23";
    long val = 560031841;
    std::cout.setf(std::ios_base::boolalpha);
    (std::cout.write(state,2) << " 1" ).write( (char*) &val, sizeof(long)) << true << std::endl;
    outfile.close();

    // intptr
    int arr_0[] = {1,2,3,4};
    intptr arr_1 = arr_0;
    std::cout << arr_1[0] << std::endl;

    // l/r value reference
    int _num = 1;
    // std::cout << test_ref1(1) << std::endl; // invalid
    std::cout << test_ref2(1) << std::endl; // valid
    std::cout << test_ref3(1) << std::endl; // valid
    std::cout << test_ref1(_num) << std::endl; // valid
    std::cout << test_ref2(_num) << std::endl; // valid
    // std::cout << test_ref3(_num) << std::endl; // invalid

    //map
    std::map<std::string, int> s2idx;
    s2idx["Shanghai"] = 1;
    s2idx["Xneng"] = 0;
    std::map<std::string, int>::iterator iter;
    for (iter = s2idx.begin(); iter != s2idx.end(); ++iter) {
        std::cout << iter->first << " : " << iter->second << "\n";
    }

    //pair
    std::pair<int, int> p1(1, 3);
    std::cout << p1.first << " , " << p1.second << "\n";
    std::pair<std::pair<int, int>, int> p2 = {p1, 2};
    std::cout << p2.first.first << " , " << p2.first.second << " , " << p2.second << "\n";

    //
    using ivec1 = std::vector<int>;
    using ivec2 = std::vector<ivec1>;
    ivec2 a;
    if (a.empty())
        a.push_back(ivec1({1, 2}));
    // std::cout << a.size() << " " << a[0].size();
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "ivec test\n";

    /* Draft code ends */
    tt.countE();
    tt();
    return 0;
}
