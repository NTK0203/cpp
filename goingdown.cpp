#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, a, b, c, dp_max[3], dp_min[3], arr[3];
    cin>>n;
    cin>>a>>b>>c;

    dp_max[0]=a; dp_min[0]=a;
    dp_max[1]=b; dp_min[1]=b;
    dp_max[2]=c; dp_min[2]=c;

    for(int i=1;i<n;i++){
        cin>>arr[0]>>arr[1]>>arr[2];
        int pre_max[3],pre_min[3];
        for(int k=0;k<3;k++){
            pre_max[k]=dp_max[k];
            pre_min[k]=dp_min[k];
        }
        for(int j=0;j<3;j++){
            if(j==0){
                dp_max[j]=max(pre_max[j],pre_max[j+1])+arr[j];
                dp_min[j]=min(pre_min[j],pre_min[j+1])+arr[j];
            }
            else if(j==1){
                dp_max[j]=max({pre_max[j-1],pre_max[j],pre_max[j+1]})+arr[j];
                dp_min[j]=min({pre_min[j-1],pre_min[j],pre_min[j+1]})+arr[j];
            }
            else{
                dp_max[j]=max(pre_max[j-1],pre_max[j])+arr[j];
                dp_min[j]=min(pre_min[j-1],pre_min[j])+arr[j];
            }
        }
    }
    cout<<max({dp_max[0],dp_max[1],dp_max[2]})<<" ";
    cout<<min({dp_min[0],dp_min[1],dp_min[2]});
}