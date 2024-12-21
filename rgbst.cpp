#include <iostream>

using namespace std;

int main(){
    int n, arr[1001][3], min;
    cin>>n;
    cin>>arr[0][0]>>arr[0][1]>>arr[0][2];
    for(int i=1;i<n;i++)
        for(int j=0;j<3;j++){
            min=9999999;
            int input;
            cin>>input;
            for(int k=0;k<3;k++){
                if(k==j)
                    continue;
                if(min>arr[i-1][k])
                    min=arr[i-1][k];
            }
            arr[i][j]=min+input;
        }
    min=9999999;
    for(int i=0;i<3;i++)
        if(arr[n-1][i]<min)
            min=arr[n-1][i];
    cout<<min;
}