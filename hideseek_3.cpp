#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, k, min=999999999;
    bool visited[100001]={false,};
    queue<pair<int,int>> q;
    cin>>n>>k;
    q.push(make_pair(n,0));
    while(!q.empty()){
        int x=q.front().first;
        int count=q.front().second;
        q.pop();
        if(x==k)
            if(min>count){
                min=count;
                continue;
            }
        if(x*2<100001)
            if(!visited[x*2]){
                q.push(make_pair(x*2,count));
                visited[x*2]=true;
            }
        if(x-1>=0)
            if(!visited[x-1]){
                q.push(make_pair(x-1,count+1));
                visited[x-1]=true;
            }
        if(x+1<100001)
            if(!visited[x+1]){
                q.push(make_pair(x+1,count+1));
                visited[x+1]=true;
            }
    }
    cout<<min;
}