#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string s;
    stack<char> stk;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            stk.push(s[i]);
        }
        else if(s[i]==')'){
            while(stk.top()!='('){
                cout<<stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else if(s[i]=='+'||s[i]=='-'){
            if(stk.empty()||stk.top()=='('||stk.top()==')')
                stk.push(s[i]);
            else{
                 while(!stk.empty()){
                    if(stk.top()=='(')
                        break;
                    cout<<stk.top();
                    stk.pop();
                }
                stk.push(s[i]);
            }
        }
        else if(s[i]=='*'||s[i]=='/'){
            if(stk.empty())
                stk.push(s[i]);
            else if(stk.top()=='*'||stk.top()=='/'){
                while(!stk.empty()){
                    if(stk.top()=='*'||stk.top()=='/'){
                        cout<<stk.top();
                        stk.pop();
                    }
                    else
                        break;
                }
                stk.push(s[i]);
            }
            else
                stk.push(s[i]);
        }
        else
            cout<<s[i];
    }
    while(!stk.empty()){
        cout<<stk.top();
        stk.pop();
    }
}