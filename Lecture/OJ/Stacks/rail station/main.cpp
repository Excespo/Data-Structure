#include <bits/stdc++.h>

using namespace std;

vector<string> tokenize(string& input_line) {
    istringstream iss(input_line);
    vector<string> tokens((istream_iterator<string>(iss)), istream_iterator<string>());
    return tokens;
}

int main () {

    int set = 0;
    string input_line;
    stack<int> station;
    int lines = 0;

    while (true) { // while !cin.eof()
        getline(cin, input_line);
        vector<string> tokens = tokenize(input_line);

        if (tokens.size()==1 && set!=1) {
            if (!set){
                if (!stoi(tokens[0])) break;
                set = stoi(tokens[0]); continue;
            }
            cout << "---" << endl; set = stol(tokens[0]); continue;
        }

        if (tokens.size()==1 && set==1){
            set = stoi(tokens[0]);
            if (!set) cout << "---" << endl;
            else cout << "Yes" << endl;
            continue;
        } 

        int n = set, i = 0, flag = 1;
        while (i < set) {
            while (!station.empty() && station.top()==n) {station.pop(); n--;}
            station.push(stoi(tokens[set-1-i]));
            i++;
            if (station.top()==n) {station.pop(); n--;}
        }

        while (n) {
            if (station.top()!=n) {
                flag = 0; break;
            }
            station.pop();
            n--;
        }

        if (!flag) { cout << "No" << endl; continue; }
        cout << "Yes" << endl; continue;
    }

    return 0;
}