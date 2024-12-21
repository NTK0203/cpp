#include <iostream>
#include <map>
using namespace std;

map<long long, long long> f;

long long fibo(long long n){
    if(n==0)
        return 0;
    if(f[n])
        return f[n];
    if(n%2==0)
        f[n]=(fibo(n/2)*(fibo(n/2+1)+fibo(n/2-1)));
    else
        f[n]=(fibo((n+1)/2)*fibo((n+1)/2)+fibo((n-1)/2)*fibo((n-1)/2));
    return f[n];
}

int main(){
    long long n;
    cin>>n;
    f[0]=0;
    f[1]=1;
    f[2]=1;
    cout<<fibo(n);
}