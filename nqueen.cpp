#include <iostream>

using namespace std;

void queen(int);
int n, count=0;
int col[16];

int main(){
    cin>>n;
    queen(0);
    cout<<count;
}

void queen(int input){
    bool check=true;
    for(int i=1;i<input&&check;i++)
        if(col[input]==col[i]||abs(col[input]-col[i])==abs(input-i))
            check=false;
    if(check==true)
        if(input==n)
            count++;
        else{
            for(int i=1;i<=n;i++){
                col[input+1]=i;
                queen(input+1);
            }
        }    
}