#include "test.h"
#include<iostream>

Node::Node(){
    next=nullptr;
    data=0;
}

LinkedList::LinkedList(){
    head=new Node();
    size=0;
}

void LinkedList::Append(int data){
    if(size==0){
        head->data=data;
        head->next=nullptr;
    }
    else{
        Node* currentNode=new Node();

        currentNode->data=data;
        currentNode->next=nullptr;

        Node* tempNode=head;

        while(tempNode->next!=nullptr){
            tempNode=tempNode->next;
        }
        ++size;
    }
}


int LinkedList::Length(){
    int count=0;
    while(head!=nullptr){
        count++;
        head=head->next;
    }
    return count;
}


void LinkedList::Print(){
    Node* tempNode=head;
    for(int i=0;i<size;++i){
        std::cout<<tempNode->data<<std::endl;
        tempNode=tempNode->next;
    }
}