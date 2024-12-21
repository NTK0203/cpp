#include <iostream>
using namespace std;

int max(int,int);

int main(){
  int n;
  int stair[301] = {0,}, list[301] = {0,};
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>stair[i];
  list[1]=stair[1];
  list[2]=list[1]+stair[2];
  list[3]=stair[3]+max(list[1],stair[2]);
  for(int i=4;i<=n;i++)
    list[i]=stair[i]+max(list[i-2],list[i-3]+stair[i-1]);
  cout<<list[n];
}

int max(int a, int b){
  if(a>b)
    return a;
  else
    return b;
}