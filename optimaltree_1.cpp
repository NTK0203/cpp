#include <iostream>
using namespace std;

void optsearchtree(int n, const float p[], float& minavg, 
int R[][99], float A[][99]) {
    int i, j, k, diagonal, check; 
    for(i=1; i<=n; i++) {
    A[i][i-1] = 0; 
    A[i][i] = p[i]; 
    R[i][i] = i; 
    R[i][i-1] = 0; 
    }
    A[n+1][n] = 0;
    R[n+1][n] = 0;
    for(diagonal=1; diagonal<= n-1; diagonal++) 
        for(i=1; i <= n-diagonal; i++) {
            j = i + diagonal;
            k=i;
            check=k;
            float min = A[i][k-1]+A[k+1][j];
            float sum=0;
            for(k=i+1;k<=j;k++)
                if(min>A[i][k-1]+A[k+1][j])
                {
                    min=A[i][k-1]+A[k+1][j];
                    check=k;
                }
            for(int l=i;l<=j;l++)
                sum+=p[l];
            A[i][j] = min+sum;
            R[i][j] = check;
        }
    minavg = A[1][n];
}

int main(void){
    int n=4;
    const float p[5]={0,0.375,0.375,0.125,0.125};
    float minavg;
    int R[n+2][99];
    float A[n+2][99];
    optsearchtree(n,p,minavg,R,A);
    cout<<"A"<<"\n";
    for(int i=1;i<=n+1;i++)
    {
        for(int j=i-1;j<=n;j++)
            cout<<A[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"R"<<"\n";
    for(int i=1;i<=n+1;i++)
    {
        for(int j=i-1;j<=n;j++)
            cout<<R[i][j]<<" ";
        cout<<"\n";
    }
    cout<<minavg<<"\n";
}