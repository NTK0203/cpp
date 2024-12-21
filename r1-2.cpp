#include <iostream>
using namespace std;

void permutation(int);
void toBinary(int,int*,int);
void print(int*,int);

int main()
{
    int n;
    cin>>n;
    permutation(n);
}

void permutation(int n)
{
    int* num;
    num = new int[n];
    for (int i=0;i<(1<<n);i++)
    {
        toBinary(i,num,n);
        print(num,n);
    }
    delete []num;
}

void toBinary(int i,int* num, int n)
{
    for(int j=0;j<n;j++)
    {
        if(i>0)
        {
        num[j]=i%2;
        i/=2;
        }
        else
            num[j]=0;
    }
}

void print(int* num, int n)
{
    for(int i=n-1;i>=0;i--)
    {
        if(num[i]==0)
        {
            cout<<"a";
        }
        else
            cout<<"b";
    }
    cout<<endl;
}