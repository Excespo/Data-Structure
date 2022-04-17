#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <iterator>
#include <utility>

using namespace std;
using tree = pair<vector<int>, vector<int>>;

int main() {

    vector<int> pre, in;
    string line;
    int n;
    getline(cin, line); stringstream ss1(line);
    while (ss1>>n) pre.push_back(n);
    getline(cin, line); stringstream ss2(line);
    while (ss2>>n) in.push_back(n);
    tree init(pre, in);
    
    for (auto ele: pre)
        cout<<ele<<". ";
    cout<<endl;
    for (auto ele: in)
        cout<<ele<<". ";
    cout<<endl;
    cout << pre.size() << ", " <<in.size() <<endl;
    cout << endl;

    queue<tree> q;
    q.push(init);
    // algo(q);

    while (!q.empty())
    {

        vector<int> pre = q.front().first;
        vector<int> in = q.front().second;
        q.pop();
        int root = pre.front();
        cout <<"Root is "<<root<<". ";
        cout << endl;
        if (pre.size()<=1) { continue; }

        

        // cout << "in: ";
        // for (auto ele: in)
        //     cout<<ele<<". ";
        // cout<<endl;

        // cout << "pre: ";
        // for (auto ele: pre)
        //     cout<<ele<<". ";
        // cout<<endl;

        auto it = in.begin(); int idx=0;
        while (*it != root) {it++; idx++;}
        // cout << "root in inoder at root, "<<*it<<" with idx= " <<idx<<". ";
        // cout << endl;

        vector<int> l_in, r_in, l_pre, r_pre;
        if (idx!=pre.size()-1) {
            r_in.assign(it+1, in.end());
            r_pre.assign(pre.begin()+idx+1, pre.end());
            tree rt(r_pre, r_in);
            q.push(rt);
        }
        if (idx!=0) {
            l_in.assign(in.begin(), it);
            l_pre.assign(pre.begin()+1, pre.begin()+idx+1);
            tree lt(l_pre, l_in);
            q.push(lt);
        } 
    }
    
    return 0;
}