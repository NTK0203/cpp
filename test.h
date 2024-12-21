#pragma ocne
#include<iostream>

class Node{
    public:
        Node();

        int data;
        Node* next;
};

class LinkedList{
    public:
        LinkedList();

        int size;
        Node* head;
        void Append(int date);
        int Length();
        void Print();
};