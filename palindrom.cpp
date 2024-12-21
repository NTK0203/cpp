#include <iostream>

using namespace std;

int n,m,arr[2001];
bool dp[2001][2001]={false,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];

    for(int i=1;i<n;i++){
        dp[i][i]=true;
        if(arr[i]==arr[i+1])
            dp[i][i+1]=true;
    }
    dp[n][n]=true;

    for(int i=n-1;i>0;i--)
        for(int j=i+1;j<=n;j++)
            if(arr[i]==arr[j]&&dp[i+1][j-1])
                dp[i][j]=true;
        
    cin>>m;
    for(int i=0;i<m;i++){
        int s,e;
        cin>>s>>e;
        cout<<dp[s][e]<<"\n";
    }
}