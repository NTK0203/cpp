#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int main(){
    int map[1000][1000];
    int arr[1000][1000];
    int n,m;
    queue <pair<int,int>> q;
    int dy[4]={0,0,1,-1};
    int dx[4]={-1,1,0,0};
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            arr[i][j]=-1;
            cin>>map[i][j];
            if(map[i][j]==2)
                q.push(make_pair(i,j));
        }

    int x=q.front().first, y=q.front().second;
    map[x][y]=0;
    arr[x][y]=0;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        for(int k=0;k<4;k++){
            int next_x, next_y;
            next_x=x+dx[k];
            next_y=y+dy[k];
            if(next_x>=0&&next_x<n&&next_y>=0&&next_y<m) //check out of bounds 
            {
                if(arr[next_x][next_y]==-1&&map[next_x][next_y]!=0) 
                {
                    arr[next_x][next_y]=arr[x][y]+1;
                    q.push(make_pair(next_x,next_y));
                }
            }
        }
        q.pop();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0){
                cout<<0<<" ";
                continue;
            }
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}