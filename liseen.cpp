#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int N, M;
    map<string,int> liseen;
    map<string, int> listup;
    string s;
    cin>>N>>M;
    for(int i=0;i<N;i++){    
        cin>>s;
        liseen[s]++;
    }

    for(int j=0;j<M;j++){
        cin>>s;
        liseen[s]++;
        if(liseen[s]>1)
            listup[s]++;
    }
    cout<<listup.size()<<"\n";
    for(auto itr:listup)
        cout<<itr.first<<"\n";
}