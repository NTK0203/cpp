#include <iostream>
#include <algorithm>
using namespace std;

typedef struct graph{
    int v1;
    int v2;
    int w;
}graph;

graph g[100001];
int parent[10001];

int cmp(graph a, graph b){
    return a.w<b.w;
}

int find(int x){
    if(parent[x]==x)
        return x;
    return parent[x]=find(parent[x]);
}

void merge(int x, int y){
    x=find(x);
    y=find(y);
    if(x<y)
        parent[y]=x;
    else parent[x]=y;
}

int main(){
    int v,e;
    cin>>v>>e;
    for(int i=1;i<=v;i++)
        parent[i]=i;
    
    for(int i=0;i<e;i++)
        cin>>g[i].v1>>g[i].v2>>g[i].w;

    sort(g, g+e, cmp);

    int total=0,count=0;
    for(int i=0;i<e&&count<v-1;i++){
        if(find(g[i].v1)!=find(g[i].v2)){
            merge(g[i].v1,g[i].v2);
            total+=g[i].w;
            count++;
        }
    }
    cout<<total;
}