#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int main(){
    int box[1000][1000];
    int n,m,count=0;
    queue <pair<int,int>> q;
    int dy[4]={0,0,1,-1};
    int dx[4]={-1,1,0,0};
    cin>>m>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>box[i][j];
            if(box[i][j]==1)
                q.push(make_pair(i,j));
        }

    int x=q.front().first, y=q.front().second;
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        for(int k=0;k<4;k++){
            int next_x, next_y;
            next_x=x+dx[k];
            next_y=y+dy[k];
            if(next_x>=0&&next_x<n&&next_y>=0&&next_y<m) //check out of bounds 
            {
                if(box[next_x][next_y]==0)
                {
                    box[next_x][next_y]=box[x][y]+1;
                    q.push(make_pair(next_x,next_y));
                }
            }
        }
        q.pop();
    }
    int max=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(box[i][j]==0)
            {
                max=-1;
                i=n;
                break;
            }    
            if(box[i][j]>max)
                max=box[i][j]-1;
        }
    cout<<max;
}