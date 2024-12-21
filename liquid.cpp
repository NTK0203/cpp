#include <iostream>

using namespace std;

int main(){
    int n,arr[100000];
    pair<int,int> p;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int l=0,r=n-1;
    p=make_pair(arr[l],arr[r]);
    while(l!=r){
        if(abs(arr[l]+arr[r])<abs(p.first+p.second))
            p=make_pair(arr[l],arr[r]);

        if(p.first+p.second==0)
            break;
        if(arr[l]+arr[r]>0)
            r--;
        else
            l++;
    }
    cout<<p.first<<" "<<p.second;
}