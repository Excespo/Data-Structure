#include <bits/stdc++.h>

using namespace std;

const int RED = 0, YELLOW = 1, BLUE = 2;

int main() {

    string input_line;
    while (getline(cin, input_line)){
        vector<int> count{0,0,0}; // 0-red, 1-yellow, 2-blue
        stack<int> expr;

        int len = input_line.size(), i = 0;
        while (i < len) {
            if (input_line[i] == '<') {
                if (input_line[i+1] == '/') {
                    expr.pop();
                }
                if (input_line[i+1] == 'r') {
                    expr.push(RED);
                }
                if (input_line[i+1] == 'y') {
                    expr.push(YELLOW);
                }
                if (input_line[i+1] == 'b') {
                    expr.push(BLUE);
                }
                while (input_line[i] != '>') {
                    i++;
                }
            // } else if (input_line[i] == ' ') {
                // i++; continue;
            } else {
                if (expr.empty()) {i++; continue;}
                count[expr.top()]++;
            }
            i++;
        }

        printf("%d %d %d\n", count[0], count[1], count[2]);
    }

    return 0;
}