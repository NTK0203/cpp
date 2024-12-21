#include <iostream>
using namespace std;

int main(){
    int t, n;
    cin>>t;
    for(int i=0;i<t;i++){
        int dp[2][100000];
        cin>>n;
        for(int j=0;j<2;j++)
            for(int k=0;k<n;k++)
                cin>>dp[j][k];
        if(n==1)
            if(dp[0][0]>dp[1][0]){
                cout<<dp[0][0]<<"\n";
                continue;
            }
            else{
                cout<<dp[1][0]<<"\n";
                continue;
            }
        dp[0][1]+=dp[1][0];
        dp[1][1]+=dp[0][0];
        for(int j=2;j<n;j++){
            if(dp[1][j-2]>dp[1][j-1])
                dp[0][j]+=dp[1][j-2];
            else
                dp[0][j]+=dp[1][j-1];

            if(dp[0][j-2]>dp[0][j-1])
                dp[1][j]+=dp[0][j-2];
            else
                dp[1][j]+=dp[0][j-1];
        }
        if(dp[0][n-1]>dp[1][n-1])
            cout<<dp[0][n-1]<<"\n";
        else
            cout<<dp[1][n-1]<<"\n";
    }
}