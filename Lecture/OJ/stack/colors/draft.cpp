#include <bits/stdc++.h>

using namespace std;

const int RED = 0, YELLOW = 1, BLUE = 2;

int main() {

    string input_line;
    getline(cin, input_line);
    vector<int> count{0,0,0}; // 0-red, 1-yellow, 2-blue
    stack<int> expr;

    int len = input_line.size(), i = 0;
    while (i < len) {
        // < begins, parse colors
        if (input_line[i] == '<') {
            cout << "i = " << i << " , < begins with next char is: " << input_line[i+1] << endl;
            // i++;
            // meet </color>, end last color
            if (input_line[i+1] == '/') {
                expr.pop();
            }
            // meet <color>
            if (input_line[i+1] == 'r') {
                expr.push(RED);
            }
            if (input_line[i+1] == 'y') {
                expr.push(YELLOW);
            }
            if (input_line[i+1] == 'b') {
                expr.push(BLUE);
            }
            // else cout << "ELSE" << endl;
            // move to > ends
            while (input_line[i] != '>') {
                i++;
            }
            cout << "i = " << i << " , > ends with next char is: " << input_line[i+1] << endl;
        }// traverse chars
        else if (input_line[i] == ' ') {
            i++; continue;
        }
        else {
            if (expr.empty()) {cout<<"expr is empty at char:"<<input_line[i]<<endl;i++; continue;}
            // if (expr.empty()) cout<<"EMPTY"<<endl;
            count[expr.top()]++;
            cout << "Go over char:" << input_line[i] << " Stack top is " << expr.top() << " with count " <<  count[expr.top()] << endl;
        }
        i++;
    }

    printf("%d %d %d\n", count[0], count[1], count[2]);

    return 0;
}