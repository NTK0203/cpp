#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> arr[100001];
bool visited[100001]={false,};
vector<pair<int,int>> total_w;
int total=0;
pair<int,int> max_leap={0,0};
void dfs(int);

int main(){
    int v;
    cin>>v;
    for(int i=0;i<v;i++){
        int p,c,w;
        cin>>p>>c;
        while(c!=-1){
            cin>>w;
            arr[p].push_back(make_pair(c,w));
            cin>>c;
        }
    }

    visited[1]=true;
    dfs(1);

    for(int i=1;i<=v;i++)
        visited[i]=false;
    visited[max_leap.first]=true;
    dfs(max_leap.first);
    cout<<max_leap.second;
}

void dfs(int nod){
    for(int i=0;i<arr[nod].size();i++){
        if(arr[nod].size()==1&&max_leap.second<total){
            max_leap.first=nod;
            max_leap.second=total;
        } 
        if(!visited[arr[nod][i].first]){
            total+=arr[nod][i].second;
            visited[arr[nod][i].first]=true;
            dfs(arr[nod][i].first);
            total-=arr[nod][i].second;
        }
    }
}