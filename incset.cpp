#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, max=1;
    vector<int> a;
    vector<int> dp;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
        dp.push_back(1);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j])
                if(dp[j]>=dp[i]){
                    dp[i]=dp[j]+1;
                    if(dp[i]>max)
                        max=dp[i];
                }
        }
    }
    cout<<max;
}