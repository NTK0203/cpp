#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, x;
    vector <int> x_1, x_2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        x_1.push_back(x);
        x_2.push_back(x);
    }
    sort(x_2.begin(),x_2.end());
    x_2.erase(unique(x_2.begin(),x_2.end()),x_2.end());
    for(int j=0;j<n;j++)
        cout<<lower_bound(x_2.begin(),x_2.end(),x_1[j]) - x_2.begin()<<" ";
}