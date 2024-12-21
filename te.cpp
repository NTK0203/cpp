#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

// GLOBAL VARIANCES and CONSTANT
const int n = 4;
const int W = 18;
int w[n+1] = {0,5,10,4,10}; // w[0] is meaningless
int p[n+1] = {0,50,60,20,10}; // p[0] is meaningless
string* include = new string[n+1];
string* bestset = new string[n+1];
int prm_node_cnt = 0;
int nprm_node_cnt = 0;
int numbest = 0;
int maxprofit = 0;
bool promising(int, int, int);
void knapsack(int i, int profit, int weight);


  bool promising(int i, int profit, int weight)
  {
    int j, k;
    int totweight;
    float bound;

    // Node is promising only if we should expand to its children.
    // There must be some capacity left for the children.
    if (weight >= W)
    {
      return false;
    }
    else
    {
      j = i + 1;
      bound = (float)profit;
      totweight = weight;

      while (j <= n && totweight + w[j] <= W)
      {
        // Grab as many items as possible.
        totweight = totweight + w[j];
        bound = bound + p[j];
        ++j;
      }

      k = j; // Use k for consistency with formula in text.
      if (k <= n) // Grab fraction of kth item.
      bound = bound + (W - totweight) * (p[k] / w[k]);

      return (bound > maxprofit);
    }
  }
  void knapsack(int i, int profit, int weight)
  {
    // This set is best so far. Set numbest to number of items considered.
    // Set bestset to this solution.
    if (weight <= W && profit > maxprofit)
    {
      maxprofit = profit;
      numbest = i;
      copy(include, include + n+1, bestset);
    }

    if (promising(i, profit, weight))
    {
      ++prm_node_cnt; // Count the number of promising node
      include[i+1] = "YES"; // Inlcude w[i+1]
      knapsack(i + 1, profit + p[i+1], weight + w[i+1]);
      include[i+1] = "NO";  // Do not include w[i+1]
      knapsack(i + 1, profit, weight);
    }
    else
    {
      ++nprm_node_cnt; // Count the number of non-promising node
    }
  }


int main( )
{
  clock_t start, end;

  start = clock( );
  knapsack(0, 0, 0);
  end = clock( );

  for (int j = 1; j <= numbest; ++j)
    cout << "w"<< j << ": " << bestset[j] << setw(3);

  cout << endl << "The answer: $" << maxprofit << endl;
  cout << "The num of promising node: " << prm_node_cnt << endl;
  cout << "The num of nonpromising node: " << nprm_node_cnt << endl;
  double result = (double)(end-start) / CLOCKS_PER_SEC;
  cout << "Elpased time is: "<< result << " sec." << endl;
  delete [ ] include;
  delete [ ] bestset;

  return EXIT_SUCCESS;
}