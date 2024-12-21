#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    pair<long long,long long> p[100001];
    int n;
    long double total=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;

    p[n]=p[0];

    for(int i=0;i<=n;i++)
       total+=p[i].first*p[i+1].second-p[i+1].first*p[i].second;
    cout<<fixed;
    cout.precision(1);
    cout<<abs(total)/2;
}