#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 99999999
using namespace std;

int main(){
    int dist[20001];
    int V,E,K;
    vector<pair<int,int>> arr[20001];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    cin>>V>>E>>K;

    for(int i=0;i<=V;i++)
        dist[i]=MAX;
    
    dist[K]=0;

    for(int i=1;i<=E;i++){
        int u,v,w;
        bool check=false;
        cin>>u>>v>>w;
        for(int j=0;j<arr[u].size();j++){
            if(arr[u][j].first==v){
                if(arr[u][j].second>w)
                    arr[u][j].second=w;
                check=true;
            }      
        }
        if(check==false)
            arr[u].push_back(make_pair(v,w));
    }
    q.push(make_pair(0,K));

    while(!q.empty()){
        pair<int,int> p=q.top();
        q.pop();
        int v_1=p.second, w_1=p.first;

        for(int i=0;i<arr[v_1].size();i++){
            int v_2=arr[v_1][i].first, w_2=arr[v_1][i].second;
            if(dist[v_2]>w_1+w_2){
                dist[v_2]=w_1+w_2;
                q.push(make_pair(dist[v_2],v_2));
            }
        }
    }

    
    for(int i=1;i<=V;i++){
        if(dist[i]==MAX)
            cout<<"INF";
        else
            cout<<dist[i];
        cout<<"\n";
    }
}