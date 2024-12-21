#include <iostream>
#define SIZE 5
using namespace std;
void floyd2(int W[][SIZE+1], int D[][SIZE+1], int P[][SIZE+1]) 
{
    int i, j, k;

    for(i=1; i <= SIZE; i++)
        for(j=1; j <= SIZE; j++)
        {
            P[i][j] = 0;
            D[i][j] = W[i][j];
        }
    for(k=1; k<= SIZE; k++)
        for(i=1; i <= SIZE; i++)
            for(j=1; j<=SIZE; j++)
                if (D[i][k] + D[k][j] < D[i][j]) 
                {
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
}
void path(int q, int r, int P[][SIZE+1]) {
    if (P[q][r] != 0) {
        path(q,P[q][r],P);
        cout << "v"<< P[q][r]<<"->";
        path(P[q][r],r,P);
    }
}
int main()
{
    int W[SIZE+1][SIZE+1]={{0,0,0,0,0,0},
                        {0,0,1,999,1,5},
                        {0,9,0,3,2,999},
                        {0,999,999,0,4,999},
                        {0,999,999,2,0,3},
                        {0,3,999,999,999,0}};
    int P[SIZE+1][SIZE+1];
    int D[SIZE+1][SIZE+1];
    int start, end;
    cin>>start>>end;
    floyd2(W,D,P);
    cout<<"D"<<"\n";
    for(int i=1;i<=SIZE;i++)
    {
        for(int j=1;j<=SIZE;j++)
            cout<<D[i][j]<<"  ";
        cout<<"\n";
    }
    cout<<"p"<<"\n";
    for(int i=1;i<=SIZE;i++)
    {
        for(int j=1;j<=SIZE;j++)
            cout<<P[i][j]<<"  ";
        cout<<"\n";
    }
    cout<<"v"<<start<<"->";
    path(start,end,P);
    cout<<"v"<<end<<"\n";
}