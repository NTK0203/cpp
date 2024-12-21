#include <iostream>
using namespace std;

void dijkstra (int n, const int W[][6], int F[][2]) { 
    int i, vnear; 
    int e=0;
    int touch[n+1]; 
    int length[n+1]; 

    for(i=2; i <= n; i++) {     // For all vertices, initialize v1 to be the last 
        touch[i] = 1;           // vertex on the current shortest path from v1, 
        length[i] = W[1][i];     // and initialize length of that path to be the
    } // weight on the edge from v1. 
    for(int j=0;j<(n-1);j++) { // Add all n-1 vertices to Y. 
        int min = 999;
        for(i=2; i <= n; i++)    // Check each vertex for having shortest path. 
            if (0 <= length[i] && length[i] <= min) {
                min = length[i];
                vnear = i;
            }
        F[e][0]=touch[vnear];
        F[e++][1]=vnear;
        for(i=2; i <= n; i++)
            if (length[vnear] + W[vnear][i] < length[i]) { 
                length[i] = length[vnear] + W[vnear][i]; 
                touch[i] = vnear; // For each vertex not in Y, update its shortest 
            }                     // path.  Add vertex indexed by vnear to Y. 
        length[vnear] = -1; 
    }
}

int main(){
    const int W[6][6]={{0,0,0,0,0,0},
                    {0,0,7,4,6,1},
                    {0,999,0,999,999,999},
                    {0,999,2,0,5,999},
                    {0,999,3,999,0,999},
                    {0,999,999,999,1,0}};
    int F[4][2]={0};
    int n=5;
    dijkstra(n,W,F);
    cout<<"F"<<"\n";
    for(int i=0;i<n-1;i++)
        cout<<F[i][0]<<" "<<F[i][1]<<"\n";
}