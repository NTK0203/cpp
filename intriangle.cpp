#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, max=0;;
    vector<int> arr[501];
    cin>>n;
    int input;
    cin>>input;
    arr[1].push_back(input);
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            cin>>input;
            if(j==0)
                arr[i].push_back(arr[i-1][0]+input);
            else if(j==(i-1))
                arr[i].push_back(arr[i-1][i-2]+input);
            else{
                if(arr[i-1][j-1]>arr[i-1][j])
                    arr[i].push_back(arr[i-1][j-1]+input);
                else
                    arr[i].push_back(arr[i-1][j]+input);
            } 
        }
    }
    for(int i=0;i<n;i++)
        if(arr[n][i]>max)
            max=arr[n][i];
    cout<<max;
}