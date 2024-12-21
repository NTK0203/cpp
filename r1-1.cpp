#include <iostream>
using namespace std;
int combination(int,int);

int main()
{
    int n,r;
    cin>>n>>r;
    cout<<combination(n,r)<<endl;
}

int combination(int n, int r)
{
    if(r==0||n==r)
    {
        return 1;
    }
    return (combination(n-1,r-1)+combination(n-1,r));
}