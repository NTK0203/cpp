#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        arr.push_back(input);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\n";
}
