#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <iterator>
#include <utility>

using namespace std;
using tree = pair<vector<int>, vector<int>>;

/**
 * @brief Do main recursion
 *
 * @return cout result
 * 
 */
int main() {

    vector<int> pre, in;
    string line;
    int n;
    getline(cin, line); stringstream ss1(line);
    while (ss1>>n) pre.push_back(n);
    getline(cin, line); stringstream ss2(line);
    while (ss2>>n) in.push_back(n);

    tree init(pre, in);
    queue<tree> q; q.push(init);

    while (!q.empty())
    {

        vector<int> pre = q.front().first;
        vector<int> in = q.front().second;
        cout << pre.front() << " ";
        q.pop();
        
        if (pre.size()<=1) 
            continue;

        auto it = in.begin();
        int idx=0;
        while (*it != pre.front()) {it++; idx++;}

        if (idx!=pre.size()-1) {
            vector<int> r_in, r_pre;
            r_in.assign(it+1, in.end());
            r_pre.assign(pre.begin()+idx+1, pre.end());
            tree rt(r_pre, r_in);
            q.push(rt);
        }
        if (idx!=0) {
            vector<int> l_in, l_pre;
            l_in.assign(in.begin(), it);
            l_pre.assign(pre.begin()+1, pre.begin()+idx+1);
            tree lt(l_pre, l_in);
            q.push(lt);
        } 
    }
    cout << endl;
    
    return 0;
}