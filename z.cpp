#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n, r, c, length, result=0;
    cin>>n>>r>>c;
    while(n>0){
        length=pow(2,n);
        if(r<length/2&&c>=length/2){
            result+=pow(4,n-1);
            c-=length/2;
        }
        else if(r>=length/2&&c<length/2){
            result+=pow(4,n-1)*2;
            r-=length/2;
        }
        else if(r>=length/2&&c>=length/2){
            result+=pow(4,n-1)*3;
            c-=length/2;
            r-=length/2;
        }
        n--;
    }
    cout<<result;
}