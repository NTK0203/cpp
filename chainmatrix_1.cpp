#include <iostream>
using namespace std;
int minmult(int n, const int d[], int M[][999], int P[][999]) 
{
    int i, j, k, diagonal;
    for(i=1; i <= n; i++)
        M[i][i] = 0;
    for(diagonal = 1; diagonal <= n-1; diagonal++)
        for(i=1; i <= n-diagonal; i++) {
            j = i + diagonal;
            M[i][j]=999;
            for(k=i;k<=j-1;k++)
            {
                int temp=M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];
                if(temp<M[i][j])
                {
                    M[i][j]=temp;
                    P[i][j]=k;
                }
            }
        }
    return M[1][n];
}

int main(void)
{
    const int d[7]={5,2,3,4,6,7,8};
    int n=6;
    int P[999][999];
    int M[999][999];
    int result=minmult(n,d,M,P);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<i)
                continue;
            cout<<M[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i=1;i<n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            if(j<=i)
                continue;
            cout<<P[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"result: "<<result<<"\n";
    return 0;
}