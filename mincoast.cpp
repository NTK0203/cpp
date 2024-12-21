#include <iostream>
#include <queue>
#define inf 99999999
using namespace std;

int main(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<pair<int,int>> list[1001];
    int dist[1001]; 
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        dist[i]=inf;
    
    for(int i=0;i<m;i++){
        int a,b,c;
        bool check=true;
        cin>>a>>b>>c;
        for(int j=0;j<list[a].size();j++){
            if(list[a][j].first==b&&list[a][j].second>c){
                list[a][j].second=c;
                check=false;
            }
        }
        if(check)
            list[a].push_back(make_pair(b,c));
    }

    int start, end;
    cin>>start>>end;
    dist[start]=0;
    q.push(make_pair(0,start));

    while(!q.empty()){
        int nod = q.top().second, w=q.top().first;
        q.pop();
        for(int i=0;i<list[nod].size();i++){
            int nod_2=list[nod][i].first, w_2=list[nod][i].second;
            if(dist[nod_2]>w+w_2){
                dist[nod_2]=w+w_2;
                q.push(make_pair(dist[nod_2],nod_2));
            }
        }
    }
    cout<<dist[end];
}