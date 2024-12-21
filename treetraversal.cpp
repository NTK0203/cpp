#include <iostream>

using namespace std;

void front(char);
void mid(char);
void back(char);
pair<char, char> tree[27];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char p, child;
        int parent;
        cin>>p;
        parent=int(p-'A'+1);
        cin>>child;
        tree[parent].first=child;
        cin>>child;
        tree[parent].second=child;
    }
    front('A');
    cout<<"\n";
    mid('A');
    cout<<"\n";
    back('A');
}

void front(char nod){
    int nodnum;
    nodnum=int(nod-'A'+1);
    cout<<nod;
    if(tree[nodnum].first!='.')
        front(tree[nodnum].first);
    if(tree[nodnum].second!='.')
        front(tree[nodnum].second);
    return;
}

void mid(char nod){
    int nodnum;
    nodnum=int(nod-'A'+1);
    if(tree[nodnum].first!='.')
        mid(tree[nodnum].first);
    cout<<nod;
    if(tree[nodnum].second!='.')
        mid(tree[nodnum].second);
    return;
}

void back(char nod){
    int nodnum;
    nodnum=int(nod-'A'+1);
    if(tree[nodnum].first!='.')
        back(tree[nodnum].first);
    if(tree[nodnum].second!='.')
        back(tree[nodnum].second);
    cout<<nod;
    return;
}