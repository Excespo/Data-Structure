#include <bits/stdc++.h>

using std::vector;

typedef vector < vector <double> >  darray;

class TestTool
{
    private:
        clock_t sTime;
        clock_t eTime;

    public:
        void countS() {sTime = clock();};
        void countE() {sTime = clock();};
        void operator() (){
            std::cout << "Use time: " << double(eTime-sTime)/CLOCKS_PER_SEC << "s" << std::endl;
        }
};

int main(int argc, char **argv){

    TestTool tt;
    /* Draft code begins */

    

    /* Draft code ends */
    tt();

    return 0;
}