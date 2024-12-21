#include <iostream>
#define inf 99999999
using namespace std;

int main(){
    int list[101][101];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)
                list[i][j]=0;
            else
                list[i][j]=inf;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(list[a][b]==inf||list[a][b]>c)
            list[a][b]=c;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(i==j||list[j][i]==inf)
                    continue;
                if(list[j][k]>list[j][i]+list[i][k])
                    list[j][k]=list[j][i]+list[i][k];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(list[i][j]==inf)
                cout<<"0 ";
            else
                cout<<list[i][j]<<" ";
        }
        cout<<"\n";
    }
}