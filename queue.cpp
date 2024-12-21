#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    string input;
    cin>>n;
    queue<int> q;
    for(int i=0;i<n;i++){
        cin>>input;
        if(input=="push"){
            int num;
            cin>>num;
            q.push(num);
        }
        else if(input=="front"){
            if(q.empty())
                cout<<"-1";
            else
                cout<<q.front();
            cout<<"\n";
        }
        else if(input=="back"){
            if(q.empty())
                cout<<"-1";
            else
                cout<<q.back();
            cout<<"\n";
        }
        else if(input=="size")
            cout<<q.size()<<"\n";
        else if(input=="empty"){
            if(q.empty())
                cout<<"1";
            else
                cout<<"0";
            cout<<"\n";
        }
        else{
            if(q.empty())
                cout<<"-1";
            else{
                cout<<q.front();
                q.pop();
            }
            cout<<"\n";
        }
    }
}