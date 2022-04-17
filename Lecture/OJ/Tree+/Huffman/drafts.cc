#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
using ivec = vector<int>;
int const N_CHAR = (int)(0x7E - 0x20);

bool cmp(int x, int y) {return x>y;}

int main() {
    int N;
    string line;
    cin >> N; getchar(); getline(cin, line);

    int * freq = new int[N_CHAR];
    memset(freq, 0, sizeof (int) * N_CHAR);
    for (int i = 0; i < line.size(); ++i)
        freq[line[i]-0x20]++;

    vector<int> fq;
    for (int i = 0; i < N_CHAR; ++i) {
        if (freq[i] != 0) fq.push_back(freq[i]);
    }
    sort(fq.begin(),fq.end(),cmp);

    int len = 0;
    while (fq.size()>=2) {
        int n1 = fq.back(); fq.pop_back();
        int n2 = fq.back(); fq.pop_back();
        len += (n1+n2);
        fq.push_back(n1+n2);
        sort(fq.begin(),fq.end(),cmp);
    }

    cout << len << endl;
}