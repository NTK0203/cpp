#include <iostream>
#include <queue>
using namespace std;

int arr[1000][1000], visited[1000][1000][2];

int main(){
    int n,m,x,y,breaking,
    dx[4]={0,0,-1,1},
    dy[4]={-1,1,0,0};
    bool check=true;
    cin>>n>>m;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%1d",&arr[i][j]);
        
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(0,0),0));
    visited[0][0][0]=1;
    while(!q.empty()){
        x=q.front().first.first, y=q.front().first.second;
        breaking=q.front().second;
        q.pop();

        if(x==n-1&&y==m-1){
            cout<<visited[x][y][breaking];
            check=false;
            break;
        }

        for(int i=0;i<4;i++){
            int nx=x+dx[i],
            ny=y+dy[i];
            if(nx<0||ny<0||nx>n-1||ny>m-1)
                continue;
            
            if(arr[nx][ny]==0&&visited[nx][ny][breaking]==0){
                visited[nx][ny][breaking]=visited[x][y][breaking]+1;
                q.push(make_pair(make_pair(nx,ny),breaking));
            }
            else if(arr[nx][ny]==1&&breaking==0){
                visited[nx][ny][1]=visited[x][y][breaking]+1;
                q.push(make_pair(make_pair(nx,ny),1));
            }        
        }
    }
    if(check)
        cout<<"-1";
}