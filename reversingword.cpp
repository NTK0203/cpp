#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    int test, check, count=0;
    string box;
    stack<char> s;
    cin>>test;
    if(test>1)
        count=test;
    cin.ignore();
    while(test--)
    {
        check=1;
        getline(cin, box);
        for(char e:box)
        {
            s.push(e);
            if(e==' ')
            {
                if(check==1)
                {
                    s.pop();
                    check=0;
                }
                while(!s.empty())
                {
                    cout<<s.top();
                    s.pop();
                }
            }
        }
        if(count>0)
            cout<<" ";
        while(!s.empty())
        {
            cout<<s.top();
            s.pop();
        }
        if(test!=0)
            cout<<"\n";
    }
    return 0;
}