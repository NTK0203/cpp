#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    string fst, snd;
    int dp[1001][1001];
    stack<char> s;
    cin>>fst>>snd;
    for(int i=0;i<=snd.size();i++)
        for(int j=0;j<=fst.size();j++){
            if(i==0||j==0)
                dp[i][j]=0;
            else if(fst[j-1]==snd[i-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    int n=0;
    for(int i=0;i<=fst.size();i++)
        if(dp[snd.size()][i]>n)
            n=dp[snd.size()][i];
    
    int i=snd.size(),j=fst.size();
    while(i!=0&&j!=0)
            if(dp[i][j]!=dp[i][j-1]&&dp[i][j]!=dp[i-1][j]){
                s.push(snd[i-1]);
                i--;
                j--;
            }
            else if(dp[i][j]!=dp[i][j-1])
                i--;
            else
                j--;
    
    cout<<n<<"\n";
    for(int i=0;i<n;i++){
        cout<<s.top();
        s.pop();
    }
}