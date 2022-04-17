#include <iostream>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;

int main() {

    string inputline;
    list<int> postorder;
    int father, child;

    while(getline(cin, inputline)) {
        stringstream line(inputline);
        line.ignore(1); line >> father;
        line.ignore(2); line >> child;

        if (postorder.empty())
            postorder.push_back(father);
        if (child == 0)
            continue;
        
        auto it = postorder.end();
        while (*(--it) != father) continue;
        postorder.insert(it, child);
    }

    for (auto ele: postorder)
        cout << ele << " ";
    cout << endl;
    
    return 0;
}