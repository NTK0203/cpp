#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int main(){
    int box[100][100][100];
    int n,m,h;
    queue <tuple<int,int,int>> q;
    int dy[4]={0,0,1,-1};
    int dx[4]={-1,1,0,0};
    cin>>m>>n>>h;
    for(int i=0;i<h;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++)
            {
                cin>>box[i][j][k];
                if(box[i][j][k]==1)
                    q.push(make_tuple(i,j,k));
            }

    int z= get<0>(q.front()), x=get<1>(q.front()), y=get<2>(q.front());
    while(!q.empty()){
        z= get<0>(q.front());
        x=get<1>(q.front()); 
        y=get<2>(q.front());
        for(int l=0;l<2;l++){
            int down=z-1, up=z+1;
            if(down>=0)
                if(box[down][x][y]==0){
                    box[down][x][y]=box[z][x][y]+1;
                    q.push(make_tuple(down,x,y));
            }
            if(up<h)
                if(box[up][x][y]==0){
                    box[up][x][y]=box[z][x][y]+1;
                    q.push(make_tuple(up,x,y));
                }
        }
        for(int k=0;k<4;k++){
            int next_x, next_y;
            next_x=x+dx[k];
            next_y=y+dy[k];
            if(next_x>=0&&next_x<n&&next_y>=0&&next_y<m) //check out of bounds 
            {
                if(box[z][next_x][next_y]==0)
                {
                    box[z][next_x][next_y]=box[z][x][y]+1;
                    q.push(make_tuple(z,next_x,next_y));
                }
            }
        }
        q.pop();
    }
    int max=0;
    for(int i=0;i<h;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++){
                if(box[i][j][k]==0)
                {
                    max=-1;
                    i=h;
                    j=n;
                    break;
                }    
                if(box[i][j][k]>max)
                    max=box[i][j][k]-1;
            }
    cout<<max;
}