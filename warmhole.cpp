#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main(){
    int tc,n,m,w,s,e,t;
    cin>>tc;
    for(int i=0;i<tc;i++){
        vector<pair<int,int>> arr[501];
        int dist[501];
        bool check=false;
        for(int j=0;j<501;j++)
            dist[i]=INT_MAX;
        dist[1]=0;
        cin>>n>>m>>w;
        for(int j=0;j<m;j++){
            cin>>s>>e>>t;
            arr[s].push_back(make_pair(e,t));
            arr[e].push_back(make_pair(s,t));
        }
        for(int j=0;j<w;j++){
            cin>>s>>e>>t;
            arr[s].push_back(make_pair(e,-t));
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++)
                for(int l=0;l<arr[k].size();l++){
                    int v_1=k, v_2=arr[k][l].first, time=arr[k][l].second;
                    if(dist[v_1]==INT_MAX)
                        continue;
                    if(dist[v_2]>dist[v_1]+time)
                        dist[v_2]=dist[v_1]+time;
                }
        }
        for(int k=1;k<=n;k++)
                for(int l=0;l<arr[k].size();l++){
                    int v_1=k, v_2=arr[k][l].first, time=arr[k][l].second;
                    if(dist[v_1]==INT_MAX)
                        continue;
                    if(dist[v_2]>dist[v_1]+time)
                        check=true;
                }
        if(check)
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
    }
}