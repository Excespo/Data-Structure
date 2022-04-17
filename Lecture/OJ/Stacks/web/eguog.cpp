#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    stack<string> s_for;
    stack<string> s_back;

    string input;
    string visit;
    string website;
    string command;

    for (int i = 0; i < n; i++){
        string now = "http://www.sjtu.edu.cn/";
        
        while (getline(cin, input)){
            if (input == "QUIT") {
                while(!s_for.empty()) s_for.pop();
                while(!s_back.empty()) s_back.pop();
                break;
            }
            visit = input.substr(0, 5);
            if (visit == "VISIT"){
                s_back.push(now);
                website = input.substr(6);
                now = website;
                while(!s_for.empty()) s_for.pop();
                cout << website << endl;

            }

            if (input == "BACK"){
                if (s_back.empty()) cout << "Ignored" << endl;
                else{
                    s_for.push(now);
                    now = s_back.top();
                    cout << now << endl;
                    s_back.pop(); 
                }

            }

            if (input == "FORWARD"){
                
                if (s_for.empty()) cout << "Ignored" << endl;
                else{
                    s_back.push(now);
                    now = s_for.top();
                    cout << now << endl;
                    s_for.pop(); 
                }

            }
        }


    }


    return 0;
}