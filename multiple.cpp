#include <iostream>
using namespace std;

long long mul(long long);
long long a,b,c;

int main(){
    cin>>a>>b>>c;
    cout<<mul(b);
}

long long mul(long long exponent){
    if(exponent==0)
        return 1;
    if(exponent==1)
        return a%c;
    if(exponent%2==0)
        return mul(exponent/2)%c*mul(exponent/2)%c;
    else
        return mul(exponent/2)%c*mul(exponent/2)%c*a%c;
}