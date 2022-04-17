#include <fstream>

#ifdef _GLIBCXX_FSTREAM
    #include <iostream> // no-use
    std::iostream coutf(NULL);
#endif

#include <string>

using namespace std;

int main () {
    fstream txt("test.txt");
    string line;
    while (getline(txt, line)) {
        for (char x: line) cout.put(x) << " ";
        cout << line << endl;
        coutf << "1";
    }
}