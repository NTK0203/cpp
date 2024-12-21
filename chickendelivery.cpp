#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
void SelectChicken(int, int);
int CalculateDist();
int n,m;
int visited[13]={false,};
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
int min_dist=INT_MAX;

int main(){
    
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int input;
            cin>>input;
            if(input==1)
                house.push_back(make_pair(i,j));
            else if(input==2){
                chicken.push_back(make_pair(i,j));
            }
        }
    SelectChicken(0,0);
    cout<<min_dist;
}

void SelectChicken(int num, int cur){
    if(cur==m){
        int dist=CalculateDist();
        if(min_dist>dist)
            min_dist=dist;
    }
    for(int i=num;i<chicken.size();i++){
        if(visited[i]==false){
            visited[i]=true;
            SelectChicken(i,cur+1);
            visited[i]=false;
        }
    }
}

int CalculateDist(){
    int citydist=0;
    for(int i=0;i<house.size();i++){
        int min_index=INT_MAX;
        for(int j=0;j<chicken.size();j++){
            if(visited[j]){
                int dist=abs(chicken[j].first-house[i].first)+abs(chicken[j].second-house[i].second);
                if(min_index>dist)
                    min_index=dist;
            }
        }
        citydist+=min_index;
    }
    return citydist;
}