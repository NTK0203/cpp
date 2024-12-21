#include <iostream>
#include <string>
#include <sstream>
#include "list.h"

using namespace std;

Node::Node(int data_, Node *next_, Node *prev_)
{
    data=data_;
    next=next_;
    prev=prev_;
}

LinkedList::LinkedList():head(0),tail(0)
{

}

void LinkedList::Append(int data)
{
    Node* newnode=new Node(data,0,0);
    if (head==0&&tail==0)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    newnode->prev = tail;
    tail->next = newnode;
    tail=newnode;
}

void LinkedList::Prepend(int data)
{
    Node* newnode=new Node(data,0,0);
    if (head==0&&tail==0)
    {
        head=newnode;
        tail=newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head=newnode;
}

int LinkedList::Length()
{
    int count=0;
    Node* curr=head;
    while(curr)
    {
        curr=curr->next;
        count++;
    }
    return count;
}

void LinkedList::Print()
{
    Node* curr=head;
    while(curr)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

void LinkedList::PrintReverse()
{
    Node* curr=tail;
    while(curr)
    {
        cout<<curr->data<<" ";
        curr=curr->prev;
    }
    cout<<endl;
}