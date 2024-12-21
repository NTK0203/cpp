#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    int dp[101][100001]={0,}, w[101]={0,}, v[101]={0,};
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>w[i]>>v[i];
    
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(w[j]>i)
                dp[j][i]=dp[j-1][i];
            else
                dp[j][i]=max(dp[j-1][i-w[j]]+v[j],dp[j-1][i]);
        }
    }
    cout<<dp[n][k];
}