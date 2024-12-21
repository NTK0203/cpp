#include <iostream>
#include <string>
#include <fstream>
#include "graph.h"

using namespace std;

void Graph::LoadMatrix(std::string& filename)
{
    ifstream ifs(filename);
    ifs>>size;
    array=(int**)malloc(sizeof(int*)*size);
    for(int i=0;i<size;i++){
    array[i]=(int*)malloc(sizeof(int)*size);
        for(int j=0;j<size;j++)
            ifs>>array[i][j];
    }
}
void Graph::PrintMatrix()
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
            cout<<array[i][j]<<" ";
        cout<<endl;
    }
}
int Graph::GetSize()
{
    return size;
}
void Graph::PrintShortestPathWeight(int s)
{
    int *dist=new int[size];
    bool *sel=new bool[size];
    for(int i=0;i<size;i++)
    {
        sel[i]=false;
        dist[i]=array[s][i];
    }
    dist[s]=0;
    sel[s]=true;
    for(int j=0;j<size-2;j++)
    {
        int minimum_d=999, u;
        for(int k=0;k<size;k++)
        {
            if(sel[k]==false&&dist[k]<minimum_d)
            {
                minimum_d=dist[k];
                u=k;
            }
        }
            sel[u]=true;
        for(int w=0;w<size;w++)
            if(sel[w]==false&&(dist[u]+array[u][w])<dist[w])
                dist[w]=dist[u]+array[u][w];
        }
    for(int i=0;i<size;i++)
        cout<<dist[i]<<endl;
}
void Graph::PrintShortestPath(int s)
{
    int *dist=new int[size];
    bool *sel=new bool[size];
    int **trace=new int*[size];
    int *index=new int[size];
    for(int i=0;i<size;i++)
    {
        trace[i]=new int[size];
        for(int j=0;j<size;j++)
            trace[i][j]=-1;
    }
    for(int i=0;i<size;i++)
    {
        sel[i]=false;
        dist[i]=array[s][i];
        trace[i][0]=s;
        trace[i][1]=i;
        index[i]=1;
    }
    dist[s]=0;
    sel[s]=true;
    for(int j=0;j<size-2;j++)
    {
        int minimum_d=999, u;
        for(int k=0;k<size;k++)
        {
            if(sel[k]==false&&dist[k]<minimum_d)
            {
                minimum_d=dist[k];
                u=k;
            }
        }
            sel[u]=true;
        for(int w=0;w<size;w++)
            if(sel[w]==false&&(dist[u]+array[u][w])<dist[w])
            {
                if(j==0){
                    trace[w][index[w]++]=u;
                    trace[w][index[w]]=w;
                }
                else{
                    for(int k=0;k<=index[u];k++)
                    {
                        trace[w][k]=trace[u][k];
                    }
                        index[w]=index[u]+1;
                        trace[w][index[w]]=w;
                }
                dist[w]=dist[u]+array[u][w];
            }
        }
    for(int i=0;i<size;i++)
    {
        if(i==s)
            continue;
        for(int j=0;j<=index[i];j++)
        {
                cout<<trace[i][j]<<" ";
        }
        cout<<endl;
    }
}