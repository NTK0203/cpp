#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int map[25][25];
    vector<int> total;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int set=2;
    int n;
    queue <pair<int,int>> q;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%1d",&map[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int count=0;
            if(map[i][j]==1){
                q.push(make_pair(i,j));
                map[i][j]=set;
                count++;
                while(!q.empty()){
                    int x=q.front().first, y=q.front().second;
                    for(int k=0;k<4;k++){
                        int next_x, next_y;
                        next_x=x+dx[k];
                        next_y=y+dy[k];
                        if(next_x>=0&&next_x<n&&next_y>=0&&next_y<n) 
                        {
                            if(map[next_x][next_y]==1)
                            {
                                map[next_x][next_y]=set;
                                q.push(make_pair(next_x,next_y));
                                count++;
                            }
                        }
                    }
                    q.pop();
                }
                total.push_back(count);
            }
        }
        sort(total.begin(),total.end());
        cout<<total.size()<<"\n";
        for(int i=0;i<total.size();i++)
            cout<<total[i]<<"\n";
}