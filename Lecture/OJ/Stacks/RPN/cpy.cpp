#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <iterator>

using namespace std;

vector<string> tokenize(string &input_line)
{
    istringstream iss(input_line);
    vector<string> tokens((istream_iterator<string>(iss)), istream_iterator<string>());
    return tokens;
}

bool isNum(string str)  
{  
    stringstream sin(str);  
    double d;  
    char c;  
    if(!(sin >> d)){return false;}
    if (sin >> c) {return false;}  
    return true;  
} 

int main()
{
    int N;
    string line;
    cin >> N;
    getchar();
    // cout << N << endl;

    for (int i = 0; i < N; ++i)
    {
        getline(cin, line);
        // cout << line;
        vector<string> tokens = tokenize(line);
        // cout << " ,size= " << tokens.size() << endl;
        stack<int> expr;

        for (int j = 0; j < tokens.size(); ++j)
        {
            string token = tokens[j];

            if (isNum(token)) {
                expr.push(stoi(token));
            }
            else {
                if (expr.empty()) continue;
                int num1 = expr.top();
                expr.pop();
                if (expr.empty()) continue;
                int num2 = expr.top();
                expr.pop();
                if (*token.c_str() == '+') {expr.push(num2 + num1);}
                if (*token.c_str() == '-') {expr.push(num2 - num1);}
                if (*token.c_str() == '*') {expr.push(num2 * num1);}
                if (*token.c_str() == '/') {
                    if (!num1) continue;
                    expr.push(num2 / num1);
                    }
            }
        }
        if (expr.size()!=1) {cout << "err" << endl; continue;}
        cout << expr.top() << endl;
    }
    return 0;
}