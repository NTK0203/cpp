#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, a, b;
    vector<int> tree[100001];
    int arr[100001];
    bool visited[100001]={false,};
    queue<int> q;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    q.push(1);
    while(!q.empty()){
        int temp=q.front();
        for(int i=0;i<tree[temp].size();i++)
        {
            {
                int v = tree[temp][i];
                if(visited[v]==false){
                    arr[v]=temp;
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
        q.pop();
    }
    for(int i=2;i<=n;i++)
        cout<<arr[i]<<"\n";
}