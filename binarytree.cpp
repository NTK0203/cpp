#include <iostream>

using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode *leftChild;
    TreeNode *rightChild; 
    TreeNode(int& data) : data(data){} 
};

void insert(TreeNode* root, int input){
    TreeNode *p=root,*pp=0;
    while(p){
        pp=p;
        if(input<p->data)
            p=p->leftChild;
        else if(input>p->data)
            p=p->rightChild;
        else
            return;
    }
    if(pp->data>input)
        pp->leftChild= new TreeNode(input);
    else if(pp->data<input)
        pp->rightChild= new TreeNode(input);
    else
        root = pp;
}

void bst(TreeNode* t){
    if(t->leftChild){
        bst(t->leftChild);
    }
    if(t->rightChild){
        bst(t->rightChild);
    }
    cout<<t->data<<"\n";
    
}

int main(){
    int input;
    cin>>input;
    TreeNode* root = new TreeNode(input);
    while(cin>>input)
        insert(root,input);
    bst(root);
}