#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct{
    int weight;
    int v_1;
    int v_2;
}edge;

edge set_of_edges[7];

struct nodetype 
{ 
    int parent; 
    int depth;
};
typedef nodetype universe[6]; 

universe U;

typedef int set_pointer;
int num=0;
int edgenum=0;
int compare(const void*, const void*);
void makeset (int);
set_pointer find(int);
void merge (set_pointer, set_pointer);
void initial(int);
int equal(int, int);
void input(int, int, int);

int compare(const void* a, const void* b)
{
	return (((edge*)a)->weight-((edge*)b)->weight);
}

void merge (set_pointer p, set_pointer q) {
    if (U[p].depth == U[q].depth) 
    { 
        U[p].depth =+1;
        U[q].parent =p; 
    }
    else if (U[p].depth < U[q].depth) 
        U[p].parent =q;
    else 
        U[q].parent = p;
}

void initial(int n)
{
	for (int i = 1; i <= n; i++)
		makeset(i);
}

int equal(int p, int q)
{
	if (p == q)
		return 1;
	else
		return 0;
}
void input(int v_1, int v_2, int weight)
{
	set_of_edges[num].v_1 = v_1;
	set_of_edges[num].v_2 = v_2;
	set_of_edges[num++].weight = weight;
}

void makeset (int i) { 
    U[i].parent = i; 
    U[i].depth = 0; 
}
set_pointer find (int i) { 
    int j; 
    j = i;
    while (U[j].parent != j) 
        j=U[j].parent; 
    return j; 
}

void kruskal(int n, int m, edge* E, edge* F) {
    int i, j;
    set_pointer p, q;
    edge e;
    qsort(E,m,sizeof(E[0]),compare);
    for(int i=0;i<m;i++)
    {
        F[i].v_1=0;
        F[i].v_2=0;
        F[i].weight=0;
    }
    initial(n);
    int index=0;
    while (1) {
        e = E[index];
        i=E[index].v_1;
        j=E[index].v_2;
        p = find(i);
        q = find(j);
        if (!equal(p,q)) {
            merge(p,q);
            F[edgenum++] = E[index];
        }
        index++;
        int cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			if (U[i].parent == i)
				cnt++;
		}
                    
		if (cnt == 1)
			break;
    }
}

int main(){
    int n=5,m=7;
    edge F[m];
    
	input(2,3,3);
	input(3,4,4);
	input(4,5,5);
	input(2,4,6);
    input(1,2,1);
	input(3,5,2);
	input(1,3,3);

    kruskal(n,m,set_of_edges,F);
    cout<<"F"<<"\n";
    for(int i=0;i<edgenum;i++)
        cout<<F[i].v_1<<"-"<<F[i].v_2<<" w="<<F[i].weight<<"\n";
}