#include <iostream>
#include <queue>
using namespace std;

int main(){
    bool visit[100001]={false,};
    int n,k,count=0;
    queue<pair<int,int>> q;

    cin>>n>>k;

    q.push(make_pair(n,0));
    visit[n]=true;

    while(!q.empty()){
        int x;
        x=q.front().first;
        count=q.front().second;
        q.pop();

        if(x==k)
            break;
        if(x*2<100001){
            if(!visit[x*2])
            {
                q.push(make_pair(x*2,count+1));
                visit[x*2]=true;
            }
        }
        if(x-1>=0){
            if(x-1>=0&&!visit[x-1]){
                q.push(make_pair(x-1,count+1));
                visit[x-1]=true;
            }
        }
        if(x+1<100001){
            if(!visit[x+1]){
                q.push(make_pair(x+1,count+1));
                visit[x+1]=true;
            }
        }
    }
    cout<<count;
}