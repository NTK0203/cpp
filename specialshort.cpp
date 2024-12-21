#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

int findShort(int,int);
int list[801][801];
int dist[801];
int n, e, v_1, v_2;

int main(){
    int totaldist_v1=0, totaldist_v2=0, temp, result;
    cin>>n>>e;
    for(int i=0;i<801;i++){
        dist[i]=INT_MAX;
        for(int j=0;j<801;j++)
            list[i][j]=INT_MAX;
    }
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        list[a][b]=c;
        list[b][a]=c;
    }
    cin>>v_1>>v_2;
    
    totaldist_v1+=findShort(1, v_1);
    if(totaldist_v1!=INT_MAX){
        temp=findShort(v_1,v_2);
        if(temp!=INT_MAX)
            totaldist_v1+=temp;
        else
            totaldist_v1=INT_MAX;
    }
    if(totaldist_v1!=INT_MAX){
        temp=findShort(v_2,n);
        if(temp!=INT_MAX)
            totaldist_v1+=temp;
        else
            totaldist_v1=INT_MAX;
    }

    totaldist_v2+=findShort(1, v_2);
    if(totaldist_v2!=INT_MAX){
        temp=findShort(v_2,v_1);
        if(temp!=INT_MAX)
            totaldist_v2+=temp;
        else
            totaldist_v2=INT_MAX;
    }
    if(totaldist_v2!=INT_MAX){
        temp=findShort(v_1,n);
        if(temp!=INT_MAX)
            totaldist_v2+=temp;
        else
            totaldist_v2=INT_MAX;
    }

    if(totaldist_v2>totaldist_v1)
        result=totaldist_v1;
    else
        result=totaldist_v2;
    if(result==INT_MAX)
        cout<<"-1";
    else
        cout<<result;
}

int findShort(int start, int end){
    for(int i=0;i<801;i++)
        dist[i]=INT_MAX;
    dist[start]=0;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int nod=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(list[nod][i]!=INT_MAX){
                if(dist[i]>dist[nod]+list[nod][i]){
                    dist[i]=dist[nod]+list[nod][i];
                    q.push(i);
                }
            }
        }
    }
    return dist[end];
}