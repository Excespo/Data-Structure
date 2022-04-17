#include <iostream>
#include <vector>
#include <iterator>
#include <queue>

using namespace std;

int main () {
    vector<int> v{1,2,3,4,5}, vc;
    auto it = v.end();
    vc.assign(v.begin()+1, v.end());
    for (auto ele: vc) cout << ele << ". ";
    cout << endl;

    queue<int> q;
    for(int i=0; i<5; i++) q.push(i);
    for(int i=0; i<5; i++) {cout<<q.front(); cout<<q.back(); q.pop();}
    
}