#include <iostream>
using namespace std;

long long A[5][5], result[5][5]={0,}, matrix[5][5];
int N;
long long B;

void CalculateMatrix(long long m_1[][5], long long m_2[][5]){
    for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                for(int k=0;k<N;k++){
                    result[i][j]+=(m_1[i][k]*m_2[k][j])%1000;
                    result[i][j]%=1000;
                }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            m_2[i][j]=result[i][j];
            result[i][j]=0;
        }
}

void DivideMatrix(long long b){
    while(b>0){
        if(b%2==1)
            CalculateMatrix(A,matrix);
        CalculateMatrix(A,A);
        b/=2;
    }
}

int main(){

    cin>>N>>B;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            cin>>A[i][j];
            matrix[i][j]=A[i][j];
        }

    DivideMatrix(B-1);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<matrix[i][j]%1000<<" ";
        cout<<"\n";
    }

}