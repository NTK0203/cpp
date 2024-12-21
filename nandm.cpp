#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m;
int arr[9]={0,};
bool visited[9]={0,};
vector<int> set;
void dfs(int,int);

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        set.push_back(temp);
    }
    sort(set.begin(),set.end());
    dfs(0,0);
}

void dfs(int num, int cur){
    if(cur==m){
        for(int i=0;i<m;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
    }
    int check=0;
    for(int i=0;i<n;i++){
        if(visited[i]==false&&check!=set[i]){
            visited[i]=true;
            arr[cur]=set[i];
            check=set[i];
            dfs(i+1,cur+1);
            visited[i]=false;
        }
    }
}