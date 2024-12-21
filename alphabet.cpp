#include <iostream>
#include <string>
using namespace std;

int r,c,total=0,count=1;
bool alphabet[26]={false,};
string arr[20];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

void dfs(pair<int,int> nod){
    int row=nod.first,col=nod.second;
    alphabet[arr[row][col]-'A']=true;
    if(count>total)
        total=count;
        for(int i=0;i<4;i++){
            bool check=false;
            if(i==0&&row>0)//up
                if(alphabet[arr[row+dy[i]][col+dx[i]]-'A']==false)
                    check=true;
                
            if(i==1&&row<r-1)//down
                if(alphabet[arr[row+dy[i]][col+dx[i]]-'A']==false)
                    check=true;

            if(i==2&&col<c-1)//right
                if(alphabet[arr[row+dy[i]][col+dx[i]]-'A']==false)
                    check=true;

            if(i==3&&col>0)//left
                if(alphabet[arr[row+dy[i]][col+dx[i]]-'A']==false)
                    check=true;

            if(check){
                count++;
                dfs(make_pair(row+dy[i],col+dx[i]));
                alphabet[arr[row+dy[i]][col+dx[i]]-'A']=false;
                count--;
            }
        }
}
    

int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++)
        cin>>arr[i];
    dfs(make_pair(0,0));
    cout<<total;
}