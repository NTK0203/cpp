#include <iostream>
using namespace std;
class DblList;
class Stack;
class DblListNode {
friend class DblList;
friend class Stack;
protected:
 int data;
 DblListNode *left, *right;
 public:
    
    /*inline DblListNode(int a){
        data=a;
        left=NULL;
        right=NULL;
    }*/
};
class DblList {
public:
 // 기타 리스트 조작 연산
    void Push(int value);
    void Pop();
    void Printl();
protected:
DblListNode *first; // 첫 노드를 가리킴
};
class Stack : public DblList, DblListNode{
    friend class DblList;
    friend class DblListNode;
    public:
        void Push(int value);
        void Pop();
        void Printl();
};
void Stack::Push(int value)
{
    DblListNode* x=new DblListNode;
    x->data=value;
    if(first!=NULL)
    {
        x->right=first;
        x->left=first->left;
        first->left->right=x;
        first->left=x;
        first=x;
    }
    else
    {
        first=x;
        x->left=first;
        x->right=first;
    }
}
void Stack::Pop()
{
    first->right->left=first->left;
    first->left->right=first->right;
    DblListNode* temp=first;
    first=first->right;
    delete temp;
}
void Stack::Printl()
{
    DblListNode* x=first;
    cout<<x->data;
    cout<<x->right->right->right->data;
    cout<<x->left->left->data;
    cout<<x->right->right->right->data;
}
int main()
{
    Stack* a=new Stack();
    a->Push(1);
    a->Push(2);
    a->Push(3);
    a->Pop();
    a->Printl();
}