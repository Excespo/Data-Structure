#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    string input;
    int n;
    cin >> n;
    int count = 0;
    while (getline(cin, input)){
        
        vector<string> tokens;
        istringstream ss(input);
        string word;
        while(ss>>word) {
            tokens.push_back(word);
        }

        int retVal = 0;
        bool isoperator = false;
        stack<int> tokenStack;
        int tokensSize = tokens.size();
        
        bool flag = true;

        for(int index = 0; index < tokensSize; ++index)
        {   
            if (tokens[index] == "+." || tokens[index] == "-." || tokens[index] == "*." || tokens[index] == "/.")
                tokens[index] = "+";
            if (tokens[index] == "+" || tokens[index] == "-" || tokens[index] == "*" || tokens[index] == "/")
            {   
                if (tokenStack.size() <= 1) break;
                
                retVal = tokenStack.top();
                tokenStack.pop();
                switch(tokens[index][0])
                {
                    case '+':
                    {   
                        flag = false;
                        retVal += tokenStack.top();
                    }
                    break;
                    case '-':
                    {   
                        flag = false;
                        retVal = tokenStack.top() - retVal;
                    }
                    break;
                    case '*':
                    {   
                        flag = false;
                        retVal *= tokenStack.top();
                    }
                    break;
                    case '/':
                    {   
                        if (retVal == 0) {break;}
                        flag = false;
                        retVal = tokenStack.top() / retVal;
                    }
                    break;
                    default:
                    break;
                }
                tokenStack.pop();
                tokenStack.push(retVal); 
            }
            else
            {
                tokenStack.push(atoi(tokens[index].c_str()));
            }
        }

        count += 1;
        if (count != 1){
            if (flag) cout << "err" << endl;
            else cout << tokenStack.top() << endl;
        }

        if (count > n) break;
        
    }

    
    return 0;
}