#include <iostream>
#include <queue>
using namespace std;

int n,m,total=0,arr[8][8], test[8][8];
vector<pair<int,int>> virus;
vector<pair<int,int>> clean;
pair<int,int> c[3];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

int bfs(){
    queue<pair<int,int>> q;
    int count=0;
    for(int i=0;i<virus.size();i++)
        q.push(virus[i]);
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        int row=p.first, col=p.second;
        for(int i=0;i<4;i++){
            bool check=false;
            if(i==0&&row>0)//up
                if(test[row+dy[i]][col+dx[i]]==0)
                    check=true;
                
            if(i==1&&row<n-1)//down
                if(test[row+dy[i]][col+dx[i]]==0)
                    check=true;

            if(i==2&&col<m-1)//right
                if(test[row+dy[i]][col+dx[i]]==0)
                    check=true;

            if(i==3&&col>0)//left
                if(test[row+dy[i]][col+dx[i]]==0)
                    check=true;

            if(check){     
                test[row+dy[i]][col+dx[i]]=2;
                q.push(make_pair(row+dy[i],col+dx[i]));
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(test[i][j]==0)
                count++;
            test[i][j]=arr[i][j];
        }
    return count;
}

void combination(int crr, int next){
    if(crr==3){
        for(int i=0;i<3;i++)
            test[c[i].first][c[i].second]=1;
        int temp=bfs();
        if(temp>total)
            total=temp;
        return;
    }

    for(int i=next;i<clean.size();i++){
        c[crr]=clean[i];
        combination(crr+1,i+1);
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            test[i][j]=arr[i][j];
            if(arr[i][j]==2)
                virus.push_back(make_pair(i,j));
            else if(arr[i][j]==0)
                clean.push_back(make_pair(i,j));
        }
    combination(0,0);
    cout<<total;
}