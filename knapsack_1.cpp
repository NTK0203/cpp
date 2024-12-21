#include <iostream>
#include <string.h>
#define FALSE false
using namespace std;

int W=16,n=4;
int w[5]={0,2,5,10,5};
int p[5]={0,40,30,50,10};
int maxprofit;
int numbest;
string bestset[5];
string include[5];

bool promising(int i, int profit, int weight) {
    int j, k;
    int totweight;
    float bound;
    if (weight >= W) 
        return FALSE;
    else {
    j = i+1;
    bound = profit;
    totweight = weight;
    while ((j <= n) && (totweight +w[j] <= W)) {
        totweight = totweight + w[j];
        bound = bound + p[j];
        j++;
    }
    k=j;
    if (k <= n)
        bound = bound +(W-totweight)*(p[k]/w[k]);
    return bound > maxprofit;
    }
}

void knapsack (int i, int profit, int weight) {
    if (weight <= W && profit > maxprofit) { // best so farmaxprofit = profit;
        maxprofit = profit;
        numbest = i;
        for(int j=0;j<=n;j++)
            bestset[j]=include[j];
    }
    if (promising(i,profit,weight)) {
    include[i+1] = "YES"; 
    knapsack(i+1, profit+p[i+1], weight+w[i+1]);
    include[i+1]="NO";
    knapsack(i+1, profit, weight);
    }
}

int main(void){
    knapsack(0,0,0);
    for(int i=1;i<=numbest;i++)
        cout<<bestset[i]<<"\n";
    return 0;
}