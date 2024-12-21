#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    int n,s,arr[100000];
    cin>>n>>s;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int min=INT_MAX,f=0,b=0,sum=arr[f];
    while(b!=n){
        if(sum>=s){
            if(min>b-f+1)
                min=b-f+1;
            if(sum-arr[f]<s){
                b++;
                sum+=arr[b];
            }
            else{
                sum-=arr[f];
                f++;
            }
        }
        else{
            b++;
            sum+=arr[b];
        }
    }
    if(min==INT_MAX)
        cout<<"0";
    else
        cout<<min;
}