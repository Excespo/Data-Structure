#include<iostream>
#include<string>
#include<stack>

using namespace std;
int main(){
    int num;
    cin>>num;getchar();
    int ctr=0;
    string order;
    string current_site="http://www.sjtu.edu.cn/";
    stack<string> s_forward;
    stack<string> s_back;
    while(ctr<num && getline(cin,order)){
        switch(order[0]){
            case 'V': while(!s_forward.empty()){s_forward.pop();} 
                    s_back.push(current_site);
                    current_site=order.substr(6);
                    cout<<current_site<<endl;
                    break;
            case 'B': if(s_back.empty()){cout<<"Ignored"<<endl;}
                    else{
                    s_forward.push(current_site);
                    current_site=s_back.top();
                    s_back.pop();
                    cout<<current_site<<endl;}
                    break;
            case 'F': 
                    if(s_forward.empty()){cout<<"Ignored"<<endl;}
                    else{
                    s_back.push(current_site);
                    current_site=s_forward.top();
                    s_forward.pop();
                    cout<<current_site<<endl;}
                    break;
            case 'Q': ctr++; 
                    while(!s_forward.empty()){s_forward.pop();}     
                    while(!s_back.empty()){s_back.pop();}  
                    current_site="http://www.sjtu.edu.cn/";
                    cout<<endl;
                    break ;
            default: cout<<"fausse input"<<endl;
        }
    }

    return 0;
}