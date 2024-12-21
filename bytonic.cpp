#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, max=0;
    vector<int> a;
    vector<int> dp_inc, dp_dec;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
        dp_inc.push_back(1);
        dp_dec.push_back(1);
    }
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[i]>a[j])
                if(dp_inc[j]>=dp_inc[i])
                    dp_inc[i]=dp_inc[j]+1;
    
    for(int i=n-2;i>=0;i--)
        for(int j=n-1;j>i;j--)
            if(a[i]>a[j])
                if(dp_dec[j]>=dp_dec[i])
                    dp_dec[i]=dp_dec[j]+1;
     
    for(int i=0;i<n;i++){
        int temp;
        if(dp_inc[i]+dp_dec[i]-1>dp_inc[i]+dp_dec[i]-1)
            temp=dp_inc[i]+dp_dec[i]-1;
        else
            temp=dp_inc[i]+dp_dec[i]-1;
        if(temp>max)
            max=temp;
    }
    cout<<max;
}