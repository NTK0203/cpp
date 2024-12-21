#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,string> a, pair<int,string> b){
    return a.first<b.first;
}

int main(){
    int n;
    vector<pair<int,string>> member;
    cin>>n;
    for(int i=0;i<n;i++){
        int age;
        string name;
        cin>>age>>name;
        member.push_back(make_pair(age,name));
    }
    stable_sort(member.begin(),member.end(),cmp);

    for(int i=0;i<n;i++)
        cout<<member[i].first<<" "<<member[i].second<<"\n";
} 