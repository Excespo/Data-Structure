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
        cout << lines++ << "turns. ";
        // read line
        getline(cin, input_line);
        vector<string> tokens = tokenize(input_line);

        // read a single digit, change stack state if train len is not 1
        cout << tokens.size() << " size, " << set << " is the set flg" << endl;
        if (tokens.size()==1 && set!=1) {
            if (!set){
                if (!stoi(tokens[0])) break;// not set and meet 0, exit
                set = stoi(tokens[0]); cout<<"set!"<<endl;continue; // not set and meet train length, set
            }
            cout << "---" << endl; set = stol(tokens[0]); continue; cout<<"next"<<endl;// set and meet 0, end case
        }

        // go backward to the station, in reverse order
        int n = set, i = 0, flag = 1;
        while (i < set) {
            while (!station.empty() && station.top()==n) {station.pop(); n--;cout<<"poped"<<endl; cout<<"Now n = "<<n<<", top = "<<station.top()<<endl;}
            station.push(stoi(tokens[set-1-i]));
            i++;
            cout<<"Now n = "<<n<<", top = "<<station.top()<<endl;
            if (station.top()==n) {station.pop(); n--;cout<<"poped"<<endl; cout<<"Now n = "<<n<<", top = "<<station.top()<<endl;}
        }
        cout << "IN STACK ends." << endl;
        // if (!station.empty()) flag = 0;

        // the rest part go backward
        while (n) {
        cout<<"Now n="<<n<<"top="<<station.top()<<endl;
            if (station.top()!=n) {
                cout << "Bad." <<endl;
                flag = 0; break;
            }
            station.pop();
            cout << "poped" <<endl; cout<<"Now n = "<<n<<", top = "<<station.top()<<endl;
            n--;
        }

        if (!flag) { cout << "No--------------" << endl; continue; }
        cout << "Yes-----------------" << endl; continue;
    }

    return 0;
}