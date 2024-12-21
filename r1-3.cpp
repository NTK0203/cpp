#include <iostream>
using namespace std;

int binarysearch(int*,int,int,int);
int count=0;

int main()
{
    int n,target;
    int* list;
    cin>>n;
    list = new int[n];
    for (int i=0;i<n;i++)
        cin>>list[i];
    cin>>target;
    cout<<binarysearch(list,target,0,n-1)<<endl;
    cout<<count<<endl;
}

int binarysearch(int* list,int target,int left,int right)
{
    if(left>right)
        return -1;
    int middle=(left+right)/2;
    count++;
    if(target<list[middle])
        return binarysearch(list,target,left,middle-1);
    else if(target>list[middle])
        return binarysearch(list,target,middle+1,right);
    else
        return middle;
}