#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

int n,m,x;
int totalTime[1001]={0,},dist[1001], result=0;
vector<pair<int,int>> arr[1001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

void dijkstra(int start){
    for(int i=1;i<=n;i++)
        dist[i]=INT_MAX;
    dist[start]=0;
    q.push(make_pair(0,start));
    while(!q.empty()){
        pair<int,int> p=q.top();
        q.pop();
        int v_1=p.second,w_1=p.first;

        for(int i=0;i<arr[v_1].size();i++){
            int v_2=arr[v_1][i].first, w_2=arr[v_1][i].second;
            if(dist[v_2]>w_1+w_2){
                dist[v_2]=w_1+w_2;
                q.push(make_pair(dist[v_2],v_2));
            }
        }
    }
}

int main(){
    cin>>n>>m>>x;
    for(int i=0;i<m;i++){
        int st, ed, t;
        cin>>st>>ed>>t;
        arr[st].push_back(make_pair(ed,t));
    }
    for(int i=1;i<=n;i++){
        dijkstra(i);
        if(i==x){
            for(int j=1;j<=n;j++)
                if(dist[j]!=INT_MAX)
                    totalTime[j]+=dist[j];
        }
        else
            if(dist[x]!=INT_MAX)
                totalTime[i]+=dist[x];
    }
    for(int i=1;i<=n;i++)
        if(totalTime[i]>result)
            result=totalTime[i];
    cout<<result;
}